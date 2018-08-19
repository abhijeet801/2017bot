int forward, rotation, translate = 0;
int max_spd = 0;
bool fast_mode = false;
int init_RX;
float alpha = 0.92;

void drive() {
  int RX = ps2x.Analog(PSS_RX);
  if (ps2x.ButtonPressed(PSB_L3) && (RX == 0 || RX == 255)) {
    fast_mode = true;
    init_RX = RX;
  }

  else if (ps2x.ButtonPressed(PSB_L3)) {
    fast_mode = false;
    max_spd = 0;
  }

  if (ps2x.ButtonPressed(PSB_PAD_UP))
    max_spd += 8;

  if (ps2x.ButtonPressed(PSB_PAD_DOWN))
    max_spd -= 8;

  max_spd = constrain(max_spd, 0, 64);

  if (!fast_mode) {
    forward = map(RX, 0, 255, max_spd, -max_spd);
    rotation = map(ps2x.Analog(PSS_LX), 0, 255, ((forward == 0) ? max_spd : forward), (-forward == 0) ? -max_spd : -forward);

    if (forward < 0) rotation *= -1;
  }
  else {
    forward = constrain((init_RX ? 1 : -1) * map(RX, init_RX, 255 - init_RX, 0, 64), -63, 63) * (1 - alpha) + forward * alpha;
    rotation = map(ps2x.Analog(PSS_LX), 0, 255, 12, -12);
  }

  if (ps2x.Analog(PSS_RY) > 128 && max_spd != 0) {
    digitalWrite(dirA, HIGH);
    digitalWrite(dirB, LOW);
    analogWrite(pwm, 26);
    translate = 4;
  }
  else if (ps2x.Analog(PSS_RY) < 128 && max_spd != 0) {
    digitalWrite(dirA, LOW);
    digitalWrite(dirB, HIGH);
    analogWrite(pwm, 20);
    translate = -4;
  }
  else {
    digitalWrite(dirA, LOW);
    digitalWrite(dirB, LOW);
    analogWrite(pwm, 0);
    translate = 0;
  }

  int left = constrain(192 + forward + rotation - translate, 129, 254);
  int right = constrain(64 + forward - rotation + translate, 1, 127);

  SABER_SERIAL.write(left);
  delay(1);
  SABER_SERIAL.write(right);
  delay(1);
}
