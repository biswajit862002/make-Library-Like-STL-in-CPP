#include<iostream>
#include"vector.cpp"

using namespace std;

int main()
{
    vector <int> a1(5);
    try
    {
        a1.insert(0,10);
        a1.append(20);
        a1.append(30);
        // a1.insert(4,40);
        a1.append(50);
        a1.append(60);



        // a1.insert(0,"Biswajit");
        // a1.append("sanjit");
        // a1.append("Binati");
        // a1.insert(3,"Suman");



    

    
        a1.showElement();
        cout<<endl;
        cout<<"capacity = "<<a1.getCapacity();
        cout<<endl;

        a1.append(70);
        cout<<endl;

        a1.showElement();
        cout<<endl;

        cout<<"capacity = "<<a1.getCapacity();
        cout<<endl;


        int re = a1.remove(4);
        cout<<"remove element = "<<re;
        cout<<endl;
        a1.showElement();
        cout<<endl;

        cout<<"capacity = "<<a1.getCapacity();
        cout<<endl;


        cout<<endl;

        // cout<<a1.current_capacity();
        a1.reverse();
        cout<<endl;
        cout<<a1.back();
        cout<<endl;
        cout<<a1.front();
        cout<<endl;
        cout<<a1.size();



    }
    catch(const invalidindex_error &e)
    {
        cout<<"Error Occoured : "<<e.what();
    }
    catch(const overflow_error &e)
    {
        cout<<"Error Occoured : "<<e.what();
    }
    
    



    return 0;
}