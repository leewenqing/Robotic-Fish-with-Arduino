/*
*
* File: BT_roboFishtest.ino
* Purpose: Example of the basic control for Robotic Fish（with Bluetooth）
* Version: 1.0.0
* 
*/


#include <SoftwareSerial.h>
#include <Servo.h>

// pin bluetooth
//SoftwareSerial MyBlue(10, 11); 

// pin servo
const int LEFT_SERVO_PIN = 6; //servo back tail 
const int CENTRAL_SERVO_PIN = 7;//fins 1 pin to 2 servo right and left
const int RIGHT_SERVO_PIN = 8;//middle tail

// posisi angle servo pada posisi awal
const long LEFT_SERVO_ZERO_VALUE = 89;
const long RIGHT_SERVO_ZERO_VALUE = 97;
const long CENTRAL_SERVO_ZERO_VALUE =97.5;

// Amplitude untuk servo samping kanan dan kiri
const long SIDE_SERVOS_FULL_AMPLITUDE = 30;
// setengah amplitude untuk servo kanan kiri saat robot berputar.
const long SIDE_SERVOS_HALF_AMPLITUDE = 15;
// amplitude untuk servo tengah
const long CENTRAL_SERVO_AMPLITUDE = 20;

// perbedaan periode pada setiap action
const long STEP_PERIOD_VERY_SLOW = 2000;
const long STEP_PERIOD_SLOW = 1500;
const long STEP_PERIOD_FAST = 1000;
const long STEP_PERIOD_VERY_FAST = 500;

long lastMillis;
long globalPhase;
float angleShiftLeftServo;
float angleShiftRightServo;
float angleShiftCentralServo;
long stepPeriod;
long amplitudeLeftServo;
long amplitudeRightServo;
boolean isAttached;
boolean isStopped;
char BLUETOOTH_VAR; 

Servo LeftServo;
Servo RightServo;
Servo CentralServo;

void attachServos() {
  if (!isAttached) {
    LeftServo.attach(LEFT_SERVO_PIN);
    RightServo.attach(RIGHT_SERVO_PIN);
    CentralServo.attach(CENTRAL_SERVO_PIN);
    isAttached = true;
  }
}

// dibeberapa posisi mungkin servo akan mengeluarkan bunyi atar bergetar
//     untuk menghindari hal ini servo akan diarahkan berhenti.
void detachServos() {
  if (isAttached) {
    LeftServo.detach();
    RightServo.detach();
    CentralServo.detach();
    isAttached = false;
  }
}

void setup() {
 
  Serial.begin(9600); 
  //MyBlue.begin(9600); 
  attachServos();
  isStopped = true;
  lastMillis = millis();

  angleShiftLeftServo = 0;
  angleShiftRightServo = 0;
  angleShiftCentralServo = 0;
  
  stepPeriod = STEP_PERIOD_VERY_SLOW;
  //Serial.println("Ready to connect"); 
  
}


int getAngle(long amplitude, long phaseMillis, float shiftAngle) {
  float alpha = 2 * PI * phaseMillis / stepPeriod + shiftAngle;
  float angle = amplitude * sin(alpha);
  return (int)angle;
}

template<typename T,size_t N>
boolean hasCode(T (&commandCodes)[N], long code) {
  for (int i = 0; i < N; i++) {
    if (commandCodes[i] == code) {
      return true;
    }
  }
  return false;
}

void loop() {
  long millisNow = millis();
  long millisPassed = millisNow - lastMillis;
  //Serial.println("ready1!");
  if (isStopped) {
    //  Kita harus menunggu setengah detik. Setelah itu kita berpikir bahwa servos 
    // berada dalam posisi nol dan kita dapat melepaskan mereka.
    if (millisPassed >= 100) {
      lastMillis = 0;
      detachServos();
    }

    globalPhase = 0;
  } else {
    lastMillis = millisNow;
    globalPhase += millisPassed;
    globalPhase = globalPhase % stepPeriod;
    //Serial.println("ready3!");
  }
  
  if(Serial.available()) {
        //Serial.println("BT is ready!");
        BLUETOOTH_VAR=Serial.read();
    if ('1'== BLUETOOTH_VAR||
        BLUETOOTH_VAR=='2' ||
        BLUETOOTH_VAR=='3' ){
    
      attachServos();
      isStopped = false;
      angleShiftLeftServo = 0;
      angleShiftRightServo = 0;
      angleShiftCentralServo = PI/2;
        
      amplitudeLeftServo = SIDE_SERVOS_FULL_AMPLITUDE;
      amplitudeRightServo = SIDE_SERVOS_FULL_AMPLITUDE;
      delay(20);
      if (BLUETOOTH_VAR=='2') {
        amplitudeLeftServo = SIDE_SERVOS_HALF_AMPLITUDE;
        delay(20);
      } else if (BLUETOOTH_VAR=='3') {
        amplitudeRightServo = SIDE_SERVOS_HALF_AMPLITUDE;
        delay(20);
      }
    } else if(BLUETOOTH_VAR=='4' ||
              BLUETOOTH_VAR=='5' ||
              BLUETOOTH_VAR=='6') {

      attachServos();
      isStopped = false;
      angleShiftLeftServo = 0;
      angleShiftRightServo = 0;
      angleShiftCentralServo = -PI/2;

      amplitudeLeftServo = SIDE_SERVOS_FULL_AMPLITUDE;
      amplitudeRightServo = SIDE_SERVOS_FULL_AMPLITUDE;
      delay(20);
      if (BLUETOOTH_VAR=='5') {
        amplitudeRightServo = SIDE_SERVOS_HALF_AMPLITUDE;
        delay(20);
      } else if (BLUETOOTH_VAR=='6') {
        amplitudeLeftServo = SIDE_SERVOS_HALF_AMPLITUDE;
        delay(20);
      }
    } else if (BLUETOOTH_VAR=='7') {
      attachServos();
      isStopped = false;
      angleShiftLeftServo = 0;
      angleShiftRightServo = PI;
      angleShiftCentralServo = -PI/2;
      amplitudeLeftServo = SIDE_SERVOS_FULL_AMPLITUDE;
      amplitudeRightServo = SIDE_SERVOS_FULL_AMPLITUDE;
      delay(20);
    } else if (BLUETOOTH_VAR=='8') {
      attachServos();
      isStopped = false;
      angleShiftLeftServo = 0;
      angleShiftRightServo = PI;
      angleShiftCentralServo = PI/2;
      amplitudeLeftServo = SIDE_SERVOS_FULL_AMPLITUDE;
      amplitudeRightServo = SIDE_SERVOS_FULL_AMPLITUDE;
      delay(20);
    } else if (BLUETOOTH_VAR=='9') {
      attachServos();
      isStopped = true;
      angleShiftLeftServo = 0;
      angleShiftRightServo = 0;
      angleShiftCentralServo = 0;
      amplitudeLeftServo = SIDE_SERVOS_FULL_AMPLITUDE;
      amplitudeRightServo = SIDE_SERVOS_FULL_AMPLITUDE;
      delay(20);
    } else if (BLUETOOTH_VAR=='a') {
      // globalPhase koreksi untuk menyimpan posisi servo ketika mengubah periode.
      globalPhase = globalPhase * STEP_PERIOD_VERY_SLOW / stepPeriod;
      stepPeriod = STEP_PERIOD_VERY_SLOW;
      delay(20);
    } else if (BLUETOOTH_VAR=='b') {
      globalPhase = globalPhase * STEP_PERIOD_SLOW / stepPeriod;
      stepPeriod = STEP_PERIOD_SLOW;
      delay(20);
    } else if (BLUETOOTH_VAR=='c') {
      globalPhase = globalPhase * STEP_PERIOD_FAST / stepPeriod;
      stepPeriod = STEP_PERIOD_FAST;
      delay(20);
    } else if (BLUETOOTH_VAR=='d') {
      globalPhase = globalPhase * STEP_PERIOD_VERY_FAST / stepPeriod;
      stepPeriod = STEP_PERIOD_VERY_FAST;
      delay(20);
    }
   
   
  }
  
  if (isAttached) {
    LeftServo.write(LEFT_SERVO_ZERO_VALUE + getAngle(amplitudeLeftServo, globalPhase, angleShiftLeftServo));
    RightServo.write(RIGHT_SERVO_ZERO_VALUE + getAngle(amplitudeRightServo, globalPhase, angleShiftRightServo));
    CentralServo.write(CENTRAL_SERVO_ZERO_VALUE + getAngle(CENTRAL_SERVO_AMPLITUDE, globalPhase, angleShiftCentralServo));
  }
}
