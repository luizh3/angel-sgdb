import QtQuick 2.15

QueryPanelManagerForm {
    id: root

    function addTab() {
        tabsModel.append({
                             "title": "Query"
                         })
    }

    function handleCurrentTabChanged() {
        stackLayout.currentIndex = tabBar.currentIndex
    }

    function handleRemoveTab(index) {
        tabsModel.remove(index)
    }

    tabBar.onCurrentIndexChanged: root.handleCurrentTabChanged()
}
