/*
 * StdinGrabber.cpp
 *
 *  Created on: Nov 11, 2012
 *      Author: gray
 */
#include "StdinGrabber.h"


StdinGrabber::StdinGrabber() : Stoppable() {

}

StdinGrabber::~StdinGrabber() {
	Stop();
}

void StdinGrabber::Start() {
	this->startThread(StdinGrabber::GrabThread, this);
}

void StdinGrabber::GrabThread(void *arg) {
	string line;
	cout << "GrabThread Starting..." << endl;

	try {
	while (true) {
		boost::this_thread::interruption_point();
		std::getline(cin, line);
		cout << "StdinGrabber: line ->" << line << "<-" << endl;
	}
	} catch (boost::thread_interrupted const&) {
		cout << "GrabThread Exiting..." << endl;
	}
}


