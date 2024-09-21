import QtQuick 2.7
import QtQuick.Controls 2.15

import AngelTheme 1.0

Column {
    spacing: 5

    property alias text: text.text
    property alias input: input
    property alias value: input.text

    Text {
        id: text
        font.family: AngelMetric.fontFamily
        font.pixelSize: 18
        color: AngelColor.text.primary
        font.bold: true
    }

    TextField {
        id: input
        width: parent.width
        height: parent.height - text.height

        color: AngelColor.text.primary
        font.pixelSize: 14

        background: Rectangle {
            border.color: input.focus ? AngelColor.primary : AngelColor.hoverGray
            radius: AngelMetric.radius.small
            color: AngelColor.hoverGray
        }
    }
}
