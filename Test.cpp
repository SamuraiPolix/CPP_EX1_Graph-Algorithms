/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->2->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->2->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->2->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->2->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->0->1->2") == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(graph.loadGraph(graph1));
}
// -- OUR TESTS: --
// ---ADDED BY US----
    // 5x5 matrix that represents connected weighted graph with a negative weight cycle
TEST_CASE("Test negativeCycle")
{
    // Unweighted graphs without a negative cycle
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    // Weighted graph without a negative cycle
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    // Unweigthted graphs with a negative cycle
    vector<vector<int>> graph4 = {
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}};
    graph.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");

    vector<vector<int>> graph5 = {
        {0, -1, 0, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    // Weighted graph with a negative cycle
    vector<vector<int>> graph6 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, -5},
        {0, 0, 0, -5, 0}};
    graph.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");
}
TEST_CASE("Test normal cycles")
{
    ariel::Graph graph;
    // Unweighted graph without a cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");

    // Unweighted graph with a cycle
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->2->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->2->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->2->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->2->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->0->1->2") == true);

    // Weighted graph with a cycle
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(graph) != "0");        // all the cycles are valid
}
TEST_CASE("Test Bipartite")
{
    ariel::Graph graph;
    // Unweighted graph that is bipartite
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

    // Unweighted graph that is not bipartite
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");

    // Weighted graph that is not bipartite
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

TEST_CASE("Directed graph"){
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Undirected graph"){
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Graph with isolated vertices"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK((ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 3, 4}, B={1}" ||
    ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={1}, B={0, 2, 3, 4})") == true);
}

TEST_CASE("Graph with a single vertex and no edges"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == true);       // one vertice only is connected
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0}, B={}");
}

TEST_CASE("Graph with self-loop"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->0") == true);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

TEST_CASE("Connected graph"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph2 = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
    };
    graph.loadGraph(graph2); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == true);      
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");    
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

        vector<vector<int>> graph3 = {
    {0, 1, 2, 0, 0},
    {1, 0, 3, 0, 0},
    {2, 3, 0, 4, 0},
    {0, 0, 4, 0, 5},
    {0, 0, 0, 5, 0}
    };
    graph.loadGraph(graph3); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == true);        
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

TEST_CASE("Unconnected graph"){
    ariel::Graph graph;
    vector<vector<int>> graph2 = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    };
    graph.loadGraph(graph2); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == false);        
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1"); 
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");    
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");        
}    

TEST_CASE("Connected graph with a negative cycle"){
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}
    };
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}
