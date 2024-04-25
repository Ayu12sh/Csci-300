# Adding more folders to ship with the application, here
folder_01.source = qml/FantasyMovieSelector
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

QML_IMPORT_PATH =

# If application uses the Qt Mobility libraries, uncomment the following line
# MOBILITY +=

QT += quick


DEFINES += QT_DEPRECATED_WARNINGS


#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
    main.cpp \
    CFantasyMovies.cpp \
    CReadFile.cpp

HEADERS += \
    CFantasyMovies.h \
    CReadFile.h \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    input.txt
