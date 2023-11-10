#ifndef FARM_MANAGEMENT_LIB_H
#define FARM_MANAGEMENT_LIB_H
#include <string>
using namespace std;

void file_write(string file_name, string text);

void file_append(string file_name,string text);

void file_read(string file_ename);

void file_edit(string file_name, int line_number_to_edit, string new_line);

void file_line_delete(string file_name, int line_number_to_delete);

#endif // FARM_MANAGEMENT_LIB_H
