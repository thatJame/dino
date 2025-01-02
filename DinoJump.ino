// Set up the servo motor
#include <Servo.h>
Servo myservo;
const byte PHOTORESISTOR_PIN = A1;

//SETUP VARIABLES
int CactiBrightness = 40; //Cacti Brightness (Dark)
int Delay = 500;          //Delay Before Jumping
int RestDelay = 150;      //Time Before Resetting Position 
int ServoPress = 45;      //Servo Motor Position Pressing Space
int ServoRest = 20;       //Servo Motor Resting Position
int AddSpeed = 5;         //Speeds Up Jump By This Number

//DEVELOPMENT VARIABLES
int Jumps = 0;            //Total Number of Jumps

void setup() {
  myservo.attach(11);
  myservo.write(-10);
  pinMode(LED_BUILTIN, OUTPUT);      
  pinMode(PHOTORESISTOR_PIN, INPUT);  
  Serial.begin(9600);  
}

void loop() {
  unsigned int light_value = analogRead(PHOTORESISTOR_PIN); 
  if (light_value <= CactiBrightness) { 
   int nDelay = Delay -= AddSpeed;
   Serial.print(nDelay);
   Serial.print("\n");
   delay(nDelay);
   myservo.write(ServoPress);
   delay(RestDelay);
   myservo.write(ServoRest);
   //delay(RestDelay);
  }
}
