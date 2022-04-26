int BP = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A5, OUTPUT);
int BP = 0;
}

void loop() {
 analogWrite(A5,255);

BP = analogRead(A0);
if(BP >1){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
}
}
