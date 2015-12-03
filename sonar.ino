// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------
// modificado para usar como DAC

#include <NewPing.h>
// para nano
#define TRIGGER_PIN  14  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     15  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

////para UNO plug and play
//#define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
//#define ECHO_PIN     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int medida_past =10 ;

void setup() {
//  pinMode(11,OUTPUT);
//  pinMode(8,OUTPUT);
//
//  digitalWrite(8,HIGH);
//  digitalWrite(11,LOW);

//para UNO
//    pinMode(11,OUTPUT);
//pinMode(8,OUTPUT);
//
//digitalWrite(8,HIGH);
//  digitalWrite(11,LOW);

  
   for (int i=0;i<8;i++){
    pinMode(i,OUTPUT);}
//  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
}

void loop() {
  //delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
  
  delay(100);//10 ping por segundo
// Serial.print("Ping: ");
int medida_actual = sonar.ping_cm();
  
int medida_filtro = ((0.8)*medida_past) + ((0.2)*medida_actual);
  
 // Serial.println(int(medida_filtro)); // Send ping, get distance in cm and print result (0 = outside set distance range)
// Serial.print("cm");
  PORTD = medida_filtro*5;
  medida_past=  medida_actual;
  
}
