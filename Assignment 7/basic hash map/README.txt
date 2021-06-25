This is the implementation of the simple not-so-smart hashtable that solves collisions via overwriting. It is the code that we did in lab. The way
this implementation hashes values is by first adding together the ascii value of each character in the key subtract the value for 'a'. This sum is
then modulo'd with the capacity of our bucket array, which we have set to 10.