#include <boost/shared_ptr.hpp>

#include <QApplication>
#include <QTextEdit>

#include "DrinkForm.h"
#include "StdinGrabber.h"

using namespace boost;

int main(int argv, char **args)
{
	QApplication app(argv, args);

	shared_ptr<DrinkForm> score( new DrinkForm(false) );
	shared_ptr<StdinGrabber> grabber( new StdinGrabber() );

	grabber->Start();

	score->show();
	return app.exec();
}

