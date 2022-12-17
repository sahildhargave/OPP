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
