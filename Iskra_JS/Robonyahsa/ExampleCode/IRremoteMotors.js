var SPEED = 0.5;
var marsohod = require('@amperka/robot-2wd').connect();
var receiver = require('@amperka/ir-receiver').connect(P1);
 
receiver.on('receive', function(code) {
  switch(code) {
    case receiver.keys.TOP:
      marsohod.go({l: SPEED, r: SPEED});
      break;
    case receiver.keys.BOTTOM:
      marsohod.go({l: -SPEED, r: -SPEED});
      break;
    case receiver.keys.LEFT:
      marsohod.go({l: -SPEED, r: SPEED});
      break;
    case receiver.keys.RIGHT:
      marsohod.go({l: SPEED, r: -SPEED});
      break;
    case receiver.keys.PLAY:
      marsohod.stop();
      break;
    default: break;
  }
});