#include<iostream>
#include"CircularList.cpp"
using namespace std;

int main()
{

    CLL<int>c1;
    try
    {
        c1.push_front(20);
        c1.push_back(15);
        c1.push_back(21);
        c1.push_back(24);



        c1.show_list();

        node<int> *n = c1.find(21);
        cout<<endl<<"Item found = "<<n->item;

        // s1.delete_item(24);

        c1.insert_after(n,60);
        cout<<endl;
        c1.show_list();
        cout<<endl;
        c1.delete_item(24);

        // c1.pop_back();
        // c1.pop_back();
        // c1.delete_node(n);
        c1.show_list();


    }
    catch(const item_not_found_error &e)
    {
        cout<<"Error Occoured : "<<e.what();
    }


    return 0;
}