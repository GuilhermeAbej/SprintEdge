#include <WiFi.h>
#include <PubSubClient.h>

// credenciais do Wi-Fi
const char* ssid = "Wokwi-GUEST"; 
const char* password = ""; 

// broker MQTT do HiveMQ
const char* mqttServer = "broker.hivemq.com"; 
const int mqttPort = 1883;                    

// MQTT
const char *TOPIC_BATERIA = "sensor/bateria";

// definindo os pinos
const int pinCorrente = 34; 
const int pinLed = 22;     

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  
  Serial.print("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado ao Wi-Fi!");

  client.setServer(mqttServer, mqttPort);
  pinMode(pinLed, OUTPUT); 
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int corrente = analogRead(pinCorrente);
  float nivelBateria = (corrente / 1023.0) * 100;

  client.publish(TOPIC_BATERIA, String(nivelBateria).c_str());

  if (nivelBateria < 20.0) {
    Serial.println("Alerta: Nível da bateria abaixo de 20%!");
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
  
  Serial.print("Nível da bateria: ");
  Serial.println(nivelBateria);
  
  delay(5000);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando reconectar ao MQTT...");
    if (client.connect("ESP32Client")) { 
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.print("Falha na conexão, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
