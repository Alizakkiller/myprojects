import QtQuick
import QtCharts 6.3
import QtQuick.Controls 6.3
import Viewmodels 1.0
import QtQuick.Dialogs


ApplicationWindow {
    property Viewmodel mymodel:model
    property var newpoints: mymodel.points
    property var newpoints1:[]
    property int c: 0





    id: window
    width: 640
    height: 480
    visible: true
    color: "#887e76"
    title: qsTr("doktor")


    onNewpointsChanged:
    {

        if(mymodel.currentStatus==="green")
         {

            mymodel.numgen();
            if(newpoints[c+1]!==0){
                series1.append(newpoints[c+1], newpoints[c]);// it must be append number of vector
                line.update();
            }
            if(newpoints[c+1]>100){ //growing width of chart
                slider.to=newpoints[c+1]+.5
            }
            if(newpoints[c]>100){ //griwing height if chart
                if(axisY.max<newpoints[c])
                {
                axisY.max=newpoints[c]
                }
            }

            c=c+2;




        }


    }


    ChartView {
        id: line
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.rightMargin: 8
        anchors.leftMargin: 6
        anchors.bottomMargin: 141
        anchors.topMargin: 6
        animationDuration: 500



        ValuesAxis {
            id: axisX
            min: slider.value
            max:15+slider.value
            tickCount: 10
        }

        ValuesAxis {
            id: axisY
            min: 0
            max:100

        }
        LineSeries {
              name: "SplineSeries"
              id:series1
              XYPoint { x: 0; y: 0.0 }
              axisX: axisX
              axisY: axisY



          }


    }


    Slider {
        id: slider
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: line.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 36
        anchors.leftMargin: 27
        anchors.bottomMargin: 100
        anchors.topMargin: 8
        from: 0
        to: 100
        value: 0
    }

    TextArea {
        id: textArea
        x: 428
        width: 176
        placeholderText: qsTr("Text Area")
        text: mymodel.receivedData //show name famili and dificality
        anchors.right: parent.right
        anchors.top: line.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 36
        anchors.bottomMargin: 19
        anchors.topMargin: 47

    }

    Button {
        id: buttondis
        x: 238
        width: 97
        text: qsTr("close and save")
        anchors.top: slider.bottom
        anchors.bottom: parent.bottom
        anchors.topMargin: 6
        anchors.bottomMargin: 19
        onClicked: {
            mymodel.close()   //close server
            mymodel.savefile() //save to .text file
            series1.clear() //clean the chart
            num_generator.repeat = false
            num_generator.running = false
        }


    }



    Button {
        id: connectbt
        x: 85
        width: 72
        text: qsTr("connect")
        anchors.top: slider.bottom
        anchors.bottom: parent.bottom
        anchors.topMargin: 6
        anchors.bottomMargin: 19
        onClicked :{
            mymodel.listen()

        }

    }
    Rectangle {
        id:rectv
        width: 30
        visible: true
        x: 27
        color:mymodel.currentStatus
        anchors.top: line.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 19
        anchors.topMargin: 92

    }
    Timer {
        id: num_generator
         interval: 100
         running: false
         repeat: false
         onTriggered: {

             slider.value=slider.value+.1

         }
    }


    Button {
        id: button1
        x: 163
        width: 69
        text: qsTr("run chart")
        anchors.top: slider.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 19
        anchors.topMargin: 6
        onClicked: {

            num_generator.repeat = !num_generator.repeat
            num_generator.running = !num_generator.running //start timer for run chart
        }
    }

    Button {
        id: button
        x: 341
        width: 72
        text: qsTr("import")
        anchors.top: slider.bottom
        anchors.bottom: parent.bottom
        anchors.topMargin: 6
        anchors.bottomMargin: 19
        onClicked: {
        fileDialog.visible=true //import files
        }
    }

    FileDialog {
        id:fileDialog
        title: "add files"


        nameFilters: ["All Files (*)"]
        visible: false



        onAccepted: {
//            newpoints1 = fileDialog.fileUrls
//                    for (var i = 0; i < 100; i++) {
//                        series1.append(newpoints[i+1], newpoints[i]);
//                    }
//            var fileUrls = fileDialog.fileUrls
//                    for (var i = 0; i < 100; i++) {
//                        var fileUrl = fileUrls[i].toString()
//                        var file = new QFile(fileUrl)
//                        if (file.open(QIODevice.ReadOnly | QIODevice.Text)) {
//                            var textStream = new QTextStream(file)
//                            var fileContent = []
//                            while (!textStream.atEnd()) {
//                                var line = textStream.readLine()
//                                fileContent.push(line)
//                            }
//                            file.close()
//                            console.log("File content:", fileContent)
//                        }
//                    }
            ///////////////////////////////////////////////////////////////////////////////////
            //it was for opening the files and show it in chart but I did not have enough time
            ///////////////////////////////////////////////////////////////////////////////////
        }
    }


}
