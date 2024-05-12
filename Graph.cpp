/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/

#include "Graph.hpp"
#include <iostream>

using namespace std;
namespace ariel {
    // Constuctors:

    void Graph::loadGraph(vector<vector<int>> graph) {
        // Check if the graph is square
        for (size_t i = 0; i < graph.size(); ++i) {
            if (graph[i].size() != graph.size()) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        // Graph is a square - load it
        adjMatrix = graph;
        this->negativeCycles = false;
        this->cycles = false;
    }

    void Graph::printGraph() {
        size_t vertices = 0;
        size_t edges = 0;
        
        for (size_t i = 0; i < this->adjMatrix.size(); ++i) {
            vertices++;     // each row represents a vertice
            for (size_t j = 0; j < this->adjMatrix[i].size(); ++j) {
                if (this->adjMatrix[i][j] != 0){        // 0 means there is no edge between vertices i and j
                    edges++;
                }
                cout << this->adjMatrix[i][j] << " ";       // print element
            }
            cout << endl;       // line drop
        }

        // Print stats
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;        
    }

    size_t Graph::getSize(){
        return adjMatrix.size();
    }


    int Graph::getWeight(size_t ver1, size_t ver2) const{
        return this->adjMatrix[ver1][ver2];   
    }
    bool Graph::getCycles() const{
        return this->cycles;
    }
    bool Graph::getNegativeCycles() const{
        return this->negativeCycles;
    }
    void Graph::setCycles(bool status){
        this->cycles = status;
    }
    void Graph::setNegativeCycles(bool status){
        this->negativeCycles = status;
        // If a negative cycles exists - a normal cycles exists as well
        this->cycles = status;
    }
}
