import QtQuick 2.7

import Angel 1.0

Item {
    id: root

    function show(title, description, type) {

        const messageInformation = Qt.createQmlObject(`
                                                      import Angel 1.0
                                                      AngelToast {}
                                                      `, parent)

        messageInformation.title = title
        messageInformation.description = description
        messageInformation.state = type
    }

    function success(title, message) {
        root.show(title, message, AngelToast.Types.SUCCESS)
    }

    function error(title, message) {
        root.show(title, message, AngelToast.Types.ERROR)
    }

    function warning(title, message) {
        root.show(title, message, AngelToast.Types.WARNING)
    }
}
