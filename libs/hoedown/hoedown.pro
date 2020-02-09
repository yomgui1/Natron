######################################################################
# Automatically generated by qmake (2.01a) Tue May 10 14:28:35 2016
######################################################################

TEMPLATE = lib
TARGET = hoedown
CONFIG+= staticlib
CONFIG-= qt
DEPENDPATH += . src
INCLUDEPATH += . src

include(../../global.pri)
include(../../libs.pri)
include(../../config.pri)

# hoedown has too many "unused parameter" warnings
*clang*|*g++*|*xcode {
  QMAKE_CFLAGS_WARN_ON += -Wno-unused-parameter -Wno-missing-declarations
}

OBJECTS_DIR = build
MOC_DIR = build
DESTDIR = 

# Input
HEADERS += \
           src/autolink.h \
           src/buffer.h \
           src/document.h \
           src/escape.h \
           src/html.h \
           src/stack.h \
           src/version.h
SOURCES += \
           src/autolink.c \
           src/buffer.c \
           src/document.c \
           src/escape.c \
           src/html.c \
           src/html_blocks.c \
           src/html_smartypants.c \
           src/stack.c \
           src/version.c
