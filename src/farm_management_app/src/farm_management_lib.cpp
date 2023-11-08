#include <iostream>
#include <string>
#include "../../farm_management_lib/include/farmmanagement_lib.h"

void main() {
  std::string name;
  printf("Enter a name: ");
  std::cin >> name;
  farm::crop::test(name);
}
