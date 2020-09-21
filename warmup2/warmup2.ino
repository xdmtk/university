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


#define STOPPED_LED  5
#define SLOWEST_LED 6
#define SLOW_LED 7
#define FAST_LED 8
#define FASTEST_LED 9
#define INPUT_ONE 3
#define INPUT_TWO 4

enum State {
    Stopped = 0x1,
    RunningSlowest = 0x2, 
    RunningSlow = 0x4,
    RunningFast = 0x8
    RunningFastest = 0x10
} state;

State lastVelocity;
int ret;

void setup() {
    state = lastVelocity = State::Stopped;
}

void loop() {

    setLedState(); 
    switch (state) {
        case State::Stopped:
        break;
        case State::RunningSlowest:
        break;
        case State::RunningSlow:
        break;
        case State::RunningFast:
        break;
        case State::RunningFastest:
        break;
    }
}

void stopped() {
    while (!(ret = getInput())) {
    }
}
void runningSlowest() {
    while (!(ret = getInput())) {
    }
}
void runningSlow() {
    while (!(ret = getInput())) {
    }
}
void runningFast() {
    while (!(ret = getInput())) {
    }
}
void runningFastest() {
    while (!(ret = getInput())) {
    }
}

char getInput() {
    if (digitalRead(INPUT_ONE)) return 0x1;
    else if (digitalRead(INPUT_ONE)) return 0x2;
    else return 0x0;
}

void setLedState() {
    for (char i = STOPPED_LED, j = 0; i <= FASTEST_LED; ++i, ++j)
        digitalWrite(i, (state >> j) & 0x1);
}
