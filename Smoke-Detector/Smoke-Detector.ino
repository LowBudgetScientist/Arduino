const int sensor = 2;
const int buzzer = 3;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int sensorVal = digitalRead(sensor);

  if (sensorVal == LOW) {
    analogWrite(buzzer, 50);

  } else {
    analogWrite(buzzer, 0);
  }

  delay(1000);
}
