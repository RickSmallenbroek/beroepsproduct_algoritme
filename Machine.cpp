/*
 * Machine.cpp
 *
 *  Created on: 14 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#include "Machine.h"
#include <iostream>

Machine::Machine()
:id(0), used(false)
{
}

Machine::Machine(const unsigned short a_id)
:id(a_id), used(false)
{
}

Machine::~Machine() {
	// TODO Auto-generated destructor stub
}

bool Machine::operator ==(const Machine& rhs) const {
	return id == rhs.getId();
}

bool Machine::isUsed() const {
	return used;
}

unsigned short Machine::getId() const {
	return id;
}

void Machine::setUsed(bool used) {
	this->used = used;
}
