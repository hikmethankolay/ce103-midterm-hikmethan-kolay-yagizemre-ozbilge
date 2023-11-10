#include <iostream>
#include <string>
#include <fstream>
#include "../../farm_management_lib/include/farm_management_lib.h"

using namespace std;
fstream File;

int main() {
  int choice;

  do {
    // Show Main menu
    cout << "Main menu\n";
    cout << "1)Crop and livestock management\n";
    cout << "2)Harvesting and producing planning\n";
    cout << "3)Equipment and vehicle maintenance\n";
    cout << "4)Reporting\n";
    cout << "5)Exit\n";
    cout << "Make a choice(1 - 5): ";
    cin >> choice;

    switch (choice) {
      case 1: {
        cout << "Choice 1st option.\n";
        break;
      }

      case 2: {
        cout << "Choice 2st option.\n";
        break;
      }

      case 3: {
        cout << "Choice 3rd option.\n";
        break;
      }

      case 4: {
        cout << "Choice 4st option.\n";
        break;
      }

      case 5: {
        cout << "You are going to exit.\n";
        break;
      }

      default:
        cout << "Please try again.";
    }
  } while (choice != 5);

  return 0;
}
