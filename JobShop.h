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
	* Default constructor of JobShop (deleted)
	*/
	JobShop() = delete;
	/**
	* JobShop constructor with arguments
	*/
	JobShop(std::ifstream& file);
	/**
	* Destructor of jobshop
	*/
	virtual ~JobShop();

	/*
	 * @param machineCount is the amount of machines needed
	 * @return an amount of machines is created equal to amount of machines needed
	 */
	void makeMachines(unsigned int machineCount);
	/*
	 * @return schedule is is created and the output is printed to the console
	 */
	void createSchedule();
	/*
	 * @return needed tasks are started and corresponding machines are set to busy
	 */
	void assignMachines();
	/*
	 * @param conflictingJobs is a vector of jobs needing the same machine
	 * @return the index of the job with the highest priority
	 */
	unsigned short getLeastSlackJob(std::vector<unsigned short>& conflictingJobs);
	/*
	 * @return tasks that need to be closed are closed and corresponding machines are freed
	 */
	void endFinishedTasks();
	/*
	 * @return the jobId's, start times and end times are printed
	 */
	void printJobShop();

	/*
	 * @return the vector of jobs in jobShop
	 */
	const std::vector<Job>& getJobs() const;

private:
	//Attributes
	std::vector<Machine> Machines;
	std::vector<Job> Jobs;
	unsigned long long currentTime;
	std::vector<unsigned long long> queue;
};

#endif /* JOBSHOP_H_ */
