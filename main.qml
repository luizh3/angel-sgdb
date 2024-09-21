import QtQuick 2.15

import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.15
import Qt.labs.qmlmodels 1.0
import Control.MainScreenControl 1.0
import Control.DatabaseControl 1.0

import View.Model.TableDataModel 1.0
import View.Model.TableQueryResultModel 1.0

import "components/connection"
import "components/Screen"

import Angel 1.0
import AngelTheme 1.0

ApplicationWindow {
    id: mainWindow
    width: 1280
    height: 960
    visible: true
    title: qsTr("Hello World")
    color: AngelColor.secundary

    function handleAddQuery() {
        loader.item.queryPanelManager.addTab()
    }

    function handleKeyboardShortcuts() {
        popupManager.push(keyboardShortcutsComponent)
    }

    menuBar: MenuBarCustom {
        onQuery: mainWindow.handleAddQuery()
        onKeyboardShortcuts: mainWindow.handleKeyboardShortcuts()
    }

    PopupManager {
        id: popupManager
        anchors.fill: parent
    }

    ToastManager {
        id: toastManager
    }

    Component {
        id: connectionDatabaseComponent
        ConnectionDatabase {}
    }

    Component {
        id: keyboardShortcutsComponent
        KeyboardShortcutsModal {}
    }

    DatabaseControl {
        id: databaseControl
    }

    MainScreenControl {
        id: control

        onShowToastError: function handleToastError(title, description) {
            toastManager.error(title, description)
        }

        onShowToastSuccess: function handleToastSuccess(title, description) {
            toastManager.success(title, description)
        }

        onShowToastWarning: function handleToastWarning(title, description) {
            toastManager.warning(title, description)
        }
    }

    Component.onCompleted: {
        var popup = popupManager.push(connectionDatabaseComponent)
        popup.success.connect(function handleSuccess() {
            popup.success.disconnect(handleSuccess)
            loader.sourceComponent = mainComponent
        })
    }

    Loader {
        id: loader
        anchors.fill: parent
    }

    Component {
        id: mainComponent

        Item {
            anchors.fill: parent

            property alias queryPanelManager: queryPanelManager

            RowLayout {
                anchors.fill: parent
                anchors.margins: AngelMetric.spacing.defaultValue

                spacing: 16

                DatabaseDataView {
                    Layout.preferredWidth: 300
                    Layout.minimumWidth: 200
                    Layout.fillHeight: true
                }

                Rectangle {
                    radius: AngelMetric.radius.small
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: AngelColor.hoverGray

                    ColumnLayout {
                        anchors.fill: parent
                        spacing: 0

                        QueryPanelManager {
                            id: queryPanelManager
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            onRunQuery: function (dsQuery) {
                                stackLayout.setSourceLoader(
                                            "components/Screen/TableDataView.qml",
                                            {
                                                "dsQuery": dsQuery
                                            })
                            }
                        }

                        StackLayout {
                            id: stackLayout
                            Layout.preferredWidth: 250
                            Layout.preferredHeight: 250
                            Layout.maximumHeight: 250
                            Layout.margins: 1
                            currentIndex: queryPanelManager.currentIndex

                            function setSourceLoader(source, properties) {
                                repeater.itemAt(
                                            stackLayout.currentIndex).setSource(
                                            source, properties)
                            }

                            Repeater {
                                id: repeater
                                model: queryPanelManager.tabsModel

                                Loader {
                                    id: loader
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
