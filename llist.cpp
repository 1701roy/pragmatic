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
#include<limits>

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
    int max();
    int Rmax(Node *p);
    Node* search(const int val);
    Node* Rsearch(Node *p, const int val);
    void Insert(const int pos, const int val);
    void append(const int val);
    void insertSorted(const int val);
    void Delete(const int pos);
    bool isSorted();
    void deleteDuplicates();
};

LinkedList::LinkedList()
{
    first = nullptr;
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

//Time Complexity: O(n), where n is the number of elements in the list
int LinkedList::max()
{
    int max = std::numeric_limits<int>::min(); 
    Node *p = first;
    while(p!=nullptr)
    {
        max = p->data > max ? p->data : max;
        p = p->next;
    }
    return max;
}

//Time Complexity: O(n), where n is the numner of elements in the list
//Space Complexity: O(n), as there will be n+1 activation records
int LinkedList::Rmax(Node *p)
{
    if(p==nullptr)
    {
        return std::numeric_limits<int>::min();
    }
    else
    {
        int x = 0;
        x = Rmax(p->next);
        return x > p->data ? x : p->data;
    }
}

//Time Complexity: Best O(1), if the head element itself is the searched value
//                 Worst O(n), if the value is not present or the last element
Node* LinkedList::search(const int val)
{
    Node *p = first;
    while(p!=nullptr)
    {
        if(p->data == val)
        {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

//Time Complexity: Best O(1), if the head element itself is the searched value
//                 Worst O(n), if the value is not present or the last element
//Space Complexity: Worst O(n), if the value is not preesnt or the last element
Node* LinkedList::Rsearch(Node *p,const int val)
{
    if(p==nullptr)
        return nullptr;

    return p->data==val ? p : Rsearch(p->next, val);
}

//Time Complexity: Best O(1), adding at 0th position
//                 Worst O(n), adding at the last element position
void LinkedList::Insert(const int pos, const int val)
{
    Node *p = first;
    for(int i=0;i<pos-1 && p;i++)
    {
        p = p->next;
    }
    if(p)
    {
        Node *t = new Node;
        t->data = val;
        if(pos == 0)
        {
            t->next = p;
            first = t;
        }
        else
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

//Time Complexity: Best O(1), if it is the head element
//                 Worst O(n), to get length and move n-1 positions
void LinkedList::append(const int val)
{
    Node *t = new Node;
    t->data = val;
    t->next = nullptr;

    if(first==nullptr)
    {
        first = t;
    }
    else
    {
        Node *p = first;
        int n = getLength();
        for(int i=0;i<n-1;i++)
        {
            p = p->next;
        }
        p->next = t;
    }
}

//Time Complexity: Best O(1), if inserting at the first node
//                 Worst O(n), if inserting at the last node
void LinkedList::insertSorted(const int val)
{
    Node *p = first;
    Node *q = nullptr;

    while(p && p->data < val)
    {
        q=p;
        p=p->next;
    }
    Node *t = new Node;
    t->data = val;
    t->next = q->next;
    q->next = t;
}

//Time Complexity: Best O(1),if deleting the first element
//                 Worst O(n), if deleting the last element 
void LinkedList::Delete(const int pos)
{
    Node *p = first;
    Node *q = nullptr;

    for(int i=0;i<pos && p;i++)
    {
        q=p;
        p=p->next;
    }
    if(p)
    {
        if(pos==0)
        {
            first = first->next;
            delete p;
        }
        else
        {
            q->next = p->next;
            delete p;
        }
    }
}

//Time Complexity: Best O(1), if the first 2 elements are not in order
//                 Worst O(n), if all sorted or last element is not sorted
bool LinkedList::isSorted()
{
    int x = std::numeric_limits<int>::min();

    Node *p = first;
    while(p!=nullptr)
    {
        if(p->data < x)
            return false;

        x = p->data;
        p = p->next;
    }

    return true;
}

//Time Complexity: O(n), where n is the lenght of the LL
void LinkedList::deleteDuplicates()
{
    //Needs a sorted LL
    Node *p = first;
    Node *q = first->next;

    while(q!=nullptr)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    int *a;
    int arr[10] = {1,2,3,4,5,5,5,8,9,10};
    a = arr;
    LinkedList lst(a,10);
    lst.Display();
    lst.deleteDuplicates();
    lst.Display();
    return 0;
}

