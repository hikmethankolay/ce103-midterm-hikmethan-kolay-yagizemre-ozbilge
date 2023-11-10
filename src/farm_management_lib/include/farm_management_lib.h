#ifndef FARM_MANAGEMENT_LIB_H
#define FARM_MANAGEMENT_LIB_H
#include <string>
using namespace std;

void file_write(string file_name, string text);

void file_append(string file_name,string text);

void file_read(string filename);

void file_edit(string file_name, int line_number_to_edit, string new_line);

#endif // FARM_MANAGEMENT_LIB_H
