PROPERTIES:
My bag of marbles will be an array of chars, each char will represent one marble. An int variable will be used to keep track of how many marbles
are in the bag. There will be a function that adds a marble by filling the next empty index of the array with the marble char ('M'). There will also
be a function that removes the marble that was last placed into the bag. There will also be a function that prints out how many marbles are in
the bag and one that prints out a visual depiction of the array.

TESTING:
Some of the tests that will be run on the bag are:
- Attempting to remove a marble when the bag has 0 capacity, which will print a appropriate exception.
- Attempting to add a marble when there are no more available spots in the array, which will print an appropriate exception.
- Repeatedly calling the add and remove marble functions, and calling the amount printing function between each call of these two functions.