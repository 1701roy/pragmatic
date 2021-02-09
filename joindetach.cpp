/*
 * =====================================================================================
 *
 *       Filename:  joindetach.cpp
 *
 *    Description:  Join vs Detach thread 
 *
 *        Version:  1.0
 *        Created:  02/01/2021 08:38:03 PM
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
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout<<"Hello from Foo!"<<std::endl;
}

void bar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout<<"Hello from Bar!"<<std::endl;
}

int main()
{
    std::thread thread1(foo);
    std::thread thread2(bar);

    thread2.detach();
    std::cout<<"Bar has detached"<<std::endl;

    thread1.join();
    std::cout<<"Foo has joined"<<std::endl;
    return 0;
}
