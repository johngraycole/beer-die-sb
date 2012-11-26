#include <boost/shared_ptr.hpp>

#include <string>

#include <QApplication>
#include <QTextEdit>

#include "GameBoard.h"
#include "StdinGrabber.h"

using namespace boost;
using namespace std;

int main(int argv, char **args)
{
	QApplication app(argv, args);

	shared_ptr<GameBoard> gameboard( new GameBoard() );
	shared_ptr<StdinGrabber> grabber( new StdinGrabber() );

	grabber->AddListener(gameboard);
	grabber->Start();

	gameboard->show();
	return app.exec();
}

