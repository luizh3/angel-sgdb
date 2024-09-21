import QtQuick 2.15

import Control.QueryPanelControl 1.0

QueryPanelForm {
    id: root

    signal runQuery(var dsQuery)

    Shortcut {
        sequence: "F5"
        onActivated: root.runQuery(root.textArea.text)
        enabled: root.visible
    }

    QueryPanelControl {
        id: control
    }
}
