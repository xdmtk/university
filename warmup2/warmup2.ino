/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!							
#								
!	Name:       Nicholas Martinez	
#	Class:		COMP 522 - Section 21648
!	Instructor:	Adam Kaplan
#	Date:		9/21/2020
!									    
#	        Warmup 2
!									     
#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!*/


/* Pin definitions */
#define STOPPED_LED  5
#define SLOWEST_LED 6
#define SLOW_LED 7
#define FAST_LED 8
#define FASTEST_LED 9
#define INPUT_ONE 3
#define INPUT_TWO 4


/* State enums - 5 total states, stopped + velocities */
enum State {
    Stopped = 0x1,
    RunningSlowest = 0x2, 
    RunningSlow = 0x4,
    RunningFast = 0x8,
    RunningFastest = 0x10
} state;

/* Velocity mapping mirroring enum values */
char velocities[] = {0x2, 0x4, 0x8, 0x10};

/* Current velocity and input response placeholders */
char currVelocity;
int ret;


/* Set initial states and pin modes */
void setup() {
    state = State::Stopped;
    currVelocity = 0;
    Serial.begin(9600);
    
    /* Hit the output pins */
    for (char i = STOPPED_LED; i <= FASTEST_LED; ++i)
        pinMode(i, OUTPUT);
    /* Hit the input pins */
    for (char i = INPUT_ONE; i <= INPUT_TWO; ++i)
        pinMode(i, INPUT);
}

/* Loop function with the switch, targeting the switch enum value
and triggering a function to respond to each respective state */
void loop() {
    
    /* The portion of code that is executed only once when a new state is entered.
    This sets a series of 5 LED's I have set up for easily identifying the current 
    state - Each of the state functions busy wait until they receive input that transitions
    them out of that state */
    setLedState();

    /* The switch against the state enum, updated globally from each state function */
    switch (state) {
        case State::Stopped:
            Serial.println("Stopped");
            stopped(); break;
        case State::RunningSlowest:
            Serial.println("Slowest");
            runningSlowest(); break;
        case State::RunningSlow:
            Serial.println("Slow");
            runningSlow(); break;
        case State::RunningFast:
            Serial.println("Fast");
            runningFast(); break;
        case State::RunningFastest:
            Serial.println("Fastest");
            runningFastest(); break;
    }
}


/* Function reacting to input when the current state is Stopped */
void stopped() {

    /* Wait for user input */
    stall();
    
    /* `if there is a currVelocity set, the motor rotates at this velocity` */
    if (ret == 0x1 && currVelocity) 
        state = (State) currVelocity;

    /* `if currVelocity has not been set, the motor rotates at an initial slow 
    velocity (chosen by you)` */
    else if (ret == 0x1) 
        currVelocity = (state = State::RunningSlowest);

    /* `if the motor is stopped, and the user activates INPUT2, the currVelocity 
    is cleared (reset to 0)` */
    else if (ret == 0x2)
        currVelocity ^= currVelocity;
}


/* Main response for all non-stopped states (behavior is similar for all speeds) */
void runningSlowest() {

    /* Wait for user input */
    stall();

    /* `if the motor is running, when the user pushes the push-button INPUT1, the motor 
    speeds up again (to 2nd velocity, and beyond). Once the motor reaches the maximum velocity, 
    additional pushes of INPUT1 have no effect.` */
    if (ret == 0x1) 
        state = currVelocity = (( state != State::RunningFastest 
        ? ((State) (state << 1)) : state));

    /* `if the motor is running, and the user activates another piece of input hardware 
    (*YOUR CHOICE*...but I will call it INPUT2) the motor stops, but remembers its current velocity 
    in variable currVelocity` */
    else if (ret == 0x2) 
        stopAndRemember();
}

/* Function to collect user input from push buttons */
char getInput() {

    char r = 0x0;
    
    /* Set `r` for push button 1 */
    if (digitalRead(INPUT_ONE))  r = 0x1;
    
    /* Set `r` for push button 2 */
    else if (digitalRead(INPUT_TWO)) r = 0x2;

    /* If either push button was pressed, wait for it to clear (finger off the button)
    so we don't trigger multiple state changes in a single press */
    if (r) while (digitalRead(INPUT_ONE) || digitalRead(INPUT_TWO)) {};

    if (r) Serial.println(r == 0x1 ? "Got button 1" : "Got button 2");
    /* Return the pushbutton selection */
    return r;
}


/* Iterates the LED state pins and illuminates the LED representing the 
current state */
void setLedState() {

    /* Iterate the LEDs */
    for (char i = STOPPED_LED, j = 0; i <= FASTEST_LED; ++i, ++j) {

        /* Since the enums are mapped to certain bits of the button, shift left 
        against the current iteration and bitwise AND by 0x1 to write the correct
        value to the LED */
        digitalWrite(i, (state >> j) & 0x1);
        Serial.println("Pin #" + String((int)i) + ": " + String((state >> j) & 0x1));
    }
}

/* Just a helpful wrapper for clarity */
inline void stopAndRemember() {
    state = State::Stopped;

    /* Doesn't actually need to explicitly remember here because currVelocity is saved
    each time the state is updated */
} 

/* This helper busy waits for push button input */
inline void stall() { 
    while (!(ret = getInput())) {

        /* If the motor required synchronous action to get it to spin (instead of simply turning it on
        or setting it at a different voltage) I would perform that action here, in this busy wait section
        since it is most frequently executed throughout the program - But since I don't have a stepper motor, 
        and the LED state indicators have already updated, this section is blank */
    }; 
}

/* These inline helpers are essentially clarity aliases for what is really identical state
behavior when the motor is running. */
inline void runningSlow() { runningSlowest(); }
inline void runningFast() { runningSlowest(); }
inline void runningFastest() { runningSlowest(); }
