/*
 * Job.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include "Job.h"
#include "Task.h"
#include "Machine.h"
#include <vector>
#include <map>
#include <Algorithm>

Job::Job() {
	// TODO Auto-generated constructor stub

}

Job::Job(std::map<Machine, unsigned short> a_tasks) {
	for(const auto& pair : a_tasks){
		Task temp(pair.first, pair.second);
		Tasks.push_back(temp);
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

unsigned short Job::getNextMachine() {
	return 0;
}

unsigned short Job::getTotalRemainingDuration() {
	return 0;
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
