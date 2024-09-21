import QtQuick 2.7
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.0

import Angel 1.0
import AngelTheme 1.0

import Model.ConnectionDatabaseModel 1.0
import Control.ConnectionDatabaseControl 1.0

AngelPopup {
    id: root
    width: 600
    height: 800

    signal success

    ConnectionDatabaseControl {
        id: control

        onSuccess: function handleSuccess() {
            root.success()
        }

        onError: function handleError() {
            buttonConfirm.setState(AngelButton.States.Default)
        }

        onFinished: function handleFinished() {
            root.close()
        }
    }

    header.title.text: qsTr("Connect a Database")
    header.onClose: root.close()

    ColumnLayout {
        id: inputsColumn
        width: parent.width

        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            leftMargin: AngelMetric.margins.defaultValue
            rightMargin: AngelMetric.margins.defaultValue
            topMargin: AngelMetric.margins.defaultValue
        }

        spacing: AngelMetric.spacing.vertical

        property ConnectionDatabaseModel _connectionDatabaseModel: ConnectionDatabaseModel {
            dsHost: hostField.value
            dsPort: portField.value
            dsDatabaseName: databaseNameField.value
            dsUsername: usernameField.value
            dsPassword: passwordField.value
        }

        RowLayout {
            id: rowHostPort
            width: parent.width
            spacing: AngelMetric.spacing.defaultValue

            property int _widthChildren: (rowHostPort.width - rowHostPort.spacing) / 2

            AngelTextField {
                id: hostField
                Layout.preferredWidth: rowHostPort._widthChildren
                Layout.preferredHeight: 60
                text: qsTr("Host")
                value: "localhost"
            }

            AngelTextField {
                id: portField
                Layout.preferredWidth: rowHostPort._widthChildren
                Layout.preferredHeight: 60
                text: qsTr("Port")
                value: "5433"
            }
        }

        AngelTextField {
            id: databaseNameField
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 60
            text: qsTr("Database name")
            value: "article"
        }

        AngelTextField {
            id: usernameField
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 60
            text: qsTr("Username")
            value: "postgres"
        }

        AngelTextField {
            id: passwordField
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 60
            text: qsTr("Password")
            value: "postgres"
        }
    }

    Row {
        id: rowButtons

        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            leftMargin: AngelMetric.margins.defaultValue
            rightMargin: AngelMetric.margins.defaultValue
            bottomMargin: AngelMetric.margins.defaultValue
        }

        width: parent.width
        spacing: AngelMetric.spacing.defaultValue

        AngelButton {
            id: buttonConfirm
            text: qsTr("Confirm")
            width: parent.width

            onClicked: function () {
                control.onConnect(inputsColumn._connectionDatabaseModel)
            }
        }
    }
}
