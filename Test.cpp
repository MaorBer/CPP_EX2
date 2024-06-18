#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0 2 1 ]\n[2 0 3 ]\n[1 3 0 ]\n");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0 0 2 ]\n[1 0 1 ]\n[1 0 0 ]\n");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
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
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Test unary operators")
{
    // Test case 1: Increment operator
    ariel::Graph g1;
    ariel::Graph g1_test;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 3},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    vector<vector<int>> graph1_after = {
        {1, 2, 1},
        {2, 1, 4},
        {1, 2, 1}};

    g1_test.loadGraph(graph1_after);

    ariel::Graph g1_expected = g1;
    ++g1_expected;

    CHECK(g1_test == g1_expected);

    // Test case 2: Decrement operator
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g2_test;
    vector<vector<int>> graph2_after = {
        {-1, 0, -1},
        {0, -1, 0},
        {-1, 0, -1}};

    g2_test.loadGraph(graph2_after);

    ariel::Graph g2_expected = g2;
    --g2_expected;

    CHECK(g2_test == g2_expected);

    // Add more test cases for unary operators here if needed
}

TEST_CASE("Test unary operators")
{
    // Test case 3: Increment operator on an empty graph
    ariel::Graph g3;
    vector<vector<int>> graph3 = {};
    g3.loadGraph(graph3);
    ariel::Graph g3_expected = g3;
    ++g3_expected;
    CHECK(g3 == g3_expected); // Incrementing an empty graph should not change it

    // Test case 4: Decrement operator on an empty graph
    ariel::Graph g4;
    vector<vector<int>> graph4 = {};
    g4.loadGraph(graph4);
    ariel::Graph g4_expected = g4;
    --g4_expected;
    CHECK(g4 == g4_expected); // Decrementing an empty graph should not change it

    // Test case 5: Increment operator on a graph with negative weights
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {-1, -2, -3},
        {-2, -1, -2},
        {-3, -2, -1}};
    g5.loadGraph(graph5);
    ariel::Graph g5_test;
    vector<vector<int>> graph5_after = {
        {0, -1, -2},
        {-1, 0, -1},
        {-2, -1, 0}};
    g5_test.loadGraph(graph5_after);
    ariel::Graph g5_expected = g5;
    ++g5_expected;
    CHECK(g5_test == g5_expected); // Incrementing should increase each weight by 1

    // Test case 6: Decrement operator on a graph with negative weights
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
        {-1, -2, -3},
        {-2, -1, -2},
        {-3, -2, -1}};
    g6.loadGraph(graph6);
    ariel::Graph g6_test;
    vector<vector<int>> graph6_after = {
        {-2, -3, -4},
        {-3, -2, -3},
        {-4, -3, -2}};
    g6_test.loadGraph(graph6_after);
    ariel::Graph g6_expected = g6;
    --g6_expected;
    CHECK(g6_test == g6_expected); // Decrementing should decrease each weight by 1
}

TEST_CASE("Test comparison operators")
{
    // Test case 1: Greater than operator
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK((g2 > g1) == true);

    // Test case 2: Less than or equal to operator
    ariel::Graph g3 = g1;
    CHECK((g3 <= g1) == true);

    // Add more test cases for comparison operators here if needed
}

TEST_CASE("Test compound assignment operators")
{
    // Test case 1: Addition assignment operator
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g1_copy = g1;
    g1_copy += g2;

    CHECK(g1 + g2 == g1_copy);

    // Test case 2: Subtraction assignment operator
    ariel::Graph g2_copy = g2;
    g2_copy -= g1;

    CHECK(g2 - g1 == g2_copy);

    // Add more test cases for compound assignment operators here if needed
}

TEST_CASE("Test binary operators")
{
    // Test case 1: Addition operator
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3_expected;
    vector<vector<int>> expectedGraph1 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g3_expected.loadGraph(expectedGraph1);

    CHECK((g1 + g2) == g3_expected);

    // Test case 2: Multiplication operator
    ariel::Graph g4_expected;
    vector<vector<int>> expectedGraph2 = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    g4_expected.loadGraph(expectedGraph2);

    CHECK((g1 * g2) == g4_expected);

    // Add more test cases for binary operators here if needed
}
