#include "StdinGrabber.h"

#include <boost/thread/thread.hpp>

#include <string>
#include <iostream>
using namespace std;
using namespace boost;

StdinGrabber::StdinGrabber(shared_ptr<DrinkForm> df) : Stoppable() {
	_df = df;
}

StdinGrabber::~StdinGrabber() {
	Stop();
}

void StdinGrabber::Start() {
	this->startThread(StdinGrabber::GrabThread, this);
}

void StdinGrabber::GrabThread(void *arg) {
	StdinGrabber *grab = (StdinGrabber*)arg;
	string line;
	cout << "GrabThread Starting..." << endl;

	try {
	while (true) {
		boost::this_thread::interruption_point();
		std::getline(cin, line);

		if (!line.empty()) {
			if (line[0] >= '0' && line[0] <= '9') {
				int score = (int)( line[0] - '0' );
				grab->_df->SetDrinkScore(score);
			}
		}
	}
	} catch (boost::thread_interrupted const&) {
		cout << "GrabThread Exiting..." << endl;
	}
}


