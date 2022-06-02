# 42Seoul_push_swap
[![yongmiki's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl3x3n267003009mk7325wwen/project/2508195)](https://github.com/JaeSeoKim/badge42)

To write a sorting algorithm is always a very important step in a coder’s life, because it
is often the first encounter with the concept of complexity.
Sorting algorithms, and their complexities are part of the classic questions discussed
during job interviews. It’s probably a good time to look at these concepts because you’ll
have to face them at one point.
The learning objectives of this project are rigor, use of C and use of basic algorithms.
Especially looking at the complexity of these basic algorithms.
Sorting values is simple. To sort them the fastest way possible is less simple, especially
because from one integers configuration to another, the most efficient sorting algorithm
can differ.

## Usage
```bash
$>make
$>./push_swap 4 3 2 1
rra
pb
sa
rra
pa
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```
