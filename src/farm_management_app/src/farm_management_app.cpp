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
choice1:
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
            goto mainmenu;
          }
          break;
        }

        break;
      }

      case 2: {
choice2:
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
              file_read("irrigation_records.txt"); //Prints irrigation records
              cout << "--------------------------------------------------------------------------------------------\n\n";
            } else {
              cout << "\nPlease sellect a correct option\n\n";
              goto choice2;
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
                goto choice2;
                break;
              } else { //if there is no file creates one print records table
                file_write("irrig_records.txt", "IRRIGATED CONTROLLED CROP | DATE OF IRRIGATION | DATE OF NEXT IRRIGATION | AREA");
                file_append("irrig_records.txt", record);
                cout << "\nData succesfully recored\n\n";
                goto choice2;
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto choice2; // Goes back to "Harvest and production planning" menu if input is not valid
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
                file_edit("pest_records.txt",line_number_to_edit, record);  // edit data of specified line
                cout << "\nData succesfully edited\n\n";
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
                cout << "\nData succesfully edited\n\n";
                break;
              } else {
                cout << "\nThere is no record to edit\n\n";
                break;
              }
            } else {
              cout << "Please sellect a correct option\n\n";
              goto choice2; // Goes back to "Harvest and production planning" menu if input is not valid
            }

            break;
          }

          case 4: {
            int line_number_to_delete;
            string record_kind_to_delete;
            string line_or_record;
            cout << "Which kind of record do you want to delete?(Pest/Irręgation):";
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
            } else if (record_kind_to_delete == "Irręgation") {
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
        cout << "Choice 2st option.\n";
        break;
      }

      case 4: {
        cout << "Choice 2st option.\n";
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
