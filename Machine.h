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
//	Machine(const Machine& rhs);
	virtual ~Machine();

	//Operators
	bool operator==(const Machine& rhs) const;

	//Getters & Setters
	bool isUsed() const;
	unsigned short getId() const;
	void setUsed(bool used);

private:
	unsigned short id;
	bool used;
};

#endif /* MACHINE_H_ */
