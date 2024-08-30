#define VERSION 

#include <WiFi.h>
#include <SD.h>
#include <Audio.h>

#define AUDIO_FILE "/Audio.wav"

const char* ssid = "SSID";
const char* password = "PASS";

#define pin_RECORD_BTN 36
#define LED 2

Audio audio_play;

bool I2S_Record_Init();
bool Record_Start(String filename);
bool Record_Available(String filename, float* audiolength_sec);

String SpeechToText_Deepgram(String filename);
void Deepgram_KeepAlive();

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(100);

  pinMode(LED, OUTPUT);
  pinMode(pin_RECORD_BTN, INPUT);

  Serial.println(VERSION);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting WLAN ");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(". Done, device connected.");
  digitalWrite(LED, LOW);

  if (!SD.begin()) {
    Serial.println("ERROR - SD Card initialization failed!");
    return;
  }

  I2S_Record_Init();

  Serial.println("> HOLD button for recording AUDIO .. RELEASE button for REPLAY & Deepgram transcription");
}

void loop() {
  if (digitalRead(pin_RECORD_BTN) == LOW) {
    digitalWrite(LED, HIGH);
    delay(30);

    Record_Start(AUDIO_FILE);
  }

  if (digitalRead(pin_RECORD_BTN) == HIGH) {
    digitalWrite(LED, LOW);

    float recorded_seconds;
    if (Record_Available(AUDIO_FILE, &recorded_seconds)) {
      if (recorded_seconds > 0.4) {
        digitalWrite(LED, HIGH);

        String transcription = SpeechToText_Deepgram(AUDIO_FILE);

        digitalWrite(LED, LOW);
        Serial.println(transcription);
      }
    }
  }

  if (digitalRead(pin_RECORD_BTN) == HIGH && !audio_play.isRunning()) {
    static uint32_t millis_ping_before;
    if (millis() > (millis_ping_before + 5000)) {
      millis_ping_before = millis();
      digitalWrite(LED, HIGH);
      Deepgram_KeepAlive();
    }
  }
}
