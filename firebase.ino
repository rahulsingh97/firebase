#include <WiFi.h>
#include <FirebaseESP32.h> 
#define WIFI_SSID "WI-FI I"
#define WIFI_PASSWORD "846239+846239"
#define FIREBASE_HOST "project-d3662.firebaseio.com/"
#define FIREBASE_AUTH "f1qhKY27siNYI1JZDr82cuQ79s9mjuc5GiwUT2ay"
 
FirebaseData firebaseData;
FirebaseJson json;
FirebaseJsonData jsonData;

void setup()
{
 
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
 
  Serial.println("------------------------------------");
  Serial.println("Connected...");

}
void loop()
{ 
delay(100); 
  jsonb.add("name", "Living Room");
  jsonb.add("temp1", 120).add("temp2", 40).add("temp3", 69);
  json.set("temp1", 12);
  json.set("temp2", 400);
  
  json.get(jsonData,"/temp1");
  Serial.println(jsonData.type);
  Serial.println(jsonData.stringValue);  
 
  Firebase.updateNode(firebaseData,"/API",json);
}
