import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// import "components"

Item {
    id: homePageView
    objectName: "homePageView"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 12
        spacing: 12

        RowLayout {
            Layout.fillWidth: true
            spacing: 12

            Text {
                text: "Home Page"
                font.pixelSize: 18
                font.bold: true
                color: "#9214B7"
                Layout.alignment: Qt.AlignCenter
            }
        }
    }
}