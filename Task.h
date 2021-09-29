/*
 * Task.h
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#ifndef TASK_H_
#define TASK_H_

#include "Machine.h"

class Task {
public:
	//Constructors & Destructor
	Task(const unsigned int a_machineId, const unsigned int a_duration);
	Task(const Task& rhs);
	virtual ~Task();

	//Getters & Setters
	unsigned int getDuration() const;
	unsigned int getMachineId() const;
	unsigned long long getEndTime() const;
	void setEndTime(unsigned long long startTime);
	bool isTaskCompleted() const;
	void setTaskCompleted(bool taskCompleted);

private:
	//Attributes
	unsigned int machineId;
	unsigned int duration;
	unsigned long long endTime;
	bool taskCompleted;
};

#endif /* TASK_H_ */
