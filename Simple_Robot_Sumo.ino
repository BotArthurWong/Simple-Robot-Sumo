

//motor 1
int enA = 10;
int in1 = 9;
int in2 = 8;

//motor 2
int enB = 4;
int in3 = 6;
int in4 = 5;

// defines pins numbers
const int trigPin = 12;
const int echoPin = 13;
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);


 pinMode(13,OUTPUT);

}

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if (distance<=50)
{
  Forward();
}
else
{
  Left();
}
}


  /*to counter robot from jerk, uncomment the firstline and the all lines that have 'millis()' and disable the last 'else' condition*/ 






void Left() {

// turn on motor A
digitalWrite(in1,1);
digitalWrite(in2,0);
analogWrite(enA,200);

//turn on motor B
digitalWrite(in3,1);
digitalWrite(in4,0);
analogWrite(enB,200);


}

void Stop()
{

analogWrite(enA,0);
analogWrite(enB,0);

}

void Forward()
{
// turn on motor A
digitalWrite(in1,0);
digitalWrite(in2,0);
analogWrite(enA,250);

//turn on motor B
digitalWrite(in3,0);
digitalWrite(in4,0);
analogWrite(enB,250);

}

void Reverse()
{
// turn on motor A
digitalWrite(in1,1);
digitalWrite(in2,1);
analogWrite(enA,210);

//turn on motor B
digitalWrite(in3,1);
digitalWrite(in4,1);
analogWrite(enB,210);

}

void Right() {

// turn on motor A
digitalWrite(in1,0);
digitalWrite(in2,0);
analogWrite(enA,200);

//turn on motor B
digitalWrite(in3,0);
digitalWrite(in4,0);
analogWrite(enB,200);


}


}
