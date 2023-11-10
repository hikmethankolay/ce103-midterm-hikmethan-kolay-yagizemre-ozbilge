#include <iostream>
#include <string>

#include "../../farm_management_lib/include/farm_management_lib.h"
using namespace std;

int main() {
  return 0;
	int choice;

	do {
	    // Show Main menu
		cout << "Main menu\n";
		cout << "1)Crop and livestock management\n";
		cout << "2)Harvesting and producing planning\n";
		cout << "3)Equipment and vehicle maintenance\n";
		cout << "4)Reporting\n";
		cout << "5)Exit\n";

		//Take your user's choice
		cout << "Make a choice(1 - 5): ";
		cin >> choice;

		//According to process in user's choice
		switch (choice) {
		    case 1:
				cout << "Choice 1st option.\n";
				// You add 1st choice codes.
				break;
			case 2:
				cout << "Choice 2st option.\n";
				// You add 2st choice codes.
				break;
			case 3:
				cout << "Choice 3st option.\n";
				// You add 3st choice codes.
				break;
			case 4:
				cout << "Choice 4st option.\n";
				// You add 4st choice codes.
				break;
			case 5:
				cout << "You are going to exit.\n";
				break;
			default:
				cout << "Useless option!Please try again.";
        }
	} while (choice != 5);


   return 0;
}
