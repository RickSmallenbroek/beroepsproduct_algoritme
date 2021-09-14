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

class Job {
public:
	//Constructors & Destructor
	Job();
	Job(std::map<unsigned short, unsigned short> a_tasks);
	virtual ~Job();

	//Operators
//	bool operator==(const Job& rhs) const;
//	bool operator<(const Job& rhs) const;
//	Job& operator=(const Job& rhs);

	//Methods
	unsigned short getNextMachine();
	unsigned short getTotalRemainingDuration();
	void printJobOutput();

	//Getters & Setters
	const std::vector<Task>& getTasks() const;
	unsigned short getEndTime() const;
	unsigned short getStartTime() const;

	//Attributes
	std::vector<Task> Tasks;
	unsigned short startTime;
	unsigned short endTime;
};

#endif /* JOB_H_ */
