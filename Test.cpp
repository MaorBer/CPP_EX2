// ID: 212305965
// Email: maorw9@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <cstdint>

using namespace std;
using namespace ariel;

TEST_CASE("Test graph addition")
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0 2 1 ]\n[2 0 3 ]\n[1 3 0 ]\n");
}

TEST_CASE("Test graph multiplication")
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0 0 2 ]\n[1 0 1 ]\n[1 0 0 ]\n");
}

TEST_CASE("Invalid operations")
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Test comparison operators")
{
    // Test case 1: Greater than operator
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK((g2 > g1) == true);

    // Test case 2: Less than or equal to operator
    Graph g3 = g1;
    CHECK((g3 <= g1) == true);

    // Add more test cases for comparison operators here if needed
}

TEST_CASE("Test compound assignment operators")
{
    // Test case 1: Addition assignment operator
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    Graph g1_copy = g1;
    g1_copy += g2;

    CHECK(g1 + g2 == g1_copy);

    // Test case 2: Subtraction assignment operator
    Graph g2_copy = g2;
    g2_copy -= g1;

    CHECK(g2 - g1 == g2_copy);

    // Add more test cases for compound assignment operators here if needed
}

TEST_CASE("Test binary operators")
{
    // Test case 1: Addition operator
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    Graph g3_expected;
    vector<vector<int>> expectedGraph1 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g3_expected.loadGraph(expectedGraph1);

    CHECK((g1 + g2) == g3_expected);

    // Test case 2: Multiplication operator
    Graph g4_expected;
    vector<vector<int>> expectedGraph2 = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    g4_expected.loadGraph(expectedGraph2);

    CHECK((g1 * g2) == g4_expected);

    // Add more test cases for binary operators here if needed
}

// Additional tests for algorithms

TEST_CASE("Bellman-Ford algorithm")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 6, 0, 0, 7},
        {0, 0, 5, -4, 8},
        {0, -2, 0, 0, 0},
        {2, 0, 7, 0, 0},
        {0, 0, -3, 9, 0}};
    g.loadGraph(graph);

    Algorithms alg;
    vector<int> d(g.get_ver(), INT32_MAX);
    vector<int> pi(g.get_ver(), -1);

    alg.bellman_ford(g, 0, d, pi);

    CHECK(d == vector<int>({0, 2, 4, -2, 7}));
    CHECK(pi == vector<int>({-1, 2, 4, 1, 0})); // Corrected expected pi
}

TEST_CASE("Check if graph is connected")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);

    Algorithms alg;
    CHECK(alg.isConnected(g) == true);
}

TEST_CASE("Test shortest path algorithm")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 0},
        {0, 0, 0, 8, 0, 0},
        {0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 0, 10},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph);

    Algorithms alg;
    CHECK(alg.shortestPath(g, 0, 5) == "0-->1-->2-->3-->4-->5");
    CHECK(alg.shortestPath(g, 1, 4) == "1-->2-->3-->4");
    CHECK(alg.shortestPath(g, 2, 3) == "2-->3");
}

TEST_CASE("Check if graph contains a cycle")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph);

    Algorithms alg;
    CHECK(alg.isContainsCycle(g) == "The cycle is:2-->4-->3-->2");
}

TEST_CASE("Check if graph is bipartite")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph);

    Algorithms alg;
    CHECK(alg.isBipartite(g) == "The graph is bipartite: A={0, 2,}, B={1, 3,}");
}

TEST_CASE("Check if graph contains a negative cycle")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 2, 0},
        {1, 0, 0, -1},
        {-5, 0, 0, 0}};
    g.loadGraph(graph);

    Algorithms alg;
    CHECK(alg.negativeCycle(g) == "0, 1, 2, 3, 0");
}
