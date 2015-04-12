#define trig1Pin 12
#define echo1Pin 13
#define trig2Pin 2
#define echo2Pin 3
#define buzzer 9
void setup()
{
 Serial.begin (9600);
 pinMode(trig1Pin, OUTPUT);
 pinMode(echo1Pin, INPUT);
 pinMode(trig2Pin, OUTPUT);
 pinMode(echo2Pin, INPUT);
 pinMode(buzzer, OUTPUT);
}
void loop()
{
 int duration1,duration2, distance1,distance2;
 
 digitalWrite(trig1Pin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trig1Pin, LOW);
 
 duration1 = pulseIn(echo1Pin, HIGH);
 distance1 = (duration1/2) / 29.1;
 if (distance1 >= 200)
 {
   Serial.println("LEFT WING CLEAR");
   
 }
 if (distance1 <= 50 )
 {
    Serial.println("MOVE RIGHT");
analogWrite(buzzer,255);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
 }
 else 
 {
   Serial.print(distance1);
   Serial.println(" cm1");
analogWrite(buzzer,255);
delay(500);
digitalWrite(buzzer,LOW);
delay(500);
 }
 
 digitalWrite(trig2Pin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trig2Pin, LOW);
 
 duration2 = pulseIn(echo2Pin, HIGH);
 distance2 = (duration2/2) / 29.1;
 
 if (distance2 >= 200)
 {
   Serial.println("RIGHT WING CLEAR");
 }
 if (distance2 <= 50 )
 {
   Serial.println("MOVE LEFT");
analogWrite(buzzer,255);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
 }
 else
 {
   Serial.print(distance2);
   Serial.println(" cm2");
analogWrite(buzzer,255);
delay(500);
digitalWrite(buzzer,LOW);
delay(500);
 }
 delay(100);
} 
