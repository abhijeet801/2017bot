#define AC_LOAD 16
int dimming = 0;

void zero_crosss_int()  // function to be fired at the zero crossing to dim the light
{
  
  int dimtime = (75*dimming);  // For 60Hz =>65
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(AC_LOAD, HIGH);   // triac firing
  delayMicroseconds(10);         // triac On propagation delay (for 60Hz use 8.33)
  digitalWrite(AC_LOAD, LOW);    // triac Off
}
void setup()
{
  pinMode(4,INPUT);
  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(digitalPinToInterrupt(4), zero_crosss_int, RISING);  // Choose the zero cross interrupt # from the table above
}
void loop()  {
  if(Serial.available()>0)
  dimming=Serial.parseInt();
  for (int i = 15; i <= 110; i++) {
    dimming = i;
    delay(10);
  }
  for (int i = 110; i >= 15; i--)
  {
    dimming = i;
    delay(10);
  }
}
