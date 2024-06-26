// ID: 212305965
// Email: maorw9@gmail.com

#ifndef GRAPH_HPP
#pragma once
#define GRAPH_HPP
#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> g;
        size_t edge_counter;
        size_t vertex_counter;
        bool dir;

    public:
        void loadGraph(std::vector<std::vector<int>> g);
        string printGraph(); // addapted to ex2
        int weight(size_t s, size_t t);
        size_t get_ver();
        bool isSymmetrical(); // If the Graph isSymmetrical then it is an undirected Graph
        // Increment operator (++)

        size_t countEdges() const;

        // OPERATORS

        friend ostream &operator<<(ostream &os, const Graph &g);

        Graph &operator++();

        // Decrement operator (--)
        Graph &operator--();

        // Greater-than operator (>)
        bool operator>(const Graph &other) const;

        // Greater-than-or-equal operator (>=)
        bool operator>=(const Graph &other) const;

        // Less-than operator (<)
        bool operator<(const Graph &other) const;

        // Less-than-or-equal operator (<=)
        bool operator<=(const Graph &other) const;

        // Equal-to operator (==)
        bool operator==(const Graph &other) const;

        // Not-equal-to operator (!=)
        bool operator!=(const Graph &other) const;

        // Addition operator (+)
        Graph operator+(const Graph &other) const;

        // Addition assignment operator (+=)
        Graph &operator+=(const Graph &other);

        // Unary plus operator (+)
        Graph operator+() const;

        // Subtraction operator (-)
        Graph operator-(const Graph &other) const;

        // Subtraction assignment operator (-=)
        Graph &operator-=(const Graph &other);

        // Unary minus operator (-)
        Graph operator-() const;

        // Multiply the weights of the graph by a scalar
        Graph &operator*=(int scalar);

        // Divide the weights of the graph by a scalar
        Graph &operator/=(int scalar);

        // Multiply two graphs element-wise
        Graph operator*(const Graph &other);
    };
}

#endif