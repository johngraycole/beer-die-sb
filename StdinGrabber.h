/*
 * StdinGrabber.h
 *
 *  Created on: Nov 11, 2012
 *      Author: gray
 */

#ifndef STDINGRABBER_H_
#define STDINGRABBER_H_

#include <boost/thread/thread.hpp>
#include "Stoppable.h"

#include <string>
#include <iostream>
using namespace std;

class StdinGrabber : public Stoppable {
public:
	StdinGrabber();
	~StdinGrabber();

	void Start();

private:
	static void GrabThread(void *arg);
};


#endif /* STDINGRABBER_H_ */
