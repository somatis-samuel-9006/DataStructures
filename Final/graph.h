#pragma once
#include <vector>
#include <list>
#include "node.h"
using namespace std;

class Graph{
    public:
        Graph();
        void print();
        void add_vertex(Node *new_vertex);
        void shortest_path(Node *source, Node *destination);
        void min_span_tree(Node *source);

    private:
        int size;       //the amount of nodes on the graph
        vector<Node> *nodes_list;
};