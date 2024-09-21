pragma Singleton

import QtQuick 2.7

QtObject {
    readonly property string primary: "#ffc300"
    readonly property string secundary: "#1d1d1d"
    readonly property string gray: "#E0E0E0"
    readonly property string white: "#FFFFFF"
    readonly property string black: "#000000"
    readonly property string transparent: "transparent"
    readonly property string hoverGray: "#2b2b2b"
    readonly property string green: "#28ca8e"
    readonly property string orange: "#ffc300"

    readonly property string red: "#f70000"
    readonly property string red400: "#f87171"

    readonly property string neutral600: "#525252"
    readonly property string neutral200: "#e5e5e5"

    readonly property QtObject text: QtObject {
        readonly property string primary: "#FFFFFF"
    }
}
