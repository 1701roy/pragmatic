/*
 * =====================================================================================
 *
 *       Filename:  desc.cpp
 *
 *    Description:  Program to print n natural numbers in descending order 
 *
 *        Version:  1.0
 *        Created:  01/25/2021 07:09:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

//Time Complexity: O(n) where n=num
//Space Complexity: O(n+1) where n=num as an extra activation record will be created in stack for num=0

#include<iostream>

void desc(int num)
{
    if(num>0)
    {
        std::cout<<num<<" ";
        desc(num-1);
    }
}


int main()
{
    desc(5);
    return 0;
}
