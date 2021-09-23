/*
 * JobShop.h
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_
#include <iostream>
#include <vector>
#include "Job.h"
#include "Machine.h"

class JobShop {
public:
	//Constructors & Destructors
	JobShop();
	JobShop(std::ifstream& input);
	virtual ~JobShop();

	//Operators
//	bool operator==(const JobShop& rhs) const;
//	bool operator<(const JobShop& rhs) const;
//	JobShop& operator=(const JobShop& rhs);

	//Methods
	void createSchedule();
	void assignMachines();
//	Job& getLeastSlackJob(std::vector<unsigned short>& conflictingJobs);
	unsigned short getLeastSlackJob(std::vector<unsigned short>& conflictingJobs);
	void endFinishedTasks();
	void printJobShop();
	void testCheck();

	//Getters & Setters
	const std::vector<Job>& getJobs() const;

private:
	//Attributes
	std::vector<Machine> Machines;
	std::vector<Job> Jobs;
	unsigned short currentTime;
	std::vector<unsigned short> queue;
};

#endif /* JOBSHOP_H_ */
