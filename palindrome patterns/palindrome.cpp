class Solution {
public:
    bool isPalindrome(string s) {
         string result1 = "";
        for(char c : s) {
            if(isalnum(c))
                result1 +=tolower(c);
        }
        int left=0;
        int right=result1.size()-1;
        while(left<right)
        {
            if(result1[left]==result1[right])
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/
