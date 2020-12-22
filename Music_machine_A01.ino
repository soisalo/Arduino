
#include "pitches.h"
// notes to play, corresponding to the 3 sensors:
// 21 pitches
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


void setup() {
  pinMode(redswitch, OUTPUT);
  Serial.begin(9600);
}

void loop() {

int switchState = digitalRead(redswitch);

    //Serial.println(switchState);
    delay(100);
    
int x = switchState;
int sensorValue = analogRead(A0);
int sensorValue2 = analogRead(A1);
int pitch = sensorValue/49;

int beat=map(sensorValue2, sensorLow, sensorHigh, 0, 1000);


//int beat = sensorValue2/49;


if (x > 0)
{
tone(speakerPin, notes[pitch], 1000);
delay(beat);
}

Serial.println(pitch);
} 
