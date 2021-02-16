/*
 * =====================================================================================
 *
 *       Filename:  arrayADT.cpp
 *
 *    Description:  Array ADT Implementation 
 *
 *        Version:  1.0
 *        Created:  01/26/2021 10:09:48 PM
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

class ArrayADT::Impl
{
  public:
        int *p;
        int size;
        int length;
        Impl(const int size);
        ~Impl();
};

ArrayADT::ArrayADT(const int size):pimpl(new ArrayADT::Impl(size)){}

ArrayADT::~ArrayADT()
{
    delete pimpl;
    pimpl = nullptr;
}

ArrayADT::Impl::Impl(const int size)
{
    p = new int[size];
    length = 0;
    this->size = size;
}

ArrayADT::Impl::~Impl()
{
    delete []p;
    p = nullptr;
}

//Time Complexity: O(n), n is the length of the array
void ArrayADT::Display()
{
    for(int i=0;i<pimpl->length;i++)
    {
        std::cout<<pimpl->p[i]<<" ";
    }
    std::cout<<std::endl;
}

//Time Comlexity: O(1)
void ArrayADT::Add(const int val)
{
    if(pimpl->length >= pimpl->size)
    {
        throw "Array Overflow";
    }
    else
    {
        pimpl->p[pimpl->length] = val;
        pimpl->length += 1;
    }
}

//Time Complexity: Best O(1) in case it is being added at the last position
//Worst O(n) in case we are adding at the 0th index
void ArrayADT::Insert(const int index, const int val)
{
    if(pimpl->length >= pimpl->size)
    {
        throw "Array Overflow";
    }
    else
    {
        for(int i=pimpl->length;i>index;i--)
        {
            pimpl->p[i] = pimpl->p[i-1];
        }
        pimpl->p[index] = val;
        pimpl->length += 1;
    }
}

//Time Complexity: Best O(1) if we are deleting the last element
//Worst O(n) if we are deleting the 0th element
void ArrayADT::Delete(const int index)
{
    if(index<0)
    {
        throw "Invalid Index";
    }
    else if(pimpl->length == 0)
    {
        throw "Array Emplty/UnderFlow";
    }
    else
    {
        for(int i=index+1;i<pimpl->length;i++)
        {
            pimpl->p[i-1] = pimpl->p[i];
        }
        pimpl->length -= 1;
    }
}

//Time Complexity: Best O(1), if the first element is the value we are looking for
//Worst case O(n), if the element is not present or is the last element
int ArrayADT::LinearSearch(const int val)
{
    for(int i=0;i<pimpl->length;i++)
    {
        if(pimpl->p[i] == val)
        {
            return i;
        }
    }
    return -1;
}

//Time Complexity: Best O(1) if found at height 1
//Worst case O(logn) if found at max depth or not found, here n is the length of the array
int ArrayADT::BinarySearch(int l, int h,const int val)
{
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(pimpl->p[mid] == val)
        {
            return mid;
        }
        else if(pimpl->p[mid] < val)
        {
            l = mid+1;
        }
        else
        {
            h = mid-1;
        }
    }
    return -1;
}

//Time Complexity: O(1) if found at height 1
//Worst case O(logn) if found at max depth or not found, here n is the length of the array
//Extra O(logn) space due to recursion stack if found at max depth
int ArrayADT::RBinarySearch(int l, int h, const int val)
{
    if(l<=h)
    {
        int mid = (l+h)/2;
        if(pimpl->p[mid] == val)
        {
            return mid;
        }
        else if(pimpl->p[mid] < val)
        {
            return ArrayADT::RBinarySearch(mid+1,h,val);
        }
        else
        {
            return ArrayADT::RBinarySearch(l,mid-1,val);
        }
    }
    return -1;
}

//Time Complexity: O(1)
int ArrayADT::getLength() const
{
    return pimpl->length;
}

//Time Complexity: O(1)
int ArrayADT::get(const int index) const
{
    if(index >= 0 && index < pimpl->length)
        return pimpl->p[index];

    return -1;
}


