// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#pragma once

namespace Alex
{
	template <typename TReturnType, typename TEventArgs>
	class Event
	{
	private:
		std::map<std::string, std::function<TReturnType(TEventArgs)>> observerList;
		std::string name;
	public:

		void Subscribe(std::string&& identifier, std::function<TReturnType(TEventArgs)>&& inFunction)
		{
			auto object = observerList.find(identifier);
			
			if (object != observerList.end())
				throw("Identifiers is already in List, choose another one!");
			
			observerList.insert(std::make_pair(identifier, inFunction));
		}

		void UnSubscribe(const std::string&& identifier)
		{
			auto object = observerList.find(identifier);

			if (object != observerList.end())
				observerList.erase(object);
			else
				throw("Cant find the Method | Cant unsubscribe");
		}

		void UnSubscribeAll()
		{
			if (observerList.empty())
				throw("No Subscribers!");

				observerList.clear();
		}

		void Invoke(TEventArgs e)
		{
			if (observerList.empty())
				return;

			for (const auto &p : observerList)
				p.second(e);
		}

		~Event()
		{
			if (!observerList.empty())
			{
				for (const auto &p : observerList)
					M_DebugLog(p.first, "pls unsusbscribe!");
			}
		}
	};
}