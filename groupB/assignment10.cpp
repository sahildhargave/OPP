/*
Title:Set A of customers like pizza and set B of customers like a burger. Write a C + +program to store two sets
using an array. compute and displaya. Set of customers who like either pizza or burger or both
b. Set of customers who like both pizza and burger.
c. Set of customers who like only pizza, not
burger.
d. Set of customers who like only burger not
pizza.
e. Number of customers who like neither pizza nor burger.
*/

Methode -1
	
	
#include<bits/stdc++.h>
using namespace std;

class customer
{
    int id[10];
    int n;
    vector <string>  name;
    public: 
    void accept();
    void display();
    friend void union_(customer &,customer &);
    friend void intersection_(customer &,customer &);
    friend void only_pizza(customer &,customer &);
    friend void only_burger(customer &,customer &);  
};
 
void union_(customer & pizza,customer & burger)
{

    int marked[100]={0};
    for(int i=0;i<pizza.n;i++)
    {
        cout<<pizza.id[i]<<" "<<pizza.name[i]<<endl;
        marked[pizza.id[i]]=1;
    }
    for(int i=0;i<pizza.n;i++)
    {
    for(int j=0;j<burger.n;j++)
    {
        if(pizza.id[i]!=burger.id[j]&&marked[burger.id[j]]==0)
        {
            marked[burger.id[j]]=1;
            cout<<burger.id[j]<<" "<<burger.name[j]<<endl;
        }
    }
    }
}
void intersection_(customer & pizza,customer & burger)
{
    int marked[100]={0};
    for(int i=0;i<pizza.n;i++)
    {
        for(int j=0;j<burger.n;j++)
        {
            if(pizza.id[i]==burger.id[j]&& marked[pizza.id[i]]==0)
            {
                marked[pizza.id[i]]=1;
                cout<<pizza.id[i]<<" "<<pizza.name[j]<<endl;
            }
        }
    }
}
void only_pizza(customer &pizza,customer &burger)
{
    int marked[100]={0};
   for(int i=0;i<pizza.n;i++)
    {
        for(int j=0;j<burger.n;j++)
        {
            if(pizza.id[i]==burger.id[j]&& marked[pizza.id[i]]==0)
            {
                marked[pizza.id[i]]=1;
            }
        }
    }
    for(int i=0;i<pizza.n;i++)
    {
        if(marked[pizza.id[i]]!=1)
        {
            cout<<pizza.id[i]<<" "<<pizza.name[i]<<endl;
        }
    }
}
void only_burger(customer &pizza,customer &burger)
{
    int marked[100]={0};
   for(int i=0;i<pizza.n;i++)
    {
        for(int j=0;j<burger.n;j++)
        {
            if(pizza.id[i]==burger.id[j]&& marked[pizza.id[i]]==0)
            {
                marked[burger.id[i]]=1;
            }
        }
    }
    for(int i=0;i<burger.n;i++)
    {
        if(marked[burger.id[i]]!=1)
        {
            cout<<burger.id[i]<<" "<<burger.name[i]<<endl;
        }
    }
}
void  customer:: accept()
{
    cout<<"Enter no. of customers "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter ID: ";
        cin>>id[i];
        cout<<"Enter Name : ";
        string s;
        cin>>s;
        name.push_back(s);
    }
}
void customer :: display()
{
     for(int i=0;i<n;i++)
    {
    cout<<"ID = "<<id[i]<<"  Name = "<<name[i]<<endl;
    }
}

int main()
{
    customer pizza;
    customer burger;
    cout<<"For Pizza"<<endl;
    pizza.accept();
    pizza.display();
    burger.accept();
    cout<<"For Burger"<<endl;
    burger.display();
    cout<<endl;
    cout<<"Customers who like either pizza or burger "<<endl;
    union_(pizza,burger);
    cout<<"Customers who like both pizza and burger"<<endl;
    intersection_(pizza,burger);
    cout<<"Customer who like only pizza"<<endl;
    only_pizza(pizza,burger);
    cout<<"Customer who like only burger"<<endl;
    only_burger(pizza,burger);
    return 0;
}




#include <iostream>

using namespace std;

class Set
{
private:
	int n;
	string name[20];

public:
	void read();
	void display();
	void unionofsets(Set c);
	void intersection(Set c);
	void a_minus_b(Set c);
	void b_minus_a(Set c);
};

void Set ::read()
{
	cout << "Enter no of customers : ";
	cin >> n;
	cout << "Enter name of customers  : \n";
	for (int i = 0; i < n; i++)
	{
		cin >> name[i];
	}
}

void Set ::display()
{
	cout << "Displaying elements of set  : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << name[i] << "\t";
	}
}

void Set ::unionofsets(Set setB)
{
	int n2 = setB.n;
	Set temp;
	int flag;
	// cout << n2;
	//  printing elements of set a
	for (int i = 0; i < n; i++)
	{
		temp.name[i] = name[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << temp.name[i] << "\t";
	}

	// checking common elements in both set
	for (int j = 0; j < n2; j++)
	{
		flag = 0;
		for (int k = 0; k < n; k++)
		{
			if (setB.name[j] == temp.name[k])
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			cout << setB.name[j] << "\t";
		}
	}
}

void Set ::intersection(Set setB)
{
	int n2 = setB.n;
	int flag, count = 0;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < n2; j++)
		{
			if (name[i] == setB.name[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			count++;
			cout << name[i] << "\t";
		}
	}

	if (count == 0)
	{
		cout << "None" << endl;
	}
}

void Set ::a_minus_b(Set setB)
{
	int n2 = setB.n;
	int flag;

	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < n2; j++)
		{
			if (name[i] == setB.name[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			cout << name[i] << "\t";
		}
	}
}

void Set ::b_minus_a(Set setB)
{
	int n2 = setB.n;
	int flag;

	for (int i = 0; i < n2; i++)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (setB.name[i] == name[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			cout << setB.name[i] << "\t";
		}
	}
}

int main()
{

	Set setA;
	Set setB;
	Set c;

	cout << "Enter customers who likes pizza : " << endl;
	setA.read();
	// setA.display();

	cout << "\nEnter customers who likes Burger : " << endl;
	setB.read();
	// setB.display();

	cout << "\n\nSet of customers who like either pizza or burger or both : " << endl;
	setA.unionofsets(setB);

	cout << "\n\nSet of customers who like both pizza and burger : " << endl;
	setA.intersection(setB);

	cout << "\n\nSet of customers who like only pizza, not burger : " << endl;
	setA.a_minus_b(setB);

	cout << "\n\nSet of customers who like only burger not pizza : " << endl;
	setA.b_minus_a(setB);

	return 0;
}
