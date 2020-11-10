var notice = require('@amperka/led').connect(P2);
notice.blink(0.1, 0.9);
var motor = require('@amperka/motor');
var leftMotor = motor.connect(motor.MotorShield.M1);
leftMotor.write(0.5);
var leftMotor = motor.connect(motor.MotorShield.M2);
leftMotor.write(0.5);