#include "../include/farm_management_lib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

fstream myFile;

void file_write(string file_name, string text) {
  myFile.open(file_name, ios::out); //Opens file with output tag

  if (myFile.is_open()) {
    myFile << "0-)" << text << "\n"; //Deletes everting insde file and inserts Text with "0-)" line number
    myFile.close();
  } else {
    cout << "File operation failed\n"; //trowhs error if fails
  }
}

void file_append(string file_name,string text) {
  myFile.open(file_name, ios::in);//Opens file with input tag
  string lastLine;
  string currentLine;

  if (myFile.is_open()) {
    while (getline(myFile, currentLine)) {
      lastLine = currentLine;  // Update lastLine for each line and finds actual last line
    }

    myFile.close();
  } else {
    cout << "File operation failed\n";
  }

  size_t pos = lastLine.find("-)"); // Finds location of "-)" inn last line
  int lineNumber = stoi(lastLine.substr(0, pos))+1; //Finds number for the appended line
  myFile.open(file_name, ios::app);//Opens file with append tag

  if (myFile.is_open()) {
    myFile << lineNumber << "-)"  << text << "\n"; //Appends text with its line number
    myFile.close();
  } else {
    cout << "File operation failed\n";
  }
}
string file_read(string file_name) {
  string stringForTest; //This is a variable for tests to run properly since function needs to retrun someting
  myFile.open(file_name, ios::in);//Opens file with input tag

  if (myFile.is_open()) {
    string line;

    while (getline(myFile, line)) { // Takes all line one by one and prints them to console
      cout << line << endl;
      stringForTest = stringForTest + line + "\n";
    }

    myFile.close();
  } else {
    cout << "File operation failed,There is no record\n";
  }

  return stringForTest; //This is a variable for tests to run since function needs to retrun someting for them to run properly
}

void file_edit(string file_name, int line_number_to_edit, string new_line) {
  myFile.open(file_name, ios::in);//Opens file with read tag

  if (myFile.is_open()) {
    vector<string> lines; // A vector to store lines
    string line;

    while (getline(myFile, line)) { // gets lines one by oone and assaign them to line variable
      lines.push_back(line); // ads line variable to lines vector
    }

    if (line_number_to_edit > 0 && line_number_to_edit+1 <= lines.size()) {
      lines[line_number_to_edit] = to_string(line_number_to_edit) + "-)" + new_line; // Changes a member of Lines vector to new line with its line number
    } else {
      cout << "You can only edit existing lines" << endl;
    }

    myFile.close();
    myFile.open(file_name, ios::out); // Opens file in write mode

    for (const string &updated_line : lines) { // writes every member of lines vector to file
      myFile << updated_line << '\n';
    }

    myFile.close();
  } else {
    cout << "File operation failed" << endl;
  }
}

void file_line_delete(string file_name, int line_number_to_delete) {
  myFile.open(file_name, ios::in);// Opens file in read mode

  if (myFile.is_open()) {
    vector<string> lines;// A vector to store lines
    string line;

    while (getline(myFile, line)) { // gets lines one by oone and assaign them to line variable
      lines.push_back(line); // ads line variable to lines vector
    }

    if (line_number_to_delete >= 0 && line_number_to_delete < lines.size()) {
      lines.erase(lines.begin() + line_number_to_delete); // Deletes a line from lines vector
    } else {
      cout << "You can only erase existing lines" << endl;
    }

    myFile.close();
    myFile.open(file_name, ios::out); // Opens file in write mode

    for (const string &updated_line : lines) {
      size_t pos = updated_line.find("-)"); // Finds postion of "-)"
      int lineNumber = stoi(updated_line.substr(0, pos)); // Finds each lines line number

      if (lineNumber > line_number_to_delete) { // decrase a lines line number if its bigger than deleted lines line number
        string updated_line_with_new_number = to_string(lineNumber - 1) + updated_line.substr(pos);
        myFile << updated_line_with_new_number << '\n';
      } else {
        myFile << updated_line << '\n';
      }
    }

    myFile.close();
  } else {
    cout << "File operation failed" << endl;
  }
}
