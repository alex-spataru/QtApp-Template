import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Page {
    id: root

    header: ToolBar {
        height: 48

        RowLayout {
            spacing: app.spacing
            anchors.fill: parent
            anchors.margins: app.spacing

            Button {
                flat: true
                icon.width: 24
                icon.height: 24
                Layout.fillHeight: true
                icon.source: "qrc:/icons/update.svg"
                text: qsTr("Check for updates") + CppTranslator.dummy
                onClicked: {
                    CppUpdater.setNotifyOnFinish(CppAppUpdaterUrl, true)
                    CppUpdater.checkForUpdates(CppAppUpdaterUrl)
                }
            }
        }
    }

    ColumnLayout {
        spacing: app.spacing
        anchors.centerIn: parent

        Image {
            source: "qrc:/images/Qt.svg"
            sourceSize: Qt.size(320, 235)
            Layout.alignment: Qt.AlignHCenter
        }

        Item {
            Layout.minimumHeight: app.spacing
        }

        Label {
            font.bold: true
            font.pixelSize: 24
            text: qsTr("Hello World")
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            font.pixelSize: 18
            text: qsTr("Click on any button")
            Layout.alignment: Qt.AlignHCenter
        }

        Item {
            Layout.minimumHeight: app.spacing
        }

        Button {
            onClicked: app.close()
            Layout.minimumWidth: 128
            Layout.alignment: Qt.AlignHCenter
            icon.source: "qrc:/icons/close.svg"
            text: qsTr("Close") + CppTranslator.dummy
        }

        Button {
            Layout.minimumWidth: 128
            Layout.alignment: Qt.AlignHCenter
            icon.source: "qrc:/icons/website.svg"
            text: qsTr("Visit website") + CppTranslator.dummy
            onClicked: Qt.openUrlExternally(CppAppOrganizationDomain)
        }
    }
}
