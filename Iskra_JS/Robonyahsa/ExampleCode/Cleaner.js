// Чистюля. Едет, видит край стола и отъезжает назад.
var FORWARD_SPEED = 0.3;
var BACKWARD_SLOW_SPEED = 0.3;
var BACKWARD_FAST_SPEED = 0.6;
var BORDER_VALUE = 0.5;
var intervalID;
 
var cleaner = require('@amperka/robot-2wd').connect();
var receiver = require('@amperka/ir-receiver').connect(P1);
var lineSensor = require('@amperka/analog-line-sensor');
var leftSensor = lineSensor.connect(A0);
var rightSensor = lineSensor.connect(A1);
 
function waitRollBack() {
  setTimeout(function() {
    cleaner.go({l: FORWARD_SPEED, r: FORWARD_SPEED});
    intervalID = setInterval(clean, 10);
  },800);
}
 
function clean() {
  intervalID = clearInterval(intervalID);
  if (leftSensor.read() > BORDER_VALUE) {
    cleaner.go({r: -BACKWARD_SLOW_SPEED, l: -BACKWARD_FAST_SPEED});
    waitRollBack();
  } else if (rightSensor.read() > BORDER_VALUE) {
    cleaner.go({r: -BACKWARD_FAST_SPEED, l: -BACKWARD_SLOW_SPEED});
    waitRollBack();
  } else {
    cleaner.go({l: FORWARD_SPEED, r: FORWARD_SPEED});
    intervalID = setInterval(clean, 10);
  }
}
 
receiver.on('receive', function(code) {
  if (code === receiver.keys.PLAY) {
    if (!intervalID) {
      leftSensor.calibrate({white: leftSensor.read()});
      rightSensor.calibrate({white: rightSensor.read()});
      intervalID = setInterval(clean, 10);
    } else {
      cleaner.stop();
      intervalID = clearInterval(intervalID);
    }
  }
});
