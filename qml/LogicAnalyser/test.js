
var testComponent;

function creatTestComponent(parent, x, y) {
    var rect;
    rect = testComponent.createObject(parent, {"x":x, "y":y, "step":4, "minWidth":20});
}

function loadTestComponent() {
    testComponent = Qt.createComponent("testComponent.qml");
}
