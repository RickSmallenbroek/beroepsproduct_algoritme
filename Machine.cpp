/*
 * Machine.cpp
 *
 *  Created on: 14 Sep 2021
 *      Author: Damo Luijpers
 */

#include "Machine.h"

Machine::Machine()
:used(false)
{
	// TODO Auto-generated constructor stub

}

Machine::~Machine() {
	// TODO Auto-generated destructor stub
}

bool Machine::isUsed() const {
	return used;
}
