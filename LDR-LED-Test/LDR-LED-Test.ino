const int ldr = 10;
const int led = 2;
int x;

void setup() {
    pinMode(ldr, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  x = digitalRead(ldr);
  
  if (x == HIGH) {
    digitalWrite(led, HIGH);
  }
  
  if (x == LOW) {
    digitalWrite(led, LOW);
  }

  delay(100);
}


