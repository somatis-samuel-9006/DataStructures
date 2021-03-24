CHART:

Function		Complexity
----------------------------------
add		O(n)
Remove		O(n) * O(n) = O(n^2)
find_min		O(n)
traversals	O(n)
insert		O(1)
remove		O(1)
print_traversals	O(1)

OVERVIEW:
Overall, the functions run in the expected time complexity for the binary search tree data structure, a structure where the amount of data can
affect the runtime. The one exception to this is my Remove function, which makes use of a find_min utility function. The Remove function it-
self is O(n), but so is find_min, making the total time complexity O(n^2).

COMPARISON:
It seems to be the case that adding, searching, and removing in general have similar time complexities for binary trees and binary search trees.
This makes sense as the two structures are very similar. In general, these three operations run in O(n) time for both binary trees and binary
search trees. However, one slight difference is that in the case of BST's, we sometimes refer to the time complexity of these three operations
as O(h), where h is the height of the tree.