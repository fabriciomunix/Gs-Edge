#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883; // Porta padrão para MQTT sem TLS
const char* topic_geracao = "energia/geracao";
const char* topic_consumo = "energia/consumo";
const char* topic_rele = "energia/dispositivos";

const int sensorGeracao = 34;
const int sensorConsumo = 35;
const int relePin = 25;

WiFiClient espClient;
PubSubClient client(espClient);

void onMessage(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println("Mensagem recebida no tópico: " + String(topic) + ", Mensagem: " + message);

  if (String(topic) == topic_rele) {
    if (message == "ON") {
      digitalWrite(relePin, HIGH);
    } else if (message == "OFF") {
      digitalWrite(relePin, LOW);
    }
  }
}

void setup_wifi() {
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi");
}

void setup() {
  Serial.begin(115200);

  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW);

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(onMessage);
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Conectando ao MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado ao MQTT");
      client.subscribe(topic_rele);
    } else {
      Serial.println("Falha na conexão. Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float geracao = analogRead(sensorGeracao) / 4095.0 * 100.0;
  float consumo = analogRead(sensorConsumo) / 4095.0 * 100.0;

  char buffer[10];
  dtostrf(geracao, 6, 2, buffer);
  client.publish(topic_geracao, buffer);

  dtostrf(consumo, 6, 2, buffer);
  client.publish(topic_consumo, buffer);

  Serial.print("Geração: ");
  Serial.print(geracao);
  Serial.print("% | Consumo: ");
  Serial.print(consumo);
  Serial.println("%");

  delay(2000);
}
