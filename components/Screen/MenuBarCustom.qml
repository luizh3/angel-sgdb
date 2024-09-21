import QtQuick 2.15
import QtQuick.Controls 2.15

import Angel 1.0
import AngelTheme 1.0

MenuBar {
    id: menuBar

    background: Rectangle {
        color: AngelColor.hoverGray
    }

    signal query
    signal keyboardShortcuts

    component MenuBarItemCustom: MenuBarItem {
        id: menuBarItemCustom

        property string title

        background: Rectangle {
            color: AngelColor.hoverGray
        }

        contentItem: Text {
            text: menuBarItemCustom.title
            font.pixelSize: 16
            color: AngelColor.white
        }
    }

    MenuBarItemCustom {
        title: qsTr("Tools")
        menu: AngelMenu {

            AngelMenuItem {
                text: qsTr("Query")
                width: parent.width
                onTriggered: menuBar.query()
            }
        }
    }

    MenuBarItemCustom {
        title: qsTr("Edit")
        menu: AngelMenu {

            AngelMenuItem {
                text: qsTr("Keyboard Shortcuts")
                width: parent.width
                onTriggered: menuBar.keyboardShortcuts()
            }
        }
    }
}
