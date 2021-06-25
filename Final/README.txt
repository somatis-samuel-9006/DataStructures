OVERVIEW:
This is my implementation of the graph class for the final. It uses a node class to store all information related to each node on the graph. The 
graph class contains a vector that stores all the nodes. This graph is unweighted and assumes that every new node created with have a value
that is 1 greater than the previous value (the first node is assigned a value of 0). The following diagram is a visual of the graph that I created
for testing purposes in the main file.

TESTING GRAPH:
               a/0     c/2
                |    /  |
                |   /   |
                |  /    |
                b/1 -- d/3 ------- e/4

COMPLEXITY ANALYSIS:

function	    |	complexity
---------------------------------
add_vertex  	   O(1)
add_edge	   O(1)
print		   O(V)  -	V=vertices
shortest_path	   O(V^2) -worst case
min_span_tree	   O(v^2) -worst case