// feedback variables
float reference;
float error;
float sample_current;
float sample_previous;
int dt;

// controller gains
float P;
float I;
float D;

// plant paremeters
float TORQUE_CONSTANT;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // set the reference
  reference;

  // calculate the error
  error = reference - sample_current;

  // input error to controller
  float P_control = P * error;
  float I_control = I * (sample_previous - sample_current) * dt;
  float D_control = D * (sample_previous - sample_current) / dt;

  // controller output
  float controller_out = P_control + I_control + D_control; // torque value

  // TODO: add disturbances to controller output
  float plant_in = controller_out; // torque value

  // input combined controller output/disturbance into plant
  float motor_current = plant_in / TORQUE_CONSTANT;

  // TODO: apply current to motor

  // sample plant performance
  sample_previous = sample_current; // store the previous angular velocity value
  sample_current; // read flywheel angular velocity
}
