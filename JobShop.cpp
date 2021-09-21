/*
 * JobShop.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <Algorithm>

#include "JobShop.h"
#include "Job.h"
#include "Machine.h"

JobShop::JobShop() {
	// TODO Auto-generated constructor stub

}

JobShop::JobShop(std::ifstream &input) {
	currentTime = 0;
	int jobsCount;
	int machinesCount;
	input >> jobsCount;
	input >> machinesCount;
	std::cout << "jobs: " << jobsCount << " machines: " << machinesCount
			<< std::endl;

	for (int i = 0; i < machinesCount; ++i) {
		Machines.push_back(Machine(i));
	}

	for (int i = 0; i < jobsCount; i++) {
		std::vector<unsigned short> machines;
		std::vector<unsigned short> durations;
		for (int j = 0; j < machinesCount; j++) {
			unsigned short machineId;
			unsigned short duration;
			input >> machineId;
			input >> duration;
			machines.push_back(machineId);
			durations.push_back(duration);
		}
		std::cout << i << ": ";
		Jobs.push_back(Job(machines, durations));
		std::cout << std::endl;
	}
	input.close();
	std::cout << "End-of-file reached.." << std::endl;
}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

void JobShop::createSchedule() {
}

void JobShop::assignMachines() {
	for (unsigned short i = 0; i < Machines.size(); i++) {
		if (!Machines[i].isUsed()) {
			std::vector<unsigned short> conflictingJobs;
			for(unsigned short j = 0; j < Jobs.size(); j++){
				if(Jobs.at(j).getNextMachineId() == Machines[i].getId()){
					conflictingJobs.push_back(j);
				}
			}

			if (conflictingJobs.size() > 0) {
				if (conflictingJobs.size() > 1) {
					Job& nextJob = getLeastSlackJob(conflictingJobs);
					nextJob.startNextTask(currentTime);
					std::cout << nextJob.getTasks()[0].getStartTime() << std::endl;
				} else {
					Job& nextJob = Jobs.at(conflictingJobs.at(0));
					nextJob.startNextTask(currentTime);
					std::cout << nextJob.getTasks()[0].getStartTime() << std::endl;
				}
				Machines[i].setUsed(true);
			}
		}
	}
}

//Hij loopt door de gegeven Jobs heen om daar de Job die de Critical Path vormt te returnen
Job& JobShop::getLeastSlackJob(std::vector<unsigned short> &conflictingJobs) {
	Job &longestJob = Jobs.at(conflictingJobs[0]);
	unsigned short longestJobDuration = longestJob.getTotalRemainingDuration();
	for (unsigned short i = 1; i < conflictingJobs.size(); i++) {
		if (longestJobDuration
				< Jobs.at(conflictingJobs[i]).getTotalRemainingDuration()) {
			longestJob = Jobs.at(conflictingJobs[i]);
			longestJobDuration = longestJob.getTotalRemainingDuration();
		}
	}
	return longestJob;
}

const std::vector<Job>& JobShop::getJobs() const {
	return Jobs;
}

void JobShop::testCheck(){
	std::cout << "Machines:" << std::endl;
	for (unsigned short i = 0; i < Machines.size(); ++i) {
		std::cout << Machines[i].getId() << " - " << Machines[i].isUsed() << std::endl;
	}

	std::cout << "Jobs:" << std::endl;

	for (unsigned short i = 0; i < Jobs.size(); i++) {
		std::cout << i << ": " << Jobs[i].getTasks()[0].getMachineId() << " - " << Jobs[i].getTotalRemainingDuration() << " - " << Jobs[i].getTasks()[0].getStartTime() << std::endl;
	}
}

