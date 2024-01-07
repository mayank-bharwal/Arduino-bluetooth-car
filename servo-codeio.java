import processing.serial.*;

Serial port;

void setup() {
  size(200, 200);
  String portName = Serial.list()[0]; // Adjust this index based on your system
  port = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
}

void keyPressed() {
  if (key == 'f' || key == 'F') {
    port.write('F');
  } else if (key == 'b' || key == 'B') {
    port.write('B');
  } else if (key == 'l' || key == 'L') {
    port.write('L');
  } else if (key == 'r' || key == 'R') {
    port.write('R');
  } else if (key == 's' || key == 'S') {
    port.write('S');
  }
}
