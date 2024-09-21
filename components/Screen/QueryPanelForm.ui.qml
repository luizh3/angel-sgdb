import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.13

import AngelTheme 1.0

import Model.TextDocumentHandlerModel 1.0

Rectangle {

    property alias textArea: textArea
    property alias textDocumentHandler: textDocumentHandler
    color: AngelColor.secundary

    TextDocumentHandlerModel {
        id: textDocumentHandler
        document: textArea.textDocument
    }
    RowLayout {
        anchors.fill: parent

        Column {
            width: 40
            Layout.fillHeight: true
            spacing: 1
            Repeater {
                model: textArea.lineCount
                width: parent.width

                Rectangle {
                    id: rectangle
                    width: parent.width
                    height: 18
                    color: AngelColor.secundary

                    property bool isCurrentRow: textArea.cursorRectangle.y === rectangle.y

                    Text {
                        text: index + 1
                        color: rectangle.isCurrentRow ? AngelColor.white : AngelColor.neutral200
                        anchors.centerIn: parent
                    }
                }
            }
        }

        TextArea {
            id: textArea
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: "select * from article;"
            selectByMouse: true
            mouseSelectionMode: TextEdit.SelectCharacters
            color: AngelColor.white
            selectionColor: AngelColor.hoverGray
            padding: 0
            topInset: 0
            textMargin: 0
            font.letterSpacing: 0
            font.wordSpacing: 0
            background: Rectangle {
                color: AngelColor.secundary

                Rectangle {
                    visible: textArea.selectedText.length === 0
                    width: parent.width
                    height: textArea.cursorRectangle.height
                    color: AngelColor.hoverGray
                    y: textArea.cursorRectangle.y
                    radius: 2
                }
            }
            font.pixelSize: 16
        }
    }
}
