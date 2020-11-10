var motor = require('@amperka/motor');
var rightMotor = motor.connect(motor.MotorShield.M2);
rightMotor.write(0.3);
 
var encoder = require('@amperka/digital-line-sensor').connect(P9);

var RADIUS = 32;
var WHEEL_LENGTH = 2 * Math.PI * RADIUS;
var STEP_LENGTH = WHEEL_LENGTH / 12 / 1000;
var speed = 0;
var lastTime = getTime();
 
encoder.on('black', function() {
  var currentTime = getTime();
  var deltaTime = currentTime - lastTime;
  speed = STEP_LENGTH / deltaTime;
  lastTime = currentTime;
  print(speed.toFixed(2), 'm/s');
});