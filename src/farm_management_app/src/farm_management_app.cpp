#include <iostream>
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
mainmenu:
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
      case 1: {
        cout << "\n--------Crop and livestock management--------\n";
        cout << "What operation do you want to do ? \n";
        cout << "1-)Show Records\n";
        cout << "2-)Register Record\n";
        cout << "3-)Update Record\n";
        cout << "4-)Delete Record\n";
        cout << "5-)Return previous menu\n";
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
              break;
            } else if (record_kind_to_see == "Livestock") {
              cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
              file_read("livestock_records.txt"); //Prints livestock records
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto mainmenu;
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

              if (livestock_ear_tag.size() != 19) { //checks if AIN number correct
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
                goto mainmenu; // Goes back to "Crop and livestock management" menu if input is not valid
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
              goto mainmenu; // Goes back to "Crop and livestock management" menu if input is not valid
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

                if (livestock_ear_tag.size() != 19) {
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
                  goto mainmenu;
                }

                file_edit("livestock_records.txt", line_number_to_edit, new_record);
                break;
              } else {
                cout << "There is no record to edit";
                break;
              }
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto mainmenu;
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
                goto mainmenu;
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
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else {
                cout << "Please sellect a correct option\n\n";
                goto mainmenu;
              }
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto mainmenu;
            }
          }

          case 5: {
            goto mainmenu;
          }
          break;
        }

        break;
      }

      case 2: {
        cout << "\n--------Harvest and production planning--------\n";
        cout << "What operation do you want to do ? \n";
        cout << "1-)Show Records\n";
        cout << "2-)Register Record\n";
        cout << "3-)Update Record\n";
        cout << "4-)Delete Record\n";
        cout << "5-)Return previous menu\n";
        cout << "\nMake a choice(1 - 6): ";
        cin >> choice_b;

        switch (choice_b) {
          case 1: {
            string record_kind_to_see;
            cout << "\nWhich record do you want to see? Pest/Irrigation?: ";
            cin >> record_kind_to_see;

            if (record_kind_to_see == "Pest") {
              cout << "\n--------------------------------------------------------------------------------------------\n";
              file_read("pest_records.txt"); // Prints pest control records
              cout << "--------------------------------------------------------------------------------------------\n\n";
            } else if (record_kind_to_see == "Irrigation") {
              cout << "\n-------------------------------------------------------------------------------------------\n";
              file_read("irrig_records.txt"); //Prints irrigation records
              cout << "--------------------------------------------------------------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto mainmenu;
            }

            break;
          }

          case 2: {
            string record;
            string record_kind_to_register;
            cout << "\nWhat kind of data do you want to enter? Pest/Irrigation?: ";
            cin >> record_kind_to_register;

            if (record_kind_to_register == "Pest") {
              string pest_kind;
              string pest_crop;
              string pest_date;
              string pest_next_date;
              string pest_area;
              cout << "What kind of pest control did you apply?:";
              cin >> pest_kind;
              cout << "To what crop did you apply this pest control?";
              cin >> pest_crop;
              cout << "What is the date of pest control?(DD/MM/YYYY):";
              cin >> pest_date;
              cout << "What is the planed date of next pest control?(DD/MM/YYYY):";
              cin >> pest_next_date;
              cout << "How big is the area pest control applied?:";
              cin >> pest_area;
              record = "  " + pest_kind + "   |    " + pest_crop + "    |     " + pest_date + "     |     " + pest_next_date + "        |       " + pest_area + "m2"; // sums all of the strings to one string
              File.open("pest_records.txt", ios::out | ios::in); // open file with both input and output tag

              if (File.is_open()) { //checks if file exist
                file_append("pest_records.txt", record); // appends data to file
                cout << "\nData succesfully recored\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("pest_records.txt", "PEST TYPE | PEST CONTROLLED CROP | DATE OF PEST CONTROL | DATE OF NEXT PEST CONTROL | AREA");
                file_append("pest_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                break;
              }
            } else if (record_kind_to_register == "Irrigation") {
              string irrig_crop;
              string irrig_date;
              string irrig_next_date;
              string irrig_area;
              cout << "Which crop did you irrigate ?:";
              cin >> irrig_crop;
              cout << "What is the date of irrigation ?(DD/MM/YYYY):";
              cin >> irrig_date;
              cout << "What is the planed date of next irrigation?(DD/MM/YYYY):";
              cin >> irrig_next_date;
              cout << "How big is the irrigated area?:";
              cin >> irrig_area;
              record = "  " + irrig_crop + "    |     " + irrig_date + "     |     " + irrig_next_date + "        |       " + irrig_area + "m2"; // sums all of the strings to one string
              File.open("irrig_records.txt", ios::out | ios::in); // open file with both input and output tag

              if (File.is_open()) { //checks if file exist
                file_append("irrig_records.txt", record); // appends data to file
                cout << "\nData succesfully recored\n\n";
                goto mainmenu;
                break;
              } else { //if there is no file creates one print records table
                file_write("irrig_records.txt", "IRRIGATED CONTROLLED CROP | DATE OF IRRIGATION | DATE OF NEXT IRRIGATION | AREA");
                file_append("irrig_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                goto mainmenu;
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto mainmenu; // Goes back to "Harvest and production planning" menu if input is not valid
            }

            break;
          }

          case 3: {
            string record;
            string record_kind_to_edit;
            int line_number_to_edit;
            cout << "\nWhat kind of data do you want to edit? Pest/Irrigation?: ";
            cin >> record_kind_to_edit;
            cout << "Which line do you wish to edit?";
            cin >> line_number_to_edit;

            if (record_kind_to_edit == "Pest") {
              string pest_kind;
              string pest_crop;
              string pest_date;
              string pest_next_date;
              string pest_area;
              cout << "What kind of pest control did you apply?:";
              cin >> pest_kind;
              cout << "To what crop did you apply this pest control?";
              cin >> pest_crop;
              cout << "What is the date of pest control?(DD/MM/YYYY):";
              cin >> pest_date;
              cout << "What is the planed date of next pest control?(DD/MM/YYYY):";
              cin >> pest_next_date;
              cout << "How big is the area pest control applied?:";
              cin >> pest_area;
              record = "  " + pest_kind + "   |    " + pest_crop + "    |     " + pest_date + "     |     " + pest_next_date + "        |       " + pest_area + "m2"; // sums all of the strings to one string
              File.open("pest_records.txt", ios::out | ios::in); // open file with both input and output tag

              if (File.is_open()) { //checks if file exist
                file_edit("pest_records.txt", line_number_to_edit, record);  // edit data of specified line
                break;
              } else {
                cout << "\nThere is no record to edit\n\n";
                break;
              }
            } else if (record_kind_to_edit == "Irrigation") {
              string irrig_crop;
              string irrig_date;
              string irrig_next_date;
              string irrig_area;
              cout << "Which crop did you irrigate ?:";
              cin >> irrig_crop;
              cout << "What is the date of irrigation ?(DD/MM/YYYY):";
              cin >> irrig_date;
              cout << "What is the planed date of next irrigation?(DD/MM/YYYY):";
              cin >> irrig_next_date;
              cout << "How big is the irrigated area?:";
              cin >> irrig_area;
              record = "  " + irrig_crop + "    |     " + irrig_date + "     |     " + irrig_next_date + "        |       " + irrig_area + "m2"; // sums all of the strings to one string
              File.open("irrig_records.txt", ios::out | ios::in); // open file with both input and output tag

              if (File.is_open()) { //checks if file exist
                file_edit("irrig_records.txt", line_number_to_edit, record); // edit data of specified line
                break;
              } else {
                cout << "\nThere is no record to edit\n\n";
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto mainmenu; // Goes back to "Harvest and production planning" menu if input is not valid
            }

            break;
          }

          case 4: {
            int line_number_to_delete;
            string record_kind_to_delete;
            string line_or_record;
            cout << "Which kind of record do you want to delete?(Pest/Irr�gation):";
            cin >> record_kind_to_delete; //Asks which record type to delete from

            if (record_kind_to_delete == "Pest") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user goin to delte all data or just one specified line

              if (line_or_record == "All") {
                File.open("pest_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  file_write("pest_records.txt", "PEST TYPE | PEST CONTROLLED CROP | DATE OF PEST CONTROL | DATE OF NEXT PEST CONTROL | AREA"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("pest_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  cout << "Which line dou you want to delete?:";
                  cin >> line_number_to_delete; // Asks which line to delete
                  file_line_delete("pest_records.txt", line_number_to_delete); // Deletes specified line
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else {
                cout << "Please sellect a correct option\n\n";
                goto mainmenu;
              }
            } else if (record_kind_to_delete == "Irr�gation") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user goin to delte all data or just one specified line

              if (line_or_record == "All") {
                File.open("irrig_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  file_write("irrig_records.txt",
                             "IRRIGATED CONTROLLED CROP | DATE OF IRRIGATION | DATE OF NEXT IRRIGATION | AREA"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("irrig_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  File.close();
                  cout << "Which line dou you want to delete?:";
                  cin >> line_number_to_delete; // Asks which line to delete
                  file_line_delete("irrig_records.txt", line_number_to_delete); // Deletes specified line
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else {
                cout << "Please sellect a correct option\n\n";
                goto mainmenu;
              }
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto mainmenu;
            }

            break;
          }

          case 5: {
            goto mainmenu;
          }
          break;
        }

        break;
      }

      case 3: {
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
              file_read("equipment_records.txt"); // Prints Equipment records
              cout << "--------------------------------------------------------------------------------------------\n\n";
            } else if (record_kind_to_see == "Vehicle") {
              cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
              file_read("vehicle_records.txt"); //Prints Vehicle records
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto mainmenu;
            }

            break;
          }

          case 2: {
            string record;
            string record_kind_to_register;
            cout << "\nWhat kind of data you want to register? Equipment/Vehicle?:";
            cin >> record_kind_to_register;

            if (record_kind_to_register == "Equipment") {
              string Equipment_type;
              string Equipment_model;
              string Equipment_bought_date;
              string Equipment_last_maintenanace_date;
              string Equipment_next_maintenanace_date;
              cout << "What kind of equipment do you want to register?:";
              cin >> Equipment_type;
              cout << "What is the model of equipment?:";
              cin >> Equipment_model;
              cout << "When is the equipment bought?(DD/MM/YYYY):";
              cin >> Equipment_bought_date;
              cout << "What is the equipment last maintenance date?(DD/MM/YYYY):";
              cin >> Equipment_last_maintenanace_date;
              cout << "What is the equipment future maintenance date?(DD/MM/YYYY):";
              cin >> Equipment_next_maintenanace_date;
              record = "  " + Equipment_type + "   |    " + Equipment_model + "   |    " + Equipment_bought_date + "    |     " + Equipment_last_maintenanace_date + "  | " + Equipment_next_maintenanace_date;
              File.open("equipment_records.txt", ios::out | ios::in); //open file and we will see input and output

              if (File.is_open()) {  //checks if file exist.
                file_append("equipment_records.txt", record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("equipment_records.txt", "EQUIPMENT TYPE | EQUIPMENT MODEL | EQUIPMENT BOUGHT DATE | EQUIPMENT LAST MAINTENANCE DATE | EQUIPMENT NEXT MAINTENANCE DATE");
                file_append("equipment_records.txt", record);
                cout << "\nDatas successfully record\n\n";
                break;
              }
            } else if (record_kind_to_register == "Vehicle") {
              string Vehicle_type;
              string Vehicle_model;
              string Vehicle_bought_date;
              string Vehicle_last_maintenanace_date;
              string Vehicle_next_maintenanace_date;
              cout << "What kind of equipment do you want to register?:";
              cin >> Vehicle_type;
              cout << "What is the model of equipment?:";
              cin >> Vehicle_model;
              cout << "When is the equipment bought?(DD/MM/YYYY):";
              cin >> Vehicle_bought_date;
              cout << "What is the equipment last production date?(DD/MM/YYYY):";
              cin >> Vehicle_last_maintenanace_date;
              cout << "What is the equipment future production date?(DD/MM/YYYY):";
              cin >> Vehicle_next_maintenanace_date;
              record = "  " + Vehicle_type + "   |    " + Vehicle_model + "    |     " + Vehicle_bought_date + "     |     " + Vehicle_last_maintenanace_date + " | " + Vehicle_next_maintenanace_date;
              File.open("vehicle_records.txt", ios::in | ios::out);

              if (File.is_open()) {  //checks if file exist.
                file_append("equipment_records.txt", record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("vehicle_records.txt", "VEHICLE TYPE | VEHICLE MODEL | VEHICLE BOUGHT DATE | VEHICLE LAST MAINTENANCE DATE | VEHICLE NEXT MAINTENANCE DATE");
                file_append("vehicle_records.txt", record);
                cout << "\nDatas successfully record\n\n";
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto mainmenu; // Goes back to "Equipment and vehicle maintenance" menu if input is not valid
            }
          }

          case 3: {
            string record;
            string record_kind_to_edit;
            int record_line_number_to_edit;
            cout << "\nWhat kind of data you want to register? Equipment/Vehicle?:";
            cin >> record_kind_to_edit;
            cout << "\nWhich line do you want to edit?:";
            cin >> record_line_number_to_edit;

            if (record_kind_to_edit == "Equipment") {
              string Equipment_type;
              string Equipment_model;
              string Equipment_bought_date;
              string Equipment_last_maintenanace_date;
              string Equipment_next_maintenanace_date;
              cout << "What kind of equipment do you want to register?:";
              cin >> Equipment_type;
              cout << "What is the model of equipment?:";
              cin >> Equipment_model;
              cout << "When is the equipment bought?(DD/MM/YYYY):";
              cin >> Equipment_bought_date;
              cout << "What is the equipment last production date?(DD/MM/YYYY):";
              cin >> Equipment_last_maintenanace_date;
              cout << "What is the equipment future production date?(DD/MM/YYYY):";
              cin >> Equipment_next_maintenanace_date;
              record = "  " + Equipment_type + "   |    " + Equipment_model + "   |    " + Equipment_bought_date + "    |     " + Equipment_last_maintenanace_date + "  | " + Equipment_next_maintenanace_date;
              File.open("equipment_records.txt", ios::out | ios::in); //open file and we will see input and output

              if (File.is_open()) {  //checks if file exist.
                file_edit("equipment_records.txt", record_line_number_to_edit, record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                cout << "\nThere is no data to edit.\n\n";
                break;
              }
            } else if (record_kind_to_edit == "Vehicle") {
              string Vehicle_type;
              string Vehicle_model;
              string Vehicle_bought_date;
              string Vehicle_last_maintenanace_date;
              string Vehicle_next_maintenanace_date;
              cout << "What kind of equipment do you want to register?:";
              cin >> Vehicle_type;
              cout << "What is the model of equipment?:";
              cin >> Vehicle_model;
              cout << "When is the equipment bought?(DD/MM/YYYY):";
              cin >> Vehicle_bought_date;
              cout << "What is the equipment last production date?(DD/MM/YYYY):";
              cin >> Vehicle_last_maintenanace_date;
              cout << "What is the equipment future production date?(DD/MM/YYYY):";
              cin >> Vehicle_next_maintenanace_date;
              record = "  " + Vehicle_type + "   |    " + Vehicle_model + "    |     " + Vehicle_bought_date + "     |     " + Vehicle_last_maintenanace_date + " | " + Vehicle_next_maintenanace_date;
              File.open("vehicle_records.txt", ios::in | ios::out);

              if (File.is_open()) {  //checks if file exist.
                file_edit("equipment_records.txt", record_line_number_to_edit, record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                cout << "\nThere is no data to edit.\n\n";
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto mainmenu; // Goes back to "Equipment and vehicle maintenance" menu if input is not valid
            }
          }

          case 4: {
            int line_number_to_delete;
            string record_kind_to_delete;
            string line_or_record;
            cout << "Which kind of record do you want to delete?(Equipment/Vehicle):";
            cin >> record_kind_to_delete; // Asks which record to delete

            if (record_kind_to_delete == "Equipment") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user going to delete all data or just one specified line

              if (line_or_record == "All") {
                File.open("equipment_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  file_write("equipment_records.txt",
                             "EQUIPMENT TYPE | EQUIPMENT MODEL | EQUIPMENT BOUGHT DATE | EQUIPMENT LAST MAINTENANCE DATE | EQUIPMENT NEXT MAINTENANCE DATE|"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("equipment_records.txt", ios::out | ios::in);

                if (File.is_open()) {  //checks if file exist
                  cout << "Which line do you want to delete?";
                  cin >> line_number_to_delete;  //Ask which line to delete
                  file_line_delete("vehicle_records.txt", line_number_to_delete); //Deletes specified line
                  break;
                } else {
                  cout << "There is no record to delete;";  //if there is no file throws error.
                  break;
                }
              } else {
                cout << "Please select a  correct option\n\n";
                goto mainmenu;
              }
            } else if (record_kind_to_delete == "Vehicle") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user goin to delte all data or just one specified line

              if (line_or_record == "All") {
                File.open("vehicle_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  file_write("vehicle_records.txt",
                             "VEHICLE TYPE | VEHICLE MODEL | VEHICLE BOUGHT DATE | VEHICLE LAST MAINTENANCE DATE | VEHICLE NEXT MAINTENANCE DATE"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("vehicle_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  cout << "Which line do you want to delete?";
                  cin >> line_number_to_delete;  //Ask which line to delete
                  file_line_delete("vehicle_records.txt", line_number_to_delete); //Deletes specified line
                  break;
                } else {
                  cout << "There is no record to delete";
                  break;
                }
              } else {
                cout << "Please sellect a correct option\n\n";
                goto mainmenu;
              }

              break;
            }
          }

          case 5: {
            goto mainmenu;
          }
          break;
        }

        break;
      }

      case 4: {
        cout << "\n--------Reporting--------\n";
        cout << "What operation do you want to do ? \n";
        cout << "1-)Show Records\n";
        cout << "2-)Register Record\n";
        cout << "3-)Update Record\n";
        cout << "4-)Delete Record\n";
        cout << "5-)Return previous menu\n";
        cout << "\nMake a choice(1 - 5): ";
        cin >> choice_d;

        switch (choice_d) {
          case 1: {
            string record_kind_to_see;
            cout << "\nWhich record do you want to see? Crop yields/Profit/Livestock health?: ";
            cin >> record_kind_to_see;

            if (record_kind_to_see == "Crop yields") {
              cout << "\n--------------------------------------------------------------------------------------------\n";
              file_read("crop_yields_records.txt"); // Prints Crop yields records
              cout << "--------------------------------------------------------------------------------------------\n\n";
            } else if (record_kind_to_see == "Profit") {
              cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
              file_read("farm_profitability_records.txt"); //Prints Farm profitability records
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
            } else if (record_kind_to_see == "Livestock health") {
              cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
              file_read("livestock_health_records.txt"); //Prints Farm profitability records
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto mainmenu;
            }

            break;
          }

          case 2: {
            string record;
            string record_kind_to_register;
            cout << "\nWhat kind of data you want to register? Crop yields/Profit/Livestock health?:";
            cin >> record_kind_to_register;

            if (record_kind_to_register == "Crop yields") {
              int Crop_yield_sample_size;
              int Crop_collected_area_size;
              int actual_field_size;
              int expected_harvest;
              cout << "How much collected sample?(Kg):";
              cin >> Crop_yield_sample_size;
              cout << "What is the size of the area where the crops are collected?(m2):";
              cin >> Crop_collected_area_size;
              cout << "What is the actual size of field?(m2)";
              cin >> actual_field_size;
              expected_harvest = (Crop_yield_sample_size / Crop_collected_area_size) * actual_field_size;
              record = "  " + to_string(Crop_yield_sample_size) + "Kg" + "   |    " + to_string(Crop_collected_area_size) + "m2" + "   |    " + to_string(actual_field_size) + "m2" + "    |     " + to_string(
                         expected_harvest) + "Kg";
              File.open("crop_yields_records.txt", ios::out | ios::in); //open file and we will see input and output

              if (File.is_open()) {  //checks if file exist.
                file_append("crop_yields_records.txt", record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("crop_yields_records.txt", "CROP SAMPLE SIZE | AREA SAMPLE SIZE | ACTUAL AREA | EXPECTED HARVEST");
                file_append("crop_yields_records.txt", record);
                cout << "\nDatas successfully record\n\n";
                break;
              }
            } else if (record_kind_to_register == "Profit") {
              string Farm_plant_type;
              int Farm_cost;
              int Farm_income;
              int Farm_profitability;
              cout << "What kind of farm plant do you want to register?:";
              cin >> Farm_plant_type;
              cout << "What is the cost?:";
              cin >> Farm_cost;
              cout << "How much money you will gain after selling this crop?($):";
              cin >> Farm_income;
              Farm_profitability = Farm_income - Farm_cost;
              record = "  " + Farm_plant_type + "   |    " + to_string(Farm_cost) + "    |     " + to_string(Farm_income) + "     |     " + to_string(Farm_profitability);
              File.open("profit_records.txt", ios::in | ios::out);

              if (File.is_open()) {  //checks if file exist.
                file_append("profit_records.txt", record); //appends to data file
                cout << "\nData succesfully recored\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("profit_records.txt", "FARM PLANT TYPE | FARM COST | FARM AMOUNT MONEY | FARM PROFITABILITY");
                file_append("profit_records.txt", record);
                cout << "\nDatas successfully recorded\n\n";
                break;
              }
            } else if (record_kind_to_register == "Livestock health") {
              string livestock_type;
              string livestock_ear_tag;
              string livestock_known_ilness;
              string livestock_last_vet_check;
              string livestock_nex_vet_check;
              cout << "What type is the livestock?";
              cin >> livestock_type;
eartag3:
              cout << "what is the eartag(AIN)(***-***-***-***-***)";
              cin >> livestock_ear_tag;

              if (livestock_ear_tag.size() != 19) { //checks if AIN number correct
                cout << "Please enter a correct form of ear tag number!\n";
                goto eartag3; // Goes back to "cin >> livestock_ear_tag;" if input is not valid
              }

              cout << "Does it have known ilnes?";
              cin >> livestock_known_ilness;
              cout << "when was the last vet check?(DD/MM/YYYY)";
              cin >> livestock_last_vet_check;
              cout << "when is the next vet check?(DD/MM/YYYY)";
              cin >> livestock_nex_vet_check;
              record = "  " + livestock_type + "   |    " + livestock_ear_tag + "    |     " + livestock_known_ilness + "     |     " + livestock_last_vet_check + "     |     " + livestock_nex_vet_check;
              File.open("livestock_health_records.txt", ios::in | ios::out);

              if (File.is_open()) {  //checks if file exist.
                file_append("livestock_health_records.txt", record); //appends to data file
                cout << "\nData succesfully recored\n\n";
                break;
              } else { //if there is no file creates one print records table
                file_write("livestock_health_records.txt", "LIVESTOCK TYPE | EAR TAG | KNOWN ILNESS | LAST VET CHECK | NEXT VET CHECK");
                file_append("livestock_health_records.txt", record);
                cout << "\nDatas successfully recorded\n\n";
                break;
              }

              break;
            } else {
              cout << "Please sellect a correct option\n\n";
              goto mainmenu; // Goes back to "Equipment and vehicle maintenance" menu if input is not valid
            }
          }

          case 3: {
            string record;
            string record_kind_to_edit;
            int record_line_number_to_edit;
            cout << "\nWhat kind of data you want to register? Crop yields/Profit/Livestock health?:";
            cin >> record_kind_to_edit;
            cout << "\nWhich line do you want to edit?:";
            cin >> record_line_number_to_edit;

            if (record_kind_to_edit == "Crop yields") {
              int Crop_yield_sample_size;
              int Crop_collected_area_size;
              int actual_field_size;
              int expected_harvest;
              cout << "How much collected sample?(Kg):";
              cin >> Crop_yield_sample_size;
              cout << "What is the size of the area where the crops are collected?(m2):";
              cin >> Crop_collected_area_size;
              cout << "What is the actual size of field?(m2)";
              cin >> actual_field_size;
              expected_harvest = (Crop_yield_sample_size / Crop_collected_area_size) * actual_field_size;
              record = "  " + to_string(Crop_yield_sample_size) + "Kg" + "   |    " + to_string(Crop_collected_area_size) + "m2" + "   |    " + to_string(actual_field_size) + "m2" + "    |     " + to_string(
                         expected_harvest) + "Kg";
              File.open("crop_yields_records.txt", ios::out | ios::in); //open file and we will see input and output

              if (File.is_open()) {  //checks if file exist.
                file_edit("livestock_health_records.txt", record_line_number_to_edit, record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                cout << "\nThere is no data to edit.\n\n";
                break;
              }
            } else if (record_kind_to_edit == "Profit") {
              string Farm_plant_type;
              int Farm_cost;
              int Farm_income;
              int Farm_profitability;
              cout << "What kind of farm plant do you want to register?:";
              cin >> Farm_plant_type;
              cout << "What is the cost?:";
              cin >> Farm_cost;
              cout << "How much money you will gain after selling this crop?($):";
              cin >> Farm_income;
              Farm_profitability = Farm_income - Farm_cost;
              record = "  " + Farm_plant_type + "   |    " + to_string(Farm_cost) + "    |     " + to_string(Farm_income) + "     |     " + to_string(Farm_profitability);
              File.open("profit_records.txt", ios::in | ios::out);

              if (File.is_open()) {  //checks if file exist.
                file_edit("livestock_health_records.txt", record_line_number_to_edit, record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                cout << "\nThere is no data to edit.\n\n";
                break;
              }
            } else if (record_kind_to_edit == "Livestock health") {
              string livestock_type;
              string livestock_ear_tag;
              string livestock_known_ilness;
              string livestock_last_vet_check;
              string livestock_nex_vet_check;
              cout << "What type is the livestock?";
              cin >> livestock_type;
eartag4:
              cout << "what is the eartag(AIN)(***-***-***-***-***)";
              cin >> livestock_ear_tag;

              if (livestock_ear_tag.size() != 19) { //checks if AIN number correct
                cout << "Please enter a correct form of ear tag number!\n";
                goto eartag4; // Goes back to "cin >> livestock_ear_tag;" if input is not valid
              }

              cout << "Does it have known ilnes?";
              cin >> livestock_known_ilness;
              cout << "when was the last vet check?(DD/MM/YYYY)";
              cin >> livestock_last_vet_check;
              cout << "when is the next vet check?(DD/MM/YYYY)";
              cin >> livestock_nex_vet_check;
              record = "  " + livestock_type + "   |    " + livestock_ear_tag + "    |     " + livestock_known_ilness + "     |     " + livestock_last_vet_check + "     |     " + livestock_nex_vet_check;
              File.open("livestock_health_records.txt", ios::in | ios::out);

              if (File.is_open()) {  //checks if file exist.
                file_edit("livestock_health_records.txt", record_line_number_to_edit, record); //appends to data file
                cout << "\nData is accomplished\n\n";
                break;
              } else { //if there is no file creates one print records table
                cout << "\nThere is no data to edit.\n\n";
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto mainmenu;
            }
          }

          case 4: {
            int line_number_to_delete;
            string record_kind_to_delete;
            string line_or_record;
            cout << "Which kind of record do you want to delete? Crop yields/Profit/Livestock health?:";
            cin >> record_kind_to_delete; // Asks which record to delete

            if (record_kind_to_delete == "Crop yields") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user going to delete all data or just one specified line

              if (line_or_record == "All") {
                File.open("crop_yields_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  file_write("crop_yields_records.txt",
                             "CROP SAMPLE SIZE | AREA SAMPLE SIZE | ACTUAL AREA | EXPECTED HARVEST"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("crop_yields_records.txt", ios::out | ios::in);

                if (File.is_open()) {  //checks if file exist
                  cout << "Which line do you want to delete?";
                  cin >> line_number_to_delete;  //Ask which line to delete
                  file_line_delete("farm_records.txt", line_number_to_delete); //Deletes specified line
                  break;
                } else {
                  cout << "There is no record to delete;";  //if there is no file throws error.
                  break;
                }
              } else {
                cout << "Please select a  correct option\n\n";
                goto mainmenu;
              }
            } else if (record_kind_to_delete == "Profit") {
              cout << "Do you want to delete all records or just a single one?(All/Single):";
              cin >> line_or_record; // Asks if user goin to delte all data or just one specified line

              if (line_or_record == "All") {
                File.open("profit_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  file_write("profit_records.txt",
                             "FARM PLANT TYPE | FARM COST | FARM AMOUNT MONEY | FARM PROFITABILITY"); //Rewrite all file from scratch
                  cout << "\nData succesfully deleted\n\n";
                  break;
                } else {
                  cout << "There is no record to delete"; //if there is no file throws error
                  break;
                }
              } else if (line_or_record == "Single") {
                File.open("profit_records.txt", ios::out | ios::in);

                if (File.is_open()) { //checks if file exist
                  cout << "Which line do you want to delete?";
                  cin >> line_number_to_delete;  //Ask which line to delete
                  file_line_delete("profit_records.txt", line_number_to_delete); //Deletes specified line
                  break;
                } else {
                  cout << "There is no record to delete";
                  break;
                }
              } else if (record_kind_to_delete == "Livestock health") {
                cout << "Do you want to delete all records or just a single one?(All/Single):";
                cin >> line_or_record; // Asks if user goin to delte all data or just one specified line

                if (line_or_record == "All") {
                  File.open("livestock_health_records.txt", ios::out | ios::in);

                  if (File.is_open()) { //checks if file exist
                    file_write("livestock_health_records.txt",
                               "LIVESTOCK TYPE | EAR TAG | KNOWN ILNESS | LAST VET CHECK | NEXT VET CHECK | "); //Rewrite all file from scratch
                    cout << "\nData succesfully deleted\n\n";
                    break;
                  } else {
                    cout << "There is no record to delete"; //if there is no file throws error
                    break;
                  }
                } else if (line_or_record == "Single") {
                  File.open("livestock_health_records.txt", ios::out | ios::in);

                  if (File.is_open()) { //checks if file exist
                    cout << "Which line do you want to delete?";
                    cin >> line_number_to_delete;  //Ask which line to delete
                    file_line_delete("livestock_health_records.txt", line_number_to_delete); //Deletes specified line
                    break;
                  } else {
                    cout << "There is no record to delete";
                    break;
                  }
                }
              } else {
                cout << "Please sellect a correct option\n\n";
                goto mainmenu;
              }

              break;
            }
          }

          case 5: {
            goto mainmenu;
          }
          break;
        }

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
