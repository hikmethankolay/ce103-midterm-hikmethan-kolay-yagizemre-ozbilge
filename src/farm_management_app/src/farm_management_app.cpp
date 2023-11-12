#include <iostream>
#include <string>
#include <fstream>
#include "../../farm_management_lib/include/farm_management_lib.h"

using namespace std;
fstream File; // Assigns fstream class to a object named "File"

int main() {
  // choice variables for each switch used in this app
  int choice;
  int choice_a;
  int choice_b;
  int choice_c;
  int choice_d;
  bool app_running = true;

  do {
    // Prints main menu
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
choice1:
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
              cout << "\n--------------------------------------------------------------------------------------------\n";
              file_read("crop_records.txt"); // Prints crop records
              cout << "--------------------------------------------------------------------------------------------\n\n";
            } else if (record_kind_to_see == "Livestock") {
              cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
              file_read("livestock_records.txt"); //Prints livestockrecords
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto choice1;
            }

            break;
          }

          case 2: {
            string record;
            string record_kind_to_register;
            cout << "\nWhat kind of data do you want to enter? Livestock/Crop?: ";
            cin >> record_kind_to_register;

            if (record_kind_to_register == "Crop") {
              string crop_type;
              string crop_plant_date;
              string crop_harvest_date;
              string crop_field;
              string crop_exp_quantity;
              cout << "What kind of crop do you want to register?:";
              cin >> crop_type;
              cout << "What is the date of plant?(DD/MM/YYYY):";
              cin >> crop_plant_date;
              cout << "What is the planed date of harvest?(DD/MM/YYYY):";
              cin >> crop_harvest_date;
              cout << "How big is the planted area?(m2):";
              cin >> crop_field;
              cout << "What is the expected harvest quantity?(Kg);";
              cin >> crop_exp_quantity;
              record = "  " + crop_type + "   |    " + crop_plant_date + "    |     " + crop_harvest_date + "     |     " + crop_field + "m2" + "        |       " + crop_exp_quantity +
                       "Kg"; // sums all of the strings to one string
              File.open("crop_records.txt", ios::out | ios::in); // open file with both input and output tag

              if (File.is_open()) { //checks if file exist
                file_append("crop_records.txt", record); // appends data to file
                cout << "\nData succesfully recored\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("crop_records.txt", "CROP TYPE | DATE OF PLANTING | DATE OF HARVESTING | CULTIVATED FIELD | EXPECTED QUANTITY");
                file_append("crop_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                break;
              }
            } else if (record_kind_to_register == "Livestock") {
              string livestock_type;
              string livestock_ear_tag;
              string livestock_birth_date;
              string livestock_food;
              string livestock_weight;
              string livestock_death;
              cout << "What kind of livestock do you want to register?:";
              cin >> livestock_type;
eartag:
              cout << "What is the ear tag number?(AIN)(***-***-***-***-***):";
              cin >> livestock_ear_tag;

              if (size(livestock_ear_tag) != 19) { //checks if AIN number correct
                cout << "Please enter a correct form of ear tag number!\n";
                goto eartag; // Goes back to "cin >> livestock_ear_tag;" if input is not valid
              }

              cout << "What is the date of birth?(DD/MM/YYYY):";
              cin >> livestock_birth_date;
              cout << "What kind of food does it eat?:";
              cin >> livestock_food;
              cout << "How heavy is it?";
              cin >> livestock_weight;
              cout << "Is it alive?(Yes/No):";
              cin >> livestock_death;

              if (livestock_death == "No") { //checks is livestock dead, depending on on outcome it lefts blank death date and death cause
                string livestock_death_date;
                string livestock_death_cause;
                cout << "What is the date of death?(DD/MM/YYYY):";
                cin >> livestock_death_date;
                cout << "What is the cause of death?:";
                cin >> livestock_death_cause;
                record = "     " + livestock_type + "         |    " + livestock_ear_tag + "    |     " + livestock_birth_date + "    |     " + livestock_food + "      |   " + livestock_weight + "Kg" + "    |      "
                         + livestock_death + "     |     " + livestock_death_date + "    |       " + livestock_death_cause; // sums all of the strings to one string
              } else if (livestock_death == "Yes") {
                record = "     " + livestock_type + "         |    " + livestock_ear_tag + "    |     " + livestock_birth_date + "    |     " + livestock_food + "      |   " + livestock_weight + "Kg" + "    |      "
                         + livestock_death + "     |     " + "----------" + "    |       " + "----------"; // sums all of the strings to one string
              } else {
                cout << "Please sellect a correct option\n\n";
                goto choice1; // Goes back to "Crop and livestock management" menu if input is not valid
              }

              File.open("livestock_records.txt", ios::out | ios::in); // open file with both input and output tag

              if (File.is_open()) { //checks if file exist
                file_append("livestock_records.txt", record); // appends data to file
                cout << "\nData succesfully recored\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("livestock_records.txt", "LIVESTOCK TYPE   |      EAR TAG NUMBER       |   DATE OF BIRTH   |   GIVEN FOOD   |   WEIGHT   |   IS ALIVE   |   DATE OF DEATH   |   CAUSE OF DEATH");
                file_append("livestock_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto choice1; // Goes back to "Crop and livestock management" menu if input is not valid
            }
          }

          case 3: {
            int line_number_to_edit;
            string record_kind_to_edit;
            string new_record;
            cout << "Which kind of record do you want to edit?(Crop/Livestock):";
            cin >> record_kind_to_edit; // Asks which record to edit
            cout << "Which line do you want to edit?:";
            cin >> line_number_to_edit; // Ask which line number to edit

            if (record_kind_to_edit == "Crop") { // Takes new data and replaces it with old data in the specified line
              File.open("crop_records.txt", ios::out | ios::in);

              if (File.is_open()) {
                string crop_type;
                string crop_plant_date;
                string crop_harvest_date;
                string crop_field;
                string crop_exp_quantity;
                cout << "What kind of crop do you want to register?:";
                cin >> crop_type;
                cout << "What is the date of plant?(DD/MM/YYYY):";
                cin >> crop_plant_date;
                cout << "What is the planed date of harvest?(DD/MM/YYYY):";
                cin >> crop_harvest_date;
                cout << "How big is the planted are?(m2):";
                cin >> crop_field;
                cout << "What is the expected harvest quantity?(Kg);";
                cin >> crop_exp_quantity;
                new_record = "  " + crop_type + "   |    " + crop_plant_date + "    |     " + crop_harvest_date + "     |     " + crop_field + "m2" + "        |       " + crop_exp_quantity + "Kg";
                file_edit("crop_records.txt", line_number_to_edit, new_record);
                cout << "\nData succesfully edited\n\n";
                break;
              } else {
                cout << "There is no record to edit";
                break;
              }
            } else if (record_kind_to_edit == "Livestock") { // Takes new data and replaces it with old data in the specified line
              File.open("livestock_records.txt", ios::out | ios::in);

              if (File.is_open()) {
                string livestock_type;
                string livestock_ear_tag;
                string livestock_birth_date;
                string livestock_food;
                string livestock_weight;
                string livestock_death;
                cout << "What kind of livestock do you want to register?:";
                cin >> livestock_type;
eartag2:
                cout << "What is the ear tag number?(AIN)(***-***-***-***-***):";
                cin >> livestock_ear_tag;

                if (size(livestock_ear_tag) != 19) {
                  cout << "Please enter a correct form of ear tag number!\n";
                  goto eartag2;
                }

                cout << "What is the date of birth?(DD/MM/YYYY):";
                cin >> livestock_birth_date;
                cout << "What kind of food does it eat?:";
                cin >> livestock_food;
                cout << "How heavy is it?";
                cin >> livestock_weight;
                cout << "Is it alive?(Yes/No):";
                cin >> livestock_death;

                if (livestock_death == "No") {
                  string livestock_death_date;
                  string livestock_death_cause;
                  cout << "What is the date of death?(DD/MM/YYYY):";
                  cin >> livestock_death_date;
                  cout << "What is the cause of death?:";
                  cin >> livestock_death_cause;
                  new_record = "     " + livestock_type + "         |    " + livestock_ear_tag + "    |     " + livestock_birth_date + "    |     " + livestock_food + "      |   " + livestock_weight + "Kg" +
                               "    |      " + livestock_death + "     |     " + livestock_death_date + "    |       " + livestock_death_cause;
                } else if (livestock_death == "Yes") {
                  new_record = "     " + livestock_type + "         |    " + livestock_ear_tag + "    |     " + livestock_birth_date + "    |     " + livestock_food + "      |   " + livestock_weight + "Kg" +
                               "    |      " + livestock_death + "     |     " + "----------" + "    |       " + "----------";
                } else {
                  cout << "Please sellect a correct option\n\n";
                  goto choice1;
                }

                file_edit("livestock_records.txt", line_number_to_edit, new_record);
                cout << "\nData succesfully edited\n\n";
                break;
              } else {
                cout << "There is no record to edit";
                break;
              }
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto choice1;
            }
          }

          case 4: {
            int line_number_to_delete;
            string record_kind_to_delete;
            string line_or_record;
            cout << "Which kind of record do you want to delete?(Crop/Livestock):";
            cin >> record_kind_to_delete; //Asks which record type to delete from

            if (record_kind_to_delete == "Crop") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user goin to delte all data or just one specified line

              if (line_or_record == "All") {
                File.open("crop_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  file_write("crop_records.txt", "CROP TYPE | DATE OF PLANTING | DATE OF HARVESTING | CULTIVATED FIELD | EXPECTED QUANTITY"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("crop_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  cout << "Which line dou you want to delete?:";
                  cin >> line_number_to_delete; // Asks which line to delete
                  file_line_delete("crop_records.txt", line_number_to_delete); // Deletes specified line
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else {
                cout << "Please sellect a correct option\n\n";
                goto choice1;
              }
            } else if (record_kind_to_delete == "Livestock") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user goin to delte all data or just one specified line

              if (line_or_record == "All") {
                File.open("livestock_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  file_write("livestock_records.txt",
                             "LIVESTOCK TYPE   |      EAR TAG NUMBER       |   DATE OF BIRTH   |   GIVEN FOOD   |   WEIGHT   |   IS ALIVE   |   DATE OF DEATH   |   CAUSE OF DEATH"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("livestock_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  cout << "Which line dou you want to delete?:";
                  cin >> line_number_to_delete; // Asks which line to delete
                  file_line_delete("livestock_records.txt", line_number_to_delete); // Deletes specified line
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else {
                cout << "Please sellect a correct option\n\n";
                goto choice1;
              }
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto choice1;
            }
          }

          case 5: {
            break;
          }
        }

      case 2: {
        cout << "Choice 2st option.\n";
        break;
      }

      case 3: {
choice3:
        cout << "\n--------Equipment and vehicle maintenance--------\n";
        cout << "What operation do you want to do ? \n";
        cout << "1-)Show Records\n";
        cout << "2-)Register Record\n";
        cout << "3-)Update Record\n";
        cout << "4-)Delete Record\n",
             cout << "5-)Return previous menu\n",
             cout << "\nMake a choice(1 - 5): ";
        cin >> choice_c;

        switch (choice_c) {
          case 1: {
            string record_kind_to_see;
            cout << "\nWhich record do you want to see? Equipment/Vehicle?: ";
            cin >> record_kind_to_see;

            if (record_kind_to_see == "Equipment") {
              cout << "\n--------------------------------------------------------------------------------------------\n";
              file_read("Equipment_records.txt"); // Prints Equipment records
              cout << "--------------------------------------------------------------------------------------------\n\n";
            } else if (record_kind_to_see == "Vehicle") {
              cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
              file_read("Vehicle_records.txt"); //Prints Vehicle records
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto choice3;
            }

            break;
          }

          case 2: {
            string record;
            string record_kind_to_register;
            cout << "\nWhich one of the use prefer this data? Equipment/Vehicle?:";
            cin >> record_kind_to_register;

            if (record_kind_to_register == "Equipment") {
              string Equipment;
              string Equipment_type;
              string Equipment_received_date;
              string Equipment_sold_date;
              string Equipment_last_production_date;
              string Equipment_future_production_date;
              cout << "What kind of equipment do you want to use?:";
              cin >> Equipment_type;
              cout << "When is the equipment received?(DD/MM/YYYY):";
              cin >> Equipment_received_date;
              cout << "When is the equipment sold?(DD/MM/YYYY):";
              cin >> Equipment_sold_date;
              cout << "What is the equipment last production date?(DD/MM/YYYY):";
              cin >> Equipment_last_production_date;
              cout << "What is the equipment future production date?(DD/MM/YYYY):";
              cin >> Equipment_future_production_date;
              record = "  " + Equipment_type + "   |    " + Equipment_received_date + "    |     " + Equipment_sold_date + "     |     " + Equipment_last_production_date + "  | " + Equipment_future_production_date 
              File.open("equipment_records.txt", ios::out | ios::in); //open file and we will see input and output

              if (File.is_open()) {  //checks if file exist.
                file_append("equipment_records.txt", record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("equipment_records.txt", "EQUIPMENT TYPE | EQUIPMENT RECEIVED DATE | EQUIPMENT SOLD DATE | EQUIPMENT LAST PRODUCTION DATE | EQUIPMENT FUTURE PRODUCTION DATE |");
              }

              file_append("equipment_records.txt", record);
              cout << "\nDatas successfully record\n\n";
              break;
            } else if (record_kind_to_register == "Vehicle") {
              string vehicle_type;
              string vehicle_received_date;
              string vehicle_sold_date;
              string vehicle_last_production_date;
              string vehicle_future_production_date;
              cout << "What kind of vehicle do you want to use?";
              cin >> vehicle_type;
              cout << "What is the stages of vehicle maintenance?:";
              cin >> vehicle_received_date;
              cout << "How many do you use equipment?:";
              cin >> vehicle_sold_date;
              cout << "What material is the equipment made of?:";
              cin >> vehicle_last_production_date;
              cout << "What material is the equipment made of?:";
              cin >> vehicle_future_production_date;
              record = "  " + vehicle_type + "   |    " + vehicle_received_date + "    |     " + vehicle_sold_date + "     |     " + vehicle_last_production_date + " | " + vehicle_last_production_date;
              File.open("vehicle_records.txt", ios::in | ios::out);

              if (File.is_open()) {  //checks if file exist.
                file_append("Equipment_records.txt", record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("vehicle_records.txt", "VEHICLE TYPE | VEHICLE RECEÝVED SOLD DATE  | VEHICLE LAST SOLD DATE | VEHICLE LAST PRODUCTION DATE | VEHICLE FUTURE PRODUCTION DATE");
              }

              file_append("vehicle_records.txt", record);
              cout << "\nDatas successfully record\n\n";
              break;
            }

             }
          }
        }

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
    }
  } while (app_running);

  return 0;
}
