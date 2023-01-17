//Original source code : http://enrique.latorres.org/2017/10/17/testing-lolin-nodemcu-v3-esp8266/
//Download LoLin NodeMCU V3 ESP8266 Board for Arduino IDE (json) : http://arduino.esp8266.com/stable/package_esp8266com_index.json
#include <ESP8266WiFi.h>
const char* ssid = "your SSID";
const char* password = "Your password";
int ledPin = 2; // Arduino standard is GPIO13 but lolin nodeMCU is 2 http://www.esp8266.com/viewtopic.php?f=26&t=13410#p61332
WiFiServer server(80);
void setup() {
 Serial.begin(115200);
 delay(10);
 pinMode(D5, OUTPUT); // relay 
  pinMode(D6, OUTPUT); // relay 
   pinMode(D7, OUTPUT); // relay 
    pinMode(D8, OUTPUT);// relay 
 digitalWrite(D7, HIGH);// relay 
// Connect to WiFi network
Serial.println();
Serial.println();
 Serial.print("Connecting to ");
 Serial.print(ssid);

WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");

// Start the server
 server.begin();
 Serial.println("Server started");

// Print the IP address
 Serial.print("Use this URL to connect: ");
 Serial.print("http://");
 Serial.print(WiFi.localIP());
 Serial.println("/");

}

void loop() {
 // Check if a client has connected
 WiFiClient client = server.available();
 if (!client) {
 return;
 }

// Wait until the client sends some data
 Serial.println("new client");
 while(!client.available()){
 delay(1);
 }

// Read the first line of the request
 String request = client.readStringUntil('r');
 Serial.println(request);
 client.flush();

// Match the request
 //Lolin nodeMCU has inverted the LED.
 //Low level turns on the led
 //while High level turns it off

//initially off
 if (request.indexOf("/ON1") != -1) {
 digitalWrite(D5, HIGH);

 }
 if (request.indexOf("/ON2") != -1) {
 digitalWrite(D6, HIGH);

 }
 if (request.indexOf("/ON3") != -1) {
 digitalWrite(D7, HIGH);

 }
 if (request.indexOf("/ON4") != -1) {
 digitalWrite(D8, HIGH);

 }
 if (request.indexOf("/OF1") != -1) {
 digitalWrite(D5, LOW);

 }
 if (request.indexOf("OF2") != -1) {
 digitalWrite(D6, LOW);

 }
 if (request.indexOf("/OF3") != -1) {
 digitalWrite(D7, LOW);

 }
 if (request.indexOf("/OF4") != -1) {
 digitalWrite(D8, LOW);

 }

// Set ledPin according to the request
 //digitalWrite(ledPin, value);

// Return the response
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println(""); 
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
 client.println("<link rel=\"stylesheet\" href=\"http://osamaelkassaby.online/ard/style.css\">");

 client.print("<body> ");
 //High=off
 //Low=on
// HTML ON
 client.print("<main class=\"btns\">");
 client.print("<div class=\"btn-on\"><a href=\"ON1\"> <button> ON S (1) </button> </a></div>");
 client.print("<div class=\"btn-on\"><a href=\"ON2\"> <button> ON S (2) </button> </a></div>");
 client.print("<div class=\"btn-on\"><a href=\"ON3\"> <button> ON S (3) </button> </a></div>");
 client.print("<div class=\"btn-on\"><a href=\"ON4\"> <button> ON S (4) </button> </a></div>");
 client.println("</main>"); 
// HTML OF
 client.print("<main class=\"btns\">");
 client.print("<div class=\"btn-of\"><a href=\"OF1\"> <button> OF S (1) </button> </a></div>");
 client.print("<div class=\"btn-of\"><a href=\"OF2\"> <button> OF S (2) </button> </a></div>");
 client.print("<div class=\"btn-of\"><a href=\"OF3\"> <button> OF S (3) </button> </a></div>");
 client.print("<div class=\"btn-of\"><a href=\"OF4\"> <button> OF S (4) </button> </a></div>");
     
 client.println("</main>"); 
 client.println("</body>");
 client.println("</html>");

delay(1);
 Serial.println("Client disonnected");
 Serial.println("");
}
