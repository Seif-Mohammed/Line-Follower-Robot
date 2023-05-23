const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;
int trig = 2;
int echo = 8;
float distance ;
float time1 ;
int buzzer = 10;
int RIR=11,LIR=12;



void forward(){
  analogWrite(ENA, 85);
  analogWrite(ENB, 85); 
  //control direction 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  }
void backward(){
  analogWrite(ENA, 85);
  analogWrite(ENB, 85); 
  //control direction 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }
void left(){
  analogWrite(ENA, 110);
  analogWrite(ENB, 110); 
  //control direction 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  }
void right(){
  analogWrite(ENA, 110);
  analogWrite(ENB, 110); 
  //control direction 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }
void stopp(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0); 
  //control direction 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

}

void loop() {
  digitalWrite(13,HIGH);
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  time1 = pulseIn(echo,HIGH);
  distance = time1/57.8;
  
  //delay(500);
  
  Serial.print(distance);
    if (distance < 20){
      tone(10,255,500);
      delay(500);
      stopp();
      }
    else if(digitalRead(12) ==0 && digitalRead(11) == 0){
      forward();
      }
    else if(digitalRead(12) ==0 && digitalRead(11) == 1){
      right();
      }
    else if(digitalRead(12) ==1 && digitalRead(11) == 0){
      left();
      }else{
     //else if(digitalRead(12) ==1 && digitalRead(11) == 1){
      stopp();
     }

}
