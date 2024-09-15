#define laser 2
#define sensor 3
#define buzzer 4

void setup() {
  Serial.begin(9600);
  pinMode(laser, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(laser, HIGH);
}

void loop() {
  bool val = digitalRead(sensor);

  if (val == 0) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
}
