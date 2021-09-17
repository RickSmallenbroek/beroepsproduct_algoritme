/*
 * Job.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include "Job.h"
#include "Task.h"
#include "Machine.h"
#include <iostream>
#include <vector>
#include <map>
#include <Algorithm>

Job::Job() {
	// TODO Auto-generated constructor stub
}

Job::Job(const std::vector<Machine>& machines, const std::vector<unsigned short>& durations) {
	for(int i = 0; i < machines.size(); i++){
		Tasks.push_back(Task(machines.at(i), durations.at(i)));
	}
}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

//bool Job::operator ==(const Job &rhs) const {
//	return Tasks == rhs.getTasks() && startTime == rhs.getStartTime() && endTime == rhs.getEndTime();
//}
//
//bool Job::operator <(const Job &rhs) const {
//	return this->getTotalRemainingDuration() < rhs.getTotalRemainingDuration();
//}
//
//Job& Job::operator =(const Job &rhs) {
//	if(*this != rhs){
//		Tasks = rhs.getTasks();
//		startTime = rhs.getStartTime();
//		endTime = rhs.getEndTime();
//	}
//	return *this;
//}

Machine Job::getNextMachine() {

	auto inQueue = [](const Task& task){
		return !task.isTaskCompleted();
	};

	auto result = std::find_if(Tasks.begin(), Tasks.end(), inQueue);
	return result->getMachine();
}

unsigned short Job::getTotalRemainingDuration() {
	short totalDuration = 0;
	for(const auto task : Tasks){
		if(!task.isTaskCompleted()){
			totalDuration += task.getDuration();
		}
	}
	return totalDuration;
}

void Job::printJobOutput() {
}

const std::vector<Task>& Job::getTasks() const {
return Tasks;
}

unsigned short Job::getEndTime() const {
return endTime;
}

unsigned short Job::getStartTime() const {
return startTime;
}
