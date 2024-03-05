// Program written by Tommy Trinh
// March 4, 2024
// This program simulates an inventory tracker for a food kiosk for
// three different kinds of food
#include <iostream>
#include <iomanip>
#include <string>
#include "Food.h"
using namespace std;

int main()
{
	// display the header
	cout << "\t\t\t\t\tCMSY 171 Lab 4\n"
		<< "Copyright 2024 - Howard Community College All rights reserved; "
		<< "Unauthorized duplication prohibited.\n\n"
		<< "\t\tWelcome to CMSY-171 Food Kiosk Inventory Program\n\n\n\n";

	// create 3 food objects
	Food Food1;
	Food Food2(7);
	Food Food3("Tossed Salad",75,7);

	// display the empty objects
	cout << "Calling the display function after initial call to constructors\n";
	Food1.display();
	Food2.display();
	Food3.display();

	// set the error conditions
	cout << "\nCalling the set functions and displaying errors\n";
	Food1.setName("Sandwiches");
	Food1.setStart(200);
	Food3.setSales(5, 105);
	Food3.setSales(-4, -105);

	// Final output
	Food1.setStart(90);
	Food1.setSales(0, 7);
	Food1.setSales(1, 8);
	Food1.setSales(2, 9);
	Food1.setSales(3, 10);
	Food1.setSales(4, 10);
	Food1.setSales(5, 5);
	Food1.setSales(6, 12);
	Food2.setName("Beverages");
	Food2.setStart(80);
	Food2.setSales(0, 10);
	Food2.setSales(1, 10);
	Food2.setSales(2, 12);
	Food2.setSales(3, 10);
	Food2.setSales(4, 12);
	Food2.setSales(5, 11);
	Food2.setSales(6, 12);
	Food3.setSales(0, 4);
	Food3.setSales(1, 6);
	Food3.setSales(2, 2);
	Food3.setSales(3, 3);
	Food3.setSales(4, 4);
	Food3.setSales(5, 7);
	Food3.setSales(6, 3);

	cout << "\nCalling the display function for each food item\n";
	Food1.display();
	Food2.display();
	Food3.display();

	// Show a good bye message
	cout << "\nThank you for using the program!\n";

	// end of program
	system("pause");
	return 0;
}