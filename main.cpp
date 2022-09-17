/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab3B

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

	double min_east_storage = get_min_east();
	std::cout << "Minimum storage in East basin: " << min_east_storage << " billion gallons" << std::endl;

	double max_east_storage = get_max_east();
	std::cout << "Maximum storage in East basin: " << max_east_storage << " billion gallons" << std::endl;
 
	return 0;
}
