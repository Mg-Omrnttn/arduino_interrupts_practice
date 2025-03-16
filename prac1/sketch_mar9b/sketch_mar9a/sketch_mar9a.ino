// In this code, interrupts in INT0 and INT1 only
// but other pins can be used for interrupts as well. I will do it later.
// setting after philips account

const int ledPin = 13;  // LED connected to pin 13

volatile bool ledState = false;  // Variable to store LED state

void setup() {
    pinMode(ledPin, OUTPUT);  // Set LED pin as output
    pinMode(2, INPUT_PULLUP); // INT0 button (Pin 2)
    pinMode(3, INPUT_PULLUP); // INT1 button (Pin 3)
    
    Serial.begin(9600); // Initialize serial communication
    
    // Attach interrupts
    attachInterrupt(digitalPinToInterrupt(2), toggleLED, FALLING);  // INT0 (Pin 2)
    attachInterrupt(digitalPinToInterrupt(3), printMessage, FALLING); // INT1 (Pin 3)
}

void loop() {
    // Nothing needed in loop, handled by interrupts
}

// ISR for INT0 - Toggle LED
void toggleLED() {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
}

// ISR for INT1 - Print message
void printMessage() {
    Serial.println("Button 2 Pressed!");
}
