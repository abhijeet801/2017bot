int state = 0;
void setup() {
  // put your setup code here, to run once:
 // pinMode(6, INPUT);
  //pinMode(13, OUTPUT);
  Serial.begin(9600);
   attachInterrupt(0, zero_crosss_int, RISING);//pin 2 on uno
  
}
void zero_crosss_int() 
{
  Serial.println("1");
}
void loop() {
  // put your main code here, to run repeatedly:
  //state = digitalRead(6);
 // Serial.println(state);
  //if(state==1)
  //digitalWrite(13,HIGH);
}
