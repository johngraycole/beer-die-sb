#include <QApplication>
#include <QTextEdit>

#include "ScoreForm.h"
#include "StdinGrabber.h"

int main(int argv, char **args)
{
	QApplication app(argv, args);

	StdinGrabber grabber;
	grabber.Start();

	ScoreForm score;
	score.show();

	return app.exec();
}

