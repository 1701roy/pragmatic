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
    LinkedList(int *p, int n);
    int getLength();
    int RgetLength(Node *p);
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
    return;
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
    return;
}

//Time Complexity: O(n), where n is the size of the array
LinkedList::LinkedList(int *p, int n)
{
    Node *q, *last;
    first = new Node;
    first->data = p[0];
    first->next = nullptr;
    last = first;

    for(int i=1;i<n;i++)
    {
        q = new Node;
        q->data = p[i];
        q->next = nullptr;
        last->next = q;
        last = q;
    }
    return;
}

//Time Complexity: O(n), where n is the number of nodes/length in the LL
int LinkedList::getLength()
{
    int length = 0;
    Node *p = first;
    while(p!=nullptr)
    {
        length += 1;
        p = p->next;
    }

    return length;
}

//Time Complexity: O(n), where n is the length of the list
//Space Complexity: O(n), n+1 activation records
int LinkedList::RgetLength(Node *p)
{
    if(p==nullptr)
    {
        return 0; 
    }
    else
    {
        return RgetLength(p->next) + 1;
    }
}

int main()
{
    int *a;
    int arr[10] = {1,2,3,4};
    a = arr;
    LinkedList lst(a,10);
    lst.Display();
    std::cout<<std::endl;
    std::cout<<lst.getLength()<<std::endl;
    return 0;
}

