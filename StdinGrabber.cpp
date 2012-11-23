#include "StdinGrabber.h"

#include <boost/thread/thread.hpp>

#include <string>
#include <iostream>
using namespace std;
using namespace boost;

StdinGrabber::StdinGrabber() : Stoppable() {
}

StdinGrabber::~StdinGrabber() {
	Stop();
}

void StdinGrabber::Start() {
	this->startThread(StdinGrabber::GrabThread, this);
}

void StdinGrabber::notify( boost::shared_ptr<GameUpdateListener> l, const GameUpdate &update ) {
	l->OnGameUpdate(update);
}

void StdinGrabber::GrabThread(void *arg) {
	StdinGrabber *grab = (StdinGrabber*)arg;
	string line;
	cout << "GrabThread Starting, enter one of following:" << endl;
	cout << "\tp1/2_score" << endl;
	cout << "\tp1/2_drink" << endl;
	cout << "\tp1/2_ondrink" << endl;
	cout << "\tp1/2_splash" << endl;
	cout << "\tp1/2_pro" << endl;
	cout << "\tundo" << endl;
	cout << "\treset" << endl;

	try {
	while (true) {
		boost::this_thread::interruption_point();
		std::getline(cin, line);

		if (!line.empty()) {

			if (line == "p1_score")
				grab->NotifyAll(GU_PLAYER1_SCORE);
			if (line == "p1_drink")
				grab->NotifyAll(GU_PLAYER1_DRINK);
			if (line == "p1_ondrink")
				grab->NotifyAll(GU_PLAYER1_ON_DRINK);
			if (line == "p1_splash")
				grab->NotifyAll(GU_PLAYER1_SPLASH);
			if (line == "p1_pro")
				grab->NotifyAll(GU_PLAYER1_PRONATE);

			if (line == "p2_score")
				grab->NotifyAll(GU_PLAYER2_SCORE);
			if (line == "p2_drink")
				grab->NotifyAll(GU_PLAYER2_DRINK);
			if (line == "p2_ondrink")
				grab->NotifyAll(GU_PLAYER2_ON_DRINK);
			if (line == "p2_splash")
				grab->NotifyAll(GU_PLAYER2_SPLASH);
			if (line == "p2_pro")
				grab->NotifyAll(GU_PLAYER2_PRONATE);

			if (line == "undo")
				grab->NotifyAll(GU_UNDO_LAST);
			if (line == "reset")
				grab->NotifyAll(GU_RESET);

		}
	}
	} catch (boost::thread_interrupted const&) {
		cout << "GrabThread Exiting..." << endl;
	}
}


