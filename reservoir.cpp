/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab3C

This program accepts a std::string specifying a date and it returns the East Basin storage for that day.
*/

#include <iostream>
#include <string>

#include <fstream>
#include <cstdlib>
#include <climits>

#include "reservoir.h"

// This function accepts an std::string specifying a date and returns the East basin storage for that day
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


// Returns the minimum storage in the East basin in 2018
double get_min_east()
{
	double minStorage = INT_MAX;
	
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

		if(eastSt < minStorage)
		{
			minStorage = eastSt;
		}
	}

	return minStorage;
	fin.close();
}


// Returns the maximum storage in the East basin in 2018
double get_max_east()
{
	double maxStorage = INT_MIN;
	
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

		fin.ignore(INT_MAX, '\n');	// skips to the end of line

		if(eastSt > maxStorage)
		{
			maxStorage = eastSt;
		}
	}

	return maxStorage;
	fin.close();
}


// Returns "East" if the East basin was higher on the specified date and "West" if the West was higher. It returns "Equal" if the values were the same.
std::string compare_basins(std::string date)
{
	std::string result;
	
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

		fin.ignore(INT_MAX, '\n');	// skips to the end of line

		if(date == d)
		{
			if(eastEl > westEl)
			{
				result = "East";
			}
			else if(westEl > eastEl)
			{
				result = "West";
			}
			else
			{
				result = "Equal";
			}
		}
	}

	return result;
	fin.close();
}
