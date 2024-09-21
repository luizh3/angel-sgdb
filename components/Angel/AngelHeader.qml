import QtQuick 2.7
import QtQuick.Controls 2.15

import AngelTheme 1.0

AngelRectangle {
    id: root
    width: parent.width
    height: 75
    color: AngelColor.hoverGray
    topLeftRadius: AngelMetric.radius.small
    topRightRadius: AngelMetric.radius.small

    property alias title: title
    property alias closeButton: closeButton

    signal close

    Text {
        id: title
        font.pixelSize: AngelMetric.fontSize.title
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: AngelMetric.margins.defaultValue
        font.family: AngelMetric.fontFamily
        color: AngelColor.text.primary
        font.bold: true
    }

    Button {
        id: closeButton
        anchors.right: parent.right
        anchors.rightMargin: AngelMetric.margins.defaultValue
        anchors.verticalCenter: parent.verticalCenter
        icon.source: "/resources/close.png"
        icon.color: AngelColor.text.primary
        background: Rectangle {
            color: "transparent"
        }

        onClicked: function handleClick() {
            root.close()
        }
    }
}
