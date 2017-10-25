/*
 * Industruino D21G EEPROM PUT/GET demo
 * Xabier Garmendia 2017
 * 
 * The EEPROM has been mapped for using a single 0-1023 byte data space.
 * 
 * Use the I2C_eeprom library from https://github.com/RobTillaart/Arduino/tree/master/libraries/I2C_EEPROM
 * And EEPROM library from 
 * 
 */
 
#include <EEPROM.h>

void setup() {
  SerialUSB.begin(9600);
  while (!SerialUSB);    // wait for Serial Monitor

  delay(1000);

  SerialUSB.println("INDUSTRUINO D21G I2C EEPROM PUT/GET DEMO");
  SerialUSB.println("================================");
  SerialUSB.println();
  
  EEPROM.begin();

  byte read_val;
  
  float float_sweep = -1089.5;
  
  SerialUSB.println("Writing entire EEPROM space...");
  SerialUSB.println();
  
  for (int i=0;i<256;i++) {
    EEPROM.put( i*4, float_sweep);
    float_sweep=float_sweep+0.1;
  }
  
  delay(1000);

  float float_sweep2;
  
  SerialUSB.print("Reading entire EEPROM space: ");
 
  for (int i=0;i<256;i++) {
    EEPROM.get(i*4,float_sweep2);
    delay(1);
    SerialUSB.println(float_sweep2);
  }
  SerialUSB.println();
}

void loop() {
  // nothing here
}