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
	virtual ~Machine();

	//Getters & Setters
	bool isUsed() const;

private:
	bool used;
};

#endif /* MACHINE_H_ */
