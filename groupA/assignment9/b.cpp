/*
b. Write C++ program using STL map for managing Person Record (Name, birth date, telephone 
no). Perform operations – add, display, search, delete, and update.
*/

#include<bits/stdc++.h>
using namespace std;

class person
{
    string name;
    string tel_no;
    string dob;
    public:
    void add(string);
    void display();
    void search(string );
    void update(string );
};

void person::add(string name)
{
    this->name=name;
    cout<<"Enter your tel no. :";
    cin>>tel_no;
    cout<<"Enter DOB : ";
    cin>>dob;
}

void person:: display()
{
    cout<<"Name : "<<name<<endl;
    cout<<"Telephone Number : "<<tel_no<<endl;
    cout<<"Date of Birth : "<<dob<<endl;
}

void person::update(string n)
{
        add(n);
}
void person :: search(string n)
{
        display();
}
void person_record()
{
    person * q;
    map<person*,string> m;
    string name;
    int ch;
    do{
    cout<<"Enter your choice : "<<endl;
    cout<<"1.Add record"<<endl
        <<"2.Display"<<endl;
    cin>>ch;
    
    if(ch==1)
    {
        person *p= new person();  
        cout<<"Enter name :";
        cin>>name;
        p->add(name);
        m[p]=name;
    }
    else if(ch==2)
    {
        for(auto a:m)
        {
            a.first->display();
        }
    }
    else if(ch==3)
    {
        cout<<"Enter name"<<endl;
        cin>>name;
        for(auto a:m)
        {
           if(a.second==name)
           {
            a.first->search(name);
           }
        }
    }
    else if(ch==4)
    {
       cout<<"Enter name"<<endl;
        cin>>name;
        for(auto a:m)
        {
           if(a.second==name)
           {
            a.first->update(name);
           }
        }
    }
    else if(ch==5)
    {
       cout<<"Enter name"<<endl;
        cin>>name;
        for(auto a:m)
        {
           if(a.second==name)
           {
              q=a.first;
              break;
           }
        }
             m.erase(q);


    }
    else if(ch==6)
    {
        break;
    }
    }while(1);
}
int main()
{
    person_record();
    return 0;
}
