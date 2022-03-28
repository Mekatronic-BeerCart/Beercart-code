//LIGGER PÅ PORT B
int MotorQ1 = 11; //er motor winding "A" //gates som skal åbnes for. AKA mosfets.
int MotorQ2 = 10; // motor winding "B"
int MotorQ3 = 9;// motor Winding "C"


//LIGGER PÅ PORT D 
int MotorQ4 = 3; //motor winding "A" NEGATIV 
int MotorQ5 = 5;// motor winding "B" NEGATIV 
int MotorQ6 = 6; // motor winding "C" NEGATIV
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

int NI = 0;


void Step1 () { //positiv A, negativ B
  PORTB = B001000;
 PORTD = B0001000;
  delay(DuCy);
 
  
}
void Step2 () { //positiv A, negativ C
  PORTB = B001000;
 PORTD = B0100000;
  delay(DuCy);
  
}
void Step3 () { //positiv B, negativ C
  PORTB = B000100;
PORTD = B0100000;
  delay(DuCy);

}
void Step4 () { //positiv B, negativ A
 PORTB = B000010;
 PORTD = B1000000;
  delay(DuCy);
}
void Step5 () { //positiv C, negativ A
  PORTB = B000010;
 PORTD = B1000000;
  delay(DuCy);

}
void Step6 () { //positiv C, negativ B
PORTB = B000010;
 PORTD = B0001000;
  delay(DuCy);

}





void setup() {
  // put your setup code here, to run once:
  DDRB = B001110;
  DDRD = B0001110;
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





  NI = analogRead(analogPin);
  DuCy = 1024 - NI;
  if (DuCy < 1024) {
    Step1();
    NI = analogRead(analogPin);
    DuCy = 1024 - NI;
    Step2();
    NI = analogRead(analogPin);
    DuCy = 1024 - NI;
    Step3();
    NI = analogRead(analogPin);
    DuCy = 1024 - NI;
    Step4();
    NI = analogRead(analogPin);
    DuCy = 1024 - NI;
    Step5();
    NI = analogRead(analogPin);
    DuCy = 1024 - NI;
    Step6();
    NI = analogRead(analogPin);
    DuCy = 1024 - NI;
  }

}
