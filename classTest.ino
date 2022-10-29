//imports the library
#include <TinyStepper_28BYJ_48.h>

// These are the pins the cables should be in, but can be changed
// tow whatever
const int MOTOR_IN1_PIN = 11;
const int MOTOR_IN2_PIN = 10;
const int MOTOR_IN3_PIN = 6;
const int MOTOR_IN4_PIN = 5;


const int STEPS_PER_REVOLUTION = 2048;

//
// create the stepper motor object
//
TinyStepper_28BYJ_48 stepper;

void setup()
{
    Serial.begin(9600);

    stepper.connectToPins(MOTOR_IN1_PIN, MOTOR_IN2_PIN, MOTOR_IN3_PIN, MOTOR_IN4_PIN)
    
}

void loop()
{
    // set the speed and acceleration rates for the stepper motor
    stepper.setSpeedInStepsPerSecond(150);
    stepper.setAccelerationInStepsPerSecondPerSecond(500);
    
    // gets the amount of steps that would be 20 degrees 
    int oneDeg = 2048/360;
    int twentyDeg = oneDeg *20;

    // Initialize a position counter
    int pos = 0;

    // for i is less than 361 continue to rotate
    for(int i = 0; i<361){
        // moves to this position in steps
        // at 0 goes to step 0, at 20 goes to steps at 20 degrees,
        // at 40 goes to steps at 40 degrees and so on...
        stepper.moveToPositionInSteps(pos);

        // adds 20 degrees in steps to the previous value
        pos+=twentyDeg;
        // adds to the counter i
        i+=20;

        // 6 second delay to record the voltage at this step
        delay(6000);
    }
}