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
	/*
	 * Default constructor
	 */
	Job();
	/*
	 * Constructor with argument machines en duration
	 */
	Job(const std::vector<unsigned short>& machines, const std::vector<unsigned short>& durations);
	/*
	 * Destructor
	 */
	virtual ~Job();
	/*
	 * @return parameter unsigned short
	 * getNextMachineId() get the id of the next machine
	 */
	unsigned short getNextMachineId();
	/*
	 * @return parameter unsigned long long
	 * getNextTaskDuration() get the duration of the next machine
	 */
	unsigned short getNextTaskDuration();
	/*
	 * @return parameter unsigned long long
	 * getNextEndTime() get the next end time
	 */
	unsigned long long getNextEndTime();
	/*
	 * @return parameter unsigned long long
	 * getTotalRemainingDuration() get the total remaing duration
	 */
	unsigned long long getTotalRemainingDuration();
	/*
	 * completeNextJob() sets the next job on jobCompleted = true
	 */
	void completeNextJob();
	/*
	 * printJobOutput() prints the job output
	 */
	void printJobOutput();
	/*
	 * startNextTask() starts the next task
	 */
	void startNextTask(const unsigned long long startTime);
	/*
	 * @return parameter std::vector<Task>
	 * getTasks() gets the vector with tasks
	 */
	const std::vector<Task>& getTasks() const;
	/*
	 * @return parameter unsigned short
	 * getNextTask() getter for the next task
	 */
	unsigned short getNextTask() const;
	/*
	 * @return parameter unsigned long long
	 * getEndTime() getter for the end time
	 */
	unsigned long long getEndTime() const;
	/*
	 * @return parameter unsigned long long
	 * getStartTime() getter for the start time
	 */
	unsigned long long getStartTime() const;
	/*
	 * @return parameter boolean
	 * isJobCompleted() checker is a job is completed
	 */
	bool isJobCompleted() const;
	/*
	 * setJobCompleted() setter for completing a job
	 */
	void setJobCompleted(bool jobCompleted);

private:
	/*
	 * Attributes
	 */
	std::vector<Task> Tasks;
	unsigned short nextTask;
	unsigned long long startTime;
	unsigned long long endTime;
	bool jobCompleted;
};

#endif /* JOB_H_ */
