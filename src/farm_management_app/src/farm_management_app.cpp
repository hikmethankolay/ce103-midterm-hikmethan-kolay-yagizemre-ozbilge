#include <iostream>
#include <string>
#include <fstream>
#include "../../farm_management_lib/include/farm_management_lib.h"

using namespace std;
fstream File;

int main() {
  int choice;
  int choice_a;
  int choice_b;
  int choice_c;
  int choice_d;
  bool app_running = true;

  do {
    //Main menu
    cout << "-----------Main menu-----------\n";
    cout << "1)Crop and livestock management\n";
    cout << "2)Harvesting and producing planning\n";
    cout << "3)Equipment and vehicle maintenance\n";
    cout << "4)Reporting\n";
    cout << "5)Exit\n";
    cout << "Make a choice(1 - 5): ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "\n--------Crop and livestock management--------\n";
        cout << "What operation do you want to do ? \n";
        cout << "1-)Show Records\n";
        cout << "2-)Register Record\n";
        cout << "3-)Update Record\n";
        cout << "4-)Delete Record\n",
             cout << "5-)Return previous menu\n",
             cout << "\nMake a choice(1 - 5): ";
        cin >> choice_a;

        switch (choice_a) {
          case 1: {
            string record_kind_to_see;
            cout << "\nWhich record do you want to see? Livestock/Crop?: ";
            cin >> record_kind_to_see;

            if (record_kind_to_see == "Crop") {
              cout << "\n-----------------------------------------\n";
              file_read("crop_records.txt");
              cout << "-----------------------------------------\n\n";
            } else if (record_kind_to_see == "Livestock") {
              cout << "\n-----------------------------------------\n";
              file_read("livestock_records.txt");
              cout << "-----------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              continue;
            }

            break;
          }

          case 2: {
            string record;
            string record_kind_to_register;
            cout << "\nWhat kind of data do you want to enter? Livestock/Crop?: ";
            cin >> record_kind_to_register;

            if (record_kind_to_register == "Crop") {
              record = "Test";
              File.open("crop_records.txt", ios::out | ios::in);

              if (File.is_open()) {
                file_append("crop_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                break;
              } else {
                file_write("crop_records.txt", "CROP TYPE / DATE OF PLANTING / DATE OF HARVESTING / CULTIVATED FIELD / EXPECTED QUANTITY");
                file_append("crop_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                break;
              }
            } else if (record_kind_to_register == "Livestock") {
              record = "Test";
              File.open("livestock_records.txt", ios::out | ios::in);

              if (File.is_open()) {
                file_append("livestock_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                break;
              } else {
                file_write("livestock_records.txt", "LIVESTOCK TYPE / EAR TAG NUMBER / DATE OF BIRTH / DATE OF DEATH / CAUSE OF DEATH / GIVEN FEED ");
                file_append("livestock_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              continue;
            }
          }

          case 3: {
          }

          case 4: {
          }

          case 5: {
            break;
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
        app_running = false;
        break;
      }

      default:
        cout << "Please try again.";
    }
  } while (app_running);

  return 0;
}
