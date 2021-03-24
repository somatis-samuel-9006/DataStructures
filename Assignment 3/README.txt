TIME COMPLEXITY ANALYSIS:

push():
Because this function only creates a new node and adjusts some pointers accordingly, it operates in O(1) time.

pop():
Because this function also works with one piece of data and adjusts pointers accordingly, it operates in O(1) time.

peek():
This function only returns the value of the node pointed to by head, so the size of the queue doesn't matter. It therefore operates in O(1) time.

print_queue():
This functions accesses each node via one while loop. Therefore the time it takes depends on the size of the queue when the function is called.
This function operates in O(n) time.