// Header created by Tommy Trinh
// March 4, 2024
// This is the header file for a food kiosk, it keeps track of sales for
// the week and calculates inventory
#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <string>
using namespace std;

class Food
{
private:
	// Define constants
	const int MIN_INV = 24;			// minimum inventory amount
	const int MAX_INV = 99;			// maximum inventory amount
	const int DEFAULT_DAYS = 7;		// default days in a week

	// Define private variables
	string name;		// stores the name of the food item
	int invStart;		// stores the starting inventory amount
	int invEnd;			// stores the ending inventory amount
	int* sales=nullptr;	// dynamic array with num elements
	int num;			// stores the number of days that a sale is recorded

	// dynamically allocate an int array with num elements initialized to 0
	void makeArray()
	{ 
		sales = new int[num];
		for (int index = 0; index < num; index++)
			sales[index] = 0;
	}
	// calculate the ending inventory when given starting inventory and sales
	void calcEnd()
	{
		int counter = 0; 
		for (int count = 0; count < num; count++)
			counter += sales[count];
		invEnd = invStart- counter;
	}
	// calculate average number of items sold per day
	double calcAvg()
	{
		return static_cast<double>(invStart - invEnd) / num;
	}

public:
	Food();							// default constructor
	Food(int n);					// constructor with days of week
	Food(string nm, int st, int n);	// constructor with all info passed in
	void setName(string nm);		// sets the name of product
	void setStart(int st);			// sets the starting inventory
	void setEnd(int end);			// sets the ending inventory
	void setSales(int i, int sale);	// sets the sales amount
	string getName()const;			// returns the name
	int getStart()const;			// returns the starting inventory
	int getEnd()const;				// returns the ending inventory
	void showSales();				// shows sales info to user
	void display();					// shows food inventory info
	~Food();						// deconstructor deletes dynamic array
};
#endif