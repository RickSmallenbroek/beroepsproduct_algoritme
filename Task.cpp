/*
 * Task.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include "Task.h"
#include <iostream>

Task::Task(const unsigned short a_machineId, const unsigned short a_duration)
:machineId(a_machineId), duration(a_duration), endTime(0), taskCompleted(false)
{
	std::cout << machineId << "-" << duration << " ";
}

Task::Task(const Task &rhs)
: machineId(rhs.getMachineId()), duration(rhs.getDuration()), endTime(rhs.getEndTime()), taskCompleted(rhs.isTaskCompleted())
{
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

unsigned short Task::getEndTime() const {
	return endTime;
}

void Task::setEndTime(unsigned short startTime) {
	this->endTime = startTime + duration;
}

bool Task::isTaskCompleted() const {
	return taskCompleted;
}

void Task::setTaskCompleted(bool taskCompleted) {
	this->taskCompleted = taskCompleted;
}

