//sensor
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;
int baca_sensor[6];

int pinEnable = 4;
int pinEnable2 = 2;
//motor kiri
int motor_kiri1 = 5;
int motor_kiri2 = 2;
//motor kanan
int motor_kanan1 = 3;
int motor_kanan2 = 11;

void setup()
{
  pinMode(sensor1, INPUT); //pin A0
  pinMode(sensor2, INPUT); //pin A1
  pinMode(sensor3, INPUT); //pin A2
  pinMode(sensor4, INPUT); //pin A3
  pinMode(sensor5, INPUT); //pin A4
  pinMode(sensor6, INPUT); //pin A5
  
  pinMode(pinEnable, OUTPUT);
  pinMode(pinEnable2, OUTPUT);
  pinMode(motor_kiri1, OUTPUT);
  pinMode(motor_kiri2, OUTPUT);
  pinMode(motor_kanan1, OUTPUT);
  pinMode(motor_kanan2, OUTPUT);
  
  Serial.begin(9600);
}

void readsensor()
{
  baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  serial.printin(baca_sensor[0];
               
  }
  
 void loop()
 {
   readsensor();
   
   if (baca_sensor[0] < 34 && baca_sensor[1] < 34 && baca_sensor[2] < 34 && baca_sensor[3] < 34 && baca_sensor[4] < 34 && baca_sensor[5] > 34);
   {
     digitalWrite (pinEnable, HIGH);
     digitalWrite (motor_kiri1, LOW);
     digitalWrite (motor_kiri2, LOW);
     digitalWrite (pinEnable2, HIGH);
     digitalWrite (motor_kanan1, HIGH);
     digitalWrite (motor_kanan2, LOW);
   }
   
 }
               
                 
            