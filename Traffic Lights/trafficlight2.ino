int red=10;
int yellow=9;
int green=8;
int button=12;
void setup(){
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(green,HIGH);
}

void loop(){
  if (digitalRead(button)==HIGH){
    delay(15);
    if (digitalRead(button)==HIGH){
      changeLights();
      delay(1500);
    }
  }
  
}

void changeLights(){
  //green off, yellow on for 3 seconds
  digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
  delay(3000);
  //Turn off yellow,then turn red on for 5 seconds
  digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
  delay(5000);
  //red and yellow on for 2 seconds(red is already pn though)
  digitalWrite(yellow,HIGH);
  delay(2000);
  //turn off red and yellow,then turn on green
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  delay(3000);
  
}
