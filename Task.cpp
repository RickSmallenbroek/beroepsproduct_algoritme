/*
 * Task.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include "Task.h"
#include <iostream>

Task::Task(const Machine& a_machine, const unsigned short a_duration)
:machine(a_machine), duration(a_duration), startTime(1), taskCompleted(false)
{
	std::cout << machine.getId() << "-" << duration << " ";
}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

const unsigned short Task::getDuration() const {
	return duration;
}

Machine& Task::getMachine() const {
	return machine;
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

