/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Entry point for programs
 *
 *        Version:  1.0
 *        Created:  02/15/2021 11:04:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include "arrayADT.h"

int main()
{
    ArrayADT a(5);
    a.Add(1);
    a.Add(10);
    a.Add(7);
    std::cout<<a.get(1)<<std::endl;
    a.reverse();
    a.Display();

    return 0;
}
