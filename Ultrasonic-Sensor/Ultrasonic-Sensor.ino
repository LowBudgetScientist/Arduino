
const int led1Pin = 2;
const int led2Pin = 3;
const int echoPin = 4;
const int trigPin = 5;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long duration, cm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  if (cm <= 5) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);

  } else if (cm <= 10) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);

  } else if (cm > 10) {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);

  }

  delay(1000);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
