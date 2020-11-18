// Робот "Прилипала". V 1.0
var SPEED = 0.5;
var DISTANCE_MIN = 10;
var DISTANCE_MAX = 14;
 
var sticker = require('@amperka/robot-2wd')
  .connect();
 
var ultrasonic = require('@amperka/ultrasonic').connect({
  trigPin: P12,
  echoPin: P13
});
 
var neck = require('@amperka/servo').connect(P8);neck.write(90); 
/* Поэкспериментируй со значением угла поворота сервопривода от 0 до 180,
чтоб голова робота смотрела прямо перед собой*/
 
function check(distance) {
  if (distance > DISTANCE_MAX) {
    sticker.go({l: SPEED, r: SPEED});
  } else if (distance < DISTANCE_MIN) {
    sticker.go({l: -SPEED, r: -SPEED});
  } else {
    sticker.stop();
  }
}
 
setInterval(function() {
  ultrasonic.ping(function(error, value) {
    if (!error) {
      check(value);
    }
  }, 'cm');
}, 100);
