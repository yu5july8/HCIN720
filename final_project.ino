#include <Grove_LED_Bar.h>

#define LED_NUM 24
Grove_LED_Bar LEDBar(0,1,0,LED_CIRCULAR_24); //clock pin, data pin and orientation

int sound_sensor = A2; //assign to pin A2


void setup() {
  Serial.begin(115200); //begin Serial Communication
  LEDBar.begin();
}

void loop() {
  int soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++) //create a for loop to read 
  { soundValue += analogRead(sound_sensor);  } //read the sound sensor
 
  soundValue >>= 5; //bitshift operation 
  Serial.println(soundValue); //print the value of sound sensor
  int level=map(soundValue, 0,90, 0, 24);// we should take a look into the measurememt of number for sound value 
  delay(5000); //a shorter delay between readings

}
