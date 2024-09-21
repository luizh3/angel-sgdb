import QtQuick 2.7
import QtQuick.Controls 2.15

import AngelTheme 1.0

Rectangle {
    id: root
    focus: true
    anchors.centerIn: parent
    radius: AngelMetric.radiusDefault
    color: AngelColor.secundary
    property alias header: header

    signal close

    AngelHeader {
        id: header
    }
}
