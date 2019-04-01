/*

    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
#include <Wire.h>
 #include <Servo.h>
 Servo myservo;

   /////////////// ACCELEROMETER
const int MPU=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
 
  ////////////////SERVO AND THE SONIC
int pos = 0; 
int trigPin = 4;    // Trigger
int echoPin = 5;    // Echo
long duration, cm, inches;
 
void setup() {
  ////////////////SERVO AND THE SONIC
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);

  /////////////// ACCELEROMETER
   Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.println();
  
  delay(100);

  if (inches <= 10)
  {
    myservo.write(40);
    }
  else
  {
    myservo.write(0);
    }
  
    /////////////// ACCELEROMETER
 Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
//  AcX=Wire.read()<<8|Wire.read();    
//  AcY=Wire.read()<<8|Wire.read();  
//  AcZ=Wire.read()<<8|Wire.read();  
//  GyX=Wire.read()<<8|Wire.read();  
//  GyY=Wire.read()<<8|Wire.read();  
//  GyZ=Wire.read()<<8|Wire.read();  

  AcX=Wire.read();    
  AcY=Wire.read();  
  AcZ=Wire.read();  
  GyX=Wire.read();  
  GyY=Wire.read();  
  GyZ=Wire.read();  
  
//  Serial.print("Accelerometer: ");
//  Serial.print("X = "); Serial.print(AcX);
//  Serial.print(" | Y = "); Serial.print(AcY);
//  Serial.print(" | Z = "); Serial.println(AcZ); 
  
//  Serial.print("Gyroscope: ");
//  Serial.print("X = "); Serial.print(GyX);
//  Serial.print(" | Y = "); Serial.print(GyY);
//  Serial.print(" | Z = "); Serial.println(GyZ);
//  Serial.println(" ");

//Serial.print(AcX);
//Serial.print(" ");
//Serial.print(AcY);
//Serial.print(" ");
//Serial.print(AcZ);
//Serial.print(" ");



Serial.print(GyX);
Serial.print(" ");
Serial.print(GyY);
Serial.print(" ");
Serial.print(GyZ);
Serial.print(" ");

  //delay(333);
  
}

