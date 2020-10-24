//pot input
int sensPin = A0;
int sensValue = 0;  // variable to store the value coming from the sensor

//sensor 1
#define trigPin1 34
#define echoPin1 35
//sensor 2
#define trigPin2 36
#define echoPin2 37
//sensor 3
#define trigPin3 38
#define echoPin3 39
// Driver 1 motor A
 int en1A = 2;
 int in1A = 41;
 int out1A = 40;
 // Driver 1 motor B
 int en1B = 3;
 int in1B = 43;
 int out1B = 42;
 // Driver 2 motor A
 int en2A = 4;
 int in2A = 45;
 int out2A = 44;
 // Driver 2 motor B
 int en2B = 5;
 int in2B = 47;
 int out2B = 46;
 // Driver 3 motor A
 int en3A = 6;
 int in3A = 49;
 int out3A = 48;
 // Driver 3 motor B
 int en3B = 7;
 int in3B = 51;
 int out3B = 50;
void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin1 as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin1 as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin2 as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin2 as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin3 as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin3 as an Input
  
  Serial.begin(9600);

  // Driver 1 motor A
  pinMode(en1A, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(out1A, OUTPUT);
  // Driver 1 motor B
  pinMode(en1B, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(out1B, OUTPUT);
  // Driver 2 motor A
  pinMode(en2A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(out2A, OUTPUT);
  // Driver 2 motor B
  pinMode(en2B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(out2B, OUTPUT);
  // Driver 3 motor A
  pinMode(en3A, OUTPUT);
  pinMode(in3A, OUTPUT);
  pinMode(out3A, OUTPUT);
  // Driver 3 motor B
  pinMode(en3B, OUTPUT);
  pinMode(in3B, OUTPUT);
  pinMode(out3B, OUTPUT);
}
void loop() {
 sensValue = analogRead(sensPin);
 sensor1(sensValue);
 delay(100);
 sensor2(sensValue);
 delay(100);
 sensor3(sensValue);
 Serial.println();
 delay(100);
} 

void sensor1(int sens){
 long unsigned duration;
 long unsigned distance;
 int sense = sens;
 digitalWrite(trigPin1, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1, LOW);
 duration = pulseIn(echoPin1, HIGH, 30000);
 distance = (duration/2) / 29.1;
 if (distance >= 255 || distance <= 0)
 {
 Serial.print("|Out of range|");
 }
 else {
 Serial.print("|");
 Serial.print(distance);
 Serial.print(" cm: ");
 Serial.print(sense);
 Serial.print("|");
 }
 int speed = 255-distance*2;
 turnMotors1(speed, sense);
}

void sensor2(int sens){
 long unsigned duration;
 long unsigned distance;
 digitalWrite(trigPin2, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2, LOW);
 duration = pulseIn(echoPin2, HIGH);
 distance = (duration/2) / 29.1;
 if (distance >= 255 || distance <= 0)
 {
 Serial.print("|Out of range|");
 }
 else {
 Serial.print("|");
 Serial.print(distance);
 Serial.print(" cm: ");
 Serial.print(sens);
 Serial.print("|");
 }
 int speed = 255-distance*2;
 turnMotors2(speed, sens);
}

void sensor3(int sens){
 long unsigned duration;
 long unsigned distance;
 digitalWrite(trigPin3, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin3, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin3, LOW);
 duration = pulseIn(echoPin3, HIGH);
 distance = (duration/2) / 29.1;
 if (distance >= 255 || distance <= 0)
 {
 Serial.print("|Out of range|");
 }
 else {
 Serial.print("|");
 Serial.print(distance);
 Serial.print(" cm: ");
 Serial.print(sens);
 Serial.print("|");
 }
 int speed = 255-distance*2;
 turnMotors3(speed, sens);
}

void turnMotors1(int speed, int sens){
 speed=speed*sens/1023;
 speed = speed*speed/255;
 //motor A
 if (speed >= 170){
  digitalWrite(in1A, HIGH);
  digitalWrite(out1A, LOW);
  analogWrite(en1A, 0);
 }
 else if (speed <= 0){
  
 }
 else{
  digitalWrite(in1A, HIGH);
  digitalWrite(out1A, LOW);
  analogWrite(en1A, speed);
 }
 //motor B
 if (speed >= 170){
  digitalWrite(in1B, HIGH);
  digitalWrite(out1B, LOW);
  analogWrite(en1B, 0);
 }
 else if (speed <= 0){
  
 }
 else{
  digitalWrite(in1B, HIGH);
  digitalWrite(out1B, LOW);
  analogWrite(en1B, speed);
 }
}

void turnMotors2(int speed,int sens){
 speed=speed*sens/1023;
 speed = speed*speed/255;
 //motor A
 if (speed >= 170){
  digitalWrite(in2A, HIGH);
  digitalWrite(out2A, LOW);
  analogWrite(en2A, 0);
 }
 else if (speed <= 0){
  
 }
 else{
  digitalWrite(in2A, HIGH);
  digitalWrite(out2A, LOW);
  analogWrite(en2A, speed);
 }
 //motor B
 if (speed >= 170){
  digitalWrite(in2B, HIGH);
  digitalWrite(out2B, LOW);
  analogWrite(en2B, 0);
 }
  else if (speed <= 0){
  
 }
 else{
  digitalWrite(in2B, HIGH);
  digitalWrite(out2B, LOW);
  analogWrite(en2B, speed);
 }
}

void turnMotors3(int speed, int sens){
 speed=speed*sens/1023;
 speed = speed*speed/255;   
 //motor A
 if (speed >= 170){
  digitalWrite(in3A, HIGH);
  digitalWrite(out3A, LOW);
  analogWrite(en3A, 0);
 }
 else if (speed <= 0){
  
 }
 else{
  digitalWrite(in3A, HIGH);
  digitalWrite(out3A, LOW);
  analogWrite(en3A, speed);
 }

 //motor B
 if (speed >= 170){
  digitalWrite(in3B, HIGH);
  digitalWrite(out3B, LOW);
  analogWrite(en3B, 0);
 }
 else if (speed <= 0){
  
 }
 else{
  digitalWrite(in3B, HIGH);
  digitalWrite(out3B, LOW);
  analogWrite(en3B, speed);
 }
}
