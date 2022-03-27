int MotorQ1 = 11; //er motor winding "A" //gates som skal åbnes for. AKA mosfets. 
int MotorQ2 =10; // motor winding "B"
int MotorQ3 = 9;// motor Winding "C"

int MotorQ4 = 3; //motor winding "A"
int MotorQ5 = 5;// motor winding "B"
int MotorQ6 = 6; // motor winding "C"
/*
#define hall1 2 //definere hall sensornes pin out på arduinoen. 
#define hall2 4 
#define hall3 7 
*/ // er kommenteret ud indtil vi skal bruge det sammen med motoren. 
/*
bool hallValue1;
bool hallValue2;
bool hallValue3;
*/
int DuCy = 0; 
int analogPin = 3;



void Step1 (){//positiv A, negativ B
  digitalWrite(MotorQ1,HIGH);
  digitalWrite(MotorQ5,HIGH); 
  delayMicroseconds(DuCy);
  digitalWrite(MotorQ1, LOW);
  digitalWrite(MotorQ5, LOW);
}
void Step2 (){//positiv A, negativ C
  digitalWrite(MotorQ1,HIGH);
  digitalWrite(MotorQ6,HIGH); 
  delayMicroseconds(DuCy);
  digitalWrite(MotorQ1, LOW);
  digitalWrite(MotorQ6, LOW);
}
void Step3 (){//positiv B, negativ C
  digitalWrite(MotorQ2,HIGH);
  digitalWrite(MotorQ6,HIGH); 
  delayMicroseconds(DuCy);
  digitalWrite(MotorQ2, LOW);
  digitalWrite(MotorQ6, LOW);
}
void Step4 (){//positiv B, negativ A
  digitalWrite(MotorQ2,HIGH);
  digitalWrite(MotorQ4,HIGH); 
  delayMicroseconds(DuCy);
  digitalWrite(MotorQ2, LOW);
  digitalWrite(MotorQ4, LOW);
}
void Step5 (){//positiv B, negativ A
  digitalWrite(MotorQ3,HIGH);
  digitalWrite(MotorQ4,HIGH); 
  delayMicroseconds(DuCy);
  digitalWrite(MotorQ3, LOW);
  digitalWrite(MotorQ4, LOW);
}
void Step6 (){//positiv B, negativ A
  digitalWrite(MotorQ3,HIGH);
  digitalWrite(MotorQ5,HIGH); 
  delayMicroseconds(DuCy);
  digitalWrite(MotorQ3, LOW);
  digitalWrite(MotorQ5, LOW);
}





void setup() {
  // put your setup code here, to run once:

}

void loop() {
/*
hallValue1 = digitalRead(hall1);//læser direkte fra vores hall sensor hvor motoren er i dens cyclus. 
hallValue2 = digitalRead(hall2);
hallValue3 = digitalRead(hall3);
if(hallValue1 == 1) && (hallValue2 == 0) && (hallValue3 == 1){ // hvis den er i denne cyclus skal den køre step1. Hvis den ikke er i denne
//cyclus så vil den bare springe dette over. Når den er så er done med det den skal gøre i step1, så vil den læse vores hallsensors igen. 
step1();
}
*/




 
DuCy = analogRead(analogPin);
if(DuCy > 0){
  Step1();
  Step2();
  Step3();
  Step4();
  Step5();
  Step6();
}
  
}
