#include <Wire.h>

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);
  Serial.println("Embedded Regression tool is initiating...");
 
  pinMode(9, OUTPUT); // power button 
  pinMode(5, OUTPUT); // user button
  
}
   
// the loop function runs over and over again forever
void loop() {
 

//0. User button - delay - Nothing happen during this period -  - Device is in GPS searching OR GPS Fix State 
 Serial.println(" Device is in GPS searching OR GPS Fix State for 2 minutes ");
 delay(120000);
 
 //1. User Button - Wi-Fi functionality-ON
 //delay(10000);
 
 Serial.println(" User Button - Wi-Fi functionality-ON ");
 digitalWrite(5, HIGH);        // sets the digital pin 13 off
 delay(280);                  // waits for a second

 digitalWrite(5, LOW);       // sets the digital pin 13 on
 delay(280);
 
 digitalWrite(5, HIGH);       // sets the digital pin 13 on
 delay(280);
 
// digitalWrite(5, LOW);       // sets the digital pin 13 on
 Serial.println(" Device is in Wi-Fi mode for 2 minutes ");
 delay(120000);  // Wi-Fi functionality ON for 2 minutes
 
//2. User Button - Wi-Fi functionality-OFF

 Serial.println(" User Button - Wi-Fi functionality-OFF ");
 digitalWrite(5,HIGH);
 delay(2000); // Long press for 2 seconds
 digitalWrite(5,LOW);

//2a. To get a GPS fix, wait for 2 minutes
  Serial.println(" Device moves to GPS Searching State to acquire a fix OR GPS fix State for next 2 minutes ");
  delay(120000); // 2 minutes - to get a GPS fix
  
//3. User Button - Session recording - STARTS
 Serial.println(" User Button - Session recording - STARTS ");
 digitalWrite(5,HIGH);
 delay(2000); // Long press for 2 seconds
 digitalWrite(5,LOW);

// 3a. User Button - Session recording - In progress for next 3 minutes
 Serial.println(" User Button - Session recording time - In progress for next 3 minutes ");
 delay(180000); // 5 minutes delay - session recording time


//4. User Button - Session recording - STOPS
 Serial.println(" User Button - Session recording - STOPS ");  
 digitalWrite(5,HIGH);
 delay(2000);   // Long press for 2 seconds
 digitalWrite(5,LOW);

//5. User button - 2min delay - Nothing happen during this period
 Serial.println(" Device moves to GPS Fix state " );
 delay(120000); //  delay for 2 mins

//6. Terminating...
 Serial.println(" Terminating ");
 exit(0);

}
