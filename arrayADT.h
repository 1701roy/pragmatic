/*
 * =====================================================================================
 *
 *       Filename:  arrayADT.h
 *
 *    Description:  API for ArrayADT 
 *
 *        Version:  1.0
 *        Created:  01/30/2021 04:18:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __ArrayADT_H_INCLUDED__
#define __ArrayADT_H_INCLUDED__

class ArrayADT
{
    private:
        class Impl;
        Impl *pimpl;

    public:
        explicit ArrayADT(const int size);
        ~ArrayADT();
        void Display();
        void Add(const int val);
        void Insert(const int index,const int val);
        void Delete(const int index);
        int LinearSearch(const int val);
        int BinarySearch(int l,int h,const int val);
        int RBinarySearch(int l,int h, const int val);
        int getLength() const;
        int get(const int index) const;
};

#endif

