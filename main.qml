import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import Fractals 1.0


Item {
    id: itemId

    Mandelbrot {

        id: fractal

        anchors.fill: parent
        xFrom: -2.0
        xTo: 1.0
        yFrom: -1.0
        yTo: 1.0

        xRes: parent.width
        yRes: parent.height


        Label {
            id: imaginaryRange
            text: "[" +  fractal.xFrom + "," + fractal.xTo + "]"
            color: "yellow"
            anchors.left: fractal.left
            anchors.bottom: fractal.bottom

        }

        Label {
            id: realRange
            text: "[" +  fractal.yFrom + "i," + fractal.yTo + "i]"
            color: "yellow"
            anchors.left: fractal.left
            anchors.bottom: imaginaryRange.top

        }

        MouseArea {
            anchors.fill: parent
            id: selectArea;

            property int mouseStartX ;
            property int mouseStartY ;

            onPressed: {
                if (selectionItem !== null) {
                    // if there is already a selection, delete it
                    selectionItem.destroy ();
                };

//                // create a new rectangle at the wanted position
                mouseStartX = mouse.x;
                mouseStartY = mouse.y;

                selectionItem = selectionComponent.createObject (selectArea, {
                    "x" : mouse.x ,
                    "y" : mouse.y
                });

            }

            onPositionChanged: {
                var startX = Math.min( mouse.x , mouseStartX );
                var startY = Math.min( mouse.y , mouseStartY );

                selectionItem.x = startX;
                selectionItem.y = startY;

                selectionItem.width = (Math.abs (mouse.x - mouseStartX));
                selectionItem.height = (Math.abs (mouse.y - mouseStartY));
            }

            onReleased: {
                fractal.zoomIn(selectionItem.x,selectionItem.y,selectionItem.width,selectionItem.height);
                selectionItem.destroy();
            }

            property Rectangle selectionItem : null;

            Component {
                id: selectionComponent;

                Rectangle {
                    color: "yellow";
                    opacity: 0.45;
                }
            }

        }
    }


}

