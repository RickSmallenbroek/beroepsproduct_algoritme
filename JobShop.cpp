/*
 * JobShop.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <Algorithm>
#include <regex>

#include "JobShop.h"
#include "Job.h"
#include "Machine.h"

JobShop::JobShop(std::ifstream &file) :
		currentTime(0) {

	std::string firstLine;
	std::getline(file, firstLine);
	std::regex posibleNumbers("[0-9]+");
	std::sregex_iterator next(firstLine.begin(), firstLine.end(), posibleNumbers);
	std::sregex_iterator end;
	std::smatch match = *next;
	std::string jobCountString = match.str(0);
	unsigned short jobsCount = static_cast<unsigned short>(stoi(jobCountString));
	++next;
	std::smatch matchb = *next;
	std::string machinesCountString = matchb.str(0);
	unsigned short machinesCount = static_cast<unsigned short>(stoi(machinesCountString));
	makeMachines(machinesCount);

	std::vector<unsigned short> machines;
	std::vector<unsigned short> durations;
	for (unsigned char x = 0; x < jobsCount; ++x) {
		std::string regel;
		std::getline(file, regel);
		unsigned char order = 0;
		std::regex task("[0-9]+");
		std::sregex_iterator next(regel.begin(), regel.end(), task);
		std::sregex_iterator end;
		while (next != end) {

			std::smatch match = *next;
			std::string aString = match.str(0);
			unsigned short machine = static_cast<unsigned short>(stoi(aString));
			++next;
			machines.push_back(machine);

			std::smatch matchb = *next;
			std::string bString = matchb.str(0);
			unsigned short duration = static_cast<unsigned short>(stoi(bString));
			durations.push_back(duration);

			++order;
			++next;
		}
		Jobs.push_back(Job(machines, durations));
	}

	file.close();
}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

void JobShop::makeMachines(unsigned int machinesCount) {
	for (unsigned short i = 0; i < machinesCount; ++i) {
		Machines.push_back(Machine(i));
	}
}

void JobShop::createSchedule() {
	assignMachines();
	sort(queue.begin(), queue.end());
	while (!queue.empty()) {
		currentTime = queue.at(0);
		queue.erase(queue.begin());
		endFinishedTasks();
		assignMachines();
		sort(queue.begin(), queue.end());
	}
	printJobShop();
}

void JobShop::assignMachines() {
	for (Machine &machine : Machines) {
		if (!machine.isUsed()) {
			std::vector<unsigned short> conflictingJobs;
			for (unsigned short j = 0; j < Jobs.size(); j++) {
				if (!Jobs.at(j).isJobCompleted()) {
					if (Jobs.at(j).getNextMachineId() == machine.getId()) {
						conflictingJobs.push_back(j);
					}
				}
			}

			if (conflictingJobs.size() > 0) {
				unsigned short nextJob;
				if (conflictingJobs.size() > 1) {
					nextJob = getLeastSlackJob(conflictingJobs);
				} else {
					nextJob = conflictingJobs.at(0);
				}
				Jobs.at(nextJob).startNextTask(currentTime);
				unsigned long long taskEndTime = currentTime
						+ Jobs.at(nextJob).getNextTaskDuration();
				if (find(queue.begin(), queue.end(), taskEndTime)
						== queue.end()) {
					queue.push_back(taskEndTime);
				}
				machine.setUsed(true);
			}
		}
	}
}

unsigned short JobShop::getLeastSlackJob(
		std::vector<unsigned short> &conflictingJobs) {
	unsigned short longestJob = conflictingJobs[0];
	unsigned long long longestJobDuration =
			Jobs.at(longestJob).getTotalRemainingDuration();
	for (unsigned short i = 1; i < conflictingJobs.size(); i++) {
		if (longestJobDuration
				< Jobs.at(conflictingJobs[i]).getTotalRemainingDuration()) {
			longestJob = conflictingJobs[i];
			longestJobDuration =
					Jobs.at(longestJob).getTotalRemainingDuration();
		}
	}
	return longestJob;
}

void JobShop::endFinishedTasks() {
	for (unsigned long long i = 0; i < Jobs.size(); i++) {
		if (!Jobs.at(i).isJobCompleted()) {
			if (Jobs.at(i).getNextEndTime() != 0
					&& Jobs.at(i).getNextEndTime() <= currentTime) {
				unsigned int machineId = Jobs.at(i).getNextMachineId();
				Machines.at(machineId).setUsed(false);
				Jobs.at(i).completeNextJob();
			}
		}
	}
}

void JobShop::printJobShop() {
	for (unsigned long long i = 0; i < Jobs.size(); i++) {
		std::cout << i << " ";
		Jobs.at(i).printJobOutput();
		std::cout << std::endl;
	}
}

const std::vector<Job>& JobShop::getJobs() const {
	return Jobs;
}
