#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Graph_algorithms/Graph_factory.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace algorithms_on_graphs;


namespace Unit_tests_graph_alorithms
{
	TEST_CLASS(Graph_factory_test)
	{
	public:

		TEST_METHOD(correct)
		{
			{
				Unweighted_undirected_graph_factory graph_factory("../Graph_algorithms/Graph_data/");

				Graph graph = graph_factory.make_graph();

				Assert::IsFalse(graph.weight);
				Assert::IsFalse(graph.direct);
				Assert::IsTrue(graph.graph.size() > 0);
			}

			{
				Unweighted_directed_graph_factory graph_factory("../Graph_algorithms/Graph_data/");

				Graph graph = graph_factory.make_graph();

				Assert::IsFalse(graph.weight);
				Assert::IsTrue(graph.direct);
				Assert::IsTrue(graph.graph.size() > 0);
			}

			{
				Weighted_undirected_graph_factory graph_factory("../Graph_algorithms/Graph_data/");

				Graph graph = graph_factory.make_graph();

				Assert::IsTrue(graph.weight);
				Assert::IsFalse(graph.direct);
				Assert::IsTrue(graph.graph.size() > 0);
			}

			{
				Weighted_directed_graph_factory graph_factory("../Graph_algorithms/Graph_data/");

				Graph graph = graph_factory.make_graph();

				Assert::IsTrue(graph.weight);
				Assert::IsTrue(graph.direct);
				Assert::IsTrue(graph.graph.size() > 0);
			}
		}
	};
}