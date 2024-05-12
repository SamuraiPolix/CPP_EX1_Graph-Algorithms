/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/

#pragma once
#include "Graph.hpp"
#include <string>

using namespace std;
namespace ariel{
    class Algorithms{
    public:
        /*
         * Gets a graph,
         * returns 1 if the graph is connected (otherwise returns 0).
         */
        static bool isConnected(Graph);

        /*
         * The function receives a graph, a start vertex and an end vertex.
         * It returns the most light-weighted path (in case the graph is not weighted - the shortest) between the two vertices.
         * If there is no such route, the function will return -1.
         */
        static string shortestPath(Graph, size_t, size_t);


        /*
         * Receives a graph and tried to print a cycle in it (if it succeeds, it will return 1).
         * If there are no circles in the graph, will return 0.
         */
        static string isContainsCycle(Graph);

        /*
         * Gets a graph and returns the partition of the graph into a bipartite graph (if it succeeds, it will return 1).
         * If the graph cannot be partitioned, will return 0.
         * 
         * Using sort of BFS, splitting vertices into 2 sets by "coloring" them.
         * Adjacent vertices with the same color = the graph is not bipartite -> returns "0".
         * Otherwise, the graph is bipartite -> return a string with the 2 sets.
         */ 
        static string isBipartite(Graph);

        /*
         * Gets a graph and tries to find a negative cycle (that is, a cycle whose sum of the weights of the sides is negative).
         * If such circle exists, will print it, and return 1. otherwise, there are no negative circles, return 0.
         */ 
        static string negativeCycle(Graph);

    private:
        /*
         * Gets a graph and a start vertice, and runs the Bellman Ford Algorithm on it.
         * Updates the Graph object if negative/positive cycles are found.
         * Returns a path vector, allowing us to track extract the shortest path from it.
         */
        static vector<size_t> bellmanFord(Graph&, size_t);

        /*
         * Gets a graph, distances vector and paths vector (pointers).
         * Tries to realx all the edges one time and update the distance and path vectors.
         * Returns the number of relaxations performed.
         */
        static int relaxEdges(Graph, vector<int>&, vector<size_t>&);

        static bool dfsVisit(Graph, size_t, vector<bool>&, vector<size_t>&, vector<size_t>&);
    };
}