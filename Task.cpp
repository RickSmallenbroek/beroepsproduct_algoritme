/*
 * Task.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include "Task.h"
#include <iostream>

Task::Task(const unsigned short a_machineId, const unsigned short a_duration)
:machineId(a_machineId), duration(a_duration), startTime(1), taskCompleted(false)
{
	std::cout << machineId << "-" << duration << " ";
}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

const unsigned short Task::getDuration() const {
	return duration;
}

unsigned short Task::getMachineId() const {
	return machineId;
}

unsigned short Task::getStartTime() const {
	return startTime;
}

void Task::setStartTime(unsigned short startTime) {
	this->startTime = startTime;
}

bool Task::isTaskCompleted() const {
	return taskCompleted;
}

void Task::setTaskCompleted(bool taskCompleted) {
	this->taskCompleted = taskCompleted;
}

