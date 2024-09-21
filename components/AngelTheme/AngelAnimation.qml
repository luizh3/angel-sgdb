pragma Singleton

import QtQuick 2.7

QtObject {
    readonly property QtObject duration: QtObject {
        readonly property int minimum: 150
    }
}
