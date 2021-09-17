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
	Task();
	Task(const Machine& a_machine, const unsigned short a_duration);
	virtual ~Task();

	//Operators
//	bool operator==(const Task& rhs) const;
//	bool operator<(const Task& rhs) const;
//	Task& operator=(const Task& rhs);

	//Getters & Setters
	const unsigned short getDuration() const;
	const Machine& getMachine() const;
	unsigned short getStartTime() const;
	void setStartTime(unsigned short startTime);
	bool isTaskCompleted() const;
	void setTaskCompleted(bool taskCompleted);

private:
	//Attributes
	Machine machine;
	unsigned short duration;
	unsigned short startTime;
	bool taskCompleted;
};

#endif /* TASK_H_ */
