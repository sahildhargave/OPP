/*

Title  :- Write a C++ program to sort N names in alphabetical order
Author :- Sahil Dhargave
*/
#include <bits/stdc++.h>
using namespace std;

void getname(vector<string> names)
{
	cout << "printing ........\n";
	for (int i = 0; i < names.size(); i++)
		cout << names[i] << endl;
	cout << "\n";
}

bool mycomp(string a, string b)
{

	return a < b;
}

vector<string> alpha_sort(vector<string> a)
{
	int n = a.size();

	sort(a.begin(), a.end(), mycomp);
	return a;
}

int main()
{
	int n;
	cout << "enter number of names to be added: ";
	cin >> n;

	vector<string> names;
	string name;
	cout << "enter names: \n";

	for (int i = 0; i < n; i++)
	{
		cin >> name;
		names.push_back(name);
	}

	cout << "\nbefore sorting\n";
	getname(names);

	names = alpha_sort(names);

	cout << "after alphabetical sorting\n";
	getname(names);

	return 0;
}
