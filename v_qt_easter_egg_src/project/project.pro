QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdminMainMenu.cpp \
    BuyerMainMenu.cpp \
    Calculator.cpp \
    EasterEggWindow.cpp \
    IOManager.cpp \
    ListWindow.cpp \
    Merchandise.cpp \
    OrderForm.cpp \
    Recharge.cpp \
    SellerMainMenu.cpp \
    SqlItem.cpp \
    System.cpp \
    TableWindow.cpp \
    Usr.cpp \
    UsrInfoMainMenu.cpp \
    UsrMainMenu.cpp \
    main.cpp \
    MainMenu.cpp \
    MainWindow.cpp

HEADERS += \
    AdminMainMenu.h \
    BuyerMainMenu.h \
    Calculator.h \
    EasterEggWindow.h \
    General.h \
    IOManager.h \
    ListWindow.h \
    Merchandise.h \
    OrderForm.h \
    Recharge.h \
    SellerMainMenu.h \
    SqlItem.h \
    System.h \
    TableWindow.h \
    Usr.h \
    UsrInfoMainMenu.h \
    UsrMainMenu.h \
    MainMenu.h \
    MainWindow.h

FORMS += \
    AdminMainMenu.ui \
    BuyerMainMenu.ui \
    EasterEggWindow.ui \
    ListWindow.ui \
    SellerMainMenu.ui \
    TableWindow.ui \
    UsrInfoMainMenu.ui \
    UsrMainMenu.ui \
    mainmenu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
