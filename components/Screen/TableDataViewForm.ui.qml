import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15

import Angel 1.0
import AngelTheme 1.0

import View.Model.TableQueryResultModel 1.0

AngelRectangle {
    id: root

    color: AngelColor.hoverGray
    bottomLeftRadius: AngelMetric.radius.small
    bottomRightRadius: AngelMetric.radius.small

    property string dsQuery

    property alias horizontalHeader: horizontalHeader
    property alias tableQueryResultModel: tableQueryResultModel

    Rectangle {
        color: AngelColor.secundary

        anchors {
            right: horizontalHeader.left
            bottom: verticalHeader.top
            left: parent.left
            top: parent.top
            rightMargin: 1
            bottomMargin: 1
        }
    }

    HorizontalHeaderView {
        id: horizontalHeader
        syncView: tableView
        anchors.top: parent.top
        anchors.left: tableView.left
        clip: true
        delegate: Rectangle {
            color: AngelColor.secundary
            implicitHeight: textHorizontal.height
            implicitWidth: textHorizontal.width

            Text {
                id: textHorizontal
                text: display
                color: AngelColor.white
                font.pixelSize: 14
                anchors.verticalCenter: parent.verticalCenter
                padding: 10
                font.bold: true
            }
        }
    }

    VerticalHeaderView {
        id: verticalHeader
        anchors.top: tableView.top
        anchors.left: parent.left
        syncView: tableView
        clip: true
        delegate: Rectangle {
            color: AngelColor.secundary
            implicitHeight: textVertical.height
            implicitWidth: textVertical.width

            Text {
                id: textVertical
                text: display
                color: AngelColor.white
                font.pixelSize: 12
                anchors.centerIn: parent
                padding: 10
            }
        }
    }

    TableView {
        id: tableView
        height: parent.height - horizontalHeader.height
        width: parent.width
        columnSpacing: 1
        rowSpacing: 1
        clip: true
        flickableDirection: Flickable.VerticalFlick
        visible: tableView.hasError
        // boundsMovement: Flickable.StopAtBounds
        // boundsBehavior: Flickable.DragOverBounds
        property bool hasError: tableQueryResultModel.dsError.length === 0
        property int selectedRow: -1

        anchors {
            left: verticalHeader.right
            top: horizontalHeader.bottom
            right: parent.right
            bottom: parent.bottom
            margins: 1
        }

        model: TableQueryResultModel {
            id: tableQueryResultModel
            dsQuery: root.dsQuery
        }

        delegate: ItemDelegate {
            implicitWidth: 400
            implicitHeight: 25

            highlighted: row === tableView.selectedRow
            onClicked: tableView.selectedRow = row

            Rectangle {
                color: highlighted ? AngelColor.neutral600 : AngelColor.secundary
                anchors.fill: parent

                Text {
                    id: text
                    text: model.display
                    anchors.centerIn: parent
                    elide: Text.ElideRight
                    width: 400
                    height: 25
                    wrapMode: Text.Wrap
                    color: AngelColor.white
                    verticalAlignment: Text.AlignVCenter
                    padding: 10
                }
            }
        }
    }

    Text {
        anchors.centerIn: parent
        text: tableQueryResultModel.dsError
        visible: !tableView.visible
        font.pixelSize: 16
        color: AngelColor.red400
    }
}
