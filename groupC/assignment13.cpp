/*
Title  :- Write a C++ program to print all the repeated numbers with their frequency in an array in minimum time
complexity
Author :- Sahil Dhargave
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "\t\t  **********************" << endl;
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		// mp[arr[i]]=mp[arr[i+1]];
		mp[arr[i]]++;
	}
	cout << "\t\t  **********************" << endl;
	for (auto &i : mp)
	{

		cout << i.first << " " << i.second << endl;
	}
}
