/*
Title  :-Write a program to maintain an employee database in binary file with employee information such as empId,
name, age, department, post and salary. Write function for adding new record, displaying all records,
searching for a particular employee, updating employee salary and post.
Author :- Sahil Dhargave
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Employee
{
	int emp_id, age;
	char name[30], department[30], post[30];
	float salery;

public:
	void read()
	{

		cout << "\n\nEnter Employee Id :";
		cin >> emp_id;

		cout << "\n\nEnter Employee Name :";
		cin >> name;

		cout << "\n\nEnter Employee Salary :";
		cin >> salery;

		cout << "\n\nEnter Employee Department:";
		cin >> department;

		cout << "\n\nEnter Employee Post :";
		cin >> post;
	}

	void display()
	{
		// cout<<"\n\nName :"<<name;
		// cout<<"\n\nEmployee id :"<<emp_id;
		// cout<<"\n\nEmployee Salary:"<<salery;
		// cout<<"\n\nDepartment:"<<department;
		// cout<<"\n\nPost:"<<post;

		cout << "\n"
			 << emp_id << "\t" << name << "\t" << salery << "\t" << department << "\t" << post;
	}
	int getEmpId()
	{
		return emp_id;
	}
};
void write_file()
{
	Employee e;

	ofstream ofs;
	e.read(); // accept data from user
	ofs.open("emp.dat", ios::binary | ios::app);
	ofs.write((char *)&e, sizeof(e)); // write data into the file
	ofs.close();
}

void read_file()
{
	Employee e;

	ifstream ifs;
	ifs.open("emp.dat", ios::binary);

	while (ifs.read((char *)&e, sizeof(e)))
	{
		e.display();
	}
	ifs.close();
}

void search(int id)
{
	ifstream fin;
	int flag = 0;
	fin.open("emp.dat", ios::binary);

	Employee e;

	while (fin.read((char *)&e, sizeof(e)))
	{
		if (id == e.getEmpId())
		{
			cout << "\n\nEmployee Id found..";
			flag = 1;
			e.display();
		}
	}
	if (flag == 0)
	{
		cout << "\nEmployee Not Found....";
	}
	fin.close();
}
void update(int id)
{

	int pos, flag = 0;

	fstream fs;
	Employee e;
	fs.open("emp.dat", ios::in | ios::binary | ios::out);

	while (!fs.eof())
	{
		// storing the position of current file pointer i.e. at the end of previously read record
		pos = fs.tellg();

		fs.read((char *)&e, sizeof(e));
		if (fs)
		{

			if (id == e.getEmpId())
			{
				flag = 1;

				e.read();

				// placing the put(writing) pointer at the starting of the  record
				fs.seekp(pos);

				fs.write((char *)&e, sizeof(e));

				e.display();
				break;
			}
		}
	}
	fs.close();

	if (flag == 1)
		cout << "\nRecord successfully modified \n";
	else
		cout << "\nRecord not found \n";
}
int main()
{
	int ch, id;
	while (1)
	{
		cout << "\n |  How May Help You..  |";
		cout << "\n1.Insert Data \n2.Display \n3.Search\n4.Update Reord\n5.Exit";
		cout << "\nEnter Your Choice:";
		cin >> ch;

		switch (ch)
		{

		case 1:
			write_file();
			break;

		case 2:
			cout << "\nEmpId\tEmpName\tSalary\tDept\tPost";
			cout << "\n--------------------------------------------";
			read_file();
			break;

		case 3:
			cout << "\n\nEnter Employee Id to Find Employee:";
			cin >> id;
			cout << "\nEmpId\tEmpName\tSalary\tDept\tPost";
			cout << "\n--------------------------------------------";
			search(id);
			break;

		case 4:
			cout << "\nEnter employee id for update:";
			cin >> id;
			update(id);
			break;
		case 5:
			exit(0);
			break;
		}
	}
	return 0;
}
