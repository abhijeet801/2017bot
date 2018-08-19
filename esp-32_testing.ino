int pin1=16;
int pin2=5;
int pin3=4;
int pin4=0;
int pin5=2;
int pin6=14;
int pin7=12;
int pin8=13;
int pin9=15;
void setup()
{
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    pinMode(pin5, OUTPUT);
    pinMode(pin6, OUTPUT);
    pinMode(pin7, OUTPUT);
    pinMode(pin8, OUTPUT);
    pinMode(pin9, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
//    Serial.println("Hello, world!");
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin5, HIGH);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin7, HIGH);
    digitalWrite(pin8, HIGH);
    digitalWrite(pin9, HIGH);
    delay(1000); 
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
    digitalWrite(pin9, LOW);
    delay(1000);
}

