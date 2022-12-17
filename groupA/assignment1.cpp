/*
Title :- Define a class to represent a bank account which includes the following
members as:
Data members:
a. Name of the depositor
b. Account Number
c. Withdrawal amount
d. Balance amount in the account Member Functions:
e. To assign initial values
f. To deposit an amount
g. To withdraw an amount after checking the balance
h. To display name and balance.

Author  :- Sahil Dhargave

*/

#include <iostream>

using namespace std;

// define a class 'Bank'
class Bank
{
private:
	int acno;
	char name[30];
	long balance;

public:
	void OpenAccount()
	{
		cout << "Enter Account Number: ";
		cin >> acno;
		cout << "Enter Account Holder Name: ";
		cin >> name;
		cout << "Enter  Balance: ";
		cin >> balance;
	}
	void ShowAccount()
	{
		cout << acno << "\t" << name << "\t" << balance;
	}
	void Deposit()
	{
		long amt;
		cout << "Enter Amount U want to deposit? ";
		cin >> amt;
		balance = balance + amt;
	}
	void Withdrawal()
	{
		long amt;
		cout << "Enter Amount U want to withdraw? ";
		cin >> amt;
		if (amt <= balance)
			balance = balance - amt;
		else
			cout << "Oops!! Less Balance..." << endl;
	}
	int Search(int);
};

int Bank::Search(int a)
{
	if (acno == a)
	{
		ShowAccount();
		return (1);
	}
	return (0);
}

// main code
int main()
{
	Bank C[3];

	int found = 0, a, ch, i;
	for (i = 0; i <= 2; i++)
	{
		C[i].OpenAccount();
	}

	do
	{
		// display options
		cout << "\nHow can I help u ?";
		cout << "\n\n1:Display All\n2:Search By Account No\n3:Deposit\n4:Withdraw\n5:Exit" << endl;

		// user input
		cout << "Please Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "\n----------------------------------------";
			cout << "\nAccNo\tName\tAccBal\n";
			cout << "\n----------------------------------------";
			for (i = 0; i <= 2; i++)
			{
				C[i].ShowAccount();
			}
			break;
		case 2:
			cout << "\nEnter Account Number: ";
			cin >> a;
			for (i = 0; i <= 2; i++)
			{
				found = C[i].Search(a);
				if (found)
					break;
			}
			if (!found)
				cout << "Record Not Found" << endl;
			break;
		case 3:
			cout << "\nEnter Account Number To Deposit Amount? ";
			cin >> a;
			for (i = 0; i <= 2; i++)
			{
				found = C[i].Search(a);
				if (found)
				{
					C[i].Deposit();
					break;
				}
			}
			if (!found)
				cout << "Record Not Found" << endl;
			break;
		case 4: // withdraw operation
			cout << "\nAccount Number To Withdraw Amount? ";
			cin >> a;
			for (i = 0; i <= 2; i++)
			{
				found = C[i].Search(a);
				if (found)
				{
					C[i].Withdrawal();
					break;
				}
			}
			if (!found)
				cout << "Record Not Found" << endl;
			break;
		case 5: // exit
			cout << "\nThank you for using Banking software.." << endl;
			break;
		default:
			cout << "Invalid Option" << endl;
		}
	} while (ch != 5);
	return 0;
}
