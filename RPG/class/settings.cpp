#include "settings.h"
#include <QColor>

const QString    Settings::c_organizationName   = "Arankir";
const QString    Settings::c_organizationDomain = "Arankir";
const QString    Settings::c_applicationName    = "RPG ft.KBAC";

QSettings *      Settings::_settings            = new QSettings(c_organizationName, c_applicationName);

void Settings::setLanguage(const int &aLanguage) {
    return _settings->setValue("language", aLanguage);
}

int Settings::language() {
    return _settings->value("language", 1).toInt();
}

void Settings::setTheme(const int &aTheme) {
    return _settings->setValue("theme", aTheme);
}

int Settings::theme() {
    return _settings->value("theme", 1).toInt();
}

void Settings::setTimeOnChat(const int &aTime) {
    return _settings->setValue("timeOnChat", aTime);
}

int Settings::timeOnChat() {
    return _settings->value("timeOnChat", 1).toInt();
}

const QString Settings::dateTimeFormat() {
    return dateFormat() + " hh:mm:ss";
}

const QString Settings::dateTimeFormatShort() {
    return dateFormat() + " hh:mm";
}

const QString Settings::dateFormat() {
//TODO сделать настраиваемым
    return "yyyy.MM.dd";
}

QRect Settings::mainWindowGeometry() {
    return (QRect(0, 0, _settings->value("mainWindow/width", 623).toInt(), _settings->value("mainWindow/height", 479).toInt()));
}

QPoint Settings::mainWindowPos() {
    return (QPoint(_settings->value("mainWindow/x", 100).toInt(), _settings->value("mainWindow/y", 100).toInt()));
}

bool Settings::isMainWindowMaximize() {
    return _settings->value("mainWindow/isMaximize", false).toBool();
}

QString Settings::defaultFont() {
    static int id = QFontDatabase::addApplicationFont(Paths::defaultFont());
    static QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    return family;
}

QString Settings::qssTheme() {
    QString qss;

    QString textColor;
    QString disabledBackgroundColor;
    QString disabledColor;
    QString hoverColor;
    QString borderColor;
    QString alternateColor;
    QString backgroundColor;
    QString backgroundSelectedItem;
    QString backgroundSecondColor;
    QString backgroundProgressbar;
    QString backgroundBadProgressbar;
    QString backgroundProgressbarProgress;
    QString selectedColor;
    QString headerFormColor;
    QString backgroundItemColor;
    QString backgroundAlternateItemColor;
    QString forItemHoverGradient;
    QString mainProfileBackground;
    QString mainBackground;
    QString pathIcons;

    switch(theme()) {
    //default: {
        // Настраиваем палитру для цветовых ролей элементов интерфейса
        //    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::WindowText, Qt::white);
        //    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        //    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        //    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        //    darkPalette.setColor(QPalette::Text, Qt::white);
        //    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ButtonText, Qt::white);
        //    darkPalette.setColor(QPalette::BrightText, Qt::red);
        //    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        // Устанавливаем данную палитру
            // Для возврата к светлой палитре достаточно
            // будет установить стандартную палитру из темы оформления
            //qApp->setPalette(style()->standardPalette());
    //}
    case 1:{//Синяя
//        QFile qssFile(":/theme/blueTheme.qss");
//        qssFile.open(QFile::ReadOnly);
//        qss = qssFile.readAll();
        textColor = "rgb(221, 221, 221)";
        disabledBackgroundColor = "rgb(20, 80, 110)";
        disabledColor = "rgb(120, 120, 120)";
        hoverColor = "rgb(20, 140, 210)";
        borderColor = "rgb(50, 65, 75)";
        alternateColor = "rgb(25, 35, 45)";
        backgroundColor = "rgb(19, 36, 62)";
        backgroundSelectedItem = "qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, stop: 0 rgb(38, 146, 255), stop: 1.0 rgb(21, 50, 87))";
        backgroundSecondColor = "qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, stop: 0 rgb(57, 152, 236), stop: 1.0 rgb(35, 95, 207))";
        backgroundProgressbar = "rgb(93, 170, 224)";
        backgroundBadProgressbar = "rgb(228, 75, 75)";
        backgroundProgressbarProgress = "rgb(56, 101, 132)";
        selectedColor = "rgb(135, 182, 255)";
        headerFormColor = "30, 41, 59";
        backgroundItemColor = "23, 26, 33";
        backgroundAlternateItemColor = "29, 32, 39";
        forItemHoverGradient = "43, 46, 53";
        mainProfileBackground = "37, 60, 94";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 rgb(18, 69, 124), stop:1 rgb(25, 37, 61))";
        pathIcons = ":/theme/iconsBlueTheme/";
        break;
    }
    case 2:{//Белая
        textColor = "rgb(15, 15, 25)";
        disabledBackgroundColor = "rgb(130, 130, 130)";
        disabledColor = "rgb(150, 150, 150)";
        hoverColor = "rgb(255, 213, 180)";
        borderColor = "rgb(50, 50, 50)";
        alternateColor = "rgb(230, 220, 210)";
        backgroundColor = "rgb(236, 236, 236)";
        backgroundSelectedItem = "rgba(110, 110, 110, 0.7)";
        backgroundSecondColor = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1E1E1, stop: 0.4 #DDDDDD, stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3)";
        backgroundProgressbar = "rgb(199, 154, 123)";
        backgroundBadProgressbar = "rgb(7, 180, 180)";
        backgroundProgressbarProgress = "rgb(200, 180, 150)";
        selectedColor = "rgb(120, 73, 0)";
        headerFormColor = "130, 130, 130";
        backgroundItemColor = "120, 120, 120";
        backgroundAlternateItemColor = "170, 170, 170";
        forItemHoverGradient = "80, 80, 80";
        mainProfileBackground = "100, 100, 100";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 #ffffff, stop:1 #777777)";
        pathIcons = ":/theme/iconsWhiteTheme/";
        break;
    }
    case 3:{//Черная
//        QFile qssFile(":/theme/blackTheme.qss");
//        qssFile.open(QFile::ReadOnly);
//        qss = qssFile.readAll();
        textColor = "rgb(240, 240, 240)";
        disabledBackgroundColor = "rgb(120, 120, 120)";
        disabledColor = "rgb(120, 120, 120)";
        hoverColor = "rgb(20, 100, 160)";
        borderColor = "rgb(60, 60, 60)";
        alternateColor = "rgb(25, 35, 45)";
        backgroundColor = "rgb(19, 19, 19)";
        backgroundSelectedItem = "rgba(11, 11, 11, 0.7)";
        backgroundSecondColor = "rgb(80, 95, 105)";
        backgroundProgressbar = "rgb(93, 170, 224)";
        backgroundBadProgressbar = "rgb(228, 75, 75)";
        backgroundProgressbarProgress = "rgb(56, 101, 132)";
        selectedColor = "rgb(135, 182, 255)";
        headerFormColor = "30, 30, 30";
        backgroundItemColor = "11, 11, 11";
        backgroundAlternateItemColor = "29, 32, 39";
        forItemHoverGradient = "11, 11, 11";
        mainProfileBackground = "70, 70, 70";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 #000000, stop:1 #252525)";
        pathIcons = ":/theme/iconsBlackTheme/";
        break;
    }
    case 4:{//Оранжевая
        textColor = "rgb(221, 221, 221)";
        disabledBackgroundColor = "rgb(110, 80, 20)";
        disabledColor = "rgb(120, 120, 120)";
        hoverColor = "rgb(210, 140, 20)";
        borderColor = "rgb(75, 65, 50)";
        alternateColor = "rgb(45, 35, 24)";
        backgroundColor = "rgb(62, 36, 19)";
        backgroundSelectedItem = "qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, stop: 0 rgb(255, 146, 38), stop: 1.0 rgb(87, 50, 21))";
        backgroundSecondColor = "qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, stop: 0 rgb(236, 152, 57), stop: 1.0 rgb(207, 95, 35))";
        backgroundProgressbar = "rgb(224, 170, 93)";
        backgroundBadProgressbar = "rgb(75, 75, 228)";
        backgroundProgressbarProgress = "rgb(132, 101, 56)";
        selectedColor = "rgb(255, 182, 135)";
        headerFormColor = "59, 41, 30";
        backgroundItemColor = "33, 26, 23";
        backgroundAlternateItemColor = "39, 32, 29";
        forItemHoverGradient = "53, 46, 43";
        mainProfileBackground = "94, 60, 37";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 rgb(124, 69, 18), stop:1 rgb(61, 37, 25))";
        pathIcons = ":/theme/iconsBlackTheme/";
        break;
    }
    case 5:{//Малиновая
        textColor = "rgb(221, 221, 221)";
        disabledBackgroundColor = "rgb(110, 20, 80)";
        disabledColor = "rgb(120, 120, 120)";
        hoverColor = "rgb(210, 20, 140)";
        borderColor = "rgb(75, 50, 65)";
        alternateColor = "rgb(45, 25, 35)";
        backgroundColor = "rgb(62, 19, 36)";
        backgroundSelectedItem = "qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, stop: 0 rgb(255, 38, 146), stop: 1.0 rgb(87, 21, 50))";
        backgroundSecondColor = "qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, stop: 0 rgb(236, 57, 152), stop: 1.0 rgb(207, 35, 95))";
        backgroundProgressbar = "rgb(224, 93, 170)";
        backgroundBadProgressbar = "rgb(75, 228, 75)";
        backgroundProgressbarProgress = "rgb(132, 56, 101)";
        selectedColor = "rgb(255, 135, 182)";
        headerFormColor = "59, 30, 41";
        backgroundItemColor = "33, 23, 26";
        backgroundAlternateItemColor = "39, 29, 32";
        forItemHoverGradient = "53, 43, 46";
        mainProfileBackground = "94, 37, 60";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 rgb(124, 18, 69), stop:1 rgb(61, 25, 37))";
        pathIcons = ":/theme/iconsBlackTheme/";
        break;
    }
    case 6:{//Лаймовая
        textColor = "rgb(240, 240, 240)";
        disabledBackgroundColor = "rgb(80, 110, 20)";
        disabledColor = "rgb(120, 120, 120)";
        hoverColor = "rgb(140, 210, 20)";
        borderColor = "rgb(65, 75, 50)";
        alternateColor = "rgb(35, 45, 25)";
        backgroundColor = "rgb(36, 62, 19)";
        backgroundSelectedItem = "qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, stop: 0 rgb(146, 255, 38), stop: 1.0 rgb(50, 87, 21))";
        backgroundSecondColor = "qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, stop: 0 rgb(152, 206, 57), stop: 1.0 rgb(95, 177, 35))";
        backgroundProgressbar = "rgb(170, 224, 93)";
        backgroundBadProgressbar = "rgb(75, 75, 228)";
        backgroundProgressbarProgress = "rgb(101, 132, 56)";
        selectedColor = "rgb(182, 255, 135)";
        headerFormColor = "41, 59, 30";
        backgroundItemColor = "26, 33, 23";
        backgroundAlternateItemColor = "32, 39, 29";
        forItemHoverGradient = "46, 53, 43";
        mainProfileBackground = "60, 94, 37";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 rgb(69, 124, 18), stop:1 rgb(37, 61, 25))";
        pathIcons = ":/theme/iconsBlackTheme/";
        break;
    }
    case 7:{//Фиолетовая
        textColor = "rgb(221, 221, 221)";
        disabledBackgroundColor = "rgb(80, 20, 110)";
        disabledColor = "rgb(120, 120, 120)";
        hoverColor = "rgb(140, 20, 210)";
        borderColor = "rgb(65, 50, 75)";
        alternateColor = "rgb(35, 25, 45)";
        backgroundColor = "rgb(36, 19, 62)";
        backgroundSelectedItem = "qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, stop: 0 rgb(146, 38, 255), stop: 1.0 rgb(50, 21, 87))";
        backgroundSecondColor = "qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, stop: 0 rgb(152, 57, 236), stop: 1.0 rgb(95, 35, 207))";
        backgroundProgressbar = "rgb(170, 93, 224)";
        backgroundBadProgressbar = "rgb(75, 228, 75)";
        backgroundProgressbarProgress = "rgb(101, 56, 132)";
        selectedColor = "rgb(182, 135, 255)";
        headerFormColor = "41, 30, 59";
        backgroundItemColor = "26, 23, 33";
        backgroundAlternateItemColor = "32, 29, 39";
        forItemHoverGradient = "46, 43, 53";
        mainProfileBackground = "60, 37, 94";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 rgb(69, 18, 124), stop:1 rgb(37, 25, 61))";
        pathIcons = ":/theme/iconsBlackTheme/";
        break;
    }
    case 8:{//Зеленая
        textColor = "rgb(255, 255, 255)";
        disabledBackgroundColor = "rgb(20, 110, 80)";
        disabledColor = "rgb(120, 120, 120)";
        hoverColor = "rgb(20, 210, 140)";
        borderColor = "rgb(50, 75, 65)";
        alternateColor = "rgb(25, 45, 35)";
        backgroundColor = "rgb(19, 62, 36)";
        backgroundSelectedItem = "qlineargradient(x1: 0, y1: -2, x2: 0, y2: 1, stop: 0 rgb(38, 255, 146), stop: 1.0 rgb(21, 87, 50))";
        backgroundSecondColor = "qlineargradient(x1: -1, y1: -1, x2: 2, y2: 2, stop: 0 rgb(57, 206, 152), stop: 1.0 rgb(35, 177, 95))";
        backgroundProgressbar = "rgb(93, 224, 170)";
        backgroundBadProgressbar = "rgb(228, 75, 75)";
        backgroundProgressbarProgress = "rgb(56, 132, 101)";
        selectedColor = "rgb(135, 255, 182)";
        headerFormColor = "30, 59, 41";
        backgroundItemColor = "23, 33, 26";
        backgroundAlternateItemColor = "29, 39, 32";
        forItemHoverGradient = "43, 53, 46";
        mainProfileBackground = "37, 94, 60";
        mainBackground = "qradialgradient(cx:0.5, cy:0.5, radius: 0.9, fx:0.4, fy:0.5, stop:0 rgb(18, 124, 69), stop:1 rgb(25, 61, 37))";
        pathIcons = ":/theme/iconsBlackTheme/";
        break;
    }
    default: {
        QFile file(Paths::documents() + "theme\\colors.txt");
        file.open(QFile::ReadOnly);

        QString textColor = QString(file.readLine()).remove("\r").remove("\n");
        QString labelValue = QString(file.readLine()).remove("\r").remove("\n");
        QString hoverColor = QString(file.readLine()).remove("\r").remove("\n");
        QString disabledColor = QString(file.readLine()).remove("\r").remove("\n");
        QString borderColor = QString(file.readLine()).remove("\r").remove("\n");
        QString disabeledBorderColor = QString(file.readLine()).remove("\r").remove("\n");
        QString backgroundColor = QString(file.readLine()).remove("\r").remove("\n");
        QString disabledBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
        QString gradientBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
        QString disabledGradientBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
        QString handlesBackgroundColor = QString(file.readLine()).remove("\r").remove("\n");
        QString mainBackground = QString(file.readLine()).remove("\r").remove("\n");
        QString pathIcons = Paths::documents() + "theme/";
        file.close();
        QFile qssColorFile(":/theme/greenTheme.qss");
        qssColorFile.open(QFile::ReadOnly);
        qss = QString(qssColorFile.readAll()).arg(textColor,
                                                  labelValue,
                                                  hoverColor,
                                                  disabledColor,
                                                  borderColor,
                                                  disabeledBorderColor,
                                                  backgroundColor,
                                                  disabledBackgroundColor,
                                                  gradientBackgroundColor,
                                                  disabledGradientBackgroundColor,
                                                  handlesBackgroundColor,
                                                  mainBackground);
        QFile qssIconsFile(":/theme/baseIcons.qss");
        qssIconsFile.open(QFile::ReadOnly);
        qss += QString(qssIconsFile.readAll()).arg(pathIcons);

        QFile qssFile(":/theme/globalTheme.qss");
        qssFile.open(QFile::ReadOnly);
        qss += qssFile.readAll();
        qss += " "
        "QWidget, QStandardItem, QAbstractItemModel, QLabel { "
            "font: " + Settings::defaultFont() + "; "
        "} ";

        return qss;
        break;
    }
    }
    QFile qssColorFile(":/theme/baseColor.qss");
    qssColorFile.open(QFile::ReadOnly);
    qss = QString(qssColorFile.readAll()).arg(textColor,
                                              disabledBackgroundColor,
                                              disabledColor,
                                              hoverColor,
                                              borderColor,
                                              alternateColor,
                                              backgroundColor,
                                              backgroundSelectedItem,
                                              backgroundSecondColor,
                                              backgroundProgressbar,
                                              backgroundBadProgressbar,
                                              backgroundProgressbarProgress,
                                              selectedColor,
                                              headerFormColor,
                                              backgroundItemColor,
                                              backgroundAlternateItemColor,
                                              forItemHoverGradient,
                                              mainProfileBackground,
                                              mainBackground);

    QFile qssIconsFile(":/theme/baseIcons.qss");
    qssIconsFile.open(QFile::ReadOnly);
    qss += QString(qssIconsFile.readAll()).arg(pathIcons);

    QFile qssFile(":/theme/globalTheme.qss");
    qssFile.open(QFile::ReadOnly);
    qss += qssFile.readAll();
    qss += " "
    "QWidget, QStandardItem, QAbstractItemModel, QLabel { "
        "font: " + Settings::defaultFont() + "; "
    "} ";
    return qss;
}

QString Settings::iconsColor() {
    switch(theme()) {
    case 1: {
        return "white";
    }
    case 2: {
        return "black";
    }
    case 3: {
        return "white";
    }
    case 4: {
        return "white";
    }
    case 5: {
        return "white";
    }
    case 6: {
        return "white";
    }
    case 7: {
        return "white";
    }
    case 8: {
        return "white";
    }
    default: {
        return "white";
    }
    }
}

void Settings::syncronizeSettings() {
    _settings->sync();
}

#include <QDir>
#define PathsStart {
QString Paths::documents() {
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::temp() {
    return QDir::tempPath() + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::desktop() {
    return QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/";
}

QString Paths::defaultFont() {
    return "://font.ttf";
}
#define PathsEnd }
