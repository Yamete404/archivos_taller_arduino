int led1=5;
int led2=6;
int led3=7;
int boton=2;
int c;
int lectura;
void setup() {
  for(c=5;c<8;c++)
  {
    pinMode(c, OUTPUT);
  }
pinMode(boton, INPUT);
}

void loop() {
  lecutra=digitalRead(boton);
  if(lectura==HIGH)
  {
    for(c=10;c>=0;c=c-1)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      delay(1000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(1000);
    }
  }
  else {
    digitalWrite(led2, LOW);
  }

}
