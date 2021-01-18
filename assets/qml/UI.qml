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
            border.color: palette.alternateBase

            anchors {
                fill: parent
                topMargin: -border.width
                leftMargin: -border.width * 10
                rightMargin: -border.width * 10
            }

            gradient: Gradient {
                GradientStop { position: 1; color: "#222" }
                GradientStop { position: 0; color: "#444" }
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
                text: qsTr("Check for updates") + CppTranslator.dummy
                onClicked: {
                    CppUpdater.setNotifyOnFinish(CppAppUpdaterUrl, true)
                    CppUpdater.checkForUpdates(CppAppUpdaterUrl)
                }
            }

            Button {
                flat: true
                icon.width: 24
                icon.height: 24
                Layout.fillHeight: true
                icon.color: palette.text
                icon.source: "qrc:/icons/bug.svg"
                onClicked: CppUtilities.openLogFile()
                text: qsTr("Application log") + CppTranslator.dummy
            }

            Item {
                Layout.fillWidth: true
            }

            Label {
                Layout.alignment: Qt.AlignVCenter
                text: qsTr("Language") + ":" + CppTranslator.dummy
            }

            ComboBox {
                Layout.alignment: Qt.AlignVCenter
                model: CppTranslator.availableLanguages
                onCurrentIndexChanged: CppTranslator.setLanguage(currentIndex)
            }
        }
    }

    //
    // Background color
    //
    background: Rectangle {
        color: "#35354a"
    }

    //
    // Image, labels & buttons
    //
    ColumnLayout {
        spacing: app.spacing
        anchors.centerIn: parent

        Image {
            source: CppAppIcon
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
            text: qsTr("Hello World") + CppTranslator.dummy
        }

        Label {
            font.pixelSize: 18
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Click on any button") + CppTranslator.dummy
        }

        Item {
            Layout.minimumHeight: app.spacing
        }

        Button {
            icon.color: palette.text
            Layout.minimumWidth: 156
            Layout.alignment: Qt.AlignHCenter
            icon.source: "qrc:/icons/close.svg"
            text: qsTr("Close") + CppTranslator.dummy
            onClicked: app.close()
        }

        Button {
            icon.color: palette.text
            Layout.minimumWidth: 156
            Layout.alignment: Qt.AlignHCenter
            icon.source: "qrc:/icons/website.svg"
            text: qsTr("Visit website") + CppTranslator.dummy
            onClicked: Qt.openUrlExternally(CppAppOrganizationDomain)
        }
    }
}
