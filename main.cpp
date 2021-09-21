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
//	inputFile.open("input.txt");
	inputFile.open(fileName);

	if (!inputFile.is_open()) { 						//checks if the file´s not open
		std::cout << "File not present!" << std::endl;
	} else {						//checks if it is the end of the file.
		JobShop jobs(inputFile);
	}

	return 0;
}

