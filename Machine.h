/*
 * Machine.h
 *
 *  Created on: 14 Sep 2021
 *      Author: Damo Luijpers, Rick Smallenbroek
 */

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine {
public:
	/*
	 * Default constructor
	 */
	Machine();
	/*
	 * Constructor with parameter
	 */
	Machine(const unsigned short a_id);
	/*
	 * Deconstructor
	 */
	virtual ~Machine();
	/*
	 * @return parameter boolean
	 * Operator ==
	 */
	bool operator==(const Machine& rhs) const;
	/*
	 * @return parameter boolean
	 * isUsed() checks if a machine is used
	 */
	bool isUsed() const;
	/*
	 * @return parameter unsigned short
	 * getId() gets the id of a machine
	 */
	unsigned short getId() const;
	/*
	 * setUsed() sets a mechine on used
	 */
	void setUsed(bool used);
private:
	/*
	 * Attributes
	 */
	unsigned short id;
	bool used;
};

#endif /* MACHINE_H_ */
