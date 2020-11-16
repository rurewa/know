// Датчик линии
var analogSensor = require('@amperka/analog-line-sensor')
  .connect(A0);
 
var showSignal = function() {
  print('signal:', analogSensor.read('V'), 'volts');
};
 
setInterval(showSignal, 100);
