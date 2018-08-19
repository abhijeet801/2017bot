int z=60;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
    delay(1);
  Serial1.begin(9600);
    delay(1);
  Serial3.begin(9600);
  delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial1.write(60);
delay(1);
  Serial1.write(195);
  delay(1);
//  Serial3.write(195);
//  delay(1);
}

