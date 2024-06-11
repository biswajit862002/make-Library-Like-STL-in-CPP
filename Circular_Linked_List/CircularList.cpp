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
template<class X>
struct node
{
    X item;
    node *next;
};

// Define a class CLL to implement circular linked list data structure with member variable last pointer of type node.
template<class X>
class CLL
{
    private:
        node<X> *last;

    public:
        CLL();
        void push_front(X);
        void push_back(X);
        void insert_after(node<X> *,X);
        node<X>* find(X);
        void pop_front();
        void pop_back();
        void delete_node(node<X> *);
        void delete_item(X);
        ~CLL();

        void show_list();
};

// Define a constructor to initialize last pointer with NULL.
template<class X>CLL<X>::CLL()
{
    last = NULL;
}

// Define a method to insert a data into the list at the beginning.
template<class X>void CLL<X>::push_front(X data)
{
    node<X>* temp = new node<X>();
    temp->item = data;

    if(last == NULL)
    {
        temp->next = temp;
        last = temp;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
}

// Define a method to insert a data into the list at the end.
template<class X>void CLL<X>::push_back(X data)
{
    node<X>* temp = new node<X>();
    temp->item = data;

    if(last == NULL)
    {
        temp->next = temp;
        last = temp;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

// Define a method to insert a data into the list after the specified node of the list.
template<class X> void CLL<X>::insert_after(node<X>* n, X data)
{
    node<X>* temp = new node<X>();
    temp->item = data;
    temp->next = n->next;
    n->next = temp;

    if(last == n)
    {
        last = temp;
    }
    
}

// Define a method to search a node with the given item.
template<class X>node<X>* CLL<X>::find(X data)
{
    if(last != NULL)
    {
        node<X>* flag = last->next;
        do
        {
            if(flag->item == data)
            {
                return flag;
            }
            flag = flag->next;
        } while(flag != last->next);
    }
    throw item_not_found_error("Item not found exception");
}

// Define a method to delete first node from the list.
template<class X>void CLL<X>::pop_front()
{
    if(last != NULL)
    {
        node<X>* temp = last->next;

        if(last == last->next)
        {
            delete last;
            last = NULL;
        }
        else
        {
            last->next = temp->next;
            delete temp;
        }
    }
}

// Define a method to delete last node from the list.
template<class X>void CLL<X>::pop_back()
{
    if(last != NULL)
    {
        node<X>* temp = last->next;

        if(last == last->next)
        {
            delete last;
            last = NULL;
        }
        else
        {
            while(temp->next->next != last->next)
            {
                temp = temp->next;
            }
            temp->next = last->next;
            delete last;
            last = temp;
        }
    
    }
}

// Define a method to delete a specific node.
template<class X>void CLL<X>::delete_node(node<X>* n)
{
    if(last != NULL)
    {
        // if n is pointing to the last node & only one node exist
        if(last == n && last == last->next)
        {
            delete last;
            last = NULL;
        }

        // if n is pointing to the last node & more than one node exist
        else if(last == n && last != last->next)
        {
            node<X>* temp = last->next;

            while(temp->next != n)
            {
                temp = temp->next;
            }
            temp->next = n->next;
            delete n;
            last = temp;
        }

        // if n is pointing to the first node & more than one node exist
        else if(n == last->next)
        {
            last->next = n->next;
            delete n;
        }


        else
        {
            node<X>* temp = last->next;
            while(temp->next != n)
            {
                temp = temp->next;
            }
            temp->next = n->next;
            delete n;
        }
    }
}

// Define a method to delete a specific item.
template<class X>void CLL<X>::delete_item(X data)
{
    node<X>* n = find(data);
    if(last != NULL)
    {
        // if n is pointing to the last node & only one node exist
        if(last == n && last == last->next)
        {
            delete last;
            last = NULL;
        }

        // if n is pointing to the last node & more than one node exist
        else if(last == n && last != last->next)
        {
            node<X>* temp = last->next;

            while(temp->next != n)
            {
                temp = temp->next;
            }
            temp->next = n->next;
            delete n;
            last = temp;
        }

        // if n is pointing to the first node & more than one node exist
        else if(n == last->next)
        {
            last->next = n->next;
            delete n;
        }
        else
        {
            node<X>* temp = last->next;
            while(temp->next != n)
            {
                temp = temp->next;
            }
            temp->next = n->next;
            delete n;
        }
    }
}

// Define a method to show the linked list.
template<class X>void CLL<X>::show_list()
{
    if(last != NULL)
    {
        node<X>* flag = last->next;
        do
        {
            cout<<flag->item<<" ";
            flag = flag->next;
        } while(flag != last->next);
    }
}

// Define a destructor to deallocates memory for all the nodes in the linked list.
template<class X>CLL<X>::~CLL()
{
    while(last != NULL)
    {
        pop_front();
    }
}