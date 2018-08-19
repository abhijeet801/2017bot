#include <PS2X_lib.h>
#include <Servo.h>
#include <Wire.h>

#define SABER_SERIAL Serial3
#define COM_SERIAL Serial2
#define ROLL_POS analogRead(roll_pot_pin)
#define PITCH_POS analogRead(pitch_pot_pin)

int roll_dirB = 9, roll_dirA = 10, roll_pwm = 4;
int pitch_dirA = 36, pitch_dirB = 2, pitch_pwm = 3;

Servo bldc;
PS2X ps2x;

int buff[2];
int roll_pot_pin = A11,pitch_pot_pin = A12;

int error, type;
int CLOCK = A1, COMMAND = A3, ATTENTION = A0, DATA = A2;

int pwm = 8, dirA = 12, dirB = 11;

int target_roll, target_pitch;

void setup();

void loop();
