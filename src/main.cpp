/*
 * Copyright (c) 2020-2021 Alex Spataru <https://github.com/alex-spataru>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <QtQml>
#include <QSysInfo>
#include <QQuickStyle>
#include <QApplication>
#include <QStyleFactory>
#include <QQmlApplicationEngine>

#include <Logger.h>
#include <FileAppender.h>
#include <ConsoleAppender.h>

#include <QSimpleUpdater.h>

#include "AppInfo.h"
#include "Utilities.h"
#include "Translator.h"

/**
 * @brief Entry-point function of the application
 *
 * @param argc argument count
 * @param argv argument data
 *
 * @return qApp exit code
 */
int main(int argc, char **argv)
{
    // Set application attributes
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Init. application
    QApplication app(argc, argv);
    app.setApplicationName(APP_NAME);
    app.setApplicationVersion(APP_VERSION);
    app.setOrganizationName(APP_DEVELOPER);
    app.setOrganizationDomain(APP_SUPPORT_URL);
    app.setStyle(QStyleFactory::create("Fusion"));

    // Configure CuteLogger
    auto fileAppender = new FileAppender;
    auto consoleAppender = new ConsoleAppender;
    fileAppender->setFormat(LOG_FORMAT);
    fileAppender->setFileName(LOG_FILE);
    consoleAppender->setFormat(LOG_FORMAT);
    cuteLogger->registerAppender(fileAppender);
    cuteLogger->registerAppender(consoleAppender);

    // Begin logging
    LOG_INFO() << "Running on"
               << QSysInfo::prettyProductName().toStdString().c_str();
    LOG_INFO() << QDateTime::currentDateTime();

    // Init application modules
    Utilities utilities;
    Translator translator;
    QQmlApplicationEngine engine;
    auto updater = QSimpleUpdater::getInstance();

    // Log status
    LOG_INFO() << "Finished creating application modules";

    // Init QML interface
    auto c = engine.rootContext();
    QQuickStyle::setStyle("Fusion");
    c->setContextProperty("CppUpdater", updater);
    c->setContextProperty("CppUtilities", &utilities);
    c->setContextProperty("CppTranslator", &translator);
    c->setContextProperty("CppAppIcon", "qrc" APP_ICON);
    c->setContextProperty("CppAppName", app.applicationName());
    c->setContextProperty("CppAppUpdaterUrl", APP_UPDATER_URL);
    c->setContextProperty("CppAppVersion", app.applicationVersion());
    c->setContextProperty("CppAppOrganization", app.organizationName());
    c->setContextProperty("CppAppOrganizationDomain", app.organizationDomain());
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    // Log QML engine status
    LOG_INFO() << "Finished loading QML interface";

    // QML error, exit
    if (engine.rootObjects().isEmpty())
    {
        LOG_WARNING() << "QML engine error";
        return EXIT_FAILURE;
    }

    // Configure the updater
    LOG_INFO() << "Configuring QSimpleUpdater...";
    updater->setNotifyOnUpdate(APP_UPDATER_URL, true);
    updater->setNotifyOnFinish(APP_UPDATER_URL, false);
    updater->setMandatoryUpdate(APP_UPDATER_URL, false);
    LOG_INFO() << "QSimpleUpdater configuration finished!";

    // Enter application event loop
    auto code = app.exec();
    LOG_INFO() << "Application exit code" << code;
    return code;
}
