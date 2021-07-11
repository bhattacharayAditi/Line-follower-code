// line follower robot using arduino uno and motor shield
#include<AFMotor.h>
//defining the two motors
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(2,MOTOR12_64KHZ);
// declaring sensor pin
int LeftSensor =A0;
int RightSensor =A1;
int L_sensor_val=0; //to store value from sensor
int R_sensor_val=0;
int threshold=500;
void setup()
{
motor1.setSpeed(150);
motor2.setSpeed(150);
// set speed to 200/255
}
void loop()
{
L_sensor_val=analogRead(LeftSensor);
R_sensor_val=analogRead(RightSensor);
if(L_sensor_val>threshold&&R_sensor_val>threshold)
{
motor1.run(FORWARD);
motor2.run(FORWARD);
}
if(L_sensor_val<threshold&&R_sensor_val<threshold)
{
motor1.run(BACKWARD);
motor2.run(FORWARD);
}
if(L_sensor_val<threshold&&R_sensor_val>threshold)
{
motor1.run(BACKWARD);
motor2.run(FORWARD);
}
if(L_sensor_val>threshold&&R_sensor_val>threshold)
{
motor1.run(FORWARD);
motor2.run(BACKWARD);
}
}
