/*
 * This example show how to ping a remote machine using it's hostname
 */

#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFiMulti.h>   // Include the Wi-Fi-Multi library
  

// const char* ssid     = "Aarushi";
// const char* password = "P@ssw0rd1";

const char* remote_host = "amazon.in";
SoftwareSerial ESPserial(2, 3); // RX | TX

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

void setup() {
  Serial.begin(9600);         // Start the Serial communication to send messages to the computer
  ESPserial.begin(115200);
  ESPserial.println("AT+IPR=9600");
  delay(10);
  ESPserial.end();  // Start the software serial for communication with the ESP8266
  ESPserial.begin(9600);
  Serial.println("Ready");
  ESPserial.println("AT+GMR");
  
  Serial.println('\n');

  // We start by connecting to a WiFi network
  wifiMulti.addAP("Aarushi", "P@ssw0rd1");   // add Wi-Fi networks you want to connect to
 // wifiMulti.addAP("Plavokac", "qwertyuiop");
  wifiMulti.addAP("A-155, phase-1", "63446344");
 // wifiMulti.addAP("Sunil","Indore@123");
 // wifiMulti.addAP("Rakesh Shukla 2G", "Aa@11111");
 // wifiMulti.addAP("Suvam", "Suvam@7788");
 // wifiMulti.addAP("Simmi", "0987654321");
  
 // wifiMulti.addAP("Sunil", "Indore@123"); 

  Serial.println();

  Serial.println("Connecting to WiFi");
  
  //WiFi.begin(ssid, password);
  
   while (wifiMulti.run() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  

  Serial.print("Pinging host ");
  Serial.println(remote_host);

  
}

void loop() { 
  if(Ping.ping(remote_host)) {
    Serial.println("Success!!");
    Serial.println();
    Serial.print("WiFi connected with ip ");  
    Serial.printf(" connected to %s\n", WiFi.SSID().c_str());
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Error :(");
  }
}
