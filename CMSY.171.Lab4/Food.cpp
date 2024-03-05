// Program written by Tommy Trinh
// March 4, 2024
// This implementation file is for the Food header
#include "Food.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Food::Food()
{ // default constructor, sets name to None, min inventory, and default days
	setName("None");
	setStart(MIN_INV);
	num = DEFAULT_DAYS;
	makeArray();
}

Food::Food(int n)
{ // constructor but with explicit days
	setName("None");
	setStart(MIN_INV);
	if (n > 0)
		num = n;
	else
		num = DEFAULT_DAYS;
	makeArray();
}

Food::Food(string nm, int st, int n)
{ // constructor with all inputs
	setName(nm);
	setStart(st);
	if (n > 0)
		num = n;
	else
		num = DEFAULT_DAYS;
	makeArray();
}

void Food::setName(string nm)
{ // takes a string input and sets it to name field
	name = nm;
}

void Food::setStart(int st)
{ // takes a number and sets it to starting inventory if between min and max
	if (MIN_INV <= st && st <= MAX_INV)
		invStart = st;
	else
	{ // else give an error
		invStart = MIN_INV;
		cout << "Invalid. Can not set starting inventory to " << st
			<< " for " << getName() << endl;
	}
}

void Food::setEnd(int en)
{ // sets an ending inventory, not actually used in program?? Always calcEnd instead
	if (en >= 0)
		invEnd = en;
	else
	{ // if invalid end inventory, give error
		invEnd = 0;
		cout << "Invalid. Cannot set ending inventory to " << en
			<< " for " << getName();
	}
}

void Food::setSales(int i, int sale)
{ // sets the sales amount for some array index
	if (i >= 0 && i < num && sale>0 && sale < 99)
		sales[i] = sale;
	else
	{ // if invalid give error
		cout << "Invalid. Can not set sales for day " << i
			<< " to " << sale << " for " << getName() << endl;
	}
}

string Food::getName()const
{ // sends back name
	return name;
}

int Food::getStart()const
{ // sends back starting inventory
	return invStart;
}

int Food::getEnd()const
{ // sends back ending inventory
	return invEnd;
}

void Food::showSales()
{ // runs through an index returning sales each day
	for (int i = 0; i < num; i++)
	{
		cout << "Day " << i + 1 << " had a sales of " << sales[i]
			<< " for item " << getName() << endl;
	}
}

void Food::display()
{ // displays all the information back to user
	cout << "\nFood Name: " << getName() << endl;
	cout << "Starting Inventory Amount: " << getStart() << endl;
	showSales();
	calcEnd();
	cout << "Final Inventory Amount: " << getEnd() << endl;
	cout << fixed << setprecision(1) << showpoint;
	cout << "The average sold per day is: " << calcAvg() << endl;
}

Food::~Food()
{ // delete dynamic array
	delete[]sales;
	sales = nullptr;
}