#include <Arduino.h>

#define verdeP 2
#define vermelhoP 0 
#define verdeS 4
#define amareloS 5
#define vermelhoS 16 
#define botao 12

volatile int flag = 0;
int crossTime=0;


void ICACHE_RAM_ATTR changeLights(){
  flag = 1;
}


void setup()
{
  pinMode(verdeP, OUTPUT);
  pinMode(vermelhoP, OUTPUT);
  pinMode(verdeS, OUTPUT);
  pinMode(vermelhoS, OUTPUT);
  pinMode(amareloS, OUTPUT);
  pinMode(botao, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(botao),changeLights ,RISING); 
}

void loop()
{ 
  digitalWrite(verdeS, HIGH);
  digitalWrite(vermelhoP, HIGH);  

  if(flag){

    digitalWrite(verdeS, LOW);
    digitalWrite(amareloS, HIGH);
    
    delay(2000);
    digitalWrite(amareloS, LOW);
    digitalWrite(vermelhoS, HIGH);
    digitalWrite(vermelhoP, LOW);
    digitalWrite(verdeP, HIGH);
    delay(5000);
    
    for(crossTime=0;crossTime<5;crossTime++){
      digitalWrite(verdeP, LOW);
      delay(500);
      digitalWrite(verdeP, HIGH);
      delay(500);
    }
    
    digitalWrite(vermelhoS, LOW);
    digitalWrite(verdeS, HIGH);
    digitalWrite(verdeP, LOW);
    digitalWrite(vermelhoP, HIGH);
    delay(5000);
    
    flag = 0;
  }
}
