/*
 * =====================================================================================
 *
 *       Filename:  ship.cpp
 *
 *    Description:  Concurrent ship operations 
 *
 *        Version:  1.0
 *        Created:  02/08/2021 10:05:07 PM
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

void clean()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout<<"Cleaning"<<std::endl;
}

void fullSpeed()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout<<"Full Speed Ahead"<<std::endl;
}

void stop()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout<<"Stopping"<<std::endl;
}

int main()
{
    int input;
    bool flag = 1;
    while(flag)
    {
        std::cin>>input;
        if(input==1)
        {
            std::thread t1(clean);
            t1.detach();
        }
        else if(input==2)
        {
            std::thread t2(fullSpeed);
            t2.join();
        }
        else if(input==3)
        {
            std::thread t3(stop);
            t3.join();
        }   
        else if(input==100)
        {
            flag = 0;
        }
        else
        {
            std::cout<<"Invalid Input"<<std::endl;
        }
    }
    return 0;
}
