int PWM_PIN=9;
int pushButton=8;
int IN1=11;
int IN2=10;
int analogInPin=A3;
unsigned long t0;
 unsigned long t;

void ISRHandler(){
  
  unsigned long t1=millis();
  t = t1-t0; //ms
  t0=t1;
  }

void setup(){

  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(pushButton,INPUT_PULLUP);
  pinMode(analogInPin,INPUT);
  pinMode(PWM_PIN,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  attachInterrupt(0,ISRHandler,RISING);
  t0=0;
}

void loop() {
 
  

  int GuageValue =0;
  int outputValue=0;
  GuageValue = analogRead(analogInPin);
  outputValue=map(GuageValue , 0 , 1023 , 0 , 255);
  analogWrite(PWM_PIN,outputValue);
  


  
  int buttonState=digitalRead(pushButton);
  if(buttonState==0){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    }
  else{
    
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
    }  
    unsigned long f = 1000/t; 
  unsigned long w = (60*f)/24;
  
  Serial.println(f);
  Serial.println(w);
}
