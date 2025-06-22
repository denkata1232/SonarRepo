#include <LiquidCrystal.h>
#include <Servo.h>

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

//bool isAuto = true;
//bool isPressed = false;
//int buttonState = 0;
int button;
int oldButton = 1;
int state = 0;
bool needToBreak = false;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  tone (buzzerPin, 1000, 2000);
  lcd.begin(32, 4);
  servo.attach(servoPin);
  //Serial.begin(9600);
}

void loop(){
  button = digitalRead(buttonPin);
    if(state == 0){
      lcd.setCursor(0, 0);
      lcd.print("Auto");
      for(pos = 15; pos < 165; pos += 1){
        CheckButton();
        if (needToBreak) {break;}
        oneAutoRotation();
      }

      for(pos = 165; pos >= 15; pos -= 1) {
        CheckButton();
        if (needToBreak) {break;}
        oneAutoRotation();
      }
      needToBreak = false;
    }
    else if (state == 1){
      CheckButton();
      lcd.setCursor(0, 0);
      lcd.print("Manual");
      potReading = analogRead(potPin);
      
      angle = map(potReading, 0, 1023, 15, 165);
      servo.write(angle);
      lcd.setCursor(0, 1);
      lcd.print(potReading);
    }
  /*if(isAuto){
    
  }
  else{
    //CheckButton();
    lcd.setCursor(0, 0);
    lcd.print("Manuall");
    delay(500);
    lcd.setCursor(0, 1);
    /*for(int i = 0;i<10;i++){
      lcd.setCursor(0, 1);
      delay(250);
      lcd.print(i);
    }
    lcd.print(isPressed);
  }*/
  
 

  //lcd.setCursor(0, 1);
  //lcd.print("Hello 2");

  //angle = map(0, 0, 1023, 0, 180);
  

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
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance);
}

void CheckButton(){
  button = digitalRead(buttonPin);
  if(button == oldButton)
  {
    oldButton = 1;
    state = !state;
    needToBreak = true;
    //lcd.blink();
    lcd.setCursor(0, 1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.clear();
    delay(250);
  }
}