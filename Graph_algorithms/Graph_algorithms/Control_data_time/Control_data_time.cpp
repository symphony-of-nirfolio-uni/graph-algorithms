#include "Control_data_time.h"

#include <Windows.h>
#include <psapi.h>
#include <thread>

namespace control_data_time 
{
	/*
	void start_algorithm(GraphAPI::Algorithm algorithm_name, Graph graph, int &can_move)
	{
		GraphAPI::instance().start_algorithm(algorithm_name, graph, can_move);

	}

	void start_algorithm(GraphAPI::Algorithm algorithm_name, Graph graph, int start, int finish, bool &can_move_on)
	{
		GraphAPI::instance().start_algorithm(algorithm_name, graph, start, finish, can_move);

	}*/

	string timeOfWork(GraphAPI::Algorithm algorithm_name, Graph graph)
	{
		std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

		GraphAPI::instance().start_algorithm_without_stops(algorithm_name, graph);

		std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
		double duration = double(std::chrono::duration_cast<std::chrono::microseconds>(start_time - end_time).count());

		string result = " mcs";
		if (duration/1000.0 > 10.0)
		{
			duration = duration / 1000.0;
			result = " ms";
		}
		return std::to_string(double(duration)) + result;
	}

	string timeOfWork(GraphAPI::Algorithm algorithm_name, Graph graph, int start, int finish)
	{
		std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

		GraphAPI::instance().start_algorithm_without_stops(algorithm_name, graph, start, finish);

		std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
		double duration = double(std::chrono::duration_cast<std::chrono::microseconds>(start_time - end_time).count());

		string result = " mcs";
		if (duration / 1000.0 > 10.0)
		{
			duration = duration / 1000.0;
			result = " ms";
		}
		return std::to_string(double(duration)) + result;
	}

	string dataUsed(GraphAPI::Algorithm algorithm_name, Graph graph)
	{
		///wait changes from bogdan
		/*
		double start_data_usage = 168.0;
		double max_data_usage = 0;
		int can_move = 0;
		PROCESS_MEMORY_COUNTERS_EX memoryInfo;
		ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
		start_data_usage += (double)memoryInfo.PrivateUsage / 1024.0;
		
		std::thread control_data(start_algorithm, algorithm_name, graph, can_move);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		control_data.detach();
		
		/*while (can_move != -1)
		{
			//how get move
			if (can_move == 0) 
			{
				ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
				GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
				max_data_usage = max(max_data_usage, memoryInfo.PrivateUsage / 1024.0 - start_data_usage);
				can_move = 1;
			}
		}*/
		return "0 KB";//std::to_string((double)max_data_usage) + " KB";
	}

	string dataUsed(GraphAPI::Algorithm algorithm_name, Graph graph, int start, int finish)
	{
		///wait changes from bogdan
		/*
		double start_data_usage = 168.0;
		double max_data_usage = 0;
		int can_move = 0;
		PROCESS_MEMORY_COUNTERS_EX memoryInfo;
		ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
		start_data_usage += (double)memoryInfo.PrivateUsage / 1024.0;

		std::thread control_data(start_algorithm, algorithm_name, graph, start, finish, can_move);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		control_data.detach();

		while (can_move != -1)
		{
			//how get move
			if (can_move == 0)
			{
				ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
				GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
				max_data_usage = max(max_data_usage, memoryInfo.PrivateUsage / 1024.0 - start_data_usage);
				can_move = 1;
			}
		}*/
		return "0 KB";//std::to_string((double)max_data_usage) + " KB";
	}
}