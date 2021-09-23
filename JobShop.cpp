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

	for (int i = 0; i < machinesCount; ++i) {
		Machines.push_back(Machine(i));
	}

	for (int i = 0; i < jobsCount; i++) {
		std::vector<unsigned short> machines;
		std::vector<unsigned short> durations;
		if (input.peek() == 10) {
			input.get();
		}
		while (input.peek() != 10 && !input.eof()) {
			unsigned short machineId;
			unsigned short duration;
			input >> machineId;
			input >> duration;
			machines.push_back(machineId);
			durations.push_back(duration);
		}
		Jobs.push_back(Job(machines, durations));
	}
	input.close();
}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
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
	for (unsigned short i = 0; i < Machines.size(); i++) { //kan ook for-each loop zijn
		if (!Machines[i].isUsed()) {
			std::vector<unsigned short> conflictingJobs;
			for (unsigned short j = 0; j < Jobs.size(); j++) {
				if(Jobs.at(j).isJobCompleted() == false){
					if (Jobs.at(j).getNextMachineId() == Machines[i].getId()) {
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
				unsigned short taskEndTime = currentTime + Jobs.at(nextJob).getNextTaskDuration();
				if (find(queue.begin(), queue.end(), taskEndTime) == queue.end()) {
					queue.push_back(taskEndTime);
				}
				Machines[i].setUsed(true);
			}
		}
	}
}

//Hij loopt door de gegeven Jobs heen om daar de Job die de Critical Path vormt te returnen
unsigned short JobShop::getLeastSlackJob(std::vector<unsigned short> &conflictingJobs) {
	unsigned short longestJob = conflictingJobs[0];
	unsigned short longestJobDuration = Jobs.at(longestJob).getTotalRemainingDuration();
	for (unsigned short i = 1; i < conflictingJobs.size(); i++) {
		if (longestJobDuration
				< Jobs.at(conflictingJobs[i]).getTotalRemainingDuration()) {
			longestJob = conflictingJobs[i];
			longestJobDuration = Jobs.at(longestJob).getTotalRemainingDuration();
		}
	}
	return longestJob;
}

void JobShop::endFinishedTasks(){
	for(Job& job : Jobs){
		if(job.getNextEndTime() != 0 && job.getNextEndTime() <= currentTime){
			unsigned short machinedId = job.getNextMachineId();
			Machines.at(machinedId).setUsed(false);
			job.completeNextJob();

		}
	}
}

void JobShop::printJobShop() {
	for(unsigned short i = 0; i < Jobs.size(); i++){
		std::cout << i << " ";
		Jobs.at(i).printJobOutput();
		std::cout << std::endl;
	}
}

const std::vector<Job>& JobShop::getJobs() const {
	return Jobs;
}

void JobShop::testCheck() {
	for (unsigned short i = 0; i < Machines.size(); ++i) {
		std::cout << Machines[i].getId() << " - " << Machines[i].isUsed()
				<< std::endl;
	}

	std::cout << "Jobs:" << std::endl;

	for (unsigned short i = 0; i < Jobs.size(); i++) {
		std::cout << i << ": " << Jobs[i].getTasks()[0].getMachineId() << " - "
				<< Jobs[i].getTotalRemainingDuration() << " - "
				<< Jobs[i].getTasks()[0].getEndTime() << std::endl;
	}
}

