
# 🌾 Crop Recommendation Using Soil Quality Test

This project provides **crop recommendations** based on **soil quality data** collected via sensors. The system uses **IoT sensors** to gather soil data and applies **Machine Learning** algorithms to analyze the data and recommend suitable crops. It leverages Arduino for sensor integration and Python for data processing and machine learning.

---

## 🛠️ Features

- **IoT Sensor Integration**: Soil quality sensors are used to capture real-time data.
- **Arduino-Based Data Collection**: Arduino collects data from the sensors and transfers it to the system.
- **Machine Learning Crop Recommendation**: A trained ML model recommends crops based on the soil quality.
- **CoolTerm for Data Capture**: CoolTerm software is used to capture sensor data in a binary text format.
  
---

## 📂 Project Structure

```txt
Crop-Recommendation-Using-soil-quality-test/
│
│── dht.ino                # Arduino code for soil sensors
│── sens.txt               # Sample sensor data file (to be generated)
│── cropdata.csv           # Data set for project
├── main.py                # Main Python file for processing data
├── README.md              # Instructions (this file)
```

---

## 🚀 Setup Instructions

### 1. Hardware Setup

- **Connect Sensors**: Insert the soil sensors into the soil.
- **Arduino Code**: Upload the provided Arduino code to your Arduino board to begin capturing sensor data.

### 2. CoolTerm Setup

- **Install CoolTerm**: Download and install **CoolTerm** to capture sensor data.
  
- **Connect Arduino to CoolTerm**:
  - Open CoolTerm and connect your Arduino’s serial port.
  - Set the data format to binary text.
  - Start capturing the sensor data from the connected Arduino.
  - Once you have captured enough data, save it as a **`.txt`** file in your project folder.

### 3. Software Setup

- **Clone the Repository**

```bash
git clone https://github.com/Aniketpagare1/Crop-Recommendation-Using-soil-quality-test.git
cd Crop-Recommendation-Using-soil-quality-test
```

- **Install Python Dependencies**

Install all required Python dependencies.


## 🛠️ Usage

### 1. Prepare Sensor Data

- After collecting the data using CoolTerm, save it as `sensor_data.txt` in the `sensors/` folder.

### 2. Run the Crop Recommendation System

- Run the main Python file `main.py` and provide the path to the sensor data file:

```bash
python main.py
```

- The program will process the sensor data and recommend the best crop for the soil quality based on the trained ML model.

---

## 🧪 Example Output

```txt
Enter the sensor data file path: sensors/sensor_data.txt
The recommended crop for your soil is: Wheat
```

---
