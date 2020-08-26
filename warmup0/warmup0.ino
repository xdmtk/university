#define LED_PIN 2
#define BUTTON_PIN 4


char ledState;
char hzSelect;
char hzRates[] = {0x1, 0x2, 0x4, 0x8};

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    hzSelect = ledState = 0;
}

void loop() { 

    digitalWrite(LED_PIN, (ledState = !ledState));
    hzSelect = ((hzSelect += delayAndCheck()) == 4 ? 0 : hzSelect);
}

int delayAndCheck() {
    
    unsigned int delayLimit = (int)(((float)(1.0/hzRates[hzSelect]))*1000);
    unsigned int delayTimer = 0;
    int readResult;
    
    while (((readResult = digitalRead(BUTTON_PIN)) == LOW) 
        && (++delayTimer) < delayLimit) {
        delay(1);
    }
    while (digitalRead(BUTTON_PIN) == HIGH) {}
    return readResult;
}
