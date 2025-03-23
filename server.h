#pragma once
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"

extern String getSensorPrediction();  

// AP Mode Configuration
const char* apSSID = "StressDetector";
const char* apPassword = "12345678";  // At least 8 characters

// Web server instance
AsyncWebServer server(80);

void startServer() {
    // Start ESP32 as an Access Point
    WiFi.softAP(apSSID, apPassword);
    Serial.println("\nAccess Point Started!");
    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.softAPIP());

    // Initialize SPIFFS (for serving HTML)
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS initialization failed!");
        return;
    }

    // Serve HTML page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", "text/html");
    });

    // Serve sensor data with ML prediction
    server.on("/getSensorData", HTTP_GET, [](AsyncWebServerRequest *request) {
        String json = getSensorPrediction();  
        request->send(200, "application/json", json);
    });

    server.begin();
}
