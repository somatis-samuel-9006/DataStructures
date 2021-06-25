#pragma once
#define MAX_NEIGHBORS 10
#include <string>
using namespace std;

class Node{
    public:
        string name;
        int value;
        int neighbor_count;
        Node *neighbors[MAX_NEIGHBORS];
        Node();
        Node(string new_name, int new_value);       //function to add vertex
        void add_edge(Node *destination);

};