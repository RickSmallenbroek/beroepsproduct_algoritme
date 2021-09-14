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
	Job getLeastSlackJob(const std::vector<Job>& conflictingJobs);

	//Getters & Setters
	const std::vector<Job>& getJobs() const;
	unsigned short getNrMachines() const;

	//Attributes
	unsigned short nrMachines;
	std::vector<Job> Jobs;
};

#endif /* JOBSHOP_H_ */
