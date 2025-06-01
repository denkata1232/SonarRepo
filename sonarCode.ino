#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd (0, 1, 8, 9, 10, 11);
int servoPin = 13;
int echoPin = 3;
int triggerPin = 4;
int buzzerPin = 2;

float duration = 0.0;
float distance = 0.0;
int pos;
Servo servo;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  tone (buzzerPin, 1000, 2000);
  lcd.begin(32, 4);
  servo.attach(servoPin);
}

void loop() {
  //angle = map(1023, 0, 1023, 0, 180);
  for(pos = 15; pos < 165; pos += 1){
    oneAutoRotation();
  }
 

  //lcd.setCursor(0, 1);
  //lcd.print("Hello 2");

  //angle = map(0, 0, 1023, 0, 180);
  for(pos = 165; pos >= 15; pos -= 1) {
    oneAutoRotation();
  }

  //lcd.scrollDisplayLeft();
  //lcd.setCursor(0, 0);
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
    delay(30); 
    distance = calculateDistance();
    if(distance > 40){
      if(pos % 30 == 0){
        tone(buzzerPin, 340, 6000);
        delay(25);
        noTone(buzzerPin);
      }
    }
    else if(distance > 25){
      if(pos % 15 == 0){
        tone(buzzerPin, 340, 6000);
        delay(25);
        noTone(buzzerPin);
      }
    }
    else if(distance > 15){
      if(pos % 5 == 0){
        tone(buzzerPin, 340, 6000);
        delay(25);
        noTone(buzzerPin);
      }
    }
    else if (distance > 10)
    {
        tone(buzzerPin, 440, 6000);
        delay(500/distance);
        noTone(buzzerPin);
    }
    else{
        tone(buzzerPin, 440, 6000);
        delay(5000/distance);
        noTone(buzzerPin);
    }

    lcd.setCursor(0, 0);
    lcd.print(distance);
}