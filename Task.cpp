/*
 * Task.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#include "Task.h"
#include <iostream>

Task::Task(const unsigned short a_machineId, const unsigned short a_duration)
:machineId(a_machineId), duration(a_duration), endTime(0), taskCompleted(false)
{
}

Task::~Task() {
}

unsigned short Task::getDuration() const {
	return duration;
}

unsigned short Task::getMachineId() const {
	return machineId;
}

unsigned long long Task::getEndTime() const {
	return endTime;
}

void Task::setEndTime(unsigned long long startTime) {
	this->endTime = startTime + duration;
}

bool Task::isTaskCompleted() const {
	return taskCompleted;
}

void Task::setTaskCompleted(bool taskCompleted) {
	this->taskCompleted = taskCompleted;
}

