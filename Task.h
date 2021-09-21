/*
 * Task.h
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#ifndef TASK_H_
#define TASK_H_

#include "Machine.h"

class Task {
public:
	//Constructors & Destructor
	Task(const unsigned short a_machineId, const unsigned short a_duration);
	virtual ~Task();

	//Getters & Setters
	const unsigned short getDuration() const;
	unsigned short getMachineId() const;
	unsigned short getStartTime() const;
	void setStartTime(unsigned short startTime);
	bool isTaskCompleted() const;
	void setTaskCompleted(bool taskCompleted);

private:
	//Attributes
	unsigned short machineId;
	unsigned short duration;
	unsigned short startTime;
	bool taskCompleted;
};

#endif /* TASK_H_ */
