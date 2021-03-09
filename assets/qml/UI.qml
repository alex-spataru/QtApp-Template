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

import QtQuick 2.12
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Page {
    id: root

    //
    // Toolbar with buttons
    //
    header: ToolBar {
        height: 48

        //
        // Background gradient
        //
        Rectangle {
            border.width: 1
            border.color: palette.midlight

            gradient: Gradient {
                GradientStop { position: 0; color: "#21373f" }
                GradientStop { position: 1; color: "#11272f" }
            }

            anchors {
                fill: parent
                topMargin: -border.width
                leftMargin: -border.width * 10
                rightMargin: -border.width * 10
            }
        }

        //
        // Toolbar controls
        //
        RowLayout {
            spacing: app.spacing
            anchors.fill: parent
            anchors.margins: app.spacing

            Button {
                flat: true
                icon.width: 24
                icon.height: 24
                Layout.fillHeight: true
                icon.color: palette.text
                icon.source: "qrc:/icons/update.svg"
                text: qsTr("Check for updates")
                onClicked: {
                    Cpp_Updater.setNotifyOnFinish(Cpp_AppUpdaterUrl, true)
                    Cpp_Updater.checkForUpdates(Cpp_AppUpdaterUrl)
                }
            }

            Button {
                flat: true
                icon.width: 24
                icon.height: 24
                Layout.fillHeight: true
                icon.color: palette.text
                icon.source: "qrc:/icons/bug.svg"
                text: qsTr("Application log")
                onClicked: Cpp_Misc_Utilities.openLogFile()
            }

            Item {
                Layout.fillWidth: true
            }

            Label {
                Layout.alignment: Qt.AlignVCenter
                text: qsTr("Language") + ":"
            }

            ComboBox {
                Layout.alignment: Qt.AlignVCenter
                model: Cpp_Misc_Translator.availableLanguages
                onCurrentIndexChanged: Cpp_Misc_Translator.setLanguage(currentIndex)
            }
        }
    }

    //
    // Background color
    //
    background: Rectangle {
        color: app.windowBackgroundColor
    }

    //
    // Image, labels & buttons
    //
    ColumnLayout {
        spacing: app.spacing
        anchors.centerIn: parent

        Image {
            source: Cpp_AppIcon
            sourceSize: Qt.size(256, 188)
            Layout.alignment: Qt.AlignHCenter
        }

        Item {
            Layout.minimumHeight: app.spacing
        }

        Label {
            font.bold: true
            font.pixelSize: 24
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Hello World")
        }

        Label {
            font.pixelSize: 18
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Click on any button")
        }

        Item {
            Layout.minimumHeight: app.spacing
        }

        Button {
            icon.color: palette.text
            Layout.minimumWidth: 156
            Layout.alignment: Qt.AlignHCenter
            icon.source: "qrc:/icons/close.svg"
            text: qsTr("Close")
            onClicked: app.close()
        }

        Button {
            icon.color: palette.text
            Layout.minimumWidth: 156
            Layout.alignment: Qt.AlignHCenter
            icon.source: "qrc:/icons/website.svg"
            text: qsTr("Visit website")
            onClicked: Qt.openUrlExternally(Cpp_AppOrganizationDomain)
        }
    }
}
