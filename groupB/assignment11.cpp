/*
Title  :- The ticket booking system of Cinemax theatre has to be implemented using C++ program. There are 15
rows and 10 seats in each row. Doubly linked lists have to be maintained to keep track of free seats in rows.
Assume some random booking to start with. Use an array to store pointers (Head pointer) to each row. On
demand
a. The list of available
b. seats is to be displayed
c. The seats are to be booked
d. The booking can be cancelled

Author :- Sahil Dhargave
*/



Methoe -1
	
	
	#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data='A';
    node * prev;
    node * next;
};
class cinema
{
    node * head[15],*tail[15],*t,*p;
    char c;
    public:
    cinema()
    {
        c = 'A';
        t=NULL;
        p=NULL;
        for(int i=0;i<15;i++)
        {
            head[i]=tail[i]=NULL;
        }
    }
    void create();
    void display();
    void book();
    void cancel();
};
void cinema::create()
{
    for(int i=0;i<15;i++)
    {
        head[i]=new node;
        p=head[i];
        p->prev=NULL;
        for(int j=1;j<10;j++)
        {
            t=new node;
            t->prev=p;
            p->next=t;
            p=t;
            tail[i]=t;
            t->next=NULL;
        }
    }
}
void cinema:: display()
{
    for(int i=0;i<10;i++)
    {
        cout<<"   "<<i+1;
    }
    cout<<endl;
    cout<<"  ";
    for(int i=0;i<14;i++)
    {
        cout<<"  "<<"_";
    }
    cout<<endl;
    
    for(int i=0;i<15;i++)
    {
        p=head[i];
        if(i<9)
        cout<<i+1<<"  |";
        else
        cout<<i+1<<" |";
        while(p!=NULL)
        {
            cout<<p->data<<"   ";
            p=p->next;
           
        }
        cout<<"|"<<endl;
    }
    cout<<"  ";
    for(int i=0;i<14;i++)
    {
        cout<<"  "<<"_";
    }
    cout<<endl;
}

void cinema ::book()
{
    int r,c;
    cout<<"Enter Which sit set u have to book enter row no. : ";
    cin>>r;
    cout<<"Enter column no.";
    cin>>c;
    p=head[r-1];
    for(int i=0;i<c-1;i++)
    {
        p=p->next;
    }
    if(p->data=='A')
    {
    p->data='B';
    cout<<"Sit booked"<<endl;
    }
    else
    {
        cout<<"Sit had already booked"<<endl;
    }
} 
void cinema ::cancel()
{
    int r,c;
    cout<<"Enter Which sit set u have to book enter row no. : ";
    cin>>r;
    cout<<"Enter column no.";
    cin>>c;
    p=head[r-1];
    for(int i=0;i<c-1;i++)
    {
        p=p->next;
    }
    if(p->data=='B')
    {
    p->data='A';
    cout<<"Sit Cancelled"<<endl;
    }
    else
    {
        cout<<"Sit had already cancelled or empty"<<endl;
    }
} 

int main()
{
    cinema c;
    c.create();
    int ch;
    do{
    cout<<"1.BOOK"<<endl<<"2.Cancel"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
    cout<<"Enter Your choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1: 
        c.book();
        break;
        case 2:
        c.cancel();
        break;
        case 3: 
        c.display();
        break;
        case 4:
        exit(0);
        break;
    }
    }while(1);
    return 0;
}




#include <iostream>
#include <math.h>
using namespace std;

// Node
class node
{
public:
	node *next;
	node *prev;
	int seat;
	string id;
	int status;
};

// Class
class cinemax
{
public:
	node *head[15], *tail[15], *temp, *end;
	cinemax()
	{
		for (int i = 0; i < 15; i++)
		{
			head[i] = NULL;
		}
	}
	void create_list();
	void display();
	void book();
	void cancel();
	void Available();
};

// ** Function Definations **

// # Create List
void cinemax::create_list()
{
	node *newnode;
	int j = 1, i, k;
	for (i = 0; i < 15; i++)
	{
		k = j;
		for (j = k;; j++)
		{
			newnode = new node;
			newnode->seat = j;
			newnode->status = 0;
			newnode->id = "null";
			if (head[i] == NULL)
			{
				tail[i] = head[i] = newnode;
				head[i]->prev = NULL;
			}
			else
			{
				tail[i]->next = newnode;
				newnode->prev = tail[i];
				tail[i] = newnode;
			}
			tail[i]->next = NULL;
			if (j % 10 == 0)
			{
				j++;
				break;
			}
		}
	}
}

void cinemax::display()
{

	int count = 0, flag = 1;
	cout << "\n---------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\t\t\t## Seat Status ##\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 15; i++)
	{
		temp = head[i];
		while (temp != NULL)
		{
			{
				if (flag == 1)
					cout << "| ";
				if (temp->seat >= 1 && temp->seat <= 9)
					cout << "S00" << temp->seat << " :";
				else if (temp->seat >= 10 && temp->seat <= 99)
					cout << "S0" << temp->seat << " :";
				else
					cout << "S" << temp->seat << " :";

				if (temp->status == 0)
					cout << "|___| ";
				else
					cout << "|_B_| ";

				count++;
				flag = 0;
				if (count % 10 == 0)
				{
					flag = 1;
					cout << "|";
					cout << endl;
				}
				temp = temp->next;
			}
		}
	}
	cout << "---------------------------------------------------------------------------------------------------------------------------\n";
}

void cinemax::book()
{
	int x;
	string y;
	int s1, s2;
	cout << "\n\n# Book Seat: " << endl;
label:
	cout << "Enter seat number to be booked: ";
	cin >> x;
	cout << "Enter your ID number: ";
	cin >> y;
	if (x < 1 || x > 150)
	{
		cout << "\n* Enter correct seat number to book (1-150)\n";
		goto label;
	}
	int pos = x / 10;
	if (x % 10 == 0)
		pos = pos - 1;

	// Selection of tail or head for traversal
	s1 = x - head[pos]->seat;
	s2 = x - tail[pos]->seat;
	if (abs(s1) < abs(s2))
	{
		temp = head[pos];
		while (temp->seat != x)
		{
			temp = temp->next;
		}
		if (temp->status == 1)
			cout << "\n* Seat is already booked!\n";
		else
		{
			temp->status = 1;
			temp->id = y;
			cout << "\n# Seat " << x << " is booked!" << endl;
		}
	}
	else
	{
		end = tail[pos];
		while (end->seat != x)
		{
			end = end->prev;
		}
		if (end->status == 1)
			cout << "\n* Seat is already booked!\n";
		else
		{
			end->status = 1;
			end->id = y;
			cout << "\n# Seat " << x << " is booked!" << endl;
		}
	}
}

void cinemax::cancel()
{
	int x;
	string y;
	int s1, s2;
	cout << "\n\n# Cancel Seat: " << endl;
label:
	cout << "\nEnter seat number to cancel booking: ";
	cin >> x;
	cout << "Enter you ID: ";
	cin >> y;
	if (x < 1 || x > 150)
	{
		cout << "\n* Enter correct seat number to cancel (1-70)\n";
		goto label;
	}
	int pos = x / 10;
	if (x % 10 == 0)
		pos = pos - 1;
	s1 = x - head[pos]->seat;
	s2 = x - tail[pos]->seat;
	if (abs(s1) < abs(s2))
	{
		temp = head[pos];
		while (temp->seat != x)
		{
			temp = temp->next;
		}

		if (temp->status == 0)
		{
			cout << "\n* Seat is not booked yet..!\n";
		}
		else
		{
			if (temp->id == y)
			{
				temp->status = 0;
				cout << "\n* Seat is Cancelled..!\n";
			}
			else
				cout << "\n* Wrong User ID !!! Seat cannot be cancelled!!!\n";
		}
	}
	else
	{
		end = tail[pos];
		while (end->seat != x)
		{
			end = end->prev;
		}

		if (end->status == 0)
		{
			cout << "\n* Seat is not booked yet..!\n";
		}
		else
		{
			if (end->id == y)
			{
				end->status = 0;
				cout << "\n* Seat is Cancelled..!\n";
			}
			else
				cout << "\n* Wrong User ID !!! Seat cannot be cancelled!!!\n";
		}
	}
}

void cinemax::Available()
{
	int r = 1;
	int count = 0, flag = 1;
	cout << "\n\n\n\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\t\t\t## Seat Available Status ##\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 15; i++)
	{
		temp = head[i];
		while (temp != NULL)
		{
			{
				if (flag == 1)
					cout << "| ";
				if (temp->seat >= 1 && temp->seat <= 9)
					cout << "S00" << temp->seat << " :";
				else if (temp->seat >= 10 && temp->seat <= 99)
					cout << "S0" << temp->seat << " :";
				else
					cout << "S" << temp->seat << " :";

				if (temp->status == 0)
					cout << "|_A_| ";

				else if (temp->status == 1)
					cout << "|___| ";

				count++;
				flag = 0;
				if (count % 10 == 0)
				{
					cout << "|";
					cout << endl;
					flag = 1;
					r++;
				}
			}
			temp = temp->next;
		}
		cout << "---------------------------------------------------------------------------------------------------------------------------\n";
	}
}

// # Main
int main()
{
	cinemax obj;
	obj.create_list();
	int ch;
	while (1)
	{
		cout << "\n\n**************************************\n";
		cout << " ## CINEMAX MOVIE THEATRE ##\n";
		cout << "**************************************\n";
		cout << "\n# Menu: \n1.Current Seat Status \n2.Book Seat \n3.Availableable Seat \n4.Cancel Seat \n5.Exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			obj.display();
			break;
		case 2:
			obj.book();
			break;
		case 3:
			obj.Available();
			break;
		case 4:
			obj.cancel();
			break;
		case 5:
			cout << "\n* You are exit \n\n";
			exit(0);
			break;
		default:
			cout << "\n* Invalid Choice \n";
			break;
		}
	}
	return 0;
}
