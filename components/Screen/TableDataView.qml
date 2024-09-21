import QtQuick 2.15

TableDataViewForm {
    Component.onDestruction: function () {
        console.info("TableDataView deleted")
    }
}
