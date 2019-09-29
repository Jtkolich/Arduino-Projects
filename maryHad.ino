#include<Servo.h>

const int trig = 9;
const int echo = 10;
const int buzzer = 2;
Servo motor;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  pinMode(trig, OUTPUT);
  motor.attach(12);
  pinMode(echo,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  motor.write(90);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  if (distance <= 25 and distance >7){
    tone(buzzer,1000,distance*5);
    delay(distance*10);
    }
  else if (distance <= 7){
    motor.write(180);
    delay(100);
    motor.write(90);
  }
  else{
   noTone(buzzer);
  }
   
}
   
