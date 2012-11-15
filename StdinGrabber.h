/*
 * StdinGrabber.h
 *
 *  Created on: Nov 11, 2012
 *      Author: gray
 */

#ifndef STDINGRABBER_H_
#define STDINGRABBER_H_

#include <boost/shared_ptr.hpp>

#include "Stoppable.h"
#include "DrinkForm.h"

class StdinGrabber : public Stoppable {
public:
	StdinGrabber(boost::shared_ptr<DrinkForm> df);
	~StdinGrabber();

	void Start();

private:
	static void GrabThread(void *arg);

	boost::shared_ptr<DrinkForm> _df;
};


#endif /* STDINGRABBER_H_ */
