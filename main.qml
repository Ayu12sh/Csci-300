import QtQuick.Layouts 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Fantasy Movie Selector"

    Rectangle {
        anchors.fill: parent
        color: "lightgrey"

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 10

            TextField {
                id: numberInput
                placeholderText: "Enter a number"
            }

            Button {
                text: "OK"
                onClicked: {
                    // Call C++ logic to handle number input
                    fantasyMovies.selectMovie(parseInt(numberInput.text))
                }
            }

            Text {
                id: movieDisplay
                text: "Surprise Movie: "
            }

            Button {
                text: "Quit"
                onClicked: Qt.quit()
            }
        }
    }

    // Connect CFantasyMovies signal to QML slot
    Connections {
        target: fantasyMovies
           function onDisplayMovie(message) {
               // Update the movie display text
               movieDisplay.text = message;
        }
    }
}
