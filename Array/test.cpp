#include<iostream>
#include"array.cpp"

using namespace std;

int main()
{
    array <string> a1(5);
    try
    {
        // a1.insert(0,10);
        // a1.append(20);
        // a1.append(30);
        // // a1.insert(4,40);
        // a1.append(50);
        // a1.append(60);
        // a1.append(70);



        a1.insert(0,"Biswajit");
        a1.append("sanjit");
        a1.append("Binati");
        a1.insert(3,"Suman");



    

    
        a1.showElement();
        cout<<endl;
        a1.reverse();
        cout<<endl;
        cout<<a1.getElement(1);
        cout<<endl;
        cout<<a1.findElement("Suman");

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