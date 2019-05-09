#include "Control_data_time.h"

namespace control_data_time 
{
	string timeOfWork()//(GraphAPI::Algorithm, Graph graph)		need new version
	{
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		//GraphAPI::start_algorithm_nonstop();
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
}