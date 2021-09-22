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
	startTime = 0;
	endTime = 0;
	jobCompleted = false;
	for(int i = 0; i < machines.size(); i++){
		Tasks.push_back(Task(machines.at(i), durations.at(i)));
	}
}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

//Task& Job::getNextTask(){
//	std::cout << "getNextTask" << std::endl;
////	auto inQueue = [](const Task& task){
////		return !task.isTaskCompleted();
////	};
////
////	auto result = std::find_if(Tasks.begin(), Tasks.end(), inQueue);
////	return *result;
//	for(auto i = 0; i < Tasks.size(); i++){
////		std::cout << "Is task complete: " << Tasks.at(i).isTaskCompleted() << std::endl;
//		if(!Tasks.at(i).isTaskCompleted()){
//			Task& nextTask = Tasks.at(i);
//			return nextTask;
//		}
//	}
//
//	return *Tasks.end();
//}

unsigned short Job::getNextTask(){
	for(auto i = 0; i < Tasks.size(); i++){
		if(!Tasks.at(i).isTaskCompleted()){
			return i;
		}
	}
	return false;
}

unsigned short Job::getNextMachineId() {
	auto result = getNextTask();
	return Tasks.at(result).getMachineId();
}

unsigned short Job::getNextTaskDuration() {
	auto result = getNextTask();
	return Tasks.at(result).getDuration();
}

unsigned short Job::getNextEndTime() {
	auto result = getNextTask();
	return Tasks.at(result).getEndTime();
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

void Job::completeNextJob() {
	auto result = getNextTask();
	Tasks.at(result).setTaskCompleted(true);
}

void Job::printJobOutput() {
	std::cout << startTime << " " << endTime;
}

void Job::startNextTask(const unsigned short startTime) {
	auto inQueue = [](const Task& task){
		return !task.isTaskCompleted();
	};

	auto result = std::find_if(Tasks.begin(), Tasks.end(), inQueue);
	if(result == Tasks.begin()){
		this->startTime = startTime;
	}
	result->setEndTime(startTime);
	if(result == Tasks.end() - 1){
		this->endTime = result->getEndTime();
		jobCompleted = true;
	}
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
