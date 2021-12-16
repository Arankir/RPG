QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GMWidgets/formcreateinventoryitem.cpp \
    class/player/inventoryitem.cpp \
    class/network/client.cpp \
    class/player/playerequipment.cpp \
    class/player/playerinventory.cpp \
    class/settings.cpp \
    class/widgets/progressbarexp.cpp \
    class/widgets/progressbarhp.cpp \
    class/widgets/progressbarmp.cpp \
    gameWidgets/formchat.cpp \
    formgame.cpp \
    playerWidgets/forminventorybag.cpp \
    playerWidgets/formplayer.cpp \
    playerWidgets/formplayerinventory.cpp \
    gameWidgets/formplayerminiature.cpp \
    gameWidgets/formregister.cpp \
    playerWidgets/formplayerstats.cpp \
    class/widgets/inventoryitemvisual.cpp \
    main.cpp \
    mainwindow.cpp \
    class/player.cpp \
    class/network/server.cpp \
    class/structs.cpp

HEADERS += \
    GMWidgets/formcreateinventoryitem.h \
    class/player/inventoryitem.h \
    class/network/client.h \
    class/player/playerequipment.h \
    class/player/playerinventory.h \
    class/settings.h \
    class/widgets/progressbarexp.h \
    class/widgets/progressbarhp.h \
    class/widgets/progressbarmp.h \
    gameWidgets/formchat.h \
    formgame.h \
    playerWidgets/forminventorybag.h \
    playerWidgets/formplayer.h \
    playerWidgets/formplayerinventory.h \
    gameWidgets/formplayerminiature.h \
    gameWidgets/formregister.h \
    playerWidgets/formplayerstats.h \
    class/widgets/inventoryitemvisual.h \
    mainwindow.h \
    class/player.h \
    class/network/server.h \
    class/structs.h

FORMS += \
    GMWidgets/formcreateinventoryitem.ui \
    gameWidgets/formchat.ui \
    formgame.ui \
    playerWidgets/forminventorybag.ui \
    playerWidgets/formplayer.ui \
    playerWidgets/formplayerinventory.ui \
    gameWidgets/formplayerminiature.ui \
    gameWidgets/formregister.ui \
    playerWidgets/formplayerstats.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/img.qrc \
    resources/res.qrc
