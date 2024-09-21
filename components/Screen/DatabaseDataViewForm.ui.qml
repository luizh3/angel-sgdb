import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.0

import View.Model.TableDataModel 1.0

import Angel 1.0
import AngelTheme 1.0

Rectangle {
    radius: AngelMetric.radius.small
    color: AngelColor.hoverGray

    property TableDataModel tableDataModel: TableDataModel {}
    ColumnLayout {
        anchors.margins: AngelMetric.margins.defaultValue
        anchors.fill: parent

        Text {
            text: "Tables"
            font.pixelSize: 18
            font.bold: true
            color: AngelColor.white
        }

        ListView {
            id: listView
            Layout.fillHeight: true
            Layout.fillWidth: true

            model: tableDataModel
            clip: true
            spacing: 8
            delegate: Component {
                Item {
                    width: listView.width
                    height: row.height + (column.visible ? column.height : 0)

                    RowLayout {
                        id: row
                        width: parent.width
                        height: 32

                        Image {
                            source: "/resources/table.png"
                            clip: true
                            Layout.preferredHeight: 20
                            Layout.preferredWidth: 20
                            Layout.alignment: Qt.AlignVCenter
                        }

                        Text {
                            text: name
                            font.pixelSize: 16
                            color: "White"
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.alignment: Qt.AlignVCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    MouseArea {
                        anchors.fill: row
                        hoverEnabled: true
                        onClicked: column.visible = !column.visible
                    }

                    ColumnLayout {
                        id: column
                        width: parent.width
                        anchors.top: row.bottom
                        anchors.topMargin: 4
                        visible: false

                        Repeater {
                            model: columns
                            Layout.fillWidth: true

                            Text {
                                Layout.leftMargin: 28
                                width: parent.width
                                text: modelData.name
                                font.pixelSize: 14
                                color: "white"
                            }
                        }
                    }
                }
            }
        }
    }
}
