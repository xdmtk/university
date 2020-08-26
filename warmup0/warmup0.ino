






/* Some macros for labeling pin numbers */
#define LED_PIN 2
#define BUTTON_PIN 4


/* A Few global states  */
char ledState;
char hzSelect;
char hzRates[] = {0x1, 0x2, 0x4, 0x8};


/* Initial function call */
void setup() {

    /* Set the pin mode for the LED pin to OUTPUT for digital writes (source) */
    pinMode(LED_PIN, OUTPUT);
    
    /* Set the pin mode for the button pin to INPUT for digital reads (sink) */
    pinMode(BUTTON_PIN, INPUT);

    /* Zero out the initial HZ and LED pin states */
    hzSelect = ledState = 0;
}


/* Main loop - Repeatedly executes this section after returning from setup() */
void loop() { 
    
    /* Oscillate the ledState between 0 and 1 to 'blink' the LED */
    digitalWrite(LED_PIN, (ledState = !ledState));

    /* Call delayAndCheck() wait on button input for the duration of the current 
    HZ selected in the global state hzSelect. If the button was pressed, it cycles
    the next available HZ value in hzRates[]. If the current selection exceeds the 
    HZ choice capacity, it wraps around to the first HZ selection */
    hzSelect = ((hzSelect += delayAndCheck()) == 4 ? 0 : hzSelect);
}


/** 
 * This function delays the 'blink' of the LED for the duration of the currently selected HZ
 * value in hzRates[]. It does this by dividing 1 into the HZ value, and multiplying this value by
 * 1000, providing an upper limit for the amount of 1ms 'ticks' this function should execute before
 * returning and oscillating the LED output state 
 */
int delayAndCheck() {
    
    /* Get the maximum 1ms ticks by the math described above */
    unsigned int delayLimit = (int)(((float)(1.0/hzRates[hzSelect]))*1000);

    /* Initialize a tick counter */
    unsigned int delayTimer = 0;

    /* Allocate a buffer for the result of the digitalRead() call */
    int readResult;
   
    /* Delay a 1ms tick if: 
        - The button was not pressed 
        - The tick limit has not been reach
       This allows us to frequently poll the push button state for potential activation 
    */
    while (((readResult = digitalRead(BUTTON_PIN)) == LOW) 
        && (++delayTimer) < delayLimit) {
        
        /* Delay a 1ms tick */
        delay(1);
    }

    /* In the event of a button press, since these reads happen very quickly, we need 
    to wait on return until the user has their finger off the button. If the button wasn't 
    pressed this function will return immediately */
    while (digitalRead(BUTTON_PIN) == HIGH) {}

    /* Return whether the button was pressed or not, indicating to loop() that the hzRates[] 
    array should be cycled to the next value */
    return readResult;
}
