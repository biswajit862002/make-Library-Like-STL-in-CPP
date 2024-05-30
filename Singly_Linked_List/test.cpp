#include<iostream>
#include"SinglyList.cpp"
using namespace std;

int main()
{
    SLL<int>s1;
    try
    {
        s1.push_front(20);
        s1.push_back(15);
        s1.push_back(21);
        s1.push_back(24);



        s1.show_list();

        // node<int> *n = s1.find(15);
        // cout<<endl<<"Item found = "<<n->item;

        s1.delete_item(24);

        // s1.insert_after(n,60);
        // cout<<endl;
        // s1.show_list();
        cout<<endl;

        // s1.pop_back();
        // s1.delete_node(n);
        s1.show_list();


    }
    

    catch(const item_not_found_error &e)
    {
        cout<<"Error Occoured : "<<e.what();
    }


    return 0;
}