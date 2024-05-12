# Graph Algorithms - C++ Assignment #1
#### (Systems Programming B @ Ariel University)
#### Author: Samuel Lazareanu (sam.lazareanu@gmail.com)

This repository contains C++ implementations of graph algorithms. The graph is represented using an adjacency matrix.

The algorithms are designed to handle both directed and undirected graphs and weighted or unweighted.

## Implemented Functions

### Algorithms.hpp/.cpp
Algorithms include connectivity check, shortest path, cycle detection, bipartiteness check, and negative cycle detection.

The integration of helper functions within the main algorithms enhances modularity, readability, and maintainability of the codebase. Each helper function serves a distinct purpose and contributes to the overall functionality of the algorithms.

#### Functions:

1. **`isConnected(Graph)`:** Determines whether the graph is connected or not. Utilizes Depth First Search (DFS) algorithm.

2. **`shortestPath(Graph, size_t, size_t)`:** Finds the shortest (or lightest-weighted) path between two vertices in the graph. Utilizes Bellman-Ford algorithm.

3. **`isContainsCycle(Graph)`:** Detects the presence of any cycle in the graph. Utilizes Depth First Search (DFS) algorithm.

4. **`isBipartite(Graph)`:** Checks if a graph can be partitioned into two sets such that no two vertices within the same set are adjacent. Utilizes Breadth First Search (BFS) algorithm.

5. **`negativeCycle(Graph)`:** Identifies the presence of a negative cycle in the graph, if any. Utilizes Bellman-Ford algorithm.

#### Algorithms
These algorithms are implemented in the helper functions mentioned below.

##### Depth First Search (DFS)
DFS is used to traverse through the graph in a depth first search. It's used in the `isContainsCycle(Graph)`, `isConnected(Graph)` functions.

##### Breadth First Search (BFS)
BFS is used to explore all the vertices of the graph in a breath first search. It's used in the `isBipartite(Graph)` function.

##### Bellman-Ford Algorithm
Bellman-Ford algorithm is utilized for finding the shortest path in a weighted graph with negative weight edges - `shortestPath(Graph, size_t, size_t)` .

### Graph.hpp/.cpp
A graph is represented using an adjacency matrix.

#### Functions:

1. **`loadGraph(vector<vector<int>>)`:** Loads the provided adjacency matrix into the graph object. Makes sure the matrix is square.

2. **`printGraph()`:** Prints the adjacency matrix representation of the graph and stats related to it.

3. **`getSize()`:** Returns the size of the adjacency matrix (number of vertices).

4. **`getWeight(size_t, size_t) const`:** Returns the weight of the edge between two vertices (0 = no edge).

5. **`getCycles() const`:** Returns the flag indicating whether cycles were detected in the graph.

6. **`getNegativeCycles() const`:** Returns the flag indicating whether negative cycles were detected in the graph.

7. **`setCycles(bool)`:** Sets the flag indicating the presence of cycles in the graph.

8. **`setNegativeCycles(bool)`:** Sets the flag indicating the presence of negative cycles in the graph.

## Usage

1. Clone the repository.
2. Build the project using the provided 'makefile' and run:
   - `make demo` -     run using `./demo`  (simple test)
   - `make test` -     run using `./test`  (advanced doctest)
   - `make tidy` -     makes sure the code is clean
   - `make valgrind` - makes sure there are no memory leaks/problems.

If you want to use the implemented functions by yourself, see the `demo.cpp` file for run exmaples.

### Personal Test Folder
The `personal_test` folder includes the file `visualize_graph.py`, which can be used to visualize graphs and write good tests for them. This Python script complements the C++ implementations by providing a visualization tool.

Example for graph3 in `demo.cpp`:

<img src="https://github.com/SamuraiPolix/CPP_EX1/assets/52662032/afdfc2e8-1546-4375-9792-bf3c94ee4407" alt="image" width="400">

