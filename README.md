# FloodFill
Flood Fill algorithim for bidimensional arrays in C++

A very simple algorithim for simulate a flood fill in a matrix in C++ using BFS. 
The size is defined in lines 5 and 6.
The matrix is loaded from a file.

Example:

R R R R R R G G G G
B G G G R R R R R R
G R R R R R R R R R
B R G G G G G R B B
B R G G B G G R B B
B R R R R R R R G B
B B B B B B B B B B
B B B B B G G B B B
R R R R R R R R R R
R B R B R B R B R B

When we start painting from 1x1 (it starts in 0) with the letter B:

R R R R R R G G G G
B B B B R R R R R R
G R R R R R R R R R
B R G G G G G R B B
B R G G B G G R B B
B R R R R R R R G B
B B B B B B B B B B
B B B B B G G B B B
R R R R R R R R R R
R B R B R B R B R B
