/*

    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
 #include <Servo.h>
 Servo myservo;
 
int pos = 0; 
int trigPin = 4;    // Trigger
int echoPin = 5;    // Echo
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);
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
  
  delay(250);

  if (inches <= 10)
  {
    myservo.write(40);
    }
  else
  {
    myservo.write(0);
    }
  

//for (pos = 0; pos <= 180; pos +=1) {
//  myservo.write(pos);
//  delay(15);
//  }
//for (pos = 180; pos >= 0; pos -= 1) {
//  myservo.write(pos);
//  delay(15);
//  }
  
  
}

