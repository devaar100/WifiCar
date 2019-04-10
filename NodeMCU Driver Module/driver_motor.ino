#include <ESP8266WiFi.h>
//Motor A
int motorLF =  2;
int motorLB =  0;    
//Motor B
int motorRF =  15;    
int motorRB =  13;

WiFiClient client;
WiFiServer server(80);

const char* ssid = "WiFi name";
const char* password = "WiFi password";

String  data ="";

void setup() 
{ 
  pinMode(motorLF, OUTPUT); 
  pinMode(motorLB, OUTPUT);
  pinMode(motorRF, OUTPUT); 
  pinMode(motorRB, OUTPUT);
    
  Serial.begin(115200);
  connectWiFi();
  server.begin();
}

void loop() 
{
    client = server.available();
    if (!client) return; 
    data = checkClient();
    Serial.println(data);

    if (data == "forw")
      rotateForward();
    else if (data == "back") 
      rotateBackward();
    else if (data == "lefo")
      rotateLeftForward();
    else if (data == "rifo")
      rotateRightForward();
    else if (data == "lebk")
      rotateLeftBackward();
    else if (data == "ribk")
      rotateRightBackward();
    else if (data == "stop")
      stop();

    Serial.println("New loop");
}

void stop(){
  digitalWrite(motorLF, LOW);
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
}

void rotateForward(){
  digitalWrite(motorLF, HIGH);
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
}

void rotateBackward(){
  digitalWrite(motorLF, LOW);
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLB, HIGH);
  digitalWrite(motorRB, HIGH);
}

void rotateLeftForward(){
  digitalWrite(motorLF, LOW);
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
}

void rotateRightForward(){
  digitalWrite(motorLF, HIGH);
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
}

void rotateLeftBackward(){
  digitalWrite(motorLF, LOW);
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, HIGH);
}

void rotateRightBackward(){
  digitalWrite(motorLF, LOW);
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLB, HIGH);
  digitalWrite(motorRB, LOW);
}

String checkClient (void)
{
  while(!client.available())
    delay(1);
  String request = client.readStringUntil('\r');
  request.remove(0, 10);
  request.remove(request.length()-9,9);
  return request;
}

void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}
