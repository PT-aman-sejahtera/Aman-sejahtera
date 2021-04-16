
// Modul praktikum 3 - sistem kendali PID kasus p
// Nama Tim : Aman sejahtera
// Nama Anggota 1 : Ahmad satibi
// Nama Anggota 2 : Ryan farhana
// Versi program : 1,0

//++++++++++++++++++++++++++++++++++++++++//

//motor directory
#define CW  0
#define CCW 1
 
//motor control pin
#define motorDirPin 7
#define motorPWMPin 9
#define enablePin 8
 
//encoder pin
#define encoderPinA 2
#define encoderPinB 4
 
//encoder var
int encoderPos = 0;

int buttonup = 12;
int buttondown = 13;

//P control
int Kp          = 10;
int Ki          = 0;
int Kd          = 0;
int   targetPos   = 100;
int   error;
int   prevError;
float   integral;
float   derivative;
float   dt = 0.01;//10 milisecond
int   control;
int   velocity;
 
//external interrupt encoder
void doEncoderA()
{
  digitalRead(encoderPinB)?encoderPos--:encoderPos++;
}
 
void setup()
{
  //setup interrupt
    pinMode(encoderPinA, INPUT_PULLUP);
    pinMode(encoderPinB, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(encoderPinA), doEncoderA,RISING);
   
    //setup motor driver
    pinMode(motorDirPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, HIGH);
   
    //Serial.begin(9600);
}
 
void loop()
{
    targetPos = analogRead(A0)/10; //ADC max 1023
    error   = targetPos - encoderPos;
    integral += error * dt;
    derivative = (error - prevError)/dt;
    control = (Kp*error) + (Ki*integral) + (Kd*derivative);
   
    velocity = min(max(control, -255), 255);
    if(velocity >= 0)
    {
        digitalWrite(motorDirPin, CW);
        analogWrite(motorPWMPin, velocity); 
    }
    else
    {
        digitalWrite(motorDirPin, CCW);
        analogWrite(motorPWMPin, 255+velocity);
    }
    //Serial.println(encoderPos);
    prevError = error;
    delay(dt*1000);             
}