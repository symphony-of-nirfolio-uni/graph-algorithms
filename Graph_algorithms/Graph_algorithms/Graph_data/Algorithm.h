#pragma once


#include "../GraphAPI/GraphAPI.h"
#include "Graph.h"

//#include <iostream>
//#include <atomic>
//using std::cout;
//
//class TempAPI
//{
//public:
//	std::atomic_bool canm;
//	TempAPI()
//	{
//		canm = false;
//	}
//
//	static TempAPI& getInstance() {
//		static TempAPI  instance;
//		return instance;
//	}
//
//	bool can_move_on()
//	{
//		if (canm)
//		{
//			canm = false;
//			return true;
//		}
//		return canm;
//	}
//
//	void highlight_vertex()
//	{
//		cout << "\n*****\n";
//	}
//};

namespace algorithms_on_graphs
{
	class Algorithm
	{

	protected:
		void waiting_for_the_next_move();

	public:
		virtual void work(Graph graph, bool need_to_stop) {};
		virtual void work(Graph graph, int start, int finish, bool need_to_stop) {};
	};
}