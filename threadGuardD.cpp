/*
 * =====================================================================================
 *
 *       Filename:  threadGuardD.cpp
 *
 *    Description:  Thread Guard helping to make application thread safe 
 *
 *        Version:  1.0
 *        Created:  02/01/2021 10:22:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<thread>
#include"threadGuard.h"

void foo()
{
    std::cout<<"Hello from Foo!"<<std::endl;
}

void someothertask()
{
    throw std::runtime_error("RE");
}

int main()
{
    std::thread thread1(foo);
    threadGuard guard(thread1);
    try
    {
        someothertask();
    }
    catch(...)
    {

    }
}
