int enablePin = 11;
int in1Pin = 11;
int in2Pin = 10;
int switchPin = 8;
int potPin = 0;
int statusPin= 13;
void setup()
{
pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(enablePin, OUTPUT);
pinMode(switchPin, INPUT_PULLUP);
pinMode(statusPin,OUTPUT);
}
 
void loop()
{
int speed = analogRead(potPin) / 4;
boolean reverse = digitalRead(switchPin);
setMotor(speed, reverse);
}
void setMotor(int speed, boolean reverse)
{
analogWrite(enablePin, speed);
digitalWrite(in1Pin, ! reverse);
digitalWrite(in2Pin, reverse);
}
