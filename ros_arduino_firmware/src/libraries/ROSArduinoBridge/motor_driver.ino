/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   
#ifdef POLOLU_VNH5019
//  /* Include the Pololu library */
//  #include "DualVNH5019MotorShield.h"
//
//  /* Create the motor driver object */
//  DualVNH5019MotorShield drive;
//  
//  /* Wrap the motor driver initialization */
//  void initMotorController() {
//    drive.init();
//  }
//
//  /* Wrap the drive motor set speed function */
//  void setMotorSpeed(int i, int spd) {
//    if (i == LEFT) drive.setM1Speed(spd);
//    else drive.setM2Speed(spd);
//  }
//
//  // A convenience function for setting both motor speeds
//  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
//    setMotorSpeed(LEFT, leftSpeed);
//    setMotorSpeed(RIGHT, rightSpeed);
//  }
#elif defined POLOLU_MC33926
//  /* Include the Pololu library */
//  #include "DualMC33926MotorShield.h"
//
//  /* Create the motor driver object */
//  DualMC33926MotorShield drive;
//  
//  /* Wrap the motor driver initialization */
//  void initMotorController() {
//    drive.init();
//  }
//
//  /* Wrap the drive motor set speed function */
//  void setMotorSpeed(int i, int spd) {
//    if (i == LEFT) drive.setM1Speed(spd);
//    else drive.setM2Speed(spd);
//  }
//
//  // A convenience function for setting both motor speeds
//  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
//    setMotorSpeed(LEFT, leftSpeed);
//    setMotorSpeed(RIGHT, rightSpeed);
//  }
#elif defined L298_MOTOR_DRIVER
  void initMotorController() {
    pinMode(RIGHT_MOTOR_FORWARD,OUTPUT);
    pinMode(RIGHT_MOTOR_BACKWARD,OUTPUT);
    pinMode(RIGHT_MOTOR_ENABLE,OUTPUT);
    pinMode(LEFT_MOTOR_FORWARD,OUTPUT);
    pinMode(LEFT_MOTOR_BACKWARD,OUTPUT);
    pinMode(LEFT_MOTOR_ENABLE,OUTPUT);

    // start with telling motors to not move either forward or back...
    digitalWrite(LEFT_MOTOR_FORWARD, 0); 
    digitalWrite(LEFT_MOTOR_BACKWARD, 0); 
    digitalWrite(RIGHT_MOTOR_FORWARD, 0); 
    digitalWrite(RIGHT_MOTOR_BACKWARD, 0); 

    // .. but start with telling both wheels to run full-speed WHEN A DIRECTION IS APPLIED
    digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
  }
  
  void setMotorSpeed(int side, int spd) {
    bool reverse = false;
    Serial.print("DBG-setMotorSpeed with side:");
    Serial.print(side);
    Serial.print(" and spd:");
    Serial.println(spd);
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = true;
    }
    if (spd > 255)
      spd = 255;
    
    if (side == LEFT) { 
      if (spd == 0) {  
        digitalWrite(LEFT_MOTOR_FORWARD, 0); 
        digitalWrite(LEFT_MOTOR_BACKWARD, 0); 
        analogWrite(LEFT_MOTOR_ENABLE, 0); 
      }
      else if (reverse) { 
        digitalWrite(LEFT_MOTOR_BACKWARD, 1); 
        digitalWrite(LEFT_MOTOR_FORWARD, 0); 
        analogWrite(LEFT_MOTOR_ENABLE, spd); 
      }
      else  { 
        digitalWrite(LEFT_MOTOR_FORWARD, 1); 
        digitalWrite(LEFT_MOTOR_BACKWARD, 0); 
        analogWrite(LEFT_MOTOR_ENABLE, spd); 
      }
    }
    else if (side == RIGHT) {
      if (spd == 0) {  
        digitalWrite(RIGHT_MOTOR_FORWARD, 0); 
        digitalWrite(RIGHT_MOTOR_BACKWARD, 0); 
        analogWrite(RIGHT_MOTOR_ENABLE, 0); 
      }
      else if (reverse) { 
        digitalWrite(RIGHT_MOTOR_BACKWARD, 1); 
        digitalWrite(RIGHT_MOTOR_FORWARD, 0); 
        analogWrite(RIGHT_MOTOR_ENABLE, spd); 
      }
      else  { 
        digitalWrite(RIGHT_MOTOR_FORWARD, 1); 
        digitalWrite(RIGHT_MOTOR_BACKWARD, 0); 
        analogWrite(RIGHT_MOTOR_ENABLE, spd); 
      }
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#else
  #error A motor driver must be selected!
#endif

#endif
