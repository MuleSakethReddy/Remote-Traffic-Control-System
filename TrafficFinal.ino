#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <string>  // for string
#define HOST "saketh712.000webhostapp.com"

const char* ssid = "Tech_D0006519";
const char* password = "KPYFXZDV";
HTTPClient http;

int red1 = D6;
int green1 = D7;
int red2= D3;
int green2 = D4;
int red3 = D0;
int green3 = D1;

WiFiServer server(80);
 
void setup()
{
  Serial.begin(115200);
  delay(10);
 
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(green3, OUTPUT);
  
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(green3, LOW);
  
 
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  delay(1000);
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
 
}
 
void loop()
{
  // Check if a client has connected
  WiFiClient client;
  http.begin(client, "http://saketh712.000webhostapp.com/dbwrite.php");
  
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available())
  {
    delay(100);
  }
  
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    // Prepare your HTTP POST request data
  int laneid = 4;
  int lane = 4;
  String httpRequestData = "laneid=" + String(laneid) + "&lane=" + String(lane);

  int httpResponseCode = http.POST(httpRequestData);

  if (httpResponseCode>0)
      {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      }
    else
    {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();

 
//  // Read the first line of the request
//  String request = client.readStringUntil('\r');
//  Serial.println(request);
//  client.flush();
// 
//  // Match the request
// 
//  int value = 0;

  // if (5 != -1)  
  // {
  //   digitalWrite(red1, LOW);
  //   digitalWrite(green1, HIGH);
  //   digitalWrite(red2, HIGH);
  //   digitalWrite(green2, LOW);
  //   digitalWrite(red3, HIGH);
  //   digitalWrite(green3, LOW);   
  //   value = 1;
  // }
  // if (5== -1)  
  // {
  //   digitalWrite(red2, LOW);
  //   digitalWrite(green2, HIGH);
  //   digitalWrite(red1, HIGH);
  //   digitalWrite(green1, LOW);
  //   digitalWrite(red3, HIGH);
  //   digitalWrite(green3, LOW);
  //   value = 2;
  // }
  // if (5== -1)  
  // {
  //   digitalWrite(red3, LOW);
  //   digitalWrite(green3, HIGH);
  //   digitalWrite(red1, HIGH);
  //   digitalWrite(green1, LOW);
  //   digitalWrite(red2, HIGH);
  //   digitalWrite(green2, LOW);
  //   value = 3;
  // }
 
// Set red1 according to the request
//digitalWrite(red1, value);
// 
//  // Return the response
//  client.println("HTTP/1.1 200 OK");
//  client.println("Content-Type: text/html");
//  client.println(""); //  do not forget this one
//  client.println("<!DOCTYPE HTML>");
//  client.println("<meta name='viewport' content='width=device-width', user-scalable='no'>");
//  client.println("<style>  a { border: 3px solid black; margin: 10px;} div { width: 75%; height: 45%; text-align:center; background-color:beige; border: 3px solid black; border-radius:5px; } </style> ");
//  client.println("<html>");
//  client.print("<h2>Command Center</h2>");
//  client.print("<div id='test'> <p> Signal Status: </p>");
 
  /*if(value == 1) 
  {
    client.print("Signal 1 is Green");
  }
  else if(value == 2)
  {
    client.print("Signal 2 is Green");
  }
  else if(value == 3)
  {
    client.print("Signal3 is Green");
  }
  else
  {
    client.print("Signals are Off");
  }
  client.println("<br><br>");*/
  
//  client.println("<a href=\"/LED=Lane1\"\"><button style=\"background:lightgreen\" >Lane 1 </button></a><br />");
//  client.println("<br />");
//  client.println("<a href=\"/LED=Lane2\"\"><button style=\"background:lightgreen\">Lane 2 </button></a><br />");
//  client.println("<br />");
//  client.println("<a href=\"/LED=Lane3\"\"><button style=\"background:lightgreen\">Lane 3 </button></a><br />");
//  client.println("</html>");
// 
//  Serial.println("Client disonnected");
//  Serial.println("");
  delay(10000);
 
}
