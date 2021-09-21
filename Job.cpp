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
}

Job::Job(const std::vector<unsigned short>& machines, const std::vector<unsigned short>& durations) {
	startTime = 1;
	endTime = 1;
	jobCompleted = false;
	for(int i = 0; i < machines.size(); i++){
		Tasks.push_back(Task(machines.at(i), durations.at(i)));
	}
}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

unsigned short Job::getNextMachineId() {
	auto inQueue = [](const Task& task){
		return !task.isTaskCompleted();
	};

	auto result = std::find_if(Tasks.begin(), Tasks.end(), inQueue);
	return result->getMachineId();
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

void Job::startNextTask(const unsigned short startTime) {
	auto inQueue = [](const Task& task){
		return !task.isTaskCompleted();
	};

	auto result = std::find_if(Tasks.begin(), Tasks.end(), inQueue);
	if(result == Tasks.begin()){
		this->startTime = startTime;
	}
	result->setStartTime(startTime);
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

bool Job::isJobCompleted() const {
	return jobCompleted;
}

void Job::setJobCompleted(bool jobCompleted) {
	this->jobCompleted = jobCompleted;
}
