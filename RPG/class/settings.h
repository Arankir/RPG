#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QFile>
#include <QRect>
#include <QLoggingCategory>
#include <QFontDatabase>
#include <QApplication>
#include <QStandardPaths>

class Settings {
public:
    static const QString c_organizationName;
    static const QString c_organizationDomain;
    static const QString c_applicationName;

    static void setLanguage(const int &language);
    static int language();
    static void setTheme(const int &theme);
    static int theme();
    static void setTimeOnChat(const int &time);
    static int timeOnChat();

    static void setMainWindowParams(QRect geometry);
    static QRect mainWindowGeometry();
    static void setMainWindowPos(const QPoint &pos);
    static QPoint mainWindowPos();
    static void setMainWindowIsMaximize(bool maximize);
    static bool isMainWindowMaximize();

    static QString iconsColor();
    static QString defaultFont();
    static QString qssTheme();

    static void syncronizeSettings();

    static const QString dateTimeFormat();
    static const QString dateFormat();
    static const QString dateTimeFormatShort();
private:
    static QSettings *_settings;

};

class Paths {
public:
    static QString documents();
    static QString temp();
    static QString desktop();
    static QString defaultFont();
};

#endif // SETTINGS_H
