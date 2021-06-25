This is the smarter hash table implementation. We are still using strings as our data type and we still hash values the same way, which is adding
together the differences between the ascii value of each letter in the string and the value of 'a'. This sum is then modulo'd with our capacity,
which is still 10. Instead of overwritting, this smarter hash table uses chaining to handle collisions.

Complexity Chart:
					Function		Complexity
					hash_table()	O(1)
					get_bucket_	O(1)
					value(),get_
					load(),&get_
					size()
					add()		O(1)-Avg. O(n)-Worst
					remove()		O(1)-Avg. O(n)-Worst
					Search()		O(1)-Avg. O(n)-Worst
					print()		O(n^2)

COMPARISON DISCUSSION:
In this particular hash table, there is likely to be a very high frequency of collisions, given that there are only 10 buckets and any string can be
passed as a key to the hash function. Even with a larger list, the likelihood of collisions is usually still significant, unless the hash function is 
designed to make sure collisions are as infrequent as possible. With a chaining implementation to handle collisions, the add and search functions 
still run in an average of O(1) time, but they can run in a worst case of O(n) if the linked list at a particular index becomes very long. Some 
downsides to this implementation is that some space is wasted, as some linked lists might not get used, and the cache performance of a chain
implementation is not as good as a linear probe implementation.