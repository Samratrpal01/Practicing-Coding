476. Number Complement
Solved
Easy
Topics
Companies
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

1 <= num < 231
 

Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/



Code: 
public class Solution {
    public int FindComplement(int num) {
        int temp=num;
        int mask=0;
      //we need to find mask to make sure our number show result result more than mask like for 5 mask will be 7 i.e 111 binary of 5 is 101 ~5 is 111010 and mask 7 than result of ~5 & 7 is 2. i.e 010
        while(temp!=0)
        {
            mask=(mask<<1) | 1;
           Console.WriteLine(mask);
            temp=temp>>1;
        }

        return ~num & mask;
    }
}
