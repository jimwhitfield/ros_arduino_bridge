/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
int ENA=5; 
int IN1=6;  // INL1
int IN2=7;  // INL2
int ENB=11; 
int IN3=8;  // INR1
int IN4=9;  // INR2

/* was  
  #define RIGHT_MOTOR_BACKWARD 5
  #define LEFT_MOTOR_BACKWARD  6
  #define RIGHT_MOTOR_FORWARD  9
  #define LEFT_MOTOR_FORWARD   10
  #define RIGHT_MOTOR_ENABLE 12
  #define LEFT_MOTOR_ENABLE 13
  */
  #define RIGHT_MOTOR_ENABLE 5
  #define RIGHT_MOTOR_FORWARD  6
  #define RIGHT_MOTOR_BACKWARD 7
  
  #define LEFT_MOTOR_ENABLE 11
  #define LEFT_MOTOR_BACKWARD  8
  #define LEFT_MOTOR_FORWARD   9


#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
