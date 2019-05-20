#include "Control_data_time.h"

#include <Windows.h>
#include <psapi.h>
#include <thread>

namespace control_data_time 
{
	void start_algorithm_for_data(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph, int &can_move)
	{
		GraphAPI::instance().start_algorithm(current_algorithm, current_graph, can_move);
	}

	void start_algorithm_for_data_start_finish(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph, int st, int fin, int &can_move)
	{
		GraphAPI::instance().start_algorithm(current_algorithm, current_graph, st, fin, can_move);
	}


	string time_of_work(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph)
	{
		std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

		GraphAPI::instance().start_algorithm_without_stops(current_algorithm, current_graph);

		std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
        double duration = double(std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count());

		string result = " mcs";
		if (duration/1000.0 > 10.0)
		{
			duration = duration / 1000.0;
			result = " ms";
		}
		return std::to_string(double(duration)) + result;
	}

	string time_of_work(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph, int st, int fin)
	{
		std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

		GraphAPI::instance().start_algorithm_without_stops(current_algorithm, current_graph, st, fin);

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

	string RAM_usage(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph)
	{
		double start_data_usage = 168.0;
		double max_data_usage = 0;
		int can_move = 0;
		PROCESS_MEMORY_COUNTERS_EX memoryInfo;
		ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
		start_data_usage += double(memoryInfo.PrivateUsage) / 1024.0;
		
		std::thread control_data(start_algorithm_for_data, current_algorithm, current_graph, std::ref(can_move));
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		control_data.detach();
		
		while (can_move != -1)
		{
			if (can_move == 0) 
			{
				ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
				GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
				max_data_usage = max(max_data_usage, double(memoryInfo.PrivateUsage) / 1024.0 - start_data_usage);
				can_move = 1;
			}
		}
		return std::to_string(double(max_data_usage)) + " KB";
	}

	string RAM_usage(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph, int st, int fin)
	{
		double start_data_usage = 168.0;
		double max_data_usage = 0;
		int can_move = 0;
		PROCESS_MEMORY_COUNTERS_EX memoryInfo;
		ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
		start_data_usage += double(memoryInfo.PrivateUsage) / 1024.0;

		std::thread control_data(start_algorithm_for_data_start_finish, current_algorithm, current_graph, st, fin, std::ref(can_move));
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		control_data.detach();

		while (can_move != -1)
		{
			if (can_move == 0)
			{
				ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
				GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
				max_data_usage = max(max_data_usage, double(memoryInfo.PrivateUsage) / 1024.0 - start_data_usage);
				can_move = 1;
			}
		}
		return std::to_string(double(max_data_usage)) + " KB";
	}
}
