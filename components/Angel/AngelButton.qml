import QtQuick 2.7
import QtQuick.Controls 2.15

import AngelTheme 1.0

AngelButtonForm {
    id: root
    height: 40

    property bool hasLoading: true
    property var _state: AngelButton.States.Default

    enum States {
        Default,
        Loading,
        Success
    }

    function handleOnClick() {

        if (hasLoading) {
            root._state = AngelButton.States.Loading
        }
        root.clicked()
    }

    function isEnableByState() {
        var statesDisabled = [AngelButton.States.Loading, AngelButton.States.Success]
        return !statesDisabled.includes(root._state)
    }

    function setState(state) {
        root._state = state
    }

    enabled: root.isEnableByState()
    mouseArea.onClicked: root.handleOnClick()

    transitions: [
        Transition {
            ColorAnimation {
                duration: AngelAnimation.duration.minimum
            }
        }
    ]

    states: [
        State {
            name: "Loading"
            when: root._state === AngelButton.States.Loading

            PropertyChanges {
                target: loading
                visible: true
            }
            PropertyChanges {
                target: contentItem
                visible: false
            }
            PropertyChanges {
                target: root
                enabled: false
            }
        },
        State {
            name: "Default"
            when: root._state === AngelButton.States.Default

            PropertyChanges {
                target: loading
                visible: false
            }
            PropertyChanges {
                target: contentItem
                visible: true
            }
            PropertyChanges {
                target: background
                color: mouseArea.containsMouse ? AngelColor.primary : AngelColor.hoverGray
                border.color: mouseArea.containsMouse ? AngelColor.primary : AngelColor.hoverGray
            }
        },
        State {
            name: "Success"
            when: root._state === AngelButton.States.Success

            PropertyChanges {
                target: loading
                visible: false
            }
            PropertyChanges {
                target: contentItem
                text: "Success!"
                visible: true
            }
            PropertyChanges {
                target: background
                color: AngelColor.green
                border.color: AngelColor.green
            }
            PropertyChanges {
                target: root
                enabled: false
            }
        }
    ]
}
