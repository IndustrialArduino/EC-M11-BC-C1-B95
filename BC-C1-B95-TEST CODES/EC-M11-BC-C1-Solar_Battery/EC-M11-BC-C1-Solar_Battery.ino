#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads1;

int analog_value = 0;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  Wire.begin(16,17);
  if (!ads1.begin(0x49)) {
    Serial.println("Failed to initialize ADS 1 .");
    while (1);
  }
}

void loop() {

   int16_t adc0, adc1, adc2, adc3;
  adc0 = ads1.readADC_SingleEnded(0);
  adc1 = ads1.readADC_SingleEnded(1);
  adc2 = ads1.readADC_SingleEnded(2);
  adc3 = ads1.readADC_SingleEnded(3);

  Serial.println("-----------------------------------------------------------");
  Serial.print("AIN1: "); Serial.print(adc0); Serial.println("  ");
  Serial.print("AIN2: "); Serial.print(adc1); Serial.println("  ");
  Serial.print("SOLAR: "); Serial.print(adc2); Serial.println("  ");
  Serial.print("AIN4: "); Serial.print(adc3); Serial.println("  ");
   
  // put your main code here, to run repeatedly:

}