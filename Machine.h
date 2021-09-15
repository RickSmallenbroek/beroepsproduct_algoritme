/*
 * Machine.h
 *
 *  Created on: 14 Sep 2021
 *      Author: Damo Luijpers
 */

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine {
public:
	//Constructor & Destructor
	Machine();
	Machine(const unsigned short a_id);
	virtual ~Machine();

	//Getters & Setters
	bool isUsed() const;
	unsigned short getId() const;

private:
	unsigned short id;
	bool used;
};

#endif /* MACHINE_H_ */
