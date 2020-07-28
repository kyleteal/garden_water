#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *ssid = "YOUR_WIFI_SSID";
const char *password = "YOUR_WIFI_PASSWORD";
const char *mqtt_server = "MQTT_SERVER_IP";
const char *mqttUser = "MQTT_USERNAME";
const char *mqttPassword = "MQTT_PASSWORD";
const int mqttPort = 1883;

WiFiClient espClient;  
PubSubClient client(espClient);

//Change the relayPin to whichever pin you connect the resistor to
int relayPin = D6;
String waterplants;
String strTopic;
String strPayload;

void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, NULL);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *payload, unsigned int length)
{
  payload[length] = '\0';
  strTopic = String((char *)topic);
  if (strTopic == "homeassistant/switch/waterplants")
  {
    waterplants = String((char *)payload);
    if (waterplants == "ON")
    {
      digitalWrite(relayPin, HIGH);
      Serial.println("OPEN");
      client.publish("homeassistant/sensor/gardenwater", "ON");
    }
    else
    {
      digitalWrite(relayPin, LOW);
      Serial.println("CLOSED");
      client.publish("homeassistant/sensor/gardenwater", "OFF");
    }
  }
}

void setup()
{
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqttPort);
  client.setCallback(callback);
  client.subscribe("homeassistant/switch/waterplants");

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}
  void reconnect()
  {
    // Loop until we're reconnected
    while (!client.connected())
    {
      Serial.print("Attempting MQTT connection...");
      // Attempt to connect
      if (client.connect("PlantsESP", mqttUser, mqttPassword))
      {
        Serial.println("connected");
        // Once connected, publish an announcement...
        client.subscribe("homeassistant/switch/waterplants");
      }
      else
      {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        // Wait 5 seconds before retrying
        delay(5000);
      }
    }
  
}

void loop()
{

  if (!client.connected())
  {
    reconnect();
  }
  else if (client.connected())
  {
  client.loop();
  }
}