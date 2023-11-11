#include "../include/farm_management_lib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

fstream myFile;

void file_write(string file_name, string text) {
  myFile.open(file_name, ios::out);

  if (myFile.is_open()) {
    myFile << "0-)" << text << "\n";
    myFile.close();
  } else {
    cout << "File operation failed\n";
  }
}

void file_append(string file_name,string text) {
  myFile.open(file_name, ios::in);//Read
  string lastLine;
  string currentLine;

  if (myFile.is_open()) {
    while (getline(myFile, currentLine)) {
      lastLine = currentLine;  // Update lastLine for each line read
    }

    myFile.close();
  } else {
    cout << "File operation failed\n";
  }

  size_t pos = lastLine.find("-)");
  int lineNumber = stoi(lastLine.substr(0, pos))+1;
  myFile.open(file_name, ios::app);//Append

  if (myFile.is_open()) {
    myFile << lineNumber << "-)"  << text << "\n";
    myFile.close();
  } else {
    cout << "File operation failed\n";
  }
}
void file_read(string filename) {
  myFile.open(filename, ios::in);//Read

  if (myFile.is_open()) {
    string line;

    while (getline(myFile, line)) {
      cout << line << endl;
    }

    myFile.close();
  } else {
    cout << "File operation failed,There is no record\n";
  }
}

void file_edit(string file_name, int line_number_to_edit, string new_line) {
  myFile.open(file_name, ios::in);//Read

  if (myFile.is_open()) {
    vector<string> lines;
    string line;

    while (getline(myFile, line)) {
      lines.push_back(line);
    }

    if (line_number_to_edit > 0 && line_number_to_edit+1 <= lines.size()) {
      lines[line_number_to_edit] = to_string(line_number_to_edit) + "-)" + new_line;
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

void file_line_delete(string file_name, int line_number_to_delete) {
  myFile.open(file_name, ios::in);//Read

  if (myFile.is_open()) {
    vector<string> lines;
    string line;

    while (getline(myFile, line)) {
      lines.push_back(line);
    }

    if (line_number_to_delete >= 0 && line_number_to_delete < lines.size()) {
      lines.erase(lines.begin() + line_number_to_delete);
    } else {
      cout << "You can only erase existing lines" << endl;
    }

    myFile.close(); // Close the file before reopening
    myFile.open(file_name, ios::out); // Open in write mode

    for (const string &updated_line : lines) {
      size_t pos = updated_line.find("-)");
      int lineNumber = stoi(updated_line.substr(0, pos));

      if (lineNumber > line_number_to_delete) {
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
