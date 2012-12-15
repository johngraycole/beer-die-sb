TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
LIBS += -lboost_date_time -lboost_thread

# Input

HEADERS += Constants.h
HEADERS += ScoreForm.h DrinkForm.h LogoForm.h ChugFillForm.h TextForm.h
HEADERS += CupDrawer.h
HEADERS += GameBoard.h
HEADERS += Stoppable.h EventCreator.h
HEADERS += StdinGrabber.h
HEADERS += GameUpdateListener.h GameStatus.h

FORMS += ScoreForm.ui DrinkForm.ui LogoForm.ui ChugFillForm.ui TextForm.ui

SOURCES += main.cpp GameBoard.cpp
SOURCES += ScoreForm.cpp DrinkForm.cpp LogoForm.cpp ChugFillForm.cpp TextForm.cpp
SOURCES += CupDrawer.cpp
SOURCES += Stoppable.cpp StdinGrabber.cpp
SOURCES += GameStatus.cpp

