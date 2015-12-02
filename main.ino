#include <Stepper.h>
#include <TTS.h>
#include <LiquidCrystal.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

int dcMotor = 1;
int button = 0;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Stepper myStepper(stepsPerRevolution, 9, 12, 8, 11);
TTS text2speech;
char text[50];

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
  pinMode(dcMotor, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  //=============================
  // lcd
  lcd.clear();
  lcd.print("Press the button");
  lcd.setCursor(0, 1);
  lcd.print("----------------");

  //==============================
  // button
  while (digitalRead(button))
    delay(20);

  //============================
  // dc motor
  digitalWrite(dcMotor, HIGH);
  delay(1000);
  digitalWrite(dcMotor, LOW);

  //============================
  // lcd
  lcd.clear();
  lcd.print("Withdraw");
  lcd.setCursor(0, 1);
  lcd.print("your card");

  //============================
  // speech
  text2speech.setPitch(2); //higher values = lower voice pitch
  strcpy(text, "Hello master, take it");
  text2speech.say(text);
  delay(500);
    
  //=========================
  // stepper motor
  int motorSpeed = 50;
  // set the motor speed:
  myStepper.setSpeed(motorSpeed);
    // step 1/4 of a revolution (90ยบ):
  myStepper.step(stepsPerRevolution / 4);

  //==========================
  // light sensor
  while (analogRead(0) > 700)
    delay(20);

  while(analogRead(0) < 700)
    delay(20);

  delay(2000);
  
  myStepper.setSpeed(motorSpeed);
  myStepper.step(-stepsPerRevolution / 4);
}
