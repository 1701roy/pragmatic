/*
 * =====================================================================================
 *
 *       Filename:  fibonacciDPBottomUp.cpp
 *
 *    Description:  Program to print the value in Fibonacci series at nth position
 *
 *        Version:  1.0
 *        Created:  01/25/2021 09:50:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

//Time Complexity: O(n), as the loop will execute n-2 times
//Space Complexity: O(n), as we will be storing the subproblem results in the array of size n+1

#include<iostream>

int fib(int n)
{
    int memo[n+1] = {0};
    memo[0]=0;
    memo[1]=1;
    for(int i=2;i<=n;i++)
    {
        memo[i] = memo[i-1]+memo[i-2];
    }
    return memo[n];
}

int main()
{
    std::cout<<fib(5);
    return 0;
}
