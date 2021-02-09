/*
 * =====================================================================================
 *
 *       Filename:  launchThread.cpp
 *
 *    Description:  Launch a thread 
 *
 *        Version:  1.0
 *        Created:  01/31/2021 12:49:43 PM
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
    std::cout<<"Hello from Foo!"<<" id-"<<std::this_thread::get_id()<<std::endl;
}

class callable_class
{
    public:
        void operator()()
        {
            std::cout<<"Hello from Callable_Class!"<<" id-"<<std::this_thread::get_id()<<std::endl;
        }
};

int main()
{
    std::thread thread1(foo);  //The thread class constrcutor needs a callable object
    //In this example a function
    
    callable_class obj;
    std::thread thread2(obj); //A callable class

    std::thread thread3([] 
    {
        std::cout<<"Hello from lambda!"<<" id-"<<std::this_thread::get_id()<<std::endl;    
    }); //A lambda expression
    
    thread1.join(); //Join is required to tell the main to wait for the thread to execute 
    thread2.join();
    thread3.join();

    std::cout<<"Hello from Main!"<<std::endl;
    return 0;
}
