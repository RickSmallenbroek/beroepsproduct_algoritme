/*
 * Job.h
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#ifndef JOB_H_
#define JOB_H_
#include <vector>
#include <map>
#include "Task.h"
#include "Machine.h"

class Job {
public:
	//Constructors & Destructor
	Job();
	Job(const std::vector<unsigned short>& machines, const std::vector<unsigned short>& durations);
	virtual ~Job();

	//Methods
	unsigned short getNextMachineId();
	unsigned short getNextTaskDuration();
	unsigned long long getNextEndTime();
	unsigned long long getTotalRemainingDuration();
	void completeNextJob();
	void printJobOutput();
	void startNextTask(const unsigned long long startTime);

	//Getters & Setters
	const std::vector<Task>& getTasks() const;
	unsigned short getNextTask() const;
	unsigned long long getEndTime() const;
	unsigned long long getStartTime() const;
	bool isJobCompleted() const;
	void setJobCompleted(bool jobCompleted);

private:
	//Attributes
	std::vector<Task> Tasks;
	unsigned short nextTask;
	unsigned long long startTime;
	unsigned long long endTime;
	bool jobCompleted;

};

#endif /* JOB_H_ */
