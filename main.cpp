/*
 * main.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#include "JobShop.h"

#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream inputFile;
	inputFile.open("input.txt");

	if (!inputFile.is_open()) { 						//checks if the file�s not open
		std::cout << "File not present!" << std::endl;
	} else {						//checks if it is the end of the file.
		JobShop jobs(inputFile);
		jobs.createSchedule();
	}

	return 0;
}

