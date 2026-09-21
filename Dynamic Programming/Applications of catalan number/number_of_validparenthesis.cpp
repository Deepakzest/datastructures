#include <iostream>
using namespace std;

// Recursive function to count the valid ways
int countValid(int n,unordered_map<int,int>&memory) {
   if(n==0||n==1)
   {
     return 1;
   }
  int curr=n;
  if(memory.find(curr)!=memory.end())
  {
    return memory[curr];
  }
  int catlan=0;
  for(int i=0;i<n;i++)
  {
    catlan+=countValid(i,memory)*countValid(n-1-i,memory);
  }
  memory[curr]=catlan;
  return memory[curr];
}

// Function to count valid parentheses
// arrangements of length n
int findWays(int n) {
    
    // If n is odd, no valid arrangements possible
    if (n % 2 == 1)
        return 0;
  	unordered_map<int,int>memory;
    return countValid(n / 2, memory);
}

int main() {
    int n = 6;
    int res = findWays(n);
    cout << res << endl;
    return 0;
}

/*
Given an integer n, find the number of valid parentheses expressions of length n.

Examples : 

Input: n = 2
Output: 1 
Explanation: There is only one possible valid expression of length 2, "()"

Input: n = 4
Output: 2 
Explanation: Possible valid expression of length 4 are "(())" and "()()" 

Input: n = 6
Output: 5
Explanation: Possible valid expressions are "((()))", "()(())", "()()()", "(())()" and "(()())"
*/
