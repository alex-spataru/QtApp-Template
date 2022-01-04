#pragma once

#include <QDir>
#include <QString>

// clang-format off
#define APP_VERSION     "1.0.0"
#define APP_DEVELOPER   "Awesome Developer"
#define APP_NAME        "Qt App"
#define APP_ICON        ":/images/icon.svg"
#define APP_SUPPORT_URL "https://github.com/alex-spataru/QtApp-Template"
#define APP_UPDATER_URL "https://raw.githubusercontent.com/alex-spataru/QtApp-Template/master/deploy/updates.json"
#define LOG_FORMAT      "[%{time}] %{message:-72} [%{TypeOne}] [%{function}]\n"
#define LOG_FILE        QString("%1/%2.log").arg(QDir::tempPath(), APP_NAME)
// clang-format on
