import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Shapes 1.15
import ViewModels 1.0




ApplicationWindow{
    property ViewModel cntc: cpp
    property double parsInt: 0
    property double totaltime: (parsInt / 1.0).toFixed(2)
    property int line: 8
    color:"#737373"



    width: 780
    height: 380
    minimumWidth: 780
    minimumHeight: 380
    maximumWidth: 780
    maximumHeight: 380
    visible: true

    property bool kyt: false
    property bool kyp: false

    Button{
        width: 56
        height: 24
        background: Rectangle{
            color: "#A6A6A6"
        }

        text: "stop"
        font.underline: false
        font.family: "Verdana"
        hoverEnabled: false
        checked: true
        x: 715
        y: 175
        enabled: !kyp
        onClicked: {
             newvin.visible = !newvin.visible
             difi.visible = !difi.visible
            kyp = true //butten start is not hide
            kyt = false // butten stop is hide
            num_time.visible = !num_time.visible
            num_generator.repeat = !num_generator.repeat
            num_generator.running = !num_generator.running
            parsInt = 0

        }
    }

    Button{

        width: 56
        height: 24
        background: Rectangle{
            color: "#A6A6A6"
        }
        text: "start"
        font.underline: false
        font.family: "Verdana"
        hoverEnabled: false
        checked: true
        x:22
        y:175
        enabled:  !kyt
        display: AbstractButton.TextBesideIcon
        onClicked:{

            newvin.visible = !newvin.visible
            difi.visible = !difi.visible
            text1.visible = false
            kyt = true  // butten stop is not hide
            kyp = false //butten start is hide

                num_time.visible = !num_time.visible
                num_generator.repeat = !num_generator.repeat
                num_generator.running = !num_generator.running  //start timer under page

            cntc.nname=textArea.text //set name
            cntc.famili=textArea1.text // set famili
            cntc.dif = difi.currentIndex // set dificalty

            cntc.connect()
            cntc.send()



        }
    }  


    ComboBox{
            id : difi
            width: 90
            height: 25
            background: Rectangle
            {
                color: "#404040"
            }
            font.family: "Times New Roman"
            focusPolicy: Qt.StrongFocus
            hoverEnabled: false
            x:22
            y:72

            model: ["easy","normal","hard"]
            onCurrentIndexChanged: {
                line = (currentIndex + 10) - currentIndex * 3
            }



        }
    TextArea {
                id: textArea
                color: "red"
                background: Rectangle
                {
                    color: "#404040"
                }
                text: "name"

                width: 90
                height: 25
                x: 22
                y: 20
                font.styleName: "Regular"
                placeholderText: qsTr("name")

            }

    TextArea {
                id: textArea1
                color: "red"
                background: Rectangle
                {
                    color: "#404040"
                }
                text: "famili"
                width: 90
                height: 25
                x: 22
                y: 46



            }


    Rectangle {
        id : timershow
        visible: true
        width: 250
        height: 40
        x:290
        y: 325
        color: "#262626"
        radius: 10
        Text {
            id: num_time
            color: "white"
            anchors.centerIn: parent
            visible: false
        }

        Timer {
            id: num_generator
             interval: 100
             running: false
             repeat: false
             onTriggered: {
                 parsInt=parsInt+.1
                 num_time.text= totaltime.toString()
             }
        }
    }

    Rectangle {
          id : newvin
                x: 124
                y: 19
                width: 580
                height: 300
                color: "#262626"

                visible: false
                radius: 30


                MouseArea {

                       anchors.fill: parent
                       onMouseXChanged:{

                           cntc.setdistance(mouseX,mouseY); //set data
                            cntc.time=parsInt //set time
                           cntc.send1(); // send this valus
                          }
                        }

        Shape
        {

           ShapePath
           {
               fillColor: "#262626"
               strokeColor: "red"
               strokeWidth:line
               startX: 0
               startY: 150


               PathLine
               {
                   x:120
                   y:100
                }
               PathLine
               {
                   x:200
                   y:10
                }
               PathLine
               {
                   x:250
                   y:46
                }
               PathLine
               {
                   x:80
                   y:150
                }
               PathLine
               {
                   x:200
                   y:109
                }
               PathLine
               {
                   x:280
                   y:117
                }
               PathLine
               {
                   x:302
                   y:90
                }
               PathLine
               {
                   x:300
                   y:210
                }
               PathLine
               {
                   x:150
                   y:205
                }
               PathLine
               {
                   x:225
                   y:250
                }
               PathLine
               {
                   x:246
                   y:229
                }
               PathLine
               {
                   x:479
                   y:201
                }
               PathLine
               {
                   x:459
                   y:93
                }

               PathLine
               {
                   x:580
                   y:150
                }
            }
        }

    }
    Text {

        id: text1
        x: 150
        y: 163
        width: 311
        height: 118
        color: "#e2d9d9"

        text: qsTr("This is a program to understand hyperactivity disorder or ADHD.
                    Help:
                    Enter your first and last name.
                    Then set the difficulty level of the game.
                    Now you can press the start button and enjoy the game.")
        font.italic: true
        font.pixelSize: 18
        visible: true
    }
    Rectangle{
        width: 30
        height: 30
        visible: true
        x: 30
        y: 330
        color: cntc.currentStatus
    }
}
