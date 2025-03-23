#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include "model.h"
#include "server.h"

#define GSR_PIN 35  

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Eloquent::ML::Port::RandomForestModel model;

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22);

    if (!mlx.begin()) {
        Serial.println("Error: MLX90614 sensor not found! Check wiring.");
        while (1);
    }

    Serial.println("MLX90614 Sensor Initialized.");
    startServer();  
}

// ✅ Function to collect sensor data and predict stress level
String getSensorPrediction() {
    float objectTempC = mlx.readObjectTempC();
    float objectTempF = (objectTempC * 9.0 / 5.0) + 32.0;  

    int gsrRaw = analogRead(GSR_PIN);
    float gsrScaled = map(gsrRaw, 0, 4095, 0, 30); 

    // ✅ Apply feature scaling (Ensure it matches training data preprocessing)
    float temp_scaled = (objectTempF - 70) / (110 - 70); 
    float gsr_scaled = gsrScaled / 30;  

    float input[] = { temp_scaled, gsr_scaled };  
    int stressLevel = model.predict(input);

    Serial.println("====== Sensor Readings ======");
    Serial.print("Temperature: "); Serial.print(objectTempF); Serial.println(" °F");
    Serial.print("GSR Value (Scaled 0-30): "); Serial.println(gsrScaled);
    Serial.print("Predicted Stress Level: "); Serial.println(stressLevel);
    Serial.println("============================\n");

    return "{\"temperature\":" + String(objectTempF) + ",\"gsr\":" + String(gsrScaled) + ",\"stressLevel\":" + String(stressLevel) + "}";
}

void loop() {
    // The web server will call getSensorPrediction() when needed
}
