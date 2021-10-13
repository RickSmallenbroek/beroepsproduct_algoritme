/*
 * main.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#include "JobShop.h"

#include <regex>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

int main(int argc, char **argv) {
	char *fileName;

	if(argc >= 2)
	{
		fileName = argv[1];
	}
	else
	{
//		return 1;
		fileName = "input.txt";
	}

	std::ifstream inputFile;
	if (!inputFile.fail())
		{
			inputFile.open(fileName);
			JobShop jobs(inputFile);
			jobs.createSchedule();
		} else
		{
			std::cout << "Failed to open file: " << fileName << std::endl;
			return 1;
		}
	return 0;
}

