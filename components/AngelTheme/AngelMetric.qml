pragma Singleton

import QtQuick 2.7

QtObject {
    readonly property int radiusDefault: 4

    readonly property QtObject border: QtObject {
        readonly property QtObject width: QtObject {
            readonly property int medium: 4
        }
    }

    readonly property QtObject radius: QtObject {
        readonly property int small: 4
    }

    readonly property QtObject margins: QtObject {
        readonly property int defaultValue: 16
    }

    readonly property QtObject fontSize: QtObject {
        readonly property int title: 24
        readonly property int normal: 16
    }

    readonly property QtObject spacing: QtObject {
        readonly property int defaultValue: 16
        readonly property int horizontal: 16
        readonly property int vertical: 28
    }

    readonly property QtObject color: QtObject {
        readonly property string text: "#404040"
    }

    readonly property string fontFamily: "Calibri"
}
