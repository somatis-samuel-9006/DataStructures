#include <iostream>
#include "node.h"

using namespace std;

//default constructor
Node::Node(){
    name = "undefined";
    value = -1;
    neighbor_count = 0;
}

//constructor with values
Node::Node(string new_name, int new_value){
    name = new_name;
    value = new_value;
    neighbor_count = 0;
}

//adds an edge from the node this function is called on to the node passed to this function
void Node::add_edge(Node *destination){
    if(neighbor_count < MAX_NEIGHBORS){     //not at max neighbor capacity
        neighbors[neighbor_count] = destination;
        neighbor_count++;
    }
    else{
        cout << "This node has already reached max neighbor capacity" << endl;
    }
}
