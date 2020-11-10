var motor = require('@amperka/motor');
var rightMotor = motor.connect(motor.MotorShield.M2);
rightMotor.write(-0.85);

var encoder = require('@amperka/digital-line-sensor').connect(P9);
var RADIUS = 32;
var WHEEL_LENGTH = 2 * Math.PI * RADIUS;
var STEP = 1 / 12;
var revolutions = 0;
var counter = 0;
var lastTime = getTime();

encoder.on('black', function() {
  revolutions = revolutions + STEP;
  var distance = revolutions * WHEEL_LENGTH;
  print(distance, 'mm');
});