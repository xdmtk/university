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
    RunningFast = 0x8,
    RunningFastest = 0x10
} state;

char velocities[] = {0x2, 0x4, 0x8, 0x10};
char currVelocity, lastVelocity;
int ret;

void setup() {
    state = State::Stopped;
    currVelocity = lastVelocity = 0;
    
    for (char i = STOPPED_LED; i <= FASTEST_LED; ++i)
        pinMode(i, OUTPUT);
    for (char i = INPUT_ONE; i <= INPUT_TWO; ++i)
        pinMode(i, INPUT);


    Serial.begin(9600);
}

void loop() {

    setLedState(); 
    switch (state) {
        case State::Stopped:
            stopped(); break;
        case State::RunningSlowest:
            runningSlowest(); break;
        case State::RunningSlow:
            runningSlow(); break;
        case State::RunningFast:
            runningFast(); break;
        case State::RunningFastest:
            runningFastest(); break;
    }
}

void stopped() {
    Serial.println("Stopped");
    stall();

    if (ret == 0x1 && currVelocity)  {
        Serial.println("1 and with currVelocity");
        state = (State) currVelocity;
    }
    else if (ret == 0x1) {
        Serial.println("1 and without currVelocity");
        currVelocity = (state = State::RunningSlowest);
    }
    else if (ret == 0x2) {
        currVelocity ^= currVelocity;
        Serial.println("2 and cleared currVelocity");
    }
    else {
        Serial.println("xor the currvelocity");
        currVelocity ^= currVelocity;
    }
}
    
void runningSlowest() {
    Serial.println("Slowest");
    stall();
    if (ret == 0x1) 
        state = currVelocity = (( state != State::RunningFastest 
        ? ((State) (state << 1)) : state));
    else if (ret == 0x2) 
        stopAndRemember();
}

char getInput() {
    char r = 0x0;;
    if (digitalRead(INPUT_ONE)) {
        Serial.println("got input 1");
        r = 0x1;
    }
    else if (digitalRead(INPUT_TWO)) { 
        Serial.println("got input 2");
        r = 0x2;
    }
    if (r) {
        while (digitalRead(INPUT_ONE) || digitalRead(INPUT_TWO)) {};
    }
    return r;
}

void setLedState() {
    for (char i = STOPPED_LED, j = 0; i <= FASTEST_LED; ++i, ++j) {
        Serial.println(String((state >> j) & 0x1));
        digitalWrite(i, (state >> j) & 0x1);
    }
}

inline void stopAndRemember() {
    state = State::Stopped;
} 

inline void stall() { while (!(ret = getInput())); }
inline void runningSlow() {

    Serial.println("Slow");
    runningSlowest(); }
inline void runningFast() {
    Serial.println("Fast");
    runningSlowest(); }
inline void runningFastest() { 
    Serial.println("Fastest");
    runningSlowest(); }
