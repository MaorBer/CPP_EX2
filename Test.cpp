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

// TEST_CASE("Test graph multiplication")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(weightedGraph);
//     ariel::Graph g4 = g1 * g2;
//     vector<vector<int>> expectedGraph = {
//         {0, 0, 2},
//         {1, 0, 1},
//         {1, 0, 0}};
//     CHECK(g4.printGraph() == "[0 0 2 ]\n[1 0 1 ]\n[1 0 0 ]\n");
// }

// TEST_CASE("Invalid operations")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1, 1},
//         {1, 0, 2, 1},
//         {1, 2, 0, 1}};
//     g2.loadGraph(weightedGraph);
//     ariel::Graph g5; 
//     vector<vector<int>> graph2 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g5.loadGraph(graph2);
//     CHECK_THROWS(g5 * g1);
//     CHECK_THROWS(g1 * g2);

//     // Addition of two graphs with different dimensions
//     ariel::Graph g6;
//     vector<vector<int>> graph3 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g6.loadGraph(graph3);
//     CHECK_THROWS(g1 + g6);
// }

// TEST_CASE("Test unary operators")
// {
//     // Test case 1: Increment operator
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1);

//     ariel::Graph g1_expected = g1;
//     ++g1_expected;

//     CHECK(g1 + g1 == g1_expected);

//     // Test case 2: Decrement operator
//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(graph2);

//     ariel::Graph g2_expected = g2;
//     --g2_expected;

//     CHECK(g2 - g2 == g2_expected);

//     // Add more test cases for unary operators here if needed
// }

// TEST_CASE("Test comparison operators")
// {
//     // Test case 1: Greater than operator
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1);

//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(graph2);

//     CHECK((g2 > g1) == true);

//     // Test case 2: Less than or equal to operator
//     ariel::Graph g3 = g1;
//     CHECK((g3 <= g1) == true);

//     // Add more test cases for comparison operators here if needed
// }

// TEST_CASE("Test compound assignment operators")
// {
//     // Test case 1: Addition assignment operator
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1);

//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(graph2);

//     ariel::Graph g1_copy = g1;
//     g1_copy += g2;

//     CHECK(g1 + g2 == g1_copy);

//     // Test case 2: Subtraction assignment operator
//     ariel::Graph g2_copy = g2;
//     g2_copy -= g1;

//     CHECK(g2 - g1 == g2_copy);

//     // Add more test cases for compound assignment operators here if needed
// }

// TEST_CASE("Test binary operators")
// {
//     // Test case 1: Addition operator
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1);

//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(graph2);

//     ariel::Graph g3_expected;
//     vector<vector<int>> expectedGraph1 = {
//         {0, 2, 1},
//         {2, 0, 3},
//         {1, 3, 0}};
//     g3_expected.loadGraph(expectedGraph1);

//     CHECK((g1 + g2) == g3_expected);

//     // Test case 2: Multiplication operator
//     ariel::Graph g4_expected;
//     vector<vector<int>> expectedGraph2 = {
//         {0, 0, 2},
//         {1, 0, 1},
//         {1, 0, 0}};
//     g4_expected.loadGraph(expectedGraph2);

//     CHECK((g1 * g2) == g4_expected);

//     // Add more test cases for binary operators here if needed
// }
