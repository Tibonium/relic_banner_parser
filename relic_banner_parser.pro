#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T16:43:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = relic_banner_parser
TEMPLATE = app


SOURCES += main.cpp\
        relic_banner_parser.cpp \
    html_source_parser.cpp \
    html_beautifier.cpp

HEADERS  += relic_banner_parser.h \
    html_source_parser.h \
    html_beautifier.h

FORMS    += relic_banner_parser.ui
