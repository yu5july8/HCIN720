//we need motion sensor, Temp humidity and ultrasonic sensor sketch in this 

#include <DHT.h>//temp hum sensor 
#include <Ultrasonic.h>//ultrasound  
#include <Grove_LED_Bar.h>//Grove LED bar

#define DHTPIN 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define MOTION_SENSOR
#define LED_NUM 24
Grove_LED_Bar LEDBar(0,1,0,LED_CIRCULAR_24); //clock pin, data pin and orientation

Ultrasonic ultrasonic(); //pin 

int sound_sensor = A2; //assign to pin A2


void setup() {
  Serial.begin(115200); //begin Serial Communication
  LEDBar.begin();
  dht.begin();
  pinMode(MOTION_SENSOR, INPUT);
  long RangeInInches
  origin=ultrasonic.MeasureInInches();
  Serial.println(ultrasonic.RangeInInches);
}

void loop() {
  long RangeInInches
  Serial.println("The distance to obstacle in front is: ");
  after=ultrasonic.MeasureInInches();
  
  if (origin != after){
    int soundValue = 0; //create variable to store many different readings
    for (int i = 0; i < 32; i++) //create a for loop to read 
    { soundValue += analogRead(sound_sensor);  } //read the sound sensor
   
    soundValue >>= 5; //bitshift operation 
    Serial.println(soundValue); //print the value of sound sensor
    int level=map(soundValue, 0,90, 0, 24);// we should take a look into the measurememt of number for sound value 
    delay(5000); //a shorter delay between readings
  }
}
