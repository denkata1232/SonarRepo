#include <LiquidCrystal.h>
#include <Servo.h>
#include "pitches.h"

int melody[] = {

  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
  
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
  
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
  
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
  NOTE_FS3, NOTE_D3, NOTE_B2, NOTE_A3, NOTE_FS3, NOTE_B2, NOTE_D3, NOTE_FS3, NOTE_A3, NOTE_FS3, NOTE_D3, NOTE_B2,
  
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
  
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
  NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
  NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
  NOTE_B3, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_B3, NOTE_G4, NOTE_B4,
  
  NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2, 
  NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
  NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
  NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3,
  
  NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2, 
  NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
  NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
  NOTE_A3, NOTE_F3, NOTE_D3, NOTE_A3, NOTE_F3, NOTE_D3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_A3, NOTE_F3, NOTE_D3,
};
int noteDurations[] = {

  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 2,
  
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 2,
  
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 2,
  
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 2,
  
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 2,
  
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  
};

LiquidCrystal lcd (0, 1, 8, 9, 10, 11);
int servoPin = 13;
int echoPin = 3;
int triggerPin = 4;
int buzzerPin = 2;
int buttonPin = 12;
int potPin = A0;

float duration = 0.0;
float distance = 0.0;
int pos;
Servo servo;

int potReading;
int angle;

int button;
int oldButton = 1;
int state = 0;
bool needToBreak = false;

int beepPeriod = 15;

int redPin = 5;
int greenPin = 6;
int bluePin = 7;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Welcome to Sonar");
  lcd.setCursor(0, 1);
  lcd.print("Defence System!");
  servo.attach(servoPin);
  SetColor(0, 0, 255);
  PlayMelody();
  SetColor(0, 255, 0);
  PlayMelody();
  SetColor(255, 0, 0);
  PlayMelody();
  SetColor(0, 0, 0);
  lcd.setCursor(0, 0);
  lcd.clear();
}

void loop(){
  button = digitalRead(buttonPin);
    if(state == 0){
      
      lcd.setCursor(0, 0);
      lcd.print("Auto");
      for(pos = 15; pos < 165; pos += 1){
        CheckButton();
        if (needToBreak) {break;}
        BeepingFar();
        oneAutoRotation();
      }

      for(pos = 165; pos >= 15; pos -= 1) {
        CheckButton();
        if (needToBreak) {break;}
        BeepingFar();
        oneAutoRotation();
      }
      needToBreak = false;
    }
    else if (state == 1){
      
      for(; beepPeriod <= 165;){
        CheckButton();
        if (needToBreak) {break;}
        ManualDistanceBeep();
        //ManualControl();
        BeepingFar();
      }
      needToBreak = false;
    }
    
}
int calculateDistance(){
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
  
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    return distance;
}
void oneAutoRotation(){
  servo.write(pos);
  DetectLogic();
}

void CheckButton(){
  button = digitalRead(buttonPin);
  if(button == oldButton)
  {
    oldButton = 1;
    if(state==1) {
      SetColor(45, 8, 130);
      tone(buzzerPin, 350, 6000);
      delay(100);
      tone(buzzerPin, 450, 400);
    }
    else{
      SetColor(45, 4, 140);
      tone(buzzerPin, 450, 6000);
      delay(100);
      tone(buzzerPin, 350, 400);
    }
    state = !state;
    needToBreak = true;
    lcd.blink();
    lcd.setCursor(0, 1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.clear();
    delay(250);
  }
}

void PlayMelody(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzzerPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);


    noTone(8);

  }
}

void Beeping(int db, int time) {
  tone(buzzerPin, db, 6000);
  delay(time/distance);
  noTone(buzzerPin);
}

void BeepingFar(){
  beepPeriod++;
    if(beepPeriod>165){
      beepPeriod = 15;
    }
}

void ManualControl(){  
  lcd.setCursor(0, 0);
  lcd.print("Manual");
  potReading = analogRead(potPin);
  angle = map(potReading, 0, 1023, 15, 165);
  servo.write(angle);
  //lcd.setCursor(0, 1);
  //lcd.print(potReading);
}

void ManualDistanceBeep(){
  ManualControl();
  DetectLogic();
}

void SetColor(int redValue, int greenValue ,int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void DetectLogic(){
  delay(30); 
    distance = calculateDistance();
    if(distance > 40){
      if(beepPeriod % 30 == 0){
        SetColor(0, 150, 150);
        tone(buzzerPin, 340, 6000);
        delay(25);
        noTone(buzzerPin);
        delay(50);
        SetColor(80, 150, 80);
      }
    }
    else if(distance > 25){
      if(beepPeriod % 15 == 0){
        SetColor(0, 150, 150);
        tone(buzzerPin, 340, 6000);
        delay(25);
        noTone(buzzerPin);
        delay(50);
        SetColor(80, 130, 80);
      }
    }
    else if(distance > 15){
      if(beepPeriod % 5 == 0){
        SetColor(100, 150, 150);
        tone(buzzerPin, 340, 6000);
        delay(25);
        noTone(buzzerPin);
        delay(50);
        SetColor(160, 130, 50);
      }
    }
    else if (distance > 10)
    {
      //SetColor(100, 150, 150);
      SetColor(255,0,0);
      Beeping(440,500);
      delay(50);
      SetColor(160, 130, 50);
    }
    else{
      SetColor(255,0,0);
      Beeping(440,5000);
    }
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance);
}