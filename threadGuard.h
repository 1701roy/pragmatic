/*
 * =====================================================================================
 *
 *       Filename:  threadGuard.h
 *
 *    Description:  Thread Guard Class
 *
 *        Version:  1.0
 *        Created:  02/01/2021 09:01:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __THREADGUARD_H_INCLUDED__
#define __THREADGUARD_H_INCLUDED__

class threadGuard
{
    private:
        std::thread &t;
    public:
        explicit threadGuard(std::thread & _t):t(_t){}
        ~threadGuard()
        {
            std::cout<<"Destrcutor called"<<std::endl;
            if(t.joinable())
            {
                t.join();
            }
        }

        threadGuard(const threadGuard &) = delete;
        const threadGuard & operator= (const threadGuard &) = delete;
};


