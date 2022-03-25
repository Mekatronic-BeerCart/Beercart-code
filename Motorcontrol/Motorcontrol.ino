int analogPin = 3;
int val = 0; 
int outPutMotor = 9; 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(analogPin);
Serial.println(val); 
}
