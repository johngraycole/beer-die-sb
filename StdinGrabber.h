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
#include "EventCreator.h"
#include "GameUpdateListener.h"

class StdinGrabber :
	public Stoppable,
	public EventCreator<GameUpdateListener, GameUpdate>
{
public:
	StdinGrabber();
	~StdinGrabber();

	void Start();

protected:
	virtual void notify( boost::shared_ptr<GameUpdateListener> l, const GameUpdate &update );

private:
	static void GrabThread(void *arg);
};


#endif /* STDINGRABBER_H_ */
