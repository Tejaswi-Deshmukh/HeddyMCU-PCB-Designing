#include <ESP8266WiFi.h>
const char WiFiPassword[] = "namune456";
const char AP_NameChar[] = "Water pump";

WiFiServer server(80);

String request = "";

int PUMP = D3;

#include <FastLED.h>
#define LED_PIN     D7
#define NUM_LEDS    4 //1
#define BRIGHTNESS  200
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

void setup()
{
  Serial.begin(115200);
  pinMode(PUMP, OUTPUT);
  
  WiFi.disconnect();
  boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
  server.begin();

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

} 

void loop()
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client)  {
    return;
  }

  // Read the first line of the request
  request = client.readStringUntil('\r');
if( request.indexOf("D3HIGH") > 0 )  
   {
    digitalWrite(PUMP, HIGH);
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
    Serial.println("Pump ON");
   }
   if  ( request.indexOf("D3LOW") > 0 ) 
   {
    digitalWrite(PUMP, LOW);
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
    Serial.println("Pump OFF");
   }
/////////////////////////////

  
//////////leds////////////

  if  ( request.indexOf("BLUE") > 0 ) 
   {
    leds[0] =CRGB::Blue;
    FastLED.show();
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
   }
   if  ( request.indexOf("RED") > 0 ) 
   {
    leds[0] =CRGB::Red;
    FastLED.show();
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
   }
   if  ( request.indexOf("GREEN") > 0 ) 
   {
    leds[0] =CRGB::Green;
    FastLED.show();
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
   }
   if  ( request.indexOf("YELLOW") > 0 ) 
   {
    leds[0] =CRGB::Yellow;
    FastLED.show();
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
   }
if  ( request.indexOf("PURPLE") > 0 ) 
   {
    leds[0] =CRGB::Purple;
    FastLED.show();
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
   }
   if  ( request.indexOf("OFF") > 0 ) 
   {
    leds[0] =CRGB::Black;
    FastLED.show();
    client.println("HTTP/1.1 200 OK\r\n");
    client.flush();
   }
  
  delay(5);

} 
