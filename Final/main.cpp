#include <iostream>
#include "graph.h"

using namespace std;

/*
The graph:
               a/0     c/2
                |    /  |
                |   /   |
                |  /    |
                b/1 -- d/3 ------- e/4
*/

//tests functionality of the add vertex and print functions
void test_add_vertex(){
    Graph graph;
    Node node_a("a", 0);
    Node node_b("b", 1);
    Node node_c("c", 2);
    graph.add_vertex(&node_a);
    graph.add_vertex(&node_b);
    graph.add_vertex(&node_c);
    graph.print();
}

//tests functionality of the add edge function
void test_add_edge(){
    Graph graph;
    Node node_a("a", 0);
    Node node_b("b", 1);
    Node node_c("c", 2);
    graph.add_vertex(&node_a);
    graph.add_vertex(&node_b);
    graph.add_vertex(&node_c);
    node_a.add_edge(&node_b);
    node_a.add_edge(&node_c);
    node_b.add_edge(&node_a);
    node_b.add_edge(&node_c);
    node_c.add_edge(&node_a);
    node_c.add_edge(&node_b);
    cout << "Node a neighbors: " << node_a.neighbors[0]->name << node_a.neighbors[1]->name <<endl;
    cout << "Node b neighbors: " << node_b.neighbors[0]->name << node_b.neighbors[1]->name <<endl;
    cout << "Node c neighbors: " << node_c.neighbors[0]->name << node_c.neighbors[1]->name <<endl;
}

//tests shortest path algorithm
void test_shortest_path(){
    Graph graph;
    Node node_a("a", 0);
    Node node_b("b", 1);
    Node node_c("c", 2);
    Node node_d("d", 3);
    Node node_e("e", 4);
    graph.add_vertex(&node_a);
    graph.add_vertex(&node_b);
    graph.add_vertex(&node_c);
    graph.add_vertex(&node_d);
    graph.add_vertex(&node_e);

    node_a.add_edge(&node_b);
    node_b.add_edge(&node_a);
    node_b.add_edge(&node_c);
    node_b.add_edge(&node_d);
    node_c.add_edge(&node_b);
    node_c.add_edge(&node_d);
    node_d.add_edge(&node_b);
    node_d.add_edge(&node_c);
    node_d.add_edge(&node_e);
    node_e.add_edge(&node_d);

    cout << "a to e: expected length 3" << endl;
    graph.shortest_path(&node_a, &node_e);
    cout <<endl;
    cout << "b to a: expected length 1" << endl;
    graph.shortest_path(&node_b, &node_a);
    cout <<endl;
    cout << "c to a: expected length 2" << endl;
    graph.shortest_path(&node_c, &node_a);
    cout <<endl;
    cout << "d to e: expected length 1" << endl;
    graph.shortest_path(&node_d, &node_e);
    cout <<endl;
    cout << "e to a: expected length 3" << endl;
    graph.shortest_path(&node_e, &node_a);
}

//tests min spanning tree algorithm
void test_min_spanning_tree(){
    Graph graph;
    Node node_a("a", 0);
    Node node_b("b", 1);
    Node node_c("c", 2);
    Node node_d("d", 3);
    Node node_e("e", 4);
    graph.add_vertex(&node_a);
    graph.add_vertex(&node_b);
    graph.add_vertex(&node_c);
    graph.add_vertex(&node_d);
    graph.add_vertex(&node_e);

    node_a.add_edge(&node_b);
    node_b.add_edge(&node_a);
    node_b.add_edge(&node_c);
    node_b.add_edge(&node_d);
    node_c.add_edge(&node_b);
    node_c.add_edge(&node_d);
    node_d.add_edge(&node_b);
    node_d.add_edge(&node_c);
    node_d.add_edge(&node_e);
    node_e.add_edge(&node_d);
    cout <<"Expected path: a, b, c, d, e"<<endl;
    graph.min_span_tree(&node_a);

}

int main(){
    cout << "TEST ADD VERTEX:" <<endl;
    test_add_vertex();
    cout <<endl;
    cout <<endl;
    cout << "TEST ADD EDGE: " <<endl;
    test_add_edge();
    cout <<endl;
    cout <<endl;
    cout << "TEST SHORTEST PATH:" <<endl;
    test_shortest_path();
    cout <<endl;
    cout <<endl;
    cout << "TEST MINIMUM SPANNING TREE: " <<endl;
    test_min_spanning_tree();

    return 0;
}

