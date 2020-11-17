// Биатлон. Движение по линии. V 1.0
var SPEED = 0.3;
var detective = require('@amperka/robot-2wd').connect();
var lineSensor = require('@amperka/analog-line-sensor');
var leftSensor = lineSensor.connect(A0);
var rightSensor = lineSensor.connect(A1);
 
var lineFollower = require('@amperka/pid').create({
  target: 0,
  kp: 6,
  ki: 0.1,
  kd: -1,
  outputMin: -SPEED,
  outputMax: SPEED
});
 
lineFollower.run(function() {
  var right = rightSensor.read();
  var left = leftSensor.read();
  var error = left - right;
  var output = lineFollower.update(error);
  detective.go({
    l: SPEED + output,
    r: SPEED - output
  });
}, 0.02);
