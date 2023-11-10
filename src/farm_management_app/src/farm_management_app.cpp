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
      case 1:
        cout << "Crop and livestock management\nWhat operation do you want to do?\n";
        cout << "1-)Show Records\n";
        cout << "2-)Register Record\n";
        cout << "3-)Update Record\n";
        cout << "4-)Delete Record\n",
             cin >> choice;

        switch (choice) {
          case 1: {
            file_read("crop_livestock_record.txt");
            break;
          }

          case 2: {
            string record;
            string record_kind;
            cout << "What kind of record do you want to enter? Livestock/Crop?";
            cin >> record_kind;

            if (record_kind == "Crop") {
              File.open("crop_records.txt", ios::out | ios::in);
              record = "Test";

              if (File.is_open()) {
                file_append("crop_records.txt", record);
                break;
              } else {
                file_write("crop_records.txt", "CROP TYPE / PLANTING DATE / HARVEST DATE / CULTIVATION AREA");
                file_append("crop_records.txt", record);
                break;
              }
            } else if (record_kind == "Livestock") {
            }
          }

          case 3: {
          }

          case 4: {
          }
        }

        break;

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
