
var testComponent;

function creatTestComponent(parent, x, y) {
    var rect;
    rect = testComponent.createObject(parent, {"x":x, "y":y});
}

function loadTestComponent() {
    testComponent = Qt.createComponent("testComponent.qml");
}
