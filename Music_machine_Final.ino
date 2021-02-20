#include "pitches.h"
#include <Servo.h>

int notes[] = {
  NOTE_B0,NOTE_C1,NOTE_D1,NOTE_E1,NOTE_F1,NOTE_G1,NOTE_A1,
  NOTE_B1,NOTE_C2,NOTE_D2,NOTE_E2,NOTE_F2,NOTE_G2,NOTE_A2,
  NOTE_B2,NOTE_C3,NOTE_D3,NOTE_E3,NOTE_F3,NOTE_G3,NOTE_A3
};

int Tone = 0;
int speakerPin = 2;
int sensorLow = 0;
int sensorHigh = 1023;
int redswitch = 1;
int servoPin = 4;
int penisLow = 0;
int penisErect = 179;

Servo Servo1;
unsigned long prevMillis = 0;

void setup() {
  pinMode(redswitch, OUTPUT);
  Serial.begin(9600);
  Servo1.attach(servoPin);
}

void loop() {

int switchState = digitalRead(redswitch);

 delay(100);
    
int x = switchState;
int sensorValue = analogRead(A0);
int sensorValue2 = analogRead(A1);
int pitchServo = map(sensorValue, sensorLow, sensorHigh, 0, 1000);
int pitch = sensorValue/49;
int beat=map(sensorValue2, sensorLow, sensorHigh, 0, 1000);
int finalAngle = ((beat+pitchServo)/2);
int throbbingpenisAngle=map(finalAngle, 0, 1000, penisLow, penisErect);


if (x > 0)
{
 tone(speakerPin, notes[pitch], 1000);
delay(beat);
}



 throbbingpenisAngle=abs(penisErect-throbbingpenisAngle);
  Servo1.write(throbbingpenisAngle);
  Serial.write(throbbingpenisAngle);

}
 //delay(1000); 
//Serial.println(beat);
//Serial.println(switchState);

