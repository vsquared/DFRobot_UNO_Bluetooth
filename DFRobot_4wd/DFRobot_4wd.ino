/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
  Written by S.Van Voorst for use with
  Adafruit MotorShield v2.3 and DFRobot 4wd
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Motor_Left_Front = AFMS.getMotor(4);
Adafruit_DCMotor *Motor_Right_Front = AFMS.getMotor(3);
Adafruit_DCMotor *Motor_Left_Rear = AFMS.getMotor(1);
Adafruit_DCMotor *Motor_Right_Rear = AFMS.getMotor(2);

const int speed = 40; // percent of maximum speed
int incomingByte = 0; // for incoming serial data
int pwm;
int pwm2;

void Forward()
{
 Motor_Left_Front->run(FORWARD);
 Motor_Left_Rear->run(FORWARD);  
 Motor_Right_Front->run(FORWARD);
 Motor_Right_Rear->run(FORWARD);
}

void Backward()
{
 Motor_Left_Front->run(BACKWARD);
 Motor_Left_Rear->run(BACKWARD);  
 Motor_Right_Front->run(BACKWARD);
 Motor_Right_Rear->run(BACKWARD);
}

void Left()
{
 Motor_Left_Front->run(BACKWARD);
 Motor_Left_Rear->run(BACKWARD);  
 Motor_Right_Front->run(FORWARD);
 Motor_Right_Rear->run(FORWARD);
}

void Right()
{
 Motor_Left_Front->run(FORWARD);
 Motor_Left_Rear->run(FORWARD);
 Motor_Right_Front->run(BACKWARD);
 Motor_Right_Rear->run(BACKWARD);
}

void Stop()
{
 Motor_Left_Front->run(RELEASE);
 Motor_Left_Rear->run(RELEASE);
 Motor_Right_Front->run(RELEASE);
 Motor_Right_Rear->run(RELEASE);
}

void setup()
{
  Serial.begin(9600);  
 
  AFMS.begin();  // create with the default frequency 1.6KHz
 //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  // scale percent into pwm range (0-255) 
  pwm = map(speed, 0,100,0,255);
  // increases speed of front wheels to match rear
  pwm2 = map(speed*1.5, 0,100,0,255);  
  Motor_Left_Front->setSpeed(pwm2);
  Motor_Right_Front->setSpeed(pwm2);
  Motor_Left_Rear->setSpeed(pwm);
  Motor_Right_Rear->setSpeed(pwm);
}

void loop()
{  
   if (Serial.available() > 0) {
       // read the incoming byte:
       incomingByte = Serial.read();
       switch (incomingByte) {
       case 102 : Serial.println("forward"); Forward(); // 'f'
       break;
       case 98 : Serial.println("backward"); Backward(); // 'b'
       break;
       case 108 : Serial.println("left"); Left(); // 'l'
       break;
       case 114 : Serial.println("right"); Right(); // 'r'
       break;
       case 115 : Serial.println("stop"); Stop(); // 's'
       break;
       default: Serial.println("something else");
       }
   }
}
