/*
 * =====================================================================================
 *
 *       Filename:  threadJoin.cpp
 *
 *    Description:  Joinable function to check if a thread is joinable 
 *
 *        Version:  1.0
 *        Created:  02/01/2021 08:19:19 PM
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

void foo()
{
    std::cout<<"Hello from Foo!"<<std::endl;
}

int main()
{
    std::thread thread1(foo);

    if(thread1.joinable())
    {
        std::cout<<"Thread1 is joinable"<<std::endl;
    }
    else
    {
        std::cout<<"Thread1 is not joinable"<<std::endl;
    }

    thread1.join();//Once the thread is joined, it becomes unjoinable.


    if(thread1.joinable())
    {
        std::cout<<"Thread1 is joinable"<<std::endl;
    }
    else
    {
        std::cout<<"Thread1 is not joinable"<<std::endl;
    }
}
