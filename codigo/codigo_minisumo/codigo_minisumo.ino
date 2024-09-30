/////COSAS PARA TERMINAR////
/*ninguna muajajajaja >:D*/
/// variables ///
int in1motorA=3;
int in2motorA=10;
int in1motorB=11;
int in2motorB=5;
int ena=8;
int enb=9;
int velE=140;
int velEM=255;
/// sensor de ultrasonido ///
int ultraTRIG=6;
int ultraECHO=7;
/// sensores infrarojos ///
int sensorirA=A7;
int sensorirB=A6;
// pruebas de variables //
long sensorTime;
int sensorDistance;
int readSensorirA;
int readSensorirB;
//funciones propias//
void movement(bool OnemotorA,bool TwomotorA,bool OnemotorB,bool TwomotorB, int velocE)
{
  digitalWrite(in1motorA, OnemotorA);
  digitalWrite(in2motorA, TwomotorA);
  digitalWrite(in1motorB, OnemotorB);
  digitalWrite(in2motorB, TwomotorB);
  digitalWrite(ena, velocE);
  digitalWrite(enb, velocE);
}
void readSensor()
{
  //sensores infrarrojos
  readSensorirA=analogRead(sensorirA);
  readSensorirB=analogRead(sensorirB);
  //sensor ultrasonico
  digitalWrite(ultraTRIG,LOW);
  delay(2);
  digitalWrite(ultraTRIG,HIGH);
  delay(10);
  digitalWrite(ultraTRIG,LOW);
  sensorTime=pulseIn(ultraECHO,HIGH);
  sensorDistance=sensorTime/58.2;
  //puerto serie
  Serial.print("Distancia: ");
  Serial.print(sensorDistance);
  Serial.print(" cm");
  Serial.print("                  valorIR: ");
  Serial.print(readSensorirA);
  Serial.print(", ");
  Serial.print(readSensorirB);
  Serial.print(" / ");
  if(readSensorirA<400||readSensorirB<400)
  {
    Serial.print("color blanco");
  } else
    {
      Serial.print("color negro");
    }
  Serial.println();
  delay(1000);
}

/// cuerpo del código (por así decirlo) ///
void setup() {
  Serial.begin(9600);
  //definiendo pines
  pinMode(in1motorA, OUTPUT);
  pinMode(in2motorA, OUTPUT);
  pinMode(in1motorB, OUTPUT);
  pinMode(in2motorB, OUTPUT);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  pinMode(sensorirA, INPUT);
  pinMode(sensorirB, INPUT);

  pinMode(ultraTRIG, OUTPUT);
  pinMode(ultraECHO, INPUT);
}

void loop() {
  //movimientos//
  readSensor();
  if(sensorDistance<=20&&sensorDistance>0)
  {
    movement(1,0,1,0,velEM);//embestir
  }
  else if(readSensorirA<400||readSensorirB<400)
  {
    movement(0,1,0,1,velE);//retroceder
    delay(500);
    movement(1,0,0,0,velE);//giro 180
    delay(200);
    movement(1,0,1,0,velE);//delante
  }
  else
  {
    movement(1,0,1,0,velE);//delante
    delay(5000);
  }
}