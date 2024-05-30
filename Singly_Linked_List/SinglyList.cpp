#include<iostream>
#include<cstdlib>
using namespace std;


// define a custom exception class item_not_found_error
class item_not_found_error : public runtime_error
{
    public:
        item_not_found_error(const string &msg):runtime_error(msg)
        {

        }
};

// Define a node structure
template <class X>
struct node
{
    X item;
    node *next;
};

// Define a class SLL to implement singly linked list data structure with member variable start pointer of type node.
template <class X>
class SLL
{
    private:
        node<X> *start;

    public:
        SLL();
        void push_front(X);
        void push_back(X);
        void insert_after(node<X> *,X);
        node<X>* find(X);
        void pop_front();
        void pop_back();
        void delete_node(node<X> *);
        void delete_item(X);
        ~SLL();

        void show_list();
};

// Define a constructor to initialize start pointer with NULL.
template<class X>SLL<X>::SLL()
{
    start = NULL;
}

// Define a method to insert a data into the list at the beginning.
template<class X>void SLL<X>::push_front(X data)
{
    node<X> *temp = new node<X>();
    temp->item = data;
    temp->next = start;

    start = temp;
}

// Define a method to insert a data into the list at the end.
template<class X>void SLL<X>::push_back(X data)
{
    node<X> *temp = new node<X>();
    temp->item = data;
    temp->next = NULL;

    if(start == NULL)
    {
        start = temp;  
    }
    else
    {
        node<X> *flag = start;
        
        while(flag->next != NULL)
        {
            flag = flag->next;
        }
        flag->next = temp;
    }
}

// Define a method to insert a data into the list after the specified node of the list.
template<class X>void SLL<X>::insert_after(node<X> *n,X data)
{
    node<X> *temp = new node<X>();
    temp->item = data;
    temp->next = n->next;

    n->next = temp;
}

// Define a method to search a node with the given item.
template<class X>node<X>* SLL<X>::find(X data)
{
    node<X> *flag = start;

    while(flag != NULL)
    {
        if(flag->item == data)
        {
            return flag;
        }
        flag = flag->next;
    }
    throw item_not_found_error("Item not found exception");
}

// Define a method to delete first node from the list.
template<class X>void SLL<X>::pop_front()
{
    node<X> *flag = start;
    
    if(flag != NULL)
    {
        start = flag->next;
        delete flag;
    }
    
}

// Define a method to delete last node from the list.
template<class X>void SLL<X>::pop_back()
{
    node<X> * flag = start;
    if(flag != NULL)
    {
        if(flag->next == NULL)
        {
            start = NULL;
            delete flag;
        }
        else
        {
            while(flag->next->next != NULL)
            {
                flag = flag->next;
            }
            delete flag->next;
            flag->next = NULL;
        }
    }
}

// Define a method to delete a specific node.
template<class X>void SLL<X>::delete_node(node<X> *n)
{
    if(start == n && n->next == NULL)
    {
        start = NULL;
        delete n;

    }
    else if(start == n && n->next != NULL)
    {
        start = n->next;
        delete n;
    }
    else
    {
        node<X> *flag = start;

        while(flag->next != n)
        {
            flag = flag->next;
        }
        flag->next = n->next;
        delete n;
    }
}

// Define a method to delete a specific item.
template<class X>void SLL<X>::delete_item(X data)
{
    node<X> *n = find(data);

    if(start == n && n->next == NULL)
    {
        start = NULL;
        delete n;

    }
    else if(start == n && n->next != NULL)
    {
        start = n->next;
        delete n;
    }
    else
    {
        node<X> *flag = start;

        while(flag->next != n)
        {
            flag = flag->next;
        }
        flag->next = n->next;
        delete n;
    }
}

// Define a destructor to deallocates memory for all the nodes in the linked list.
template<class X>SLL<X>::~SLL()
{
    while(start != NULL)
    {
        pop_front();
    }
}

// Define a method to show the linked list.
template<class X>void SLL<X>::show_list()
{
    node<X> *flag = start;

    while(flag != NULL)
    {
        cout<<flag->item<<" ";
        flag = flag->next;
    }
}
