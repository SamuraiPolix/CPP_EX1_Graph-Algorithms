/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/

#include <stack>
#include "Algorithms.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <limits>

using namespace std;
namespace ariel{
    bool Algorithms::isConnected(Graph graph) {
        if (graph.getSize() <= 1) {
            return true;        // an empty/1 vertice graph is connected
        }
        vector<bool> visited(graph.getSize(), false);       // For each vertex, stores if it was visited yet by DFS or not. All initialized to false
        stack<size_t> stack;
        stack.push(0);

        // Run DFS
        while (!stack.empty()) {
            // Start from the top vertex
            size_t vertice = stack.top();
            stack.pop();

            // Mark the vertex as visited
            visited[vertice] = true;

            // Add unvisited neighbors to the stack
            for (size_t neighbor = 0; neighbor < graph.getSize(); ++neighbor) {
                if (graph.getWeight(vertice, neighbor) != 0 && !visited[neighbor]) { // Check if there's an edge and if the neighbor was not visited yet
                    stack.push(neighbor);
                }
            }
        }

        // Check if all vertices are visited
        for (size_t ind = 0; ind < visited.size(); ++ind){
            if (!visited[ind]) {
                return false;
            }
        }

        return true;
    }


    string Algorithms::shortestPath(Graph graph, size_t start, size_t end){
        // Run Bellman-Ford
        vector<size_t> path = bellmanFord(graph, start);

        // If the path to the end vertex is MIN/MAX INT then there is no path to it (either a negative cycles or no path to it)
        if (graph.getSize() <= 1 || path.empty() || (path[end] == INT32_MIN || path[end] == INT32_MAX || path[end] == 0)) {
            return "-1";
        }
        string ans = to_string(end); // Initialize string with end vertex
        size_t ind = end;     // Track the path back from the end
        while (path[ind] != start) {      // Keep going until the start is reached
            ind = path[ind];
            ans.insert(0, to_string(ind) + "->");
        }
        ans.insert(0, to_string(start) + "->"); // Add the start vertex to the beginning
        
        return ans;
    }

    string Algorithms::isBipartite(Graph graph) {
        vector<string> color(graph.getSize(), "WHITE");
        string result; // string to store the result

        // vectors to store vertices in setA and setB
        vector<size_t> setA;       // BLUE
        vector<size_t> setB;       // RED

        // sort of BFS on the graph
        for (size_t ind = 0; ind < graph.getSize(); ++ind) {
            if (color[ind] == "WHITE") {
                queue<size_t> queue;
                color[ind] = "BLUE";
                setA.push_back(ind); // Add the starting vertex to setA
                queue.push(ind);         // push starting vertex to queue

                while (!queue.empty()) {
                    size_t vertice = queue.front();
                    queue.pop();

                    for (size_t neighbor = 0; neighbor < graph.getSize(); ++neighbor) {
                        if (graph.getWeight(vertice, neighbor) != 0) {
                            if (color[neighbor] == "WHITE") {
                                color[neighbor] = (color[vertice] == "BLUE") ? "RED" : "BLUE";
                                queue.push(neighbor);

                                // Add the vertex to its set based on its color
                                if (color[neighbor] == "RED") {
                                    setB.push_back(neighbor);
                                } else {
                                    setA.push_back(neighbor);
                                }
                            } else if (color[neighbor] == color[vertice]) {
                                // If adjacent vertices have the same color, the graph is not bipartite
                                return "0";
                            }
                        }
                    }
                }
            }
        }

        // Build the result string
        result += "The graph is bipartite: A={";
        for (size_t ind = 0; ind < setA.size(); ++ind) {
            result += to_string(setA[ind]);
            if (ind < setA.size() - 1) {
                result += ", ";
            }
        }
        result += "}, B={";
        for (size_t ind = 0; ind < setB.size(); ++ind) {
            result += to_string(setB[ind]);
            if (ind < setB.size() - 1) {
                result += ", ";
            }
        }
        result += "}";

        return result; // Return the built result string
    }

    string Algorithms::negativeCycle(Graph graph){
        bellmanFord(graph, 0);
        if(graph.getNegativeCycles()){
            return "Graph does have negativeCycles";
        }
        return "Graph doesn't have negativeCycles";
    }

    vector<size_t> Algorithms::bellmanFord(Graph& graph, size_t source) {
        // Initialize distance and path vectors to MAX - each index represents a vertex
        vector<int> distance(graph.getSize(), INT32_MAX);
        vector<size_t> path(graph.getSize(), INT32_MAX);

        distance[source] = 0; // Set distance to source vertex as 0

        // Relax edges repeatedly (NumOfVertices - 1 times)
        for (int ind = 0; ind < graph.getSize()-1; ++ind){
            if (relaxEdges(graph, distance, path) == 0){
                return path;  // No relaxation was made - no need to continue relaxing
            }
        }

        // Check for negative cycles, after running relax on all edges for NumOfVertices-1 times total
        if (relaxEdges(graph, distance, path) > 0){
            // at least one edge was relaxed again - after we already relaxed all edges V-1 times -> negative edge found
            graph.setNegativeCycles(true);      // update graph object
        }

        if (graph.getNegativeCycles() || isContainsCycle(graph) == "1"){
            return vector<size_t>();            // A cycles exists in the graph - return an empty vector indicating no path was found
        }

        return path;
    }


    int Algorithms::relaxEdges(Graph graph, vector<int>& distance, vector<size_t>& path){
        int countChanges = 0;
        for (size_t vertice = 0; vertice < graph.getSize(); ++vertice) {
            for (size_t neighbor = 0; neighbor < graph.getSize(); ++neighbor) {
                int weight = graph.getWeight(vertice, neighbor); // Get the weight of the edge (vertice, neighbor)
                // If an edge exists between the vertices && we already reached vertice u && this route is better - update it
                if (weight != 0 && distance[vertice] != INT32_MAX && distance[vertice] + weight < distance[neighbor]) {
                    distance[neighbor] = distance[vertice] + weight;
                    path[neighbor] = vertice;    // Update the predecessor of neighbor to print the shortest path later
                    countChanges++;
                }
            }
        }
        return countChanges;
    }

    bool Algorithms::dfsVisit(Graph graph, size_t vertice, vector<bool>& visited, vector<size_t>& parent, vector<size_t>& cycle) {
        visited[vertice] = true; // Mark the curr vertex as visited

        // Traverse all adjacent vertices of curr vertex
        for (size_t neighbor = 0; neighbor < graph.getSize(); ++neighbor) {
            int weight = graph.getWeight(vertice, neighbor); // Get the weight of the edge (vertice, neighbor)

            // If an edge exists between the vertices and the vertex isnt the parent of curr vertex
            if (weight != 0 && parent[vertice] != neighbor) {
                // If the adjacent vertex is already visited - we found a cycle
                if (visited[neighbor]) {
                    // get cycle by back tracking using parent
                    size_t cur = vertice;
                    while (cur != neighbor) {
                        cycle.push_back(cur);
                        cur = parent[cur];
                    }
                    cycle.push_back(neighbor);
                    cycle.push_back(vertice);
                    return true;
                }
                // If the vertex is not visited, recursively visit it
                else {
                    parent[neighbor] = vertice; // Set the parent of the vertex
                    if (dfsVisit(graph, neighbor, visited, parent, cycle)) {
                        return true;
                    }
                }
            }
        }
        return false; // No cycle found
    }

    string Algorithms::isContainsCycle(Graph graph) {
        vector<bool> visited(graph.getSize(), false);
        vector<size_t> parent(graph.getSize(), INT32_MAX);
        vector<size_t> cycle;

        // Iterate over all vertices and run dfsVisit if not visited yet
        for (size_t ind = 0; ind < graph.getSize(); ++ind) {
            if (!visited[ind]) {
                if (dfsVisit(graph, ind, visited, parent, cycle)) {
                    string ans = "The cycle is: ";
                    size_t indCycle = 0;
                    for (;indCycle < cycle.size()-1; ++indCycle) {
                        ans += to_string(cycle[indCycle]) + "->";
                    }
                    ans += to_string(cycle[indCycle]);
                    graph.setCycles(true);
                    return ans;
                }
            }
        }

        return "0";
    }
}
