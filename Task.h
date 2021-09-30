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
	/*
	 * Constructor with parameter
	 */
	Task(const unsigned short a_machineId, const unsigned short a_duration);
	/*
	 * Deconstructor
	 */
	virtual ~Task();

	/*
	 * @return duration of a task
	 */
	unsigned short getDuration() const;
	/*
	 * @return machineId of the machine used by a task
	 */
	unsigned short getMachineId() const;
	/*
	 * @return end time of a task
	 */
	unsigned long long getEndTime() const;
	/*
	 * @param startTime is the startTime of a task
	 * @return end time of a task is set
	 */
	void setEndTime(unsigned long long startTime);
	/*
	 * @return if task is completed
	 */
	bool isTaskCompleted() const;
	/*
	 * @param taskCompleted is the state to set the task to
	 * @return taskCompleted is set to given value
	 */
	void setTaskCompleted(bool taskCompleted);

private:
	/*
	 * Attributes
	 */
	unsigned short machineId;
	unsigned short duration;
	unsigned long long endTime;
	bool taskCompleted;
};

#endif /* TASK_H_ */
