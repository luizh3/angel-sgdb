import QtQuick 2.7
import QtQuick.Controls 2.15

import AngelTheme 1.0

MenuItem {
    id: root
    height: 50

    background: Rectangle {
        implicitWidth: root.width
        implicitHeight: root.height
        color: root.hovered ? AngelColor.secundary : AngelColor.hoverGray
        radius: AngelMetric.radius.small
    }
    contentItem: Text {
        id: txtLabel
        anchors.fill: parent
        text: root.text
        font.pixelSize: AngelMetric.fontSize.normal
        color: AngelColor.text.primary
        verticalAlignment: Text.AlignVCenter
        anchors.left: parent.left
        anchors.leftMargin: 8
    }
}
