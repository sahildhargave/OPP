/*
Title  :-  Implement a class Complex which represents the Complex Number data type. Implement the
following operations:
a. Constructor (including a default constructor which creates the complex number
0+0i).
b. Overloaded operator + to add two complex numbers.
c. Overloaded operator * to multiply two complex numbers.
d. Overloaded << and >> to print and read Complex Numbers.
Write a C + + program to read and display all project information using Operator Overloading

Author  :-  Sahil Dhargve



*/


#include <iostream>
using namespace std;

class complex
{
	float x;
	float y;

public:
	complex()
	{
		x = 0;
		y = 0;
	}

	complex operator+(complex);
	complex operator*(complex);
	complex operator-(complex);

	friend istream &operator>>(istream &input, complex &t)
	{
		cout << "\nEnter the real part:";
		input >> t.x;
		cout << "Enter the imaginary part:";
		input >> t.y;
	}

	friend ostream &operator<<(ostream &output, complex &t)
	{
		output << t.x << "+" << t.y << "i\n";
	}
};

complex complex::operator+(complex c)
{
	complex temp;
	temp.x = x + c.x;
	temp.y = y + c.y;
	return (temp);
}

complex complex::operator*(complex c)
{
	complex temp2;
	temp2.x = (x * c.x) - (y * c.y);
	temp2.y = (y * c.x) + (x * c.y);
	return (temp2);
}

complex complex::operator-(complex c)
{
	complex temp1;
	temp1.x = x - c.x;
	temp1.y = y - c.y;
	return (temp1);
}

int main()
{
	complex c1, c2, c3, c4, c5;
	cout << "Default constructor value = ";
	cout << c1;
	cout << "\nFor 1st number";
	cin >> c1;
	cout << "\nFor 2nd number";
	cin >> c2;
	c3 = c1 + c2;
	c4 = c1 * c2;
	c5 = c1 - c2;
	cout << "\nThe first number is:";
	cout << c1;
	cout << "\nThe second number is:";
	cout << c2;
	cout << "\nThe addition is:";
	cout << c3;
	cout << "\nThe multiplication is:";
	cout << c4;
	cout << "\nThe substraction is:";
	cout << c5;
	return 0;
}
