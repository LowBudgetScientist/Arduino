#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int d0 = 2;
const int d1 = 3;
const int d2 = 4;
const int d3 = 5;

int a;
int b;
int c;
int d;

void setup() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5,5);
  display.println("Waiting for a key press..");
  display.display();

  pinMode(d0, INPUT);
  pinMode(d1, INPUT);
  pinMode(d2, INPUT);
  pinMode(d3, INPUT);

  Serial.begin(9600);
}

void loop() {
  a = digitalRead(d3);
  b = digitalRead(d2);
  c = digitalRead(d1);
  d = digitalRead(d0);

  if (a == HIGH) {
    display.clearDisplay();
    display.setCursor(5,5);
    display.println("Button A was pressed");
    display.display();
  }

  if (b == HIGH) {
    display.clearDisplay();
    display.setCursor(5,5);
    display.println("Button B was pressed");
    display.display();
  }

  if (c == HIGH) {
    display.clearDisplay();
    display.setCursor(5,5);
    display.println("Button C was pressed");
    display.display();
  }

  if (d == HIGH) {
    display.clearDisplay();
    display.setCursor(5,5);
    display.println("Button D was pressed");
    display.display();
  }
}
