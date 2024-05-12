#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>
#include <LiquidCrystal.h>


#define LED 2

AsyncWebServer server(80);

const char* ssid = "neumanns2";          // Your WiFi SSID
const char* password = "akash222";  // Your WiFi Password

// Create An LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal My_LCD(22, 23, 19, 18, 5, 17);



void recvMsg(uint8_t *data, size_t len){
  WebSerial.println("Received Data...");
  String d = "";
  for(int i=0; i < len; i++){
    d += char(data[i]);
  }
  WebSerial.println(d);
  if (d == "ON"){
    digitalWrite(LED, HIGH);
  }
  if (d=="OFF"){
    digitalWrite(LED, LOW);
  }
  else {
    // Initialize The LCD. Parameters: [ Columns, Rows ]
    My_LCD.begin(16, 2);
  // Clears The LCD Display
    My_LCD.clear();
    My_LCD.print(d);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  // WebSerial is accessible at "<IP Address>/webserial" in browser
  WebSerial.begin(&server);
  WebSerial.msgCallback(recvMsg);
  server.begin();
}

void loop() {
  WebSerial.println("Hello!");
  delay(2000);
}