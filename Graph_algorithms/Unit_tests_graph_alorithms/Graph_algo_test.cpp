#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Graph_algorithms/Graph_algo.h"
#include "../Graph_algorithms/Graph_is_acyclic.h"
#include "../Graph_algorithms/Graph_is_connected.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace algorithms_on_graphs;


namespace Unit_tests_graph_alorithms
{
	TEST_CLASS(Graph_algo_test)
	{
	public:

		TEST_METHOD(graph_is_acyclic)
		{
			{
				shared_ptr<Algorithm> algorithm = Graph_is_acyclic_factory::get_algorithm();
				Graph graph = Graph_is_acyclic_factory::get_graph("../Graph_algorithms/Graph_data/");

				Graph_algo graph_algo(algorithm);

				Assert::IsFalse(graph_algo.work_without_stops(graph));
			}

			{
				shared_ptr<Algorithm> algorithm = Graph_is_acyclic_factory::get_algorithm();
				Graph graph = Graph_is_acyclic_factory::get_graph("../Graph_algorithms/Graph_data/", false);

				Graph_algo graph_algo(algorithm);

				Assert::IsFalse(graph_algo.work_without_stops(graph));
			}

			{
				shared_ptr<Algorithm> algorithm = Graph_is_connected_factory::get_algorithm();
				Graph graph = Graph_is_connected_factory::get_graph("../Graph_algorithms/Graph_data/");

				Graph_algo graph_algo(algorithm);

				Assert::IsFalse(graph_algo.work_without_stops(graph));
			}

			{
				shared_ptr<Algorithm> algorithm = Graph_is_connected_factory::get_algorithm();
				Graph graph = Graph_is_connected_factory::get_graph("../Graph_algorithms/Graph_data/", false);

				Graph_algo graph_algo(algorithm);

				Assert::IsTrue(graph_algo.work_without_stops(graph));
			}
		}
	};
}