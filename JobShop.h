/*
 * JobShop.h
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <iostream>
#include <vector>

#include "Job.h"
#include "Machine.h"

class JobShop {
public:
	/**
	*
	*/
	JobShop() = delete;
	/**
	*
	*/
	JobShop(std::ifstream& file);
	/**
	* Destructor of jobshop
	*/
	virtual ~JobShop();

	//Methods
	void createSchedule();

	void makeMachines(unsigned int machineCount);

	void assignMachines();
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
	unsigned long long currentTime;
	std::vector<unsigned long long> queue;
};

#endif /* JOBSHOP_H_ */
