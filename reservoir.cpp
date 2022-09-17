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

double get_east_storage(std::string date)
{
	double eastStorage;
	
	std::string d;
	double eastSt;
	double eastEl;
	double westSt;
	double westEl;

	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if(fin.fail())
	{
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);	// exit if failed to open the file
	}

	std::string junk;	// new string variable
	getline(fin, junk);	// read one line from the file
  
  	while(fin >> d >> eastSt >> eastEl >> westSt >> westEl)
	{
			// this loop reads the file line-by-line
			// extracting 5 values on each iteration

		fin.ignore(INT_MAX, '\n');	// skips to the end of line,
													// ignoring the remaining columns

		if(date == d)
		{
			eastStorage = eastSt;
		}
	}

	return eastStorage;
	fin.close();
}  
