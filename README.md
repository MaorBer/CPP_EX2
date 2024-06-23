# Assignment 2 - graphs and operator loading (continuation of Assignment 1)

## Overview

Welcome to the Graph Operations and Algorithms repository, an extension of Task 1 in the System Programming 2 course at Ariel University. This assignment focuses on implementing operators and extending graph functionality using C++. The repository includes a Graph class with support for various operations and algorithms commonly used in graph theory.

## Assignment Details

### Graph Class

The core of this repository is the `Graph` class, implemented in `Graph.hpp` and `Graph.cpp`. Originally developed in Task 1, the Graph class utilizes an adjacency matrix to represent graphs and supports operations such as loading a graph, printing it, accessing weights between vertices, and checking graph properties.

### Operator Implementations

In Task 2, we extended the Graph class to include operator overloads. These operators are designed to work on adjacency matrices of graphs, allowing arithmetic operations (addition, subtraction, multiplication, etc.) and comparison operations (greater than, less than, equality, etc.) between graphs. This extension enhances the utility of the Graph class, enabling intuitive manipulation and comparison of graph structures.

### Algorithms

The repository also includes implementations of several fundamental graph algorithms in `Algorithms.cpp`. These algorithms leverage the capabilities of the Graph class and include:

- **Bellman-Ford Algorithm**: Computes shortest paths from a source vertex to all other vertices, handling negative weights.
- **Connectivity Check**: Determines if the graph is connected.
- **Shortest Path**: Finds the shortest path between two vertices.
- **Cycle Detection**: Detects cycles in the graph.
- **Bipartiteness Check**: Checks if the graph is bipartite.
- **Negative Cycle Detection**: Detects the presence of negative cycles.

## Files Included

- **Graph.hpp**: Header file defining the Graph class with member functions and operator overloads.
- **Graph.cpp**: Implementation file for the Graph class, including definitions of member functions and operators.
- **Algorithms.cpp**: Implementation of various graph algorithms utilizing the Graph class(taken from Task 1 of the course).
- **Algorithms.hpp**: Header file of Algorithms.c(taken from Task 1 of the course).
- **TestCounter.cpp, Test.cpp**: Test files for unit testing the Graph class and algorithms.
- **Demo.cpp**: Demo file showcasing the usage of the Graph class and algorithms.

## Getting Started

### Prerequisites

a C++ compiler

### Build Instructions

Use the provided `Makefile` to build (and run the tests) the project:
```bash
make
