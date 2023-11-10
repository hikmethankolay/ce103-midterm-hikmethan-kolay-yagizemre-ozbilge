#include "../include/farm_management_lib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void file_write(string file_name, string text) {
  fstream myFile;
  myFile.open(file_name, ios::out);//Write

  if (myFile.is_open()) {
    myFile << "1-)" << text << "\n";
    myFile.close();
  } else {
    cout << "File operation failed";
  }
}

void file_append(string file_name,string text) {
  fstream myFile;
  myFile.open(file_name, ios::in);//Read
  string lastLine;
  string currentLine;

  if (myFile.is_open()) {
    while (getline(myFile, currentLine)) {
      lastLine = currentLine;  // Update lastLine for each line read
    }

    myFile.close();
  } else {
    cout << "File operation failed";
  }

  size_t pos = lastLine.find("-)");
  int lineNumber = stoi(lastLine.substr(0, pos))+1;
  myFile.open(file_name, ios::app);//Append

  if (myFile.is_open()) {
    myFile << lineNumber << "-)"  << text << "\n";
    myFile.close();
  } else {
    cout << "File operation failed";
  }
}
void file_read(string filename) {
  fstream myFile;
  myFile.open(filename, ios::in);//Read

  if (myFile.is_open()) {
    string line;

    while (getline(myFile, line)) {
      cout << line << endl;
    }

    myFile.close();
  } else {
    cout << "File operation failed";
  }
}

void file_edit(string file_name, int line_number_to_edit, string new_line) {
  fstream myFile;
  myFile.open(file_name, ios::in);//Read

  if (myFile.is_open()) {
    vector<string> lines;
    string line;

    while (getline(myFile, line)) {
      lines.push_back(line);
    }

    if (line_number_to_edit >= 0 && line_number_to_edit < lines.size()) {
      lines[line_number_to_edit] = to_string(line_number_to_edit+1) + "-)" + new_line;
    } else {
      cout << "You can only edit existing lines" << endl;
    }

    myFile.close(); // Close the file before reopening
    myFile.open(file_name, ios::out); // Open in write mode

    for (const string &updated_line : lines) {
      myFile << updated_line << '\n';
    }

    myFile.close();
  } else {
    cout << "File operation failed" << endl;
  }
}
