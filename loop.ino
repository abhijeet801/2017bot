bool master = false;
int spd;
bool f = false;

void loop() {
  ps2x.read_gamepad();

  while (Serial.available()) {
    target_pitch = Serial.parseInt();

    f = true;
    
    while (target_pitch < PITCH_POS) {
      ps2x.read_gamepad();
      Serial.print("UP ");Serial.println(PITCH_POS);
      digitalWrite(pitch_dirA, LOW);  //pitch up
      digitalWrite(pitch_dirB, HIGH);
      if(ps2x.Button(PSB_SQUARE))
      spd = 140;
      else
      spd = 105;
      analogWrite(pitch_pwm, spd);
      f = false;
    }
    while (target_pitch > PITCH_POS && f == true) {
      ps2x.read_gamepad();
      Serial.print("DOWN ");Serial.println(PITCH_POS);
      digitalWrite(pitch_dirA, HIGH); //pitch down
      digitalWrite(pitch_dirB, LOW);
      if(ps2x.Button(PSB_SQUARE))
      spd = 160;
      else
      spd = 120;
      analogWrite(pitch_pwm, spd);
      if(target_pitch < PITCH_POS)
      f = false;
    }
//    Serial.println(analogRead(roll_pot_pin));
  }

  //    target_pitch = map(Serial.parseInt(), 0, 45, 481, 145);
  //    int r = ROLL_POS;

  //  while (target_pitch < PITCH_POS) {
  //    Serial.print("UP ");
  //    digitalWrite(pitch_dirA, LOW);  //pitch up
  //    digitalWrite(pitch_dirB, HIGH);
  //    //    int spd = map(abs(target_pitch - PITCH_POS), 227, 0, 240, 170);
  //    //    int spd = abs(target_pitch - PITCH_POS) > 30 ? 255 : 220;
  //    int spd = 220;
  //    analogWrite(pitch_pwm, spd);
  //    Serial.print(spd); Serial.print(' ');
  //    //      analogWrite(pitch_pwm, map(PITCH_POS, 145, 481, 190, 200));
  //  }
  //  while (target_pitch > PITCH_POS) {
  //    Serial.print("DOWN ");
  //    digitalWrite(pitch_dirA, HIGH); //pitch down
  //    digitalWrite(pitch_dirB, LOW);
  //    //    int spd = map(abs(target_pitch - PITCH_POS), 227, 0, 255, 200) > 230 ? 255 : 230;
  //    //    int spd = abs(target_pitch - PITCH_POS) > 30 ? 160 : 145;
  //    analogWrite(pitch_pwm, spd);
  //    Serial.print(spd); Serial.print(' ');
  //      analogWrite(pitch_pwm, map(PITCH_POS, 145, 481, 180, 155));
//}

/*
  Serial.println(ps2x.Button(PSB_SELECT));
  if (ps2x.Button(PSB_SELECT) && ps2x.Button(PSB_SQUARE)) {
  Serial.println("yo yo master bitches");
  master = true;
  }

  if (master) {
  if (ps2x.ButtonReleased(PSB_GREEN)) {
    Serial.println("uh");
    align_roll(35); master = false;
  }
  else if (ps2x.ButtonReleased(PSB_RED)) {
    Serial.println("uhhh");
    align_roll(20); master = false;
  }
  else if (ps2x.ButtonReleased(PSB_BLUE)) {
    Serial.println("uhhhhhhh");
    align_roll(4); master = false;
  }
  }
  else {
  Serial.println("u nu master fek off");
  }
*/


//  //  translate_finder();
//
//  buff[1] = 0b00 << 7 | ps2x.Button(PSB_R3) << 6 | ps2x.ButtonPressed(PSB_GREEN) << 5 | ps2x.ButtonPressed(PSB_RED) << 4 | ps2x.ButtonPressed(PSB_BLUE) << 3 | ps2x.ButtonPressed(PSB_PAD_RIGHT) << 2 | ps2x.ButtonPressed(PSB_PAD_LEFT) << 1 | ps2x.Button(PSB_PINK) << 0;
//
//  if (buff[1] != buff[0])
//  {
//    // Serial.println(buff[1],BIN);
//    Serial2.write(buff[1]);
//    buff[0] = buff[1];
//  }
RP();
//  drive();
Serial.print(target_pitch); Serial.print(' ');
Serial.println(PITCH_POS);
}

//700 0
//550 35

void align_roll(int target) {
  target = map(target, 0, 35, 700, 550);
  bool f = true;

  while (target < ROLL_POS) {
    digitalWrite(roll_dirA, HIGH);
    digitalWrite(roll_dirB, LOW);
    analogWrite(roll_pwm, constrain(map(abs(target - ROLL_POS), 700, 550, 60, 30), 50, 30));
    f = false;
  }
  while (target > ROLL_POS) {
    digitalWrite(roll_dirA, LOW);
    digitalWrite(roll_dirB, HIGH);
    analogWrite(roll_pwm, constrain(map(abs(target - ROLL_POS), 700, 550, 170, 140), 155, 140));
    f = false;
  }
}

//471 -- 0
//194 -- 35
