/*
 * =====================================================================================
 *
 *       Filename:  fibonacci.cpp
 *
 *    Description:  Program to print Fibonacci series element at position n 
 *
 *        Version:  1.0
 *        Created:  01/25/2021 07:57:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

//Time Complexity: O(2^n) which will for the upper bound, by taking the assumption that each call will make 2 subsequent calls
//Space Complexity: O(n), since activation records were being creared and destroyed, total n+1 activation records will be created, where n is also the height of the tree

#include<iostream>

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fib(n-2)+fib(n-1);
}

int main()
{
    std::cout<<fib(6);
    return 0;
}
