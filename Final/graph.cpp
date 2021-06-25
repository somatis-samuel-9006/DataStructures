#include <iostream>
#include "graph.h"
using namespace std;

//constructor
Graph::Graph(){
    size = 0;
    nodes_list = new vector<Node>[5];   //initialize whatever starting size
}

//adds a pre-created node to the graph
void Graph::add_vertex(Node *new_vertex){
    nodes_list->push_back(*new_vertex);
    size++;
}

//uses BFS to find the shortest path from any two nodes on our unweighted graph
void Graph::shortest_path(Node *source, Node *destination){
    list<Node*> queue;         //store the node values in a queue
    int distances[size];

    for(int i = 0; i < size; ++i){      //initially set all elements in distance and predecesors to be some bad value  
        distances[i] = -1;
    }

    distances[source->value] = 0;       //distance from source to itself
    queue.push_back(source);     //add source to queue

    while(!queue.empty()){      //loop until the queue is empty
        Node *front = queue.front();//.front() returns direct reference to node object, so the Node* declaration requires the use of &
        queue.pop_front();      //capture front in variable then pop it out of the queue
        for(int i = 0; i < front->neighbor_count; ++i){      //loop through neighbors list of source. front = source->value at first
            if(distances[front->neighbors[i]->value] == -1){
                distances[front->neighbors[i]->value] = distances[front->value] + 1;
                queue.push_back(front->neighbors[i]);      //(maybe?) trying to push front which is of type Node * to list of nodes, so we need another *

                if(front->neighbors[i]->value == destination->value){      //we found the destination
                    cout << "shortest path length found: " << distances[front->neighbors[i]->value];
                    return;
                }

            }
        }
    }
}

//uses BFS to create a min spanning tree on our unweighted graph. Starts always at the start node (node_a)
void Graph::min_span_tree(Node *source){        //add source as the parameter ?
    list<Node*> queue;
    string path[size];
    bool visited[size];

    for(int i = 0; i < size; ++i){
        path[i] = "-1";
        visited[i] = false;
    }
    path[0] = source->name;         //first element in the path is first node
    visited[0] = true;
    queue.push_back(source);

    while(!queue.empty()){
        Node *front = queue.front();
        queue.pop_front();
        for(int i = 0; i < front->neighbor_count; ++i){
            if(visited[front->neighbors[i]->value] == false){
                visited[front->neighbors[i]->value] = true;
                path[front->neighbors[i]->value] = front->neighbors[i]->name;
                queue.push_back(front->neighbors[i]);
            }
        }
    }
    //we have now built the path array
    cout << "Minimum Spanning Tree Path:" << endl;
    for(int i = 0; i < size; ++i){
        cout << path[i] << endl;
    }


}
//prints the names and values of each node in the nodes vector
void Graph::print(){
    for(auto it = nodes_list->begin(); it != nodes_list->end(); it++){      //in each iteration, it points to an element, which are nodes, until it reaches the end of the vector
        cout << it->name << ":" << it->value << endl;
    }
}
