import QtQuick 2.15
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.15

import AngelTheme 1.0

Rectangle {
    id: root
    width: 400
    height: 80
    color: AngelColor.hoverGray

    property alias icon: icon
    property alias barStatus: barStatus

    property string title
    property string description

    Rectangle {
        id: barStatus
        width: 10
        height: parent.height
        anchors.left: parent.left
    }

    Image {
        id: icon
        width: 24
        height: 24
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: barStatus.right
        anchors.leftMargin: AngelMetric.margins.defaultValue
    }

    ColumnLayout {
        anchors.left: icon.right
        anchors.leftMargin: AngelMetric.margins.defaultValue
        anchors.right: closeButton.left
        anchors.rightMargin: AngelMetric.margins.defaultValue
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width

        Label {
            font.pixelSize: AngelFont.size.medium
            font.bold: true
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            color: AngelColor.text.primary
            text: root.title
        }

        Label {
            font.pixelSize: AngelFont.size.verySmall
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            color: AngelColor.text.primary
            text: root.description
        }
    }

    Button {
        id: closeButton
        anchors.right: parent.right
        anchors.rightMargin: AngelMetric.margins.defaultValue
        anchors.verticalCenter: parent.verticalCenter
        icon.source: "/resources/close.png"
        icon.color: AngelColor.text.primary
        background: Rectangle {
            color: AngelColor.transparent
        }
    }
}
