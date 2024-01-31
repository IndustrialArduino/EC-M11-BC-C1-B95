#include <Adafruit_ADS1015.h>

#define RXD2 25
#define TXD2 26
#define PIN 22
#define RES 32

Adafruit_ADS1115 ads1(0x49);
String adcString[8];

void setup() {
  // Initialize both serial ports:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  pinMode(PIN, OUTPUT);
  pinMode(RES, OUTPUT);

  digitalWrite(RES, HIGH);
  digitalWrite(PIN, HIGH);

  // Additional setup for analog inputs and other components
  Wire.begin(16, 17);
  ads1.begin();
  ads1.setGain(GAIN_ONE);

  Serial.println("The device is powered up");
  Serial.println("Initialized analog inputs");
}

void loop() {
  // Read and send data from Serial2 to Serial
  if (Serial2.available()) {
    int inByte = Serial2.read();
    Serial.write(inByte);
  }

  // Read and send data from Serial to Serial2
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial2.write(inByte);
  }

  // Additional code for your loop
  Serial.print("I1: ");
  Serial.println(digitalRead(35));
  Serial.print("I2: ");
  Serial.println(digitalRead(34));
  Serial.print("Battery Voltage: ");
  Serial.println(readBattery());
  delay(800);
  printanalog();
  delay(800);
  digitalWrite(18, HIGH);
  delay(800);
}

int readBattery() {
  unsigned int analog_value;
  analog_value = analogRead(36);
  return analog_value;
}

void printanalog() {
  for (int i = 0; i < 4; i++) {
    adcString[i] = String(ads1.readADC_SingleEnded(i));
    adcString[i] = String(ads1.readADC_SingleEnded(i));
    delay(10);
    Serial.print("A" + String(i + 1) + ": ");
    Serial.print(adcString[i]);
    Serial.print("  ");
  }

  Serial.println("____________________________________");
}
