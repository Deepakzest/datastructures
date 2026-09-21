#include <iostream>
using namespace std;

int findCatalan(int n)
{

    // Base case
    if (n <= 1)
        return 1;

    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    int res = 0;
    for (int i = 0; i < n; i++)
        res += findCatalan(i) * findCatalan(n - i - 1);

    return res;
}

int main()
{
    int n = 3;
    int res = findCatalan(n);
    cout << res;
    return 0;
}
/*
Given a number n, the task is to find the nth Catalan number.  Catalan Number for n is equal to the number of expressions containing n pairs of parenthesis that are correctly matched, i.e., for each of the n(' there exist n ')' on there right and vice versa. The first few Catalan numbers for n = 0, 1, 2, 3, 4, 5… are: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ...  so on.

Examples:

Input: n = 3
Output: 5
Explanation: For n = 3, there are 5 valid combinations of balanced parentheses:  ((())), (()()), (())(), ()(()), ()()()

Input: n = 4
Output: 14
Explanation: For n = 4, there are 14 distinct valid combinations of balanced parentheses that can be formed
*/
