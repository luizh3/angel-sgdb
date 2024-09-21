import QtQuick 2.15
import QtQuick.Window 2.0
import QtQuick.Controls 2.15

import AngelTheme 1.0

AngelToastForm {
    id: root
    parent: Overlay.overlay

    anchors {
        right: parent.right
        top: parent.top
        topMargin: AngelMetric.margins.defaultValue
        rightMargin: AngelMetric.margins.defaultValue
    }

    enum Types {
        WARNING,
        ERROR,
        SUCCESS
    }

    SequentialAnimation {
        running: true
        OpacityAnimator {
            target: root
            from: 0
            to: 1
            duration: 250
        }
        NumberAnimation {
            duration: 5000
        }
        OpacityAnimator {
            target: root
            from: 1
            to: 0
            duration: 250
        }
    }

    states: [
        State {
            name: AngelToast.Types.WARNING
            PropertyChanges {
                target: barStatus
                color: AngelColor.orange
            }
            PropertyChanges {
                target: icon
                source: "/resources/warning.png"
            }
        },
        State {
            name: AngelToast.Types.ERROR
            PropertyChanges {
                target: barStatus
                color: AngelColor.red
            }
            PropertyChanges {
                target: icon
                source: "/resources/error.png"
            }
        },
        State {
            name: AngelToast.Types.SUCCESS
            PropertyChanges {
                target: barStatus
                color: AngelColor.green
            }
            PropertyChanges {
                target: icon
                source: "/resources/success.png"
            }
        }
    ]
}
