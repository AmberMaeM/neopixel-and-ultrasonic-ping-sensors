#include <Adafruit_NeoPixel.h>

#define N_PIXELS 84// Number of pixels you are using
#define LED_PIN     6 // NeoPixel LED strand is connected to GPIO #0 / D0
Adafruit_NeoPixel  pixels = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

#define echoPin 12 // echo is in pin 2
#define trigPin 13 //trig is in pin 3


long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);
  pixels.begin();
  pixels.show(); // Update pixels

}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);// reads the echo pin
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
 
  Serial.print("Distance: "); 
  Serial.print(distance); //puts the updated distance beside the word distance and before the cm
  Serial.println(" cm");

  for (int i = distance; i < N_PIXELS; i++) { //distance is always changing.The colour red will fill anythingless than 84(N_PIXELS)
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));//red will fill all pixels from i(i = the distance)

    pixels.show(); // update pixels
   
    
  }
    for (int i =N_PIXELS ; i >distance; i--) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));//blue will fill all pixels more than the distance

    pixels.show(); // update pixels
   
    }
}
