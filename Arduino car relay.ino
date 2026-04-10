/* * PROFESSIONAL RC CAR RELAY CONTROLLER 
 * Architecture: Object-Oriented Programming (OOP) 
 * Features: Hardware Short-Circuit Protection, Bluetooth Watchdog Fail-Safe 
 */

// --- CONFIGURATION ---
// Change to LOW if your relay modules turn ON with a LOW signal (Active-Low)
const int RELAY_ON = HIGH;  
const int RELAY_OFF = LOW;

const unsigned long TIMEOUT_MS = 500; // Stop motors if no command received for 500ms
unsigned long lastCommandTime = 0;    // Tracks the last Bluetooth heartbeat

// ==========================================
// 1. MOTOR CLASS (Blueprint for Wheels)
// ==========================================
class Motor {  
  private:    
    int pinFwd;    
    int pinRev;

  public:    
    // Constructor maps the pins when the object is created    
    Motor(int fwdPin, int revPin) {      
      pinFwd = fwdPin;      
      pinRev = revPin;    
    }

    // Initializes pins and ensures they start OFF    
    void begin() {      
      pinMode(pinFwd, OUTPUT);      
      pinMode(pinRev, OUTPUT);      
      stop();    
    }

    void forward() {      
      digitalWrite(pinRev, RELAY_OFF); // SAFETY FIRST: Turn off reverse      
      digitalWrite(pinFwd, RELAY_ON);  // Then turn on forward    
    }

    void reverse() {      
      digitalWrite(pinFwd, RELAY_OFF); // SAFETY FIRST: Turn off forward      
      digitalWrite(pinRev, RELAY_ON);  // Then turn on reverse    
    }

    void stop() {      
      digitalWrite(pinFwd, RELAY_OFF);      
      digitalWrite(pinRev, RELAY_OFF);    
    }
};

// ==========================================
// 2. ACCESSORY CLASS (Blueprint for Lights/Horn)
// ==========================================
class Accessory {  
  private:    
    int pin;

  public:    
    Accessory(int accPin) {      
      pin = accPin;    
    }

    void begin() {      
      pinMode(pin, OUTPUT);      
      turnOff();    
    }

    void turnOn() {      
      digitalWrite(pin, RELAY_ON);    
    }

    void turnOff() {      
      digitalWrite(pin, RELAY_OFF);    
    }
};

// ==========================================
// 3. CREATE HARDWARE OBJECTS (Pin Mapping)
// ==========================================
// 4 Motors (Forward Pin, Reverse Pin)
Motor motorFL(2, 3); // Front Left
Motor motorFR(4, 5); // Front Right
Motor motorRL(6, 7); // Rear Left
Motor motorRR(8, 9); // Rear Right

// 4 Accessories (Single Relays)
Accessory acc1(10); // e.g., Headlights
Accessory acc2(11); // e.g., Tail lights
Accessory acc3(12); // e.g., Horn
Accessory acc4(13); // e.g., Extra

// ==========================================
// 4. MAIN SETUP
// ==========================================
void setup() {  
  Serial.begin(9600); // Start Bluetooth Communication

  // Initialize all motors  
  motorFL.begin();  
  motorFR.begin();  
  motorRL.begin();  
  motorRR.begin();

  // Initialize all accessories  
  acc1.begin();  
  acc2.begin();  
  acc3.begin();  
  acc4.begin();
}

// ==========================================
// 5. MAIN LOOP
// ==========================================
void loop() {    
  // --- A. READ BLUETOOTH COMMANDS ---  
  if (Serial.available() > 0) {    
    char cmd = Serial.read();        
    
    // Reset the Watchdog Timer every time a command is received    
    lastCommandTime = millis(); 

    switch (cmd) {      
      // --- CAR MOVEMENT ---      
      case 'F': // Drive Forward        
        motorFL.forward(); motorFR.forward();        
        motorRL.forward(); motorRR.forward();        
        break;

      case 'B': // Drive Backward        
        motorFL.reverse(); motorFR.reverse();        
        motorRL.reverse(); motorRR.reverse();        
        break;

      case 'L': // Turn Left (Left wheels reverse, Right wheels forward)        
        motorFL.reverse(); motorFR.forward();        
        motorRL.reverse(); motorRR.forward();        
        break;

      case 'R': // Turn Right (Left wheels forward, Right wheels reverse)        
        motorFL.forward(); motorFR.reverse();        
        motorRL.forward(); motorRR.reverse();        
        break;

      case 'S': // Stop Motors        
        stopAllMotors();        
        break;

      // --- ACCESSORIES (ON / OFF) ---      
      case 'I': acc1.turnOn(); break;      
      case 'i': acc1.turnOff(); break;            
      
      case 'J': acc2.turnOn(); break;      
      case 'j': acc2.turnOff(); break;            
      
      case 'K': acc3.turnOn(); break;      
      case 'k': acc3.turnOff(); break;            
      
      case 'M': acc4.turnOn(); break; // Used 'M' to avoid conflict with 'L' (Left Turn)      
      case 'm': acc4.turnOff(); break;    
    }  
  }

  // --- B. WATCHDOG TIMER (FAIL-SAFE) ---  
  // If the car goes out of Bluetooth range or the app crashes,   
  // stop the motors after 500 milliseconds to prevent a runaway vehicle.  
  // Note: This only stops motors; headlights/accessories stay on!  
  if (millis() - lastCommandTime > TIMEOUT_MS) {    
    stopAllMotors();  
  }
}

// Helper function to stop all motors cleanly
void stopAllMotors() {  
  motorFL.stop();  
  motorFR.stop();  
  motorRL.stop();  
  motorRR.stop();
}
