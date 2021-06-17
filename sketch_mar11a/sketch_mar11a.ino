#define INFRAPIN 8
#define LAMPPIN 9


void setup() 
{
  pinMode(INFRAPIN, INPUT);
  pinMode(LAMPPIN, OUTPUT);
}

void loop() 
{
  digitalWrite(LAMPPIN, !digitalRead(8));
}
