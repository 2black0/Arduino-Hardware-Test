# 🔧 Arduino Hardware Test Collection

This repository contains a set of simple and modular sketches to **test and demonstrate various hardware modules with Arduino and ESP32**. Each folder includes a standalone `.ino` sketch focused on testing a specific sensor, module, or functionality.

## 🎯 Purpose

This project is designed to:
- Serve as a reference for quickly testing different sensors and communication modules.
- Help students and developers validate hardware setup before deeper integration.
- Provide clean, minimal, and focused examples for each hardware type.

## 📁 Folder Structure

```

.
├── ads1115/                  # Analog-to-digital converter (ADS1115) test
│   └── ads1115.ino
├── am2320/                   # AM2320 temperature & humidity sensor test
│   └── am2320.ino
├── bmp280/                   # BMP280 barometric pressure sensor test
│   └── bmp280.ino
├── ds3231/                   # DS3231 RTC test (read time)
│   └── ds3231.ino
├── ds3231-alarm/             # DS3231 RTC alarm interrupt test
│   └── ds3231-alarm.ino
├── ds3231-set/               # Set time to DS3231 RTC
│   └── ds3231-set.ino
├── hdc1080/                  # HDC1080 temperature & humidity sensor test
│   └── hdc1080.ino
├── jsn-sr04t/                # JSN-SR04T waterproof ultrasonic sensor test
│   └── jsn-sr04t.ino
├── sim800l/                  # SIM800L GSM module test
│   └── sim800l.ino
├── webserver-esp32-spiffs/  # ESP32 Web Server with SPIFFS for serving HTML/JS/CSS
│   ├── data/
│   │   ├── about.html
│   │   ├── index.html
│   │   └── scr/
│   │       ├── bootstrap.bundle.min.js
│   │       ├── bootstrap.min.css
│   │       └── jquery-3.3.1.min.js
│   └── webserver-esp32-spiffs.ino

```

## ▶️ How to Use

1. **Clone this repository**:
   ```bash
   git clone [https://github.com/yourusername/arduino-hardware-tests](https://github.com/2black0/Arduino-Hardware-Test-Collection).git
   ```

2. **Open any sketch** using the Arduino IDE or PlatformIO.

3. **Connect the corresponding hardware module** as required by the sketch.

4. **Upload** the code to your Arduino/ESP32 board.

5. **Monitor Serial Output** (if available) using the Serial Monitor (baud rates are usually defined in the sketch).

## 📦 Dependencies

Each sketch may require one or more libraries. Install them via the Arduino Library Manager or PlatformIO.

Example:

* `Adafruit_BMP280`
* `Adafruit_Sensor`
* `RTClib`
* `Wire`
* `SoftwareSerial`
* `ESPAsyncWebServer`
* etc.

Check each `.ino` file for library includes.

## 💡 Highlights

* Tested on **Arduino Uno**, **ESP32**, and **ESP8266**
* Minimal dependencies
* Clear and modular code
* Supports SPIFFS file upload for ESP32 web server example

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## 🙋‍♂️ Contributions

Feel free to fork this repository and submit a pull request for additional test sketches, improvements, or documentation updates.
