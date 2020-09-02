#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WiFi.h>

const char *ssid = "SSID";
const char *password = "PASS";

AsyncWebServer server(80);

String getDate() {
  String dateValue = "01/09/2020";
  Serial.println(dateValue);
  return dateValue;
}

String getTimes() {
  String timeValue = "12:05:20";
  Serial.println(timeValue);
  return timeValue;
}

String getBattery() {
  float batValue = random(15);
  Serial.println(batValue);
  return String(batValue);
}

String getSignal() {
  float sigValue = random(100);
  Serial.println(sigValue);
  return String(sigValue);
}

String getIrradiance() {
  float irrValue = random(1000);
  Serial.println(irrValue);
  return String(irrValue);
}

String getPressure() {
  float preValue = random(1000);
  Serial.println(preValue);
  return String(preValue);
}

String getTempHDC() {
  float hdctempValue = random(80);
  Serial.println(hdctempValue);
  return String(hdctempValue);
}

String getHumHDC() {
  float hdchumValue = random(100);
  Serial.println(hdchumValue);
  return String(hdchumValue);
}

String getTempAMS() {
  float amstempValue = random(80);
  Serial.println(amstempValue);
  return String(amstempValue);
}

String getHumAMS() {
  float amshumValue = random(100);
  Serial.println(amshumValue);
  return String(amshumValue);
}

String getRainfall() {
  float raiValue = random(100);
  Serial.println(raiValue);
  return String(raiValue);
}

String getWindSpeed() {
  float wspValue = random(100);
  Serial.println(wspValue);
  return String(wspValue);
}

String getWindDirection() {
  String wdiValue = "North";
  Serial.println(wdiValue);
  return String(wdiValue);
}

String getUltrasonic1() {
  float ul1Value = random(250);
  Serial.println(ul1Value);
  return String(ul1Value);
}

String getUltrasonic2() {
  float ul2Value = random(250);
  Serial.println(ul2Value);
  return String(ul2Value);
}

String processor(const String &var) {
  Serial.println(var);
  if (var == "DATE") {
    return getDate();
  } else if (var == "TIME") {
    return getTimes();
  } else if (var == "BAT") {
    return getBattery();
  } else if (var == "SIG") {
    return getSignal();
  } else if (var == "IRR") {
    return getIrradiance();
  } else if (var == "PRE") {
    return getPressure();
  } else if (var == "TIN") {
    return getTempHDC();
  } else if (var == "HIN") {
    return getHumHDC();
  } else if (var == "TOU") {
    return getTempAMS();
  } else if (var == "HOU") {
    return getHumAMS();
  } else if (var == "RAI") {
    return getRainfall();
  } else if (var == "WSP") {
    return getWindSpeed();
  } else if (var == "WDI") {
    return getWindDirection();
  } else if (var == "UL1") {
    return getUltrasonic1();
  } else if (var == "UL2") {
    return getUltrasonic2();
  }
}

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  server.on("/about.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/about.html", "text/html");
  });
  server.on("/scr/bootstrap.bundle.min.js", HTTP_GET,
            [](AsyncWebServerRequest *request) {
              request->send(SPIFFS, "/scr/bootstrap.bundle.min.js",
                            "text/javascript");
            });
  server.on(
      "/scr/jquery-3.3.1.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/scr/jquery-3.3.1.min.js", "text/javascript");
      });
  server.on("/scr/bootstrap.min.css", HTTP_GET,
            [](AsyncWebServerRequest *request) {
              request->send(SPIFFS, "/scr/bootstrap.min.css", "text/css");
            });
  server.on("/date", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getDate().c_str());
  });
  server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getTimes().c_str());
  });
  server.on("/battery", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getBattery().c_str());
  });
  server.on("/signal", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getSignal().c_str());
  });
  server.on("/irradiance", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getIrradiance().c_str());
  });
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getPressure().c_str());
  });
  server.on("/temperatureIn", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getTempHDC().c_str());
  });
  server.on("/humidityIn", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getHumHDC().c_str());
  });
  server.on("/temperatureOut", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getTempAMS().c_str());
  });
  server.on("/humidityOut", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getHumAMS().c_str());
  });
  server.on("/rainfall", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getRainfall().c_str());
  });
  server.on("/windspeed", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getWindSpeed().c_str());
  });
  server.on("/winddirection", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getWindDirection().c_str());
  });
  server.on("/ultrasonic1", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getUltrasonic1().c_str());
  });
  server.on("/ultrasonic2", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", getUltrasonic2().c_str());
  });
  server.onNotFound(notFound);
  server.begin();
}

void loop() {}