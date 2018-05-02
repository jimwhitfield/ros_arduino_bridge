/* *************************************************************
   Encoder definitions
   
   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
   
#ifdef USE_BASE

#ifdef ROBOGAIA
  /* The Robogaia Mega Encoder shield */
  #include "MegaEncoderCounter.h"

  /* Create the encoder shield object */
  MegaEncoderCounter encoders = MegaEncoderCounter(4); // Initializes the Mega Encoder Counter in the 4X Count mode
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return encoders.YAxisGetCount();
    else return encoders.XAxisGetCount();
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT) return encoders.YAxisReset();
    else return encoders.XAxisReset();
  }
#elif defined(ARDUINO_ENC_COUNTER)
  volatile long right_enc_count = 0L;
/* Interrupt routine for RIGHT (was LEFT) encoder, taking care of actual counting */
  ISR (PCINT2_vect){
    static uint8_t enc_last_D=0;    
    enc_last_D = (PIND); 
    if (enc_last_D > 0) {
        right_enc_count++;
    }
}

  volatile long left_enc_count = 0L;  
/* Interrupt routine for LEFT encoder (Was RIGHT on PORTC), taking care of actual counting */
  ISR (PCINT0_vect){
    static uint8_t enc_last_B=0;
            
    enc_last_B = (PINB);   
    if (enc_last_B > 0) {
        left_enc_count++;
    }
}
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return left_enc_count;
    else return right_enc_count;
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT){
      left_enc_count=0L;
      return;
    } else { 
      right_enc_count=0L;
      return;
    }
  }

#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif

