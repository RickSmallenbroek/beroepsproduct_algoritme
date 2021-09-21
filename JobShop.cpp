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
	int jobsCount;
	int machinesCount;
//	int num;
	input >> jobsCount;
	input >> machinesCount;
	std::cout << "jobs: " << jobsCount << " machines: " << machinesCount
			<< std::endl;

	for (int i = 0; i < machinesCount; ++i) {
		Machines.push_back(Machine(i));
	}

	for (int i = 0; i < jobsCount; i++) {
		std::vector<Machine> machines;
		std::vector<unsigned short> durations;
		if (input.peek() == 10) {
			input.get();
		}
		while (input.peek() != 10 && !input.eof()) {
			unsigned short machineId;
			unsigned short duration;
			input >> machineId;
			input >> duration;
			machines.push_back(Machines[machineId]);
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

//bool JobShop::operator ==(const JobShop &rhs) const {
//	return nrMachines == rhs.getNrMachines() && Jobs == rhs.getJobs();
//}
//
//bool JobShop::operator <(const JobShop &rhs) const {
//	if(Jobs.size() == rhs.getJobs().size()){
//		return nrMachines < rhs.nrMachines;
//	}else{
//		return Jobs.size() < rhs.getJobs().size();
//	}
//}
//
//JobShop& JobShop::operator =(const JobShop &rhs) {
//	if(*this != rhs){
//		nrMachines = rhs.getNrMachines();
//		Jobs = rhs.getJobs();
//	}
//	return *this;
//}

void JobShop::createSchedule() {
}

void JobShop::assignMachines() {
}

//Hij loopt door de gegeven Jobs heen om daar de Job die de Critical Path vormt te returnen
Job& JobShop::getLeastSlackJob(std::vector<Job> &conflictingJobs) {
	Job &longestJob = conflictingJobs[0];
	unsigned short longestJobDuration = longestJob.getTotalRemainingDuration();
	for (auto i = 1; i < conflictingJobs.size(); i++) {
		if (longestJobDuration
				< conflictingJobs[i].getTotalRemainingDuration()) {
			longestJob = conflictingJobs[i];
		}
	}
	return longestJob;
}

const std::vector<Job>& JobShop::getJobs() const {
	return Jobs;
}

