#define BLYNK_PRINT Serial  
#define BLYNK_TEMPLATE_ID "TMPLOwrJohUK"
#define BLYNK_DEVICE_NAME "orarkom"
#define BLYNK_AUTH_TOKEN "pj9snrAOmDG0IqIYzLYzrJgNmJqWl3aV"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const int trigPin = 12;
const int echoPin = 14;
  
//connect internet
char auth[] = "pj9snrAOmDG0IqIYzLYzrJgNmJqWl3aV"; //input koded auth blynk
char ssid[] = "UDINUS-H3";
char pass[] = "";

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Blynk.begin(auth, ssid, pass, "Blynk.Cloud");
}

void loop() {
  
   Blynk.run();
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
    
  Blynk.virtualWrite(V0, distanceCm);
  Blynk.virtualWrite(V1, distanceInch);


  delay(1000);
}