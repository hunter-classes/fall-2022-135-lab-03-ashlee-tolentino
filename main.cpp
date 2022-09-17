/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab3A

This program accepts a std::string specifying a date and it returns the East Basin storage for that day.
*/

#include <iostream>
#include <string>

#include <fstream>
#include <cstdlib>
#include <climits>

#include "reservoir.h"

int main()
{
  double east_storage = get_east_storage("05/20/2018");
  std::cout << "East basin storage: " << east_storage << " billion gallons" << std::endl;
 
  return 0;
}
