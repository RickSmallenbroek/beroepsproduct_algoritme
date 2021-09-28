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

int main(int argc, char **argv) {
	std::string fileName;
	if(argc >= 2){
		fileName = argv[1];
	}else{
		return 1;
	}
	std::ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.is_open()) {
		JobShop jobs(inputFile);
		jobs.createSchedule();
	}else{
		std::cout << "Unable to open file." << std::endl;
	}
	return 0;
}

