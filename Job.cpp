/*
 * Job.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
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
	nextTask = 0;
	startTime = 0;
	endTime = 0;
	jobCompleted = false;
	for(unsigned long long i = 0; i < machines.size(); i++){
		Tasks.push_back(Task(machines.at(i), durations.at(i)));
	}
}

Job::~Job() {
}

unsigned short Job::getNextTask() const{
	return nextTask;
}

unsigned short Job::getNextMachineId() {
	return Tasks.at(nextTask).getMachineId();
}

unsigned short Job::getNextTaskDuration() {
	return Tasks.at(nextTask).getDuration();
}

unsigned long long Job::getNextEndTime() {
	return Tasks.at(nextTask).getEndTime();
}

unsigned long long Job::getTotalRemainingDuration() {
	long long totalDuration = 0;
	for(const auto task : Tasks){
		if(!task.isTaskCompleted()){
			totalDuration += task.getDuration();
		}
	}
	return totalDuration;
}

void Job::completeNextJob() {
	Tasks.at(nextTask).setTaskCompleted(true);
	if(nextTask == Tasks.size() - 1){
		this->endTime = Tasks.at(nextTask).getEndTime();
		jobCompleted = true;
	}
	if(nextTask < Tasks.size() - 1){
		nextTask++;
	}
}

void Job::printJobOutput() {
	std::cout << startTime << " " << endTime;
}

void Job::startNextTask(const unsigned long long startTime) {
	if(nextTask == 0){
		this->startTime = startTime;
	}
	Tasks.at(nextTask).setEndTime(startTime);
}

const std::vector<Task>& Job::getTasks() const {
	return Tasks;
}

unsigned long long Job::getEndTime() const {
	return endTime;
}

unsigned long long Job::getStartTime() const {
	return startTime;
}

bool Job::isJobCompleted() const {
	return jobCompleted;
}

void Job::setJobCompleted(bool jobCompleted) {
	this->jobCompleted = jobCompleted;
}
