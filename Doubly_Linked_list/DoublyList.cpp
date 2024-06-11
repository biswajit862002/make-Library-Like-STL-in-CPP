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
 
class empty_list_error : public runtime_error
{
    public:
        empty_list_error(const string &msg):runtime_error(msg)
        {

        }
};

// Define a node structure
template<class X>
struct node
{
    node *prev;
    X item;
    node *next;
};


// Define a class DLL to implement doubly linked list data structure.
template<class X>
class DLL
{
    private:
        node<X> *start;

    public:
        DLL();
        void push_front(X);
        void push_back(X);
        node<X>* find(X);
        void insert_after(node<X> *,X);
        void insert_after(X,X);
        X pop_front();
        X pop_back();
        X delete_node(node<X> *);
        X delete_item(X);
        void show_list();
        ~DLL();
};


// Define a constructor to initialize start pointer with NULL.
template<class X>DLL<X>::DLL()
{
    start = NULL;
}

// Define a method to insert a data into the list at the beginning.
template<class X>void DLL<X>::push_front(X data)
{
    node<X> *temp = new node<X>(); 
    temp->prev = NULL;
    temp->item = data;
    temp->next = start;
    if(start != NULL)
        start->prev = temp;
    start = temp;
}

// Define a method to insert a data into the list at the end.
template<class X>void DLL<X>::push_back(X data)
{
    node<X> *temp = new node<X>(); 
    temp->item = data;
    temp->next = NULL;

    if(start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        node<X> *flag = start;

        while(flag->next != NULL)
        {
            flag = flag->next;
        }
        temp->prev = flag;
        flag->next = temp;
    }
}

// Define a method to search a node with the given item.
template<class X>node<X>* DLL<X>::find(X data)
{
    node<X> * flag= start;

    while(flag != NULL)
    {
        if(flag->item == data)
        {
            return flag;
        }
        flag = flag->next;
    }
    throw item_not_found_error("Search item not found exception");
}

// Define a method to insert a data into the list after the specific node.
template<class X>void DLL<X>::insert_after(node<X> *n,X data)
{
    node<X> *temp = new node<X>();
    temp->prev = n;
    temp->item = data; 
    temp->next = n->next;
    if(n->next != NULL)
        n->next->prev = temp;
    n->next = temp;
}

// Define a method to insert a data into the list after the specific item.
template<class X>void DLL<X>::insert_after(X searchData,X data)
{
    node<X> *n = find(searchData);

    node<X> *temp = new node<X>();
    temp->prev = n;
    temp->item = data;
    temp->next = n->next;
    if(n->next != NULL)
        n->next->prev = temp; 
    n->next = temp;
}

// Define a method to delete first node from the list.
template<class X>X DLL<X>::pop_front()
{
    node<X> * flag = start;
    X item; // return the poped item;

    if(start != NULL)
    {
        if(start->next == NULL)
        {
            start = NULL;
            item = flag->item;
            delete flag;
            return item;
        }
        else
        {
            start->next->prev = NULL;
            start = start->next; 
            item = flag->item;
            delete flag;
            return item;
        }
    }
    throw empty_list_error("Empty list exception");
}

// Define a method to delete last node of the list.
template<class X>X DLL<X>::pop_back()
{
   node<X> * flag = start;
   X item; // return the poped item;

   if(flag != NULL)
   {
        if(flag->next == NULL)
        {
            start = NULL;
            item = flag->item;
            delete flag;
            return item;
        }
        else
        {
            while(flag->next != NULL)
            {
                flag = flag->next;
            }
            flag->prev->next = NULL;
            item = flag->item;
            delete flag;
            return item;
        }
   } 
   throw empty_list_error("Empty list exception"); 
}

// Define a method to delete a specific node.
template<class X>X DLL<X>::delete_node(node<X> *n)
{
    // n->prev->next = n->next;
    // n->next->prev = n->prev;

    X item; // return the poped item;

    if(start == n && n->next == NULL)
    {
        start = NULL;
        item = n->item;
        delete n;
        return item;
    }
    else if(start == n && n->next != NULL)
    {
        start = n->next;
        n->next->prev = NULL;
        item = n->item;
        delete n;
        return item;
    }
    else
    {
        node<X> *flag = start;

        while(flag->next != n)
        {
            flag = flag->next;
        }
        flag->next = n->next;

        if(n->next != NULL)
        {
            n->next->prev = n->prev;
        }
        item = n->item;
        delete n;
        return item;
    }

    /*
    
    node<X> *n = start;
    while(n)
    {
        if(n->item == data)
        {
            if(n->next != NULL)
                n->next->prev = n->prev;
            if(n->prev != NULL)
                n->prev->next = n->next;
            if(n->prev == NULL)
                start = n->next;
            delete n;
            break;
        }
        t = t->next;
    }
    
    */
}

// Define a method to delete a specific item.
template<class X>X DLL<X>::delete_item(X searchData)
{
    node<X> *n = find(searchData);
    X item; // return the poped item;

    if(start == n && n->next == NULL)
    {
        start = NULL;
        item = n->item;
        delete n;
        return item;
    }
    else if(start == n && n->next != NULL)
    {
        start = n->next;
        n->next->prev = NULL;
        item = n->item;
        delete n;
        return item;
    }
    else
    {
        node<X> *flag = start;

        while(flag->next != n)
        {
            flag = flag->next;
        }
        flag->next = n->next;

        if(n->next != NULL)
        {
            n->next->prev = n->prev;
        }
        item = n->item;
        delete n;
        return item;
    }
}

// Define a destructor to deallocates memory for all nodes in the linked list
template<class X>DLL<X>::~DLL()
{
    while(start != NULL)
    {
        pop_front();
    }
}

// Define a method to show the linked list.
template<class X>void DLL<X>::show_list()
{
    node<X> *flag = start;

    if(flag == NULL)
    {
        throw empty_list_error("Empty list exception");
    }
    while(flag != NULL)
    {
        cout<<flag->item<<" ";
        flag = flag->next;
    }
}

