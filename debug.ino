void debug_bane() {
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW);

  analogWrite(pwm, 25);

  delay(2000);

  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH);

  analogWrite(pwm, 25);

  delay(2000);
}

void debug_translate() {
  if (ps2x.Analog(PSS_RY) > 128) {
    digitalWrite(dirA, HIGH);
    digitalWrite(dirB, LOW);
    analogWrite(pwm, 100);
    Serial3.write(200);
    Serial3.write(56);
  }
  else if (ps2x.Analog(PSS_RY) < 128) {
    digitalWrite(dirA, LOW);
    digitalWrite(dirB, HIGH);
    analogWrite(pwm, 99);
    Serial3.write(186);
    Serial3.write(70);
  }
  else {
    digitalWrite(dirA, LOW);
    digitalWrite(dirB, LOW);
    Serial3.write(64);
    Serial3.write(192);
  }
}

void translate_finder() {

  int bane_spd = map(ps2x.Analog(PSS_RY), 128, 0, 0, 50);
  int maxon_spd = map(ps2x.Analog(PSS_LY), 128, 0, 0, 8);
  if (bane_spd < 0) {
    digitalWrite(dirA, HIGH);
    digitalWrite(dirB, LOW);
  }
  else {
    digitalWrite(dirA, LOW);
    digitalWrite(dirB, HIGH);
  }

  analogWrite(pwm, abs(bane_spd));
  Serial3.write(192 + maxon_spd);
  Serial3.write(64 - maxon_spd);
  //  debug_bane();

  if (ps2x.ButtonPressed(PSB_R2)) {
    Serial.print(bane_spd); Serial.print(' '); Serial.print(192 + maxon_spd); Serial.print(' '); Serial.print(64 - maxon_spd); Serial.println(' ');
  }
}

//void debug_ps2(){
//  Serial.print(ps2x.Button(PSB_PAD_BLUE));Serial.print(' ');
//}
void debug_RP() {
  while (Serial.available()) {
    int pos = Serial.parseInt();

    if (pos > 0) {
      digitalWrite(pitch_dirA, HIGH); //up
      digitalWrite(pitch_dirB, LOW);
    }
    else {
      digitalWrite(pitch_dirA, LOW); //down
      digitalWrite(pitch_dirB, HIGH);
    }

    Serial.println(pos);
    analogWrite(pitch_pwm, abs(pos));

    delay(100);

    digitalWrite(pitch_dirA, HIGH);
    digitalWrite(pitch_dirB, HIGH);

    analogWrite(pitch_pwm, 0);
  }
}
