int led1=5;
int led2=6;
int led3=7;
int led4=8;
int led5=9;
int boton=2;
int tiempo=100;
int c;

void setup() {
  pinMode(boton,INPUT);
  for(c=5; c<=9; c++)
  {
    pinMode(c, OUTPUT);
  }
}

void loop() {
  if (digitalRead(boton)==HIGH)
  {
    for(c=5; c<=9; c++) {
    digitalWrite(c, HIGH);
    delay(tiempo);
    digitalWrite(c, LOW);
    delay(tiempo);
    }
    for(c=9; c>=5; c=c-1) {
    digitalWrite(c, HIGH);
    delay(tiempo));
    digitalWrite(c, LOW);
    delay(tiempo);
    }
  }
}
