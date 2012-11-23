TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
LIBS += -lboost_date_time -lboost_thread

# Input

HEADERS += Constants.h
HEADERS += ScoreForm.h DrinkForm.h
HEADERS += Stoppable.h EventCreator.h
HEADERS += StdinGrabber.h
HEADERS += GameUpdateListener.h

FORMS += ScoreForm.ui DrinkForm.ui

SOURCES += main.cpp
SOURCES += ScoreForm.cpp DrinkForm.cpp
SOURCES += Stoppable.cpp StdinGrabber.cpp
