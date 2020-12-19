# Floyd_Warshall_Parallel_Serial
Floyd-Warshall Algorithm is an algorithm for finding the shortest path between
all the pairs of vertices in a weighted graph. A single execution of the algorithm
will find the lengths (summed weights) of shortest paths between all pairs of
vertices. This algorithm follows the dynamic programming approach to find the
shortest paths.
Overall .zip file consist of three programs. First code is based on sequential
logic which complete serial program implemented in order to understand how
Floyd’s algorithm works. In second code is based on parallel programming. It
has openMp library which is dedicated to convert serial ”for” loops into parallel.

# Testing OpenMP Code:
My approach towards testing: 1) I write down program for sequential floyds
algorithm and test with two different input matrix which is given in problem
statement. 2) Further i add parallel library open-Mp and made node size vari-
able so that user can test code with different node sizes. I randomized process
of input matrix generation which ranges from 0-19 so in total 20 count. I have
added conditional statement’s such as remove 0 and enter infinity. and test
code for multiple threads. 3) Added time to calculate time required to calculate
different number of threads. 4)I added one more for loop in order to change
thread numbers.
