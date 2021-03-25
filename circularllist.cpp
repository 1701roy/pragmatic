/*Circular LL Implementation */

#include<iostream>
#include<limits>

class Node
{
    public:
        int data;
        Node *next;
};

class CircularLList
{
    public:
        Node *head;
        CircularLList();
        void Display();
        void RDisplay(Node *p);
};

CircularLList::CircularLList()
{
    Node *p = new Node;
    head = p;
    p->data = 0;
    p->next = p;
}

//Time Complexity: O(n), where n is the length of the non repeating list
//Space Complexity: O(1)
void CircularLList::Display()
{
    Node *p = head;
    do
    {
        std::cout<<p->data<<std::endl;
        p = p->next;
    }while(p!=head);
}

//Time Complexity: O(n), where n is the length of the non repeating list
//Space Complexity: o(n), as n+1 activation records will be created
void CircularLList::RDisplay(Node *p)
{
    static int flag = 0;
    if(p!= head || flag == 0)
    {
        flag = 1;
        std::cout<<p->data<<std::endl;
        RDisplay(p->next);
    }
    flag = 0;
}

int main()
{
    CircularLList lst;
    lst.Display();
    lst.RDisplay(lst.head);
    return 0;
}
