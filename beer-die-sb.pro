TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
LIBS += -lboost_date_time -lboost_thread

# Input

HEADERS += Constants.h
HEADERS += ScoreForm.h DrinkForm.h LogoForm.h GameBoard.h
HEADERS += Stoppable.h EventCreator.h
HEADERS += StdinGrabber.h
HEADERS += GameUpdateListener.h

FORMS += ScoreForm.ui DrinkForm.ui LogoForm.ui

SOURCES += main.cpp
SOURCES += ScoreForm.cpp DrinkForm.cpp LogoForm.cpp GameBoard.cpp
SOURCES += Stoppable.cpp StdinGrabber.cpp
