#include <LiquidCrystal_I2C.h>

// feedback variables
float reference = 0; // desired rpms
float error;
float sample_current;
float sample_previous;
int dt;

// controller gains
float P = 1;
float I = 0;
float D = 0;

// plant paremeters
float TORQUE_CONSTANT;

// pin assignments
const int EN_A = 9;
const int IN_1 = 6;
const int IN_2 = 7;
const int BUTTON = 10;
const int HALL_EFFECT = 13;
const int POT = A0;

// board variables
bool pressed = false;

// create LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();

  // attach pins
  pinMode(EN_A, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(HALL_EFFECT, INPUT);

  // set initial state
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);

  delay(1000);
}

void loop() {
  //Read button input
  if (digitalRead(BUTTON)) {
    pressed = !pressed;
  }
  // Debounce button
  while (digitalRead(BUTTON)) {
    delay(20);
  }

  if (pressed == true) {
    int potInput = analogRead(POT);
    
    int speed = map(potInput, 0, 1023, 0, 255);
    
    // set the reference
    reference;

    // // calculate the error
    // error = reference - sample_current;

    // // input error to controller
    // float P_control = P * error;
    // float I_control = I * (sample_previous - sample_current) * dt;
    // float D_control = D * (sample_previous - sample_current) / dt;

    // // controller output
    // float controller_out = P_control + I_control + D_control; // torque value

    // // TODO: add disturbances to controller output
    // float plant_in = controller_out; // torque value

    // // input combined controller output/disturbance into plant
    // float motor_current = plant_in / TORQUE_CONSTANT;

    // // TODO: apply current to motor
    analogWrite(EN_A, speed);
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);

    // // sample plant performance
    // sample_previous = sample_current; // store the previous angular velocity value
    // sample_current; // read flywheel angular velocity

    // Write info to LCD
    lcd.setCursor(0,0);
    lcd.print("Ref: " + reference)
    lcd setCursor(0,2);
    lcd.print("Speed: " + sample_current)

  } else {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
  }
}
