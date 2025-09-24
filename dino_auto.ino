#include <Servo.h>
Servo S;
int sensor = A0;
int sensor2 = A1;
int birdpin = A2;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  S.attach(10);
  // put your setup code here, to run once:
}

void jump() {
  S.write(0);
  //S.write(90);
  //delay(1000);
  S.write(60);
  delay(150);
  S.write(0);
}

void loop() {
  int sensor_sig = analogRead(sensor); // put your main code here, to run repeatedly:
  //Serial.println(sensor_sig);
  //delay(100);

  int mode_sig = analogRead(sensor2);
  Serial.println(mode_sig);
  int bird_sig = analogRead(birdpin);

  if (mode_sig >= 600) { // light mode
    if (sensor_sig <= 660 || bird_sig <= 600) {
      digitalWrite(13, HIGH);
      jump();
      delay(50);
      digitalWrite(13, LOW);
    }
  } else {
    if (sensor_sig >= 500 || bird_sig >= 500) {
      digitalWrite(13, HIGH);
      jump();
      delay(100);
      digitalWrite(13, LOW);
    }
  }
}