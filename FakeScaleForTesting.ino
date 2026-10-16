/*
 * Fake Weight Scale Simulator
 * WARNING: This project is strictly for educational purposes only.
 * Credit / GitHub: NarayanGz
 */

// Define the 3 physical button pins
const int button1Pin = 2; // Low weights
const int button2Pin = 3; // Mid weights
const int button3Pin = 4; // High weights

// The exact weights that will be sent to your Android App
String weights1[] = {"+001.000 Kg", "+005.000 Kg", "+008.000 Kg", "+014.000 Kg"}; 
String weights2[] = {"+010.000 Kg", "+012.000 Kg", "+015.000 Kg", "+020.000 Kg"}; 
String weights3[] = {"+025.000 Kg", "+030.000 Kg", "+035.000 Kg", "+040.000 Kg"}; 

// Track where we are in each list
int index1 = 0;
int index2 = 0;
int index3 = 0;

// Variables to detect a fresh "click" (HIGH means unpressed)
int lastState1 = HIGH; 
int lastState2 = HIGH;
int lastState3 = HIGH;

// Lightning-fast 50ms cooldown for rapid clicking
unsigned long lastTapTime = 0;
const unsigned long tapCooldown = 50; 

// Start the scale at 0 kg
String currentWeight = "+000.000 Kg";

unsigned long lastPrintTime = 0;
const long printInterval = 160; // 160ms matches the speed of a real scale

void setup() {
  // Start the USB connection to your Android phone
  Serial.begin(9600);
  
  // Turn on the Arduino's internal power for the buttons
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
}

void loop() {
  // Read the physical buttons (LOW means it is being pressed down)
  bool press1 = (digitalRead(button1Pin) == LOW);
  bool press2 = (digitalRead(button2Pin) == LOW);
  bool press3 = (digitalRead(button3Pin) == LOW);

  // --- BUTTON 1 LOGIC (Low Weights) ---
  if (press1 == true && lastState1 == HIGH && (millis() - lastTapTime > tapCooldown)) {
    currentWeight = weights1[index1]; 
    index1++; 
    if (index1 >= 4) index1 = 0; 
    
    // Reset the other buttons so they start fresh next time
    index2 = 0; 
    index3 = 0; 
    
    lastTapTime = millis(); 
  }
  
  // --- BUTTON 2 LOGIC (Mid Weights) ---
  if (press2 == true && lastState2 == HIGH && (millis() - lastTapTime > tapCooldown)) {
    currentWeight = weights2[index2];
    index2++;
    if (index2 >= 4) index2 = 0; 
    
    index1 = 0; 
    index3 = 0; 
    
    lastTapTime = millis(); 
  }

  // --- BUTTON 3 LOGIC (High Weights) ---
  if (press3 == true && lastState3 == HIGH && (millis() - lastTapTime > tapCooldown)) {
    currentWeight = weights3[index3];
    index3++;
    if (index3 >= 4) index3 = 0; 
    
    index1 = 0; 
    index2 = 0; 
    
    lastTapTime = millis(); 
  }

  // Save the states for the next loop
  lastState1 = press1 ? LOW : HIGH;
  lastState2 = press2 ? LOW : HIGH;
  lastState3 = press3 ? LOW : HIGH;

  // --- CONTINUOUSLY SEND DATA TO YOUR ANDROID APP ---
  if (millis() - lastPrintTime >= printInterval) {
    lastPrintTime = millis();
    Serial.println(currentWeight);
  }
}