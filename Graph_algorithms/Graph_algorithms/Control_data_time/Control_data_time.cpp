#include "Control_data_time.h"

namespace control_data_time 
{
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
		return string();
	}
}