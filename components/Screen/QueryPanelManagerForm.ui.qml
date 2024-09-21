import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15

import AngelTheme 1.0
import Angel 1.0

AngelRectangle {
    id: root

    color: AngelColor.hoverGray
    topLeftRadius: AngelMetric.radius.small
    topRightRadius: AngelMetric.radius.small

    property alias tabBar: tabBar
    property alias currentIndex: tabBar.currentIndex
    property alias stackLayout: stackLayout
    property alias tabsModel: root.tabsModel

    signal runQuery(var dsQuery)

    property ListModel tabsModel: ListModel {
        ListElement {
            title: "Query"
        }
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        spacing: 0

        AngelRectangle {
            Layout.fillWidth: true
            color: AngelColor.neutral600
            topLeftRadius: AngelMetric.radius.small
            topRightRadius: AngelMetric.radius.small
            Layout.alignment: Qt.AlignTop
            height: 50

            TabBar {
                id: tabBar
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter
                spacing: 0

                Repeater {
                    id: repeater
                    model: root.tabsModel

                    TabButton {
                        id: button
                        height: 50

                        property bool isFirst: index === 0
                        property bool isLast: index === repeater.count - 1
                        property bool isSelected: tabBar.currentIndex === index

                        background: AngelRectangle {
                            color: button.isSelected ? AngelColor.hoverGray : AngelColor.neutral600
                            topLeftRadius: button.isFirst ? AngelMetric.radius.small : 0
                            topRightRadius: button.isLast ? AngelMetric.radius.small : 0
                        }

                        contentItem: Item {

                            property alias buttonClose: buttonClose

                            Button {
                                id: buttonClose
                                icon.source: "/resources/close.png"
                                display: AbstractButton.IconOnly
                                icon.color: AngelColor.text.primary
                                anchors.right: parent.right
                                anchors.verticalCenter: parent.verticalCenter
                                visible: root.tabsModel.count > 1
                                background: Rectangle {
                                    color: AngelColor.transparent
                                }

                                Connections {
                                    function onClicked() {
                                        handleRemoveTab(index)
                                    }
                                }
                            }

                            Text {
                                text: `${model.title} #${index + 1}`
                                color: AngelColor.white
                                font.bold: true
                                font.pixelSize: 14
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }

        AngelRectangle {
            color: AngelColor.secundary
            Layout.fillHeight: true
            Layout.fillWidth: true
            borderColor: AngelColor.hoverGray
            borderWidth: 2

            ScrollView {
                id: view
                anchors.fill: parent
                anchors.margins: 2
                padding: 16

                StackLayout {
                    id: stackLayout
                    anchors.fill: parent
                    currentIndex: 0

                    Repeater {
                        model: root.tabsModel

                        QueryPanel {
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            Connections {
                                function onRunQuery(dsQuery) {
                                    root.runQuery(dsQuery)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
