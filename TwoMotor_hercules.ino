void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(4,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
//digitalWrite(11,HIGH);
//digitalWrite(12,LOW);
analogWrite(5,200);
//analogWrite(10,0);
}
