#define LS_PIN A2        // Pin for light sensor
#define LED1_PIN A1      // Pin for LED
#define BUZZER_PIN 5    // Pin for Buzzer
#define POWER   4        // Power pin (unused in current code)
#define TIME     150     // Delay time (unused in current code)

void setup() {
  pinMode(LS_PIN, INPUT);        // Set light sensor pin as input
  pinMode(LED1_PIN, OUTPUT);     // Set LED pin as output
  pinMode(BUZZER_PIN, OUTPUT);   // Set buzzer pin as output
  Serial.begin(9600);            // Start Serial communication for debugging
}

void loop() {
  // Read the light sensor value (0-1023)
  int sensorReading = analogRead(LS_PIN); 

  // Optional: Print the raw sensor reading for debugging
  Serial.print("Raw Sensor Reading: ");
  Serial.println(sensorReading);

  // Map the sensor reading (2 to 16) to the LED brightness range (0 to 255)
  // To increase sensitivity, we map the small range (2-16) to a wider range for LED
  int brightness = map(sensorReading, 2, 16, 0, 255);

  // Ensure the brightness stays within the valid LED range (0-255)
  brightness = constrain(brightness, 0, 255);

  // Fade LED brightness: gradually adjust brightness
  for (int i = brightness; i >= 0; i--) {
    analogWrite(LED1_PIN, i);
    delay(1);  // Adjust the delay for slower or faster fading
  }

  // Check if brightness exceeds 70% of the max value (70% of 255 = 178.5)
  if (brightness < 178) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on the buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn off the buzzer
  }

  // Output the brightness value for debugging
  Serial.print("LED Brightness: ");
  Serial.println(brightness);

  // Delay to avoid flooding the Serial Monitor
  delay(10);
}
