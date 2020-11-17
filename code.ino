long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}

void loop()
{ 
  int cm = 0.01723 * readUltrasonicDistance(7, 6);
  int num = cm / 100;
  
  Serial.print(cm);
  Serial.println("cm, ");
  
  int a = num % 2;
  int b = (num / 2) % 2;
  int c = (num / 4) % 2;
  int d = (num / 8) % 2;
  
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  
  digitalWrite(8, LOW);
  digitalWrite(8, HIGH);
  
  num = (cm / 10) % 10;
  
  a = num % 2;
  b = (num / 2) % 2;
  c = (num / 4) % 2;
  d = (num / 8) % 2;
  
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  
  digitalWrite(9, LOW);
  digitalWrite(9, HIGH);
  
  num = cm % 10;
  
  a = num % 2;
  b = (num / 2) % 2;
  c = (num / 4) % 2;
  d = (num / 8) % 2;
  
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  
  digitalWrite(10, LOW);
  digitalWrite(10, HIGH);
}
