// Пример управления сонаром. Робот видит препятствия и едет назад
var neck = require('@amperka/servo').connect(P8);
var SPEED = 0.5; // Скорость вращения двигателями
var DISTANCE_MIN = 10;
var DISTANCE_MAX = 14;
// Библиотека управления 2-мя моторами
var sticker = require('@amperka/robot-2wd').connect();

var ultrasonic = require('@amperka/ultrasonic').connect({
  trigPin: P12,
  echoPin: P13
});

neck.write(90); // Чтобы "смотрел" прямо

// Алгоритм движения
var check = function(distance) {
  if (distance > DISTANCE_MAX) {
    sticker.go({l: SPEED, r: SPEED});
  } 
  else if (distance < DISTANCE_MIN) {
    sticker.go({l: -SPEED, r: -SPEED});
  } 
  else {
    sticker.stop();
  }
};

setInterval(function() {
  // Результат измерения передаётся в value
  // В error передаётся ошибка измерения 
  // (слишком большое расстояния, например)
  ultrasonic.ping(function(error, value) {
    if (!error) {
      check(value);
    }
  }, 'cm');
}, 100);
