// ID: 212305965
// Email: maorw9@gmail.com

#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;
using namespace ariel;

void Graph::loadGraph(std::vector<std::vector<int>> graph)
{
    if (graph.empty())
    {
        throw invalid_argument("Invalid graph: The graph is empty.");
    }

    size_t n = graph.size(); // Assuming the graph is square
    for (size_t i = 0; i < n; ++i)
    {
        if (graph[i].size() != n)
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    g = graph;
    vertex_counter = n;

    // Reset edge counter
    edge_counter = 0;

    // Detect if the graph is directed or not
    bool hasDirectedEdge = false;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (graph[i][j] != 0)
            {
                edge_counter++;
                if (i != j && graph[j][i] != 0) // Undirected edge
                {
                    dir = false;
                }
                else // Directed edge
                {
                    hasDirectedEdge = true;
                }
            }
        }
    }

    // If the graph has directed edges but no undirected edges, consider it directed
    dir = hasDirectedEdge || dir;

    // If the graph is directed, ensure self-loops are removed
    if (dir)
    {
        for (size_t i = 0; i < n; ++i)
        {
            g[i][i] = 0;
        }
    }
}

void Graph::printGraph()
{
    std::cout << "Graph with " << vertex_counter << " vertices and " << edge_counter << " edges." << std::endl;
}

int Graph::weight(size_t s, size_t t)
{
    return this->g[s][t];
}

size_t Graph::get_ver()
{
    return this->vertex_counter;
}

bool Graph::isSymmetrical()
{
    size_t n = get_ver();
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (weight(i, j) != weight(j, i))
            {
                return false;
            }
        }
    }
    return true;
}

// OPERATORS =========================================================================


size_t Graph::countEdges() const
{
    // Count the total number of edges
    size_t totalEdges = 0;
    for (const auto &row : g)
    {
        for (int weight : row)
        {
            if (weight != 0)
            {
                totalEdges++;
            }
        }
    }
    return totalEdges;
}

Graph &Graph::operator++()
{
    // Increment all edge weights by 1
    for (auto &row : g)
    {
        for (int &weight : row)
        {
            weight++;
        }
    }
    return *this;
}

Graph &Graph::operator--()
{
    // Decrement all edge weights by 1
    for (auto &row : g)
    {
        for (int &weight : row)
        {
            weight--;
        }
    }
    return *this;
}


bool Graph::operator>(const Graph &other) const
{
    // Compare the number of edges in the graphs
    return countEdges() > other.countEdges();
}

bool Graph::operator>=(const Graph &other) const
{
    // Compare the number of edges in the graphs
    return countEdges() >= other.countEdges();
}

bool Graph::operator<(const Graph &other) const
{
    // Compare the number of edges in the graphs
    return countEdges() < other.countEdges();
}

bool Graph::operator<=(const Graph &other) const
{
    // Compare the number of edges in the graphs
    return countEdges() <= other.countEdges();
}

bool Graph::operator==(const Graph &other) const
{
    // Compare the adjacency matrices of the graphs
    return g == other.g;
}

bool Graph::operator!=(const Graph &other) const
{
    // Compare the adjacency matrices of the graphs
    return g != other.g;
}

Graph Graph::operator+(const Graph &other) const
{
    // Perform element-wise addition of the adjacency matrices
    Graph result = *this;
    for (size_t i = 0; i < g.size(); ++i)
    {
        for (size_t j = 0; j < g[i].size(); ++j)
        {
            result.g[i][j] += other.g[i][j];
        }
    }
    return result;
}

Graph &Graph::operator+=(const Graph &other)
{
    // Perform in-place element-wise addition of the adjacency matrices
    for (size_t i = 0; i < g.size(); ++i)
    {
        for (size_t j = 0; j < g[i].size(); ++j)
        {
            g[i][j] += other.g[i][j];
        }
    }
    return *this;
}

Graph Graph::operator+() const
{
    // Return a copy of the current graph
    return *this;
}

Graph Graph::operator-(const Graph &other) const
{
    // Perform element-wise subtraction of the adjacency matrices
    Graph result = *this;
    for (size_t i = 0; i < g.size(); ++i)
    {
        for (size_t j = 0; j < g[i].size(); ++j)
        {
            result.g[i][j] -= other.g[i][j];
        }
    }
    return result;
}

Graph &Graph::operator-=(const Graph &other)
{
    // Perform in-place element-wise subtraction of the adjacency matrices
    for (size_t i = 0; i < g.size(); ++i)
    {
        for (size_t j = 0; j < g[i].size(); ++j)
        {
            g[i][j] -= other.g[i][j];
        }
    }
    return *this;
}

Graph Graph::operator-() const
{
    // Return the negation of the current graph
    Graph result = *this;
    for (size_t i = 0; i < g.size(); ++i)
    {
        for (size_t j = 0; j < g[i].size(); ++j)
        {
            result.g[i][j] = -result.g[i][j];
        }
    }
    return result;
}

namespace ariel {
    ostream &operator<<(ostream &os, Graph &g) {
        size_t n = g.get_ver();
        for (size_t i = 0; i < n; ++i) {
            os << "[";
            for (size_t j = 0; j < n; ++j) {
                os << g.weight(i, j) << " ";
            }
            os << "]";
            os << std::endl;
        }
        return os;
    }
}

Graph &Graph::operator*=(int scalar)
{
    // Multiply all edge weights by the scalar
    for (auto &row : g)
    {
        for (int &weight : row)
        {
            weight *= scalar;
        }
    }
    return *this;
}

Graph &Graph::operator/=(int scalar)
{
    // Divide all edge weights by the scalar
    for (auto &row : g)
    {
        for (int &weight : row)
        {
            weight /= scalar;
        }
    }
    return *this;
}

Graph Graph::operator*(const Graph &other)
{
    // Perform element-wise multiplication of the adjacency matrices
    Graph result = *this;
    for (size_t i = 0; i < g.size(); ++i)
    {
        for (size_t j = 0; j < g[i].size(); ++j)
        {
            result.g[i][j] *= other.g[i][j];
        }
    }
    return result;
}
