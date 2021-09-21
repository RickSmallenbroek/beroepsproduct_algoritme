/*
 * Job.h
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
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
//	Job(const Job& rhs);
	virtual ~Job();

	//Methods
	unsigned short getNextMachineId();
	unsigned short getTotalRemainingDuration();
	void printJobOutput();
	void startNextTask(const unsigned short startTime);

	//Getters & Setters
	const std::vector<Task>& getTasks() const;
	unsigned short getEndTime() const;
	unsigned short getStartTime() const;
	bool isJobCompleted() const;
	void setJobCompleted(bool jobCompleted);

private:
	//Attributes
	std::vector<Task> Tasks;
	unsigned short startTime;
	unsigned short endTime;
	bool jobCompleted;
};

#endif /* JOB_H_ */
