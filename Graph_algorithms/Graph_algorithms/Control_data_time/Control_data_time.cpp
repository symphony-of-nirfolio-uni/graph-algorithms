#include "Control_data_time.h"

#include <Windows.h>
#include <psapi.h>
#include <thread>

namespace control_data_time 
{
	void start_algorithm_without_stops(GraphAPI::Algorithm algorithm_name, Graph graph)
	{
		GraphAPI::instance().start_algorithm_without_stops(algorithm_name, graph);

	}

	string timeOfWork(GraphAPI::Algorithm algorithm_name, Graph graph)
	{
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

		GraphAPI::instance().start_algorithm_without_stops(algorithm_name, graph);

		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		double duration = double(std::chrono::duration_cast<std::chrono::microseconds>(start - end).count());

		string result = " mcs";
		if (duration/1000.0 > 10.0)
		{
			duration = duration / 1000.0;
			result = " ms";
		}
		return std::to_string(double(duration)) + result;
	}

	string dataUsed(GraphAPI::Algorithm algorithm_name, Graph graph)
	{
		double start_data_usage = 168.0;
		double max_data_usage = 0;
		PROCESS_MEMORY_COUNTERS_EX memoryInfo;
		ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
		start_data_usage += (double)memoryInfo.PrivateUsage / 1024.0;
		
		std::thread control_data(start_algorithm_without_stops, algorithm_name, graph);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		control_data.detach();
		
		while (true)
		{
			//how get move
			if (true) 
			{//todo)
				ZeroMemory(&memoryInfo, sizeof(PROCESS_MEMORY_COUNTERS_EX));
				GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memoryInfo, sizeof(memoryInfo));
				max_data_usage = max(max_data_usage, memoryInfo.PrivateUsage / 1024.0 - start_data_usage);
			}
		}
		return std::to_string((double)max_data_usage) + " KB";
	}
}