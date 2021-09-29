/*
 * Task.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#include "Task.h"
#include <iostream>

Task::Task(const unsigned int a_machineId, const unsigned int a_duration)
:machineId(a_machineId), duration(a_duration), endTime(0), taskCompleted(false)
{
}

Task::Task(const Task &rhs)
: machineId(rhs.getMachineId()), duration(rhs.getDuration()), endTime(rhs.getEndTime()), taskCompleted(rhs.isTaskCompleted())
{
}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

unsigned int Task::getDuration() const {
	return duration;
}

unsigned int Task::getMachineId() const {
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

