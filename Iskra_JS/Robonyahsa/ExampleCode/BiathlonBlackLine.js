// Биатлон. Движение по линии. V 1.0
var SPEED = 0.3;
var detective = require('@amperka/robot-2wd').connect();
var lineSensor = require('@amperka/analog-line-sensor');
var leftSensor = lineSensor.connect(A0);
var rightSensor = lineSensor.connect(A1);

// Библиотека ПИД-регулятора. Принимает параметром объект с настройками ПИД-регулятора
var lineFollower = require('@amperka/pid').create({
  target: 0, // Требуемое значение контролируемой величины
  // Все коэффициенты подобраны опытным путём
  kp: 6, // Пропорциональный коэффициент
  ki: 0.1, // Интегральный коэффициент
  kd: -1, // Диффиринциальный коэффициен
  outputMin: -SPEED,
  outputMax: SPEED
});
 
lineFollower.run(function() {
  var right = rightSensor.read();
  var left = leftSensor.read();
  var error = left - right; // Вычисляет разность значений левого и правого датчика
  var output = lineFollower.update(error); // Обновляем значение ПИД-регулятора
  detective.go({
    l: SPEED + output,
    r: SPEED - output
  });
}, 0.02); // Функция повторяет переданный в неё код каждые 0,02 сек.

/*
* Задай коэффициентам ki и kd нулевое значение. Посмотри, как
* себя будет вести Робоняша на линии, если установить коэффи-
* циент kp равным 1. Попробуй установить значения kp равными
* 2, 5, 10 и 20. Сравни результаты.
*/
