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
class vector
{
    private:
        int capacity;
        int lastIndex;
        X *ptr;

    protected:
        void doubleArray();
        void halfArray();

    public:
        vector();
        vector(int);
        void createArray(int);
        int getCapacity();
        bool isEmpty();
        bool isFull();
        void append(X);
        void insert(int, X);
        void edit(int,X);
        X remove(int);
        X getElement(int);
        int countElement();
        int findElement(X);
        void reverse();
        X back();
        X front();
        int size();
        void showElement();

        ~vector();
        vector(vector &);
        vector& operator =(vector &);



        
};

// When create object without parameter then member variable are assign default value
template <class X>vector<X>::vector()
{
    this->capacity = 0;
    lastIndex = -1;
    ptr = NULL;
}

// Define a parametrized constructor to create an array of specified size
template <class X>vector<X>::vector(int capacity)
{
    this->capacity = capacity;
    lastIndex = -1;
    ptr = new X[this->capacity]; 
}

// After creating object we can call this method to create array and size wil be pass by the parameter
template <class X>void vector<X>::createArray(int capacity)
{
    this->capacity = capacity;
    lastIndex = -1;
    if(ptr != NULL)
    {
        delete []ptr;
    }
    ptr = new X[this->capacity];  
}

// Define a method doubleArray() to increase the size of the array by double of its size
template <class X>void vector<X>::doubleArray()
{
    capacity = 2*capacity;
    X *temp = new X[capacity];

    for(int i=0; i<=lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete []ptr;
    ptr = temp;
}

// Define a method halfArray() to decrease the size of the array half of its size
template <class X>void vector<X>::halfArray()
{ 
    capacity = capacity/2;
    X *temp = new X[capacity];

    for(int i=0; i<=lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete []ptr;
    ptr = temp;
}

// Define a method which returns the current capacity of the array
template<class X>int vector<X>::getCapacity()
{
    return capacity;
}

// This method to check whether an array is empty or not by returing true or false
template <class X>bool vector<X>::isEmpty()
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

// Define a method to check if the array is full by returing true or false
template<class X>bool vector<X>::isFull()
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

// This method to append a new element in the array
template <class X>void vector<X>::append(X data)
{
    if(isFull())
    {
        doubleArray();
    }
    lastIndex++;
    ptr[lastIndex] = data;
}

// Define a method to insert a new element at specified index
template <class X>void vector<X>::insert(int index, X data)
{
    if(index < 0 || index > lastIndex+1)
    {
        throw invalidindex_error("invalid index exception");
    }
    else 
    {
        if(isFull())
            doubleArray();
        for(int i=lastIndex; i>=index; i--)
        {
            ptr[i+1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }   
}

// Define a method to edit an element at specified index
template<class X>void vector<X>::edit(int index, X data)
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

// Define a method to delete an element at specified index
template<class X>X vector<X>::remove(int index)
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
        

        if(capacity>1 && lastIndex+1 <= capacity/2)
        {
            halfArray();
        }  

        return temp;
    }
}

// Define a method to get element at specified index
template<class X>X vector<X>::getElement(int index)
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
template<class X>int vector<X>::countElement()
{
    return lastIndex+1;
}

// Define a method to find an element in the array. Return index if the element found, otherwise return -1
template<class X>int vector<X>::findElement(X data)
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

// Define a method return last element of an array
template<class X>X vector<X>::back()
{
    return ptr[lastIndex];
}

// Define a method return first element of an array
template<class X>X vector<X>::front()
{
    return ptr[0];
}

// Define a method return size of an array
template<class X>int vector<X>::size()
{
    return lastIndex+1;
}

// Define a method to reverse array element
template<class X>void vector<X>::reverse()
{
    for(int i=lastIndex; i>=0; i--)
    {
        cout<<ptr[i]<<" ";
    }    
}

// Define a method to show all the element in array
template<class X>void vector<X>::showElement()
{
    for(int i=0; i<=lastIndex; i++)
    {
        cout<<ptr[i]<<" ";
    }
}

// Define a copy constructor in array class to perform deep mcopy
template<class X>vector<X>::vector(vector<X> &r)
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
template<class X>vector<X>& vector<X>::operator=(vector<X> &r)
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
template<class X> vector<X>::~vector()
{
    delete []ptr;  
}



