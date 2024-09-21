import QtQuick 2.7
import QtQuick.Controls 2.15

import AngelTheme 1.0

Button {
    id: root
    font.pixelSize: AngelFont.size.small
    font.bold: true
    palette.buttonText: AngelColor.text.primary

    property alias mouseArea: mouseArea
    property alias loading: loading

    background: Rectangle {
        color: AngelColor.hoverGray
        border.color: AngelColor.hoverGray
        border.width: AngelMetric.border.width.medium
        radius: AngelMetric.radius.small
    }

    MouseArea {
        id: mouseArea
        anchors.fill: root
        hoverEnabled: true
    }

    AngelLoading {
        id: loading
        anchors.fill: parent
        anchors.centerIn: parent
        visible: false
        size: 30
        lineWidth: 3
    }
}
