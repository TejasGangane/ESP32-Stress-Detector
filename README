# 🧠 Sweat-Based Stress Detection System

A **real-time stress monitoring system** using the **ESP32**, **GSR (Galvanic Skin Response)** sensor, and **temperature sensor**, powered by a **machine learning (Random Forest)** model. This system detects stress levels based on physiological signals and displays the results on a responsive **Next.js web application**.

---

## 🚀 Project Overview

This project aims to measure and analyze human stress levels using a sweat-based approach. The system captures skin conductance (sweating) and body temperature, processes the data through a trained ML model, and visualizes the results in real-time via a web interface.

Key features:
- Real-time physiological data collection
- ML-based stress classification (levels 0, 1, 2)
- WebSocket-based live communication with Next.js frontend
- Baseline calibration to handle personal variations

---

## 🧩 Hardware & Circuit Design

### 🖥️ Microcontroller
- **ESP32 Dev Board**
  - Built-in **Wi-Fi** used for real-time data transfer

### 🔌 Pin Assignments
| Sensor              | ESP32 Pin      | Notes                    |
|---------------------|----------------|---------------------------|
| **GSR Sensor**       | GPIO36 / A0     | Analog Input              |
| **Temperature Sensor** | GPIO4           | Uses OneWire Protocol     |

> 💡 Ensure sensors are correctly connected and powered before running tests or collecting data.

---

## 🧪 Testing Strategy

### ✅ Sensor Testing
- Confirm sensor readings via **Serial Monitor** before training or inference.
- Validate range:
  - **GSR Range**: 0–30 (normalized)
  - **Temperature Range**: 70–110°F

### 🔄 Real-Time Communication
- Implemented using **WebSockets** for live data transmission from ESP32 to the web application.

---

## 🧠 Machine Learning

- **Model Type**: Random Forest Classifier
- **Inputs**: Averaged 10-second values from GSR and Temperature sensors
- **Outputs**: Stress Level → `0` (Low), `1` (Moderate), `2` (High)

---

## 🌐 Web Interface (Next.js)

The frontend web app provides:
- “**Start Monitoring**” button to begin stress level analysis
- Live stress level display after 10-second sensor capture
- Clean Apple-style UI with blue accents and a “How it Works” section

---

## 🧪 PlatformIO Unit Testing

This directory also supports **PlatformIO Unit Testing**.

**Unit Testing** is a method to validate individual units (functions, modules) of code for expected behavior. In embedded systems, this ensures your MCU code and procedures operate correctly before deployment.

📚 More on PlatformIO Unit Testing:  
👉 [PlatformIO Unit Testing Docs](https://docs.platformio.org/en/latest/advanced/unit-testing/index.html)

---

## 📁 Project Structure


---

## 🔧 Setup & Requirements

- **Hardware**: ESP32, GSR Sensor, MLX90614/temperature sensor
- **Software**:
  - PlatformIO IDE
  - Python for ML model training
  - TensorFlow Lite / `TensorFlowLite_ESP32` for deployment
  - Next.js & Tailwind CSS for frontend UI

---

## 📌 Future Improvements

- Add adaptive stress thresholds based on user profiling
- Use more biosignals like heart rate (PPG) or SpO₂
- Store long-term stress trends on the cloud for behavioral insights

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

> Built with 💙 using IoT, ML, and clean design principles to make stress detection accessible and real-time.
