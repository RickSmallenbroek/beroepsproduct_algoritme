/*
 * Task.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include "Task.h"

Task::Task()
{
	// TODO Auto-generated constructor stub
}

Task::Task(const Machine a_machine, const unsigned short a_duration)
:machine(a_machine), duration(a_duration)
{
}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

//bool Task::operator ==(const Task &rhs) const {
//	return machine == rhs.getMachine() && duration == rhs.getDuration() && startTime == rhs.getStartTime() && taskCompleted == rhs.isTaskCompleted();
//}
//
//bool Task::operator <(const Task &rhs) const {
//	return duration < rhs.getDuration();
//}
//
//Task& Task::operator =(const Task &rhs) {
//	if(*this != rhs){
//		machine = rhs.getMachine();
//		duration = rhs.getDuration();
//		startTime = rhs.getStartTime();
//		taskCompleted = rhs.isTaskCompleted();
//	}
//	return *this;
//}

const unsigned short Task::getDuration() const {
	return duration;
}

const Machine Task::getMachine() const {
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

