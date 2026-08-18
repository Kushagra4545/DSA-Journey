/*
Given an permutation array consisting value from 1 to N. 
2 types of operations can be performed on the array, 

1. Swap any 2 elements at different index
2. Rotate Left

2nd operation can be used only once. 

Find the minimum operations to sort the array


Example 
arr = [3, 1, 2]
ans = 1

Explanation - rotate left once 

arr = [5, 3, 2, 1, 4]
ans = 2

Explanation - 
1. Rotate left -> arr becomes [3, 2, 1, 4, 5]
2. Swap 1 and 3 -> arr = [1, 2, 3, 4, 5]
*/

