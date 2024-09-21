import QtQuick 2.7
import QtQuick.Shapes 1.7

Shape {
    id: root
    vendorExtensionsEnabled: true
    layer.enabled: true
    layer.samples: 16
    layer.smooth: true

    property int topLeftRadius: 0
    property int topRightRadius: 0
    property int bottomRightRadius: 0
    property int bottomLeftRadius: 0

    property string color
    property string borderColor: "transparent"
    property int borderWidth: 0

    ShapePath {
        strokeColor: borderColor
        strokeWidth: borderWidth
        fillColor: root.color
        strokeStyle: ShapePath.SolidLine

        startX: 0
        startY: root.topLeftRadius

        PathArc {
            x: root.topLeftRadius
            y: 0
            radiusX: root.topLeftRadius
            radiusY: root.topLeftRadius
            useLargeArc: false
        }

        PathLine {
            x: root.width - root.topRightRadius
            y: 0
        }

        PathArc {
            x: root.width
            y: root.topRightRadius
            radiusX: root.topRightRadius
            radiusY: root.topRightRadius
            useLargeArc: false
        }

        PathLine {
            x: root.width
            y: root.height - root.bottomRightRadius
        }

        PathArc {
            x: root.width - root.bottomRightRadius
            y: root.height
            radiusX: root.bottomRightRadius
            radiusY: root.bottomRightRadius
            useLargeArc: false
        }

        PathLine {
            x: root.bottomLeftRadius
            y: root.height
        }

        PathArc {
            x: 0
            y: root.height - root.bottomLeftRadius
            radiusX: root.bottomLeftRadius
            radiusY: root.bottomLeftRadius
            useLargeArc: false
        }

        PathLine {
            x: 0
            y: root.topLeftRadius
        }
    }
}
