/**
   Bitbloq generated code for Junior Bloqs.
   For more info please visit https://bitbloq.cc
   10/8/2020 - 11:5
**/

// custom defines

#define NOTE_C4  262

#define NOTE_D4  294

#define NOTE_E4  330

#define NOTE_F4  349

#define NOTE_G4  392

#define NOTE_A4  440

#define NOTE_B4  494

#define NOTE_C5  523

#define NOTE_D5  587

#define NOTE_E5  659

#define NOTE_F5  698

#define NOTE_G5  784

#define NOTE_A5  880

#define NOTE_B5  988

#define red 0

#define green 1

#define blue 2

#define white 3

#define black 4


// headers to be included

#include <ArduinoEventsLib.h>

#include <BQZUMJunior.h>

#include <BQZUMJuniorPorts.h>

#include <BQZUMI2CTempSensor.h>

#include <BQZUMI2CColorSensor.h>

#include <BQZUMI2CALPSSensor.h>



// global declarations

Heap heap;

BQ::ZUMJunior zumJunior;


uint8_t zumJuniorRGBLEDPinRed = 7 ;

uint8_t zumJuniorRGBLEDPinGreen = 8 ;

uint8_t zumJuniorRGBLEDPinBlue = 2 ;



uint8_t zumJuniorBuzzerPin = 4 ;



uint8_t sensoresi2c = BQ::ZUMJunior::i2cPorts[A] ;



BQ::ZUM::I2CALPSSensor sensoresi2cALPS(sensoresi2c);
BQ::ZUM::I2CColorSensor sensoresi2cColor(sensoresi2c);
BQ::ZUM::I2CTempSensor sensoresi2cTemp(sensoresi2c);
uint8_t ___tempThresholdsensoresi2cTemp;



uint8_t ledWhitePin = BQ::ZUMJunior::ports[1][0] ;

uint8_t ledColorPin = BQ::ZUMJunior::ports[1][1] ;



uint8_t led2WhitePin = BQ::ZUMJunior::ports[2][0] ;

uint8_t led2ColorPin = BQ::ZUMJunior::ports[2][1] ;



uint8_t led3WhitePin = BQ::ZUMJunior::ports[4][0] ;

uint8_t led3ColorPin = BQ::ZUMJunior::ports[4][1] ;


bool timeline1 = false;

void func_1();

bool timeline2 = false;

void func_2();


// Initialization and configuration
void setup() {

  zumJunior.setup();


  pinMode(zumJuniorRGBLEDPinRed, OUTPUT);
  analogWrite(zumJuniorRGBLEDPinRed, 255);

  pinMode(zumJuniorRGBLEDPinGreen, OUTPUT);
  analogWrite(zumJuniorRGBLEDPinGreen, 255);

  pinMode(zumJuniorRGBLEDPinBlue, OUTPUT);
  analogWrite(zumJuniorRGBLEDPinBlue, 255);



  pinMode(zumJuniorBuzzerPin, OUTPUT);



  sensoresi2cALPS.setup();
  sensoresi2cColor.setup();
  sensoresi2cTemp.setup();
  ___tempThresholdsensoresi2cTemp = sensoresi2cTemp.getTemp();



  pinMode(ledWhitePin, OUTPUT);

  pinMode(ledColorPin, OUTPUT);



  digitalWrite(ledWhitePin, HIGH);

  digitalWrite(ledColorPin, HIGH);



  pinMode(led2WhitePin, OUTPUT);

  pinMode(led2ColorPin, OUTPUT);



  digitalWrite(led2WhitePin, HIGH);

  digitalWrite(led2ColorPin, HIGH);



  pinMode(led3WhitePin, OUTPUT);

  pinMode(led3ColorPin, OUTPUT);



  digitalWrite(led3WhitePin, HIGH);

  digitalWrite(led3ColorPin, HIGH);


}

// Main loop program
void loop() {


  if (

    sensoresi2cALPS.getAL() >= 60

  ) {
    if (!timeline1) {
      heap.insert(func_1);
      timeline1 = true;
    }
  }



  if (

    sensoresi2cALPS.getAL() <= 40

  ) {
    if (!timeline2) {
      heap.insert(func_2);
      timeline2 = true;
    }
  }






  heap.eventloop();

}

// Global functions definition

void func_1() {


  digitalWrite(ledWhitePin, LOW);

  digitalWrite(led2WhitePin, LOW);

  digitalWrite(led3WhitePin, LOW);


  timeline1 = false;
}

void func_2() {


  digitalWrite(ledWhitePin, HIGH);

  digitalWrite(led2WhitePin, HIGH);

  digitalWrite(led3WhitePin, HIGH);


  timeline2 = false;
}

