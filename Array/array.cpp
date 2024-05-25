#include<iostream>
#include<stdio.h>
using namespace std;

// define a custom exception class invalidindex_error
class invalidindex_error : public runtime_error
{
    public:
        invalidindex_error(const string &msg):runtime_error(msg)
        {

        }
};

template <class X>
class array
{
    private:
        int capacity;
        int lastIndex;
        X *ptr;

    public:
        array();
        array(int);
        void createArray(int);
        bool isEmpty();
        bool isFull();
        void append(X);
        void insert(int, X);
        void edit(int,X);
        X remove(int);
        void showElement();
        X getElement(int);
        int countElement();
        int findElement(X);
        void reverse();
        X back();
        X front();
        int size();

        ~array();
        array(array &);
        array& operator =(array &);
};

// When create object without parameter then member variable are assign default value
template <class X>array<X>::array()
{
    this->capacity = 0;
    lastIndex = -1;
    ptr = NULL;
}

// Define a parametrized constructor to create an array of specified size
template <class X>array<X>::array(int capacity)
{
    this->capacity = capacity;
    lastIndex = -1;
    ptr = new X[this->capacity]; 
}

// After creating object we can call this method to create array and size wil be pass by the parameter
template <class X>void array<X>::createArray(int capacity)
{
    this->capacity = capacity;
    lastIndex = -1;
    if(ptr != NULL)
    {
        delete []ptr;
    }
    ptr = new X[this->capacity];  
}

// This method to check whether an array is empty or not by returing true or false
template <class X>bool array<X>::isEmpty()
{
    if(lastIndex == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Define a method to append a new element in the array
template <class X>void array<X>::append(X data)
{
    if(isFull())
    {
        throw overflow_error("Over flow, array is full");
    }
    else
    {
        lastIndex++;
        ptr[lastIndex] = data;
    }
}

// Define a method to insert a new element at specified index
template <class X>void array<X>::insert(int index, X data)
{
    if(index < 0 || index > lastIndex+1)
    {
        throw invalidindex_error("invalid index exception");
    }
    else if(isFull())
    {
        throw overflow_error("over flow, array is full");
    }
    else
    {
        for(int i=lastIndex; i>=index; i--)
        {
            ptr[i+1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
}

// Define a method to edit an element at specified index
template<class X>void array<X>::edit(int index, X data)
{
    if(index < 0 || index > lastIndex)
    {
        throw invalidindex_error("invalid index exception");
    }
    else
    {
        ptr[index] = data;
    }
}

// Define a method to show all the element in array
template<class X>void array<X>::showElement()
{
    for(int i=0; i<=lastIndex; i++)
    {
        cout<<ptr[i]<<" ";
    }
}

// Define a method to check if the array is full by returing true or false
template<class X>bool array<X>::isFull()
{
    if(lastIndex == capacity - 1) // array is fulled
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Define a method to get element at specified index
template<class X>X array<X>::getElement(int index)
{
    if(index < 0 || index > lastIndex)
    {
        throw invalidindex_error("invalid index exception");
    }
    else
    {
        return ptr[index];
    }
}

// Define a method to count number of elements present in the array 
template<class X>int array<X>::countElement()
{
    return lastIndex+1;
}

// Define a method to find an element in the array. Return index if the element found, otherwise return -1
template<class X>int array<X>::findElement(X data)
{
    for(int i=0; i<=lastIndex; i++)
    {
        if(ptr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

// Define a method to delete an element at specified index
template<class X>X array<X>::remove(int index)
{
    if(index < 0 || index > lastIndex)
    {
        throw invalidindex_error("invalid index exception");
    }
    else  
    {
        X temp = ptr[index];
        for(int i=index; i<lastIndex; i++)
        {
            ptr[i] = ptr[i+1];
        }
        lastIndex--;
        return temp;
    }
}

// Define a method return last element of an array
template<class X>X array<X>::back()
{
    return ptr[lastIndex];
}

// Define a method return first element of an array
template<class X>X array<X>::front()
{
    return ptr[0];
}

// Define a method return size of an array
template<class X>int array<X>::size()
{
    return lastIndex+1;
}

// Define a method to reverse array element
template<class X>void array<X>::reverse()
{
    for(int i=lastIndex; i>=0; i--)
    {
        cout<<ptr[i]<<" ";
    }    
}

// Define a copy constructor in array class to perform deep mcopy
template<class X>array<X>::array(array<X> &r)
{
    capacity = r.capacity;
    lastIndex = r.lastIndex;
    ptr = new X[capacity];
    for(int i=0; i<=lastIndex; i++)
    {
        ptr[i] = r.ptr[i];
    }
}

// Define a copy assignment operator in array class to perform deep copy
template<class X>array<X>& array<X>::operator=(array<X> &r)
{
    if(this != &r)
    {
        if(ptr != NULL)
        {
            delete []ptr;
        }
        capacity = r.capacity;
        lastIndex = r.lastIndex;
        ptr = new X[capacity];
        for(int i=0; i<=lastIndex; i++)
        {
            ptr[i] = r.ptr[i];
        }
    }
    return *this;
    
}

// Define a destructor to deallocate the memory of array
template<class X> array<X>::~array()
{
    delete []ptr;  
}
