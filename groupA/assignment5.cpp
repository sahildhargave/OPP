#include <iostream>
using namespace std;

class shape
{
public:
	double side_1;
	double side_2;

	shape()
	{
		side_1 = 0;
		side_2 = 0;
	}

	void get_data()
	{
		cout << "\n\nEnter the side 1 : ";
		cin >> side_1;

		cout << "Enter the side 2 : ";
		cin >> side_2;
	}

	virtual void display_area()
	{
	}
};

class rectangle : public shape
{
public:
	double area;

	void display_area()
	{
		area = side_1 * side_2;

		cout << "\nArea of rectangle = " << area;
	}
};

class triangle : public shape
{
public:
	double area;

	void display_area()
	{
		area = 0.5 * side_1 * side_2;

		cout << "\nArea of triangle = " << area;
	}
};

int main()
{
	shape *s;
	rectangle r;
	triangle t;

	s = &r;
	s->get_data();
	s->display_area();

	s = &t;
	s->get_data();
	s->display_area();

	return 0;
}