/***
    eeprom_bits example.
    
	This example sketch is highlighting the usage 
	of EEPROM.readBit() and EEPROM.writeBit().
    
	
	
    Written by Christopher Andrews 2015
    Released under MIT licence.
***/

#include <EEPROM.h>

void setup() {
  
  int address = 0; //Address to first EEPROM cell.
  
  EEPROM.start();
  
  delay( 2000 );  //Prevent touching the EEPROM through resets and uploading of sketch.
  SerialUSB.begin( 9600 );
  
  while (!SerialUSB) {
    ; // wait for serial port to connect. Needed for Leonardo boards only.
  }
  
  //Clear first cell so we can see the changes.
  EEPROM.update( address, 0 );
  
  SerialUSB.print( "Contents of cell 0: " );
  SerialUSB.println( EEPROM.read( address ), HEX );
  delay( 500 );
  
  //Set the fourth bit HIGH, or true
  EEPROM.writeBit( address, 3, true ); //Parameters: cell index, bit index, value
  
  SerialUSB.print( "Contents of cell 0 after setting bit: " );
  SerialUSB.println( EEPROM.read( address ), HEX );
  delay( 500 );
  
  SerialUSB.print( "Value of fourth bit: " );
  
  bool value = EEPROM.readBit( address, 3 );
  
  if( value ){
    SerialUSB.println( "true" );
  }else{
    SerialUSB.println( "false" );
  }
}

void loop(){

}