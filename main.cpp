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
	std::string fileName;
	std::cout << "Enter the file name: ";
	std::cin >> fileName;
	std::ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.is_open()) {
		JobShop jobs(inputFile);
		jobs.createSchedule();
	}

	return 0;
}

