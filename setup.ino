void setup() {
  Serial.begin(9600);
  COM_SERIAL.begin(9600);
  SABER_SERIAL.begin(9600);

  setup_pot();
  setup_RP();
  setup_ps2();
  setup_bane();

  target_roll = ROLL_POS;
  target_pitch = PITCH_POS;
}

void setup_ps2() {
  error = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA, false, false);

  while (error != 0) {
//    error = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA, false, false);
    Serial.println("Check PS2 Wiring");
  }
}

void setup_saber() {
  SABER_SERIAL.begin(9600);

  SABER_SERIAL.write(64);
  delay(2);
  SABER_SERIAL.write(192);
  delay(2);
}

void setup_bane() {
  pinMode(pwm, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);

  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
}

void setup_RP() {
  pinMode(roll_dirA, OUTPUT);
  pinMode(roll_dirB, OUTPUT);
  pinMode(roll_pwm, OUTPUT);

  pinMode(pitch_dirA, OUTPUT);
  pinMode(pitch_dirB, OUTPUT);
  pinMode(pitch_pwm, OUTPUT);

  digitalWrite(roll_dirA, HIGH);
  digitalWrite(roll_dirB, HIGH);

  digitalWrite(pitch_dirA, HIGH);
  digitalWrite(pitch_dirB, HIGH);

  analogWrite(roll_pwm, 0);
  analogWrite(pitch_pwm, 0);
}

void setup_pot(){
  pinMode(roll_pot_pin,INPUT);
  pinMode(pitch_pot_pin,INPUT);
}

