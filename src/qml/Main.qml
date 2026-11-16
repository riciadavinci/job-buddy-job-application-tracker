import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// import "components"

ApplicationWindow {
    id: window
    width: 1280
    height: 800
    visible: true
    title: "JobBuddy - Job Tracking App"

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "Home.qml"
    }
}