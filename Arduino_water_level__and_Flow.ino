int Time ;
int distance;
int waterInput;
const int analogInPin = A0;
int level = 0;
int echo = 6;
int trig = 7;

void setup()
{
pinMode(analogInPin, INPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

pinMode(4, OUTPUT);
pinMode(3, OUTPUT);

Serial.begin(9600);
}

void loop()
{
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
delayMicroseconds(5);
digitalWrite(trig,HIGH);
delayMicroseconds(10);

Time = pulseIn(echo,HIGH);

distance= 0.0343*Time/2;
Serial.print("Water distance at -> ");
Serial.println(distance);

digitalWrite(3, HIGH);  // Turn the sensor ON
  
level = analogRead(analogInPin);// Read the analog value form sensor
Serial.print("Water level = ");
Serial.println(level);

delay(500);

if(distance<=1){
digitalWrite(4,LOW);
}
//HIGH
if(distance>=5 && distance <=10 && level > 250)
{
digitalWrite(8,LOW); //Low
digitalWrite(9,LOW); //Warning
digitalWrite(10,LOW); //Mid
digitalWrite(11,HIGH); //High


noTone(5);
}
//MEDIUM
if(distance>10 && distance <=15 && level > 250)
{
digitalWrite(8,LOW); //Low
digitalWrite(9,LOW); //Warning
digitalWrite(10,HIGH); //Mid
digitalWrite(11,LOW); //High

noTone(5);
}
// WARNING
if(distance > 15 && distance<=20 && level > 250)
{
digitalWrite(8,LOW); //Low
digitalWrite(9,HIGH); //Warning
digitalWrite(10,LOW); //Mid
digitalWrite(11,LOW); //High
delay(1000);

digitalWrite(9,LOW); //Warning


tone(5, 500);
delay(200);
noTone(5);
}
// LOW
if(distance>20 && level > 250)
{
digitalWrite(8,HIGH); //Low
digitalWrite(9,LOW); //Warning
digitalWrite(10,LOW); //Mid
digitalWrite(11,LOW); //High\

digitalWrite(4,HIGH);
tone(5, 1000);
}

if(level <= 360){
digitalWrite(8,LOW); //Low
digitalWrite(10,LOW); //Mid
digitalWrite(11,LOW); //High

digitalWrite(9,HIGH);//WARNING
tone(5, 500);
delay(1000);
digitalWrite(9,LOW);//WARNING
noTone(5);
}


}
