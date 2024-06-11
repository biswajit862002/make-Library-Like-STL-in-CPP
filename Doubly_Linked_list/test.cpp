#include<iostream>
#include"DoublyList.cpp"
using namespace std;

int main()
{
    DLL<int>d1;

    try
    {
        d1.push_front(10);
        d1.push_back(20);
        d1.push_back(30);
        d1.push_back(40);
        d1.push_front(5);

        cout<<endl;
        d1.show_list();
        cout<<endl;
        node<int>*n = d1.find(5);
        d1.insert_after(n,25);
        cout<<endl;
        d1.show_list();

        // cout<<"poped element = "<<d1.pop_front();
        // cout<<"poped element = "<<d1.pop_back();
        // d1.delete_item(25);
        d1.delete_node(n);

        cout<<endl;
        d1.show_list();


    }
    catch(const item_not_found_error &e)
    {
        cout<<"Error Occoured : "<<e.what();
    }
    catch(const empty_list_error &e)
    {
        cout<<"Error Occoured : "<<e.what();
    }



    return 0;
}