// Esther Tapia
// Created on: 12/31/2017
// combined both RGB LED and Digital Inputs lessons from Arduino Kit
// to pause RGB LED at a color and to turn the RBG LED white with push switches

// define pins for switches on and pause
int buttonONpin = 9;    // on switch on pin 9
int buttonPAUSEpin = 8;   // pause switch on pin 8

// Define Pins for RGB LED
#define BLUE 3    // blue LED on pin 3
#define GREEN 5   // green LED on pin 5
#define RED 6     // red LED on pin 6

void setup()
{
// RGB LED
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);    // initially red LED is turned on,
digitalWrite(GREEN, LOW);   // and green and blue LED are off
digitalWrite(BLUE, LOW);

// switches
pinMode(buttonONpin, INPUT_PULLUP);
pinMode(buttonPAUSEpin, INPUT_PULLUP);
}

// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{
#define delayTime 10 // fading time between colors

redValue = 255; // choose a value between 1 and 255 to change the color.
greenValue = 0;
blueValue = 0;

for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
{
redValue -= 1;  // as red LED is slowly decreasing in color, green LED is increasing
greenValue += 1;
analogWrite(RED, redValue);
analogWrite(GREEN, greenValue);
delay(delayTime);

if(digitalRead(buttonONpin) == LOW)   // turns led to white
{
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);
  delay(1000);    // pauses for a second
}
if(digitalRead(buttonPAUSEpin) == LOW)
{
  delay(5000);    // pause RGB LED for 5 seconds (to enjoy color)
}
}

redValue = 0;
greenValue = 255;
blueValue = 0;

for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
{
greenValue -= 1;  // as green LED is slowly decreasing in color, blue LED is increasing
blueValue += 1;
analogWrite(GREEN, greenValue);
analogWrite(BLUE, blueValue);
delay(delayTime);

if(digitalRead(buttonONpin) == LOW)   // turns led to white
{
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);
  delay(1000);    // pauses for a second
}
if(digitalRead(buttonPAUSEpin) == LOW)
{
  delay(5000);    // pause RGB LED for 5 seconds (to enjoy color)
}
}

redValue = 0;
greenValue = 0;
blueValue = 255;

for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
{
// The following code has been rearranged to match the other two similar sections
blueValue -= 1; // as blue LED is slowly decreasing in color, red LED is increasing
redValue += 1;
analogWrite(BLUE, blueValue);
analogWrite(RED, redValue);
delay(delayTime);

if(digitalRead(buttonONpin) == LOW)     // turns led to white
{
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);
  delay(1000);    // pauses for a second
}
if(digitalRead(buttonPAUSEpin) == LOW)
{
  delay(5000);    // pause RGB LED for 5 seconds (to enjoy color)
}
}


}
