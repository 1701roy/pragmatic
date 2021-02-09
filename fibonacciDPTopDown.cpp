/*
 * =====================================================================================
 *
 *       Filename:  fibonacciDPTopDown.cpp
 *
 *    Description:  Program to print the element at the nth postion in the Fibonacci Series 
 *
 *        Version:  1.0
 *        Created:  01/25/2021 10:13:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

//Time Complexity: O(n), since the fib function will be called recursively n times
//Space Complexity: O(2n), since array of size n+1 and n+1 activation records 

#include<iostream>

int fib(int n,int x[])
{
    if(n<=1)
    {
        return n;
    }
    if(x[n]!=0)
    {
        return x[n];
    }
    else
    {
        x[n] = fib(n-1,x)+fib(n-2,x);
        return x[n];
    }
}

int main()
{
    int n = 5;
    int memo[n+1] = {0};
    std::cout<<fib(n, memo);
    return 0;
}
