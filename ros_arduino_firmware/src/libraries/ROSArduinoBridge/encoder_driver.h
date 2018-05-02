/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER
//below can be changed, but should be PORTB and PORTD pins; 
#define LEFT_ENC_PIN    PB2  //port 10 = PB2 (=pin 16 = SS) = PCINT2
#define RIGHT_ENC_PIN   PD2  //pin 2 = PD2 = INT0 = PCINT18
#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

