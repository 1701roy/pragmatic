/*
 * =====================================================================================
 *
 *       Filename:  llist.cpp
 *
 *    Description:  Linked List Class 
 *
 *        Version:  1.0
 *        Created:  02/24/2021 11:20:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>

class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{
    public:
    Node *first;
    LinkedList();
    void Display();
    void RDisplay(Node *p);
};

LinkedList::LinkedList()
{
    first = new Node;
    first->data = 0;
    first->next = nullptr;
}

//Time Complexity: O(n), where n is the length of the linked list
void LinkedList::Display()
{
    Node *p = first;
    while(p!=nullptr)
    {
        std::cout<<p->data<<" ";
        p = p->next; 
    }
    std::cout<<std::endl;
}
//Time Complexity: O(n), where n is the length of the linked list
//Space Complexity: O(n), n+1 activation records will be created in the stack
void LinkedList::RDisplay(Node *p)
{
    if(p!=nullptr)
    {
        std::cout<<p->data<<" ";
        RDisplay(p->next);
    }
}

int main()
{
    LinkedList a;
    a.RDisplay(a.first);
    std::cout<<std::endl;
    return 0;
}

