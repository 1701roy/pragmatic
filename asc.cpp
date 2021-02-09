/*
 * =====================================================================================
 *
 *       Filename:  asc.cpp
 *
 *    Description:  Program to print all n natural numbers in ascending order
 *
 *        Version:  1.0
 *        Created:  01/25/2021 06:59:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

//Time Complexity: O(n) where n=num
//Space Complexity: O(n+1) where n=num as an extra activation record will be created in the Stack for n=0

#include<iostream>

void ascPrint(int num)
{
    if(num>0)
    {
        ascPrint(num-1);
        std::cout<<num<<" ";
    }
}

int main()
{
    ascPrint(5);
    return 0;
}

