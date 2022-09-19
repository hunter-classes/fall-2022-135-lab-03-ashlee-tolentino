/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab3D

This function prints out the West basin elevation for all days in the interval in reverse chronological order.
*/

#include <iostream>
#include <string>

#include <fstream>
#include <cstdlib>
#include <climits>

#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2)
{	
	std::string d;
	double eastSt;
	double eastEl;
	double westSt;
	double westEl;

	std::string dates[365];
	double west_elevations[365];
	int array_length = 0;
	bool save_to_array = false;

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
		if(d == date1)
		{
			save_to_array = true;
		}
		
		if(save_to_array)
		{
			dates[array_length] = d;
			west_elevations[array_length] = westEl;
			array_length++;
		}

		if(d == date2)
		{
			save_to_array = false;
		}
	}

	for(int i = array_length - 1; i >= 0; i--)
	{
		std::cout << dates[i] << " " << west_elevations[i] << " ft" << std::endl;
	}

	fin.close();
}