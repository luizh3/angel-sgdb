import QtQuick 2.15
import QtQuick.Layouts 1.3

import AngelTheme 1.0

KeyboardShortcutsModalForm {
    id: root

    header.title.text: qsTr("Keyboard Shortcuts")
    header.onClose: root.close()

    component KeywordIcon: Rectangle {
        id: keyboardIcon
        width: textKeyword.width
        height: textKeyword.height

        required property string keyword

        radius: AngelMetric.radius.small
        border.color: AngelColor.hoverGray
        color: AngelColor.hoverGray

        Text {
            id: textKeyword
            text: keyboardIcon.keyword
            anchors.centerIn: parent
            font.pixelSize: 14
            padding: AngelMetric.margins.defaultValue
            font.bold: true
            color: AngelColor.white
        }
    }

    component ShortcutElement: RowLayout {
        id: shortcutElement
        spacing: 0
        height: 40

        required property string description
        required property string keyword

        Text {
            text: shortcutElement.description
            Layout.preferredHeight: shortcutElement.height
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 16
            color: AngelColor.white
        }
        KeywordIcon {
            keyword: shortcutElement.keyword
            Layout.preferredHeight: shortcutElement.height
            Layout.alignment: Qt.AlignRight
        }
    }

    Item {
        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            margins: 16
        }

        width: parent.width
        height: parent.height - header.height

        ShortcutElement {
            width: parent.width
            description: qsTr("Run Query")
            keyword: "F5"
        }
    }
}
