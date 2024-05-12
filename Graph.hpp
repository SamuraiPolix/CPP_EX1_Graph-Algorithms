/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/

#pragma once
#include <vector>

using namespace std;
namespace ariel {
    class Graph{
        // private: by default

        vector<vector<int>> adjMatrix;
        bool negativeCycles;
        bool cycles;

        public:
            // Inline Constructors
            Graph(){ negativeCycles = false; cycles = false; adjMatrix = {}; }

            Graph(vector<vector<int>> adjMatrix){ Graph(); loadGraph(adjMatrix); }
            
            // Declaring Functions:

            /*
             * Load the received adjacency matrix to the object.
             * Returns 1 if succeeds, 0 if fails.
            */ 
            void loadGraph(vector<vector<int>>);
            
            /*
             * Prints the adjMatrix and the number of verices and edges in the graph.
            */
            void printGraph();

            /*
             * Returns the size of the AdjMatrix of the graph.
             * Size represents the number vertices = number of rows and cols (square matrix).
            */ 
            size_t getSize();

            int getWeight(size_t, size_t) const;
            bool getCycles() const;
            bool getNegativeCycles() const;
            void setCycles(bool);
            void setNegativeCycles(bool);
    };
}