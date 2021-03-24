TIME COMPLEXITY CHART:

					function	      	Complexity (big O)
					-----------------------------------------
					get_length    	O(1)
					get_head	     	O(1)
					get_tail		O(1)

					add		O(n)
					remove		O(n)
					search		O(n)
					print		O(n)

OVERVIEW:
For the first three functions, seeing as they only return one variable each, and no iteration or anything else like that is needed for them to do
their jobs, they run in O(1) time. Add, remove, search, and print are all very similar. Each one involves iteration through the linked list with a
while loop until a specific goal is accomplished. Due to the nature of these functions, their runtime in O(n), as the time it takes for them to due
their jobs will very based on how much data is stored in the structure.

