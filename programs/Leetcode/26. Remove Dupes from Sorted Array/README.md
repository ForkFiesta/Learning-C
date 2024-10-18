## Work on Example

Input: `nums = [1, 1, 2]`
Output: `2, nums = [1,2,_]`
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Writing down Algo:

1. Create int repeat_num;
2. Loop through list, labeling items i, counting from i=0, to numsSize exclusive.
   -
   - Conditions:
     - if i > 0 && previous == current:
       - assign nums[i] to repeat_num;
       - assign `_` to nums[i];

Iteration 1:
when i[1]:
i[1] = 0
i[0] = 0
repeat*num = i[0];
i[i] = '*'
nums = [0,_,1,1,1,2,2,3,3,4]

Iteration 2:
when i[3]:
i[3] = 1
i[2] = 1;
