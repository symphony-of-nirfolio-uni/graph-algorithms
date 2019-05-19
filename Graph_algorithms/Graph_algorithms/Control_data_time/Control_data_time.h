#pragma once
#include "../Graph_data/Graph.h"
#include "../GraphAPI/GraphAPI.h"
#include <chrono>
#include <string>

namespace control_data_time
{
	using algorithms_on_graphs::Graph;

	string timeOfWork(GraphAPI::Algorithm algorithm_name, Graph graph);
	string timeOfWork(GraphAPI::Algorithm algorithm_name, Graph graph, int start, int finish);

	string dataUsed(GraphAPI::Algorithm algorithm_name, Graph graph);
	string dataUsed(GraphAPI::Algorithm algorithm_name, Graph graph, int start, int finish);
}
