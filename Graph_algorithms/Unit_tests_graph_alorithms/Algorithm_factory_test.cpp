#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Graph_algorithms/Algorithm_factory.h"
#include "../Graph_algorithms/Graph_is_acyclic.h"
#include "../Graph_algorithms/Graph_is_connected.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace algorithms_on_graphs;


namespace Unit_tests_graph_alorithms
{
	TEST_CLASS(Algorithm_factory_test)
	{
	public:

		TEST_METHOD(correct)
		{
			{
				shared_ptr<Algorithm> algorithm = Graph_is_acyclic_factory::get_algorithm();
				Graph graph = Graph_is_acyclic_factory::get_graph("../Graph_algorithms/Graph_data/");

				Assert::IsTrue(graph.is_direct());
				Assert::IsTrue(graph.get_size() > 0);

				Assert::IsTrue(typeid(Graph_is_acyclic) == typeid(*algorithm));
			}

			{
				shared_ptr<Algorithm> algorithm = Graph_is_connected_factory::get_algorithm();
				Graph graph = Graph_is_connected_factory::get_graph("../Graph_algorithms/Graph_data/");

				Assert::IsTrue(graph.is_direct());
				Assert::IsTrue(graph.get_size() > 0);

				Assert::IsTrue(typeid(Graph_is_connected) == typeid(*algorithm));
			}
		}
	};
}