/*
 * JobShop.cpp
 *
 *  Created on: 12 Sep 2021
 *      Author: Damo Luijpers
 */

#include <fstream>
#include <iostream>
#include <istream>
#include <vector>
#include <Algorithm>
#include "JobShop.h"
#include "Job.h"
#include "Machine.h"

JobShop::JobShop() {
	// TODO Auto-generated constructor stub

}

JobShop::JobShop(std::ifstream& input) {

}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

//bool JobShop::operator ==(const JobShop &rhs) const {
//	return nrMachines == rhs.getNrMachines() && Jobs == rhs.getJobs();
//}
//
//bool JobShop::operator <(const JobShop &rhs) const {
//	if(Jobs.size() == rhs.getJobs().size()){
//		return nrMachines < rhs.nrMachines;
//	}else{
//		return Jobs.size() < rhs.getJobs().size();
//	}
//}
//
//JobShop& JobShop::operator =(const JobShop &rhs) {
//	if(*this != rhs){
//		nrMachines = rhs.getNrMachines();
//		Jobs = rhs.getJobs();
//	}
//	return *this;
//}

void JobShop::createSchedule() {
}

void JobShop::assignMachines() {
}

Job& JobShop::getLeastSlackJob(const std::vector<Job>& conflictingJobs) {

}

const std::vector<Job>& JobShop::getJobs() const {
return Jobs;
}

