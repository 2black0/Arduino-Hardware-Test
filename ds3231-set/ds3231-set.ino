#include <ErriezDS3231.h>
#include <Wire.h>


// Create DS3231 RTC object
static DS3231 rtc;

// Function prototypes
static void setDateTime();
static void printDateTime();

void setup() {
  // Initialize serial port
  Serial.begin(115200);
  Serial.println(F("DS3231 RTC getting started example\n"));

  // Initialize TWI
  Wire.begin();
  Wire.setClock(400000);

  // Initialize RTC
  while (rtc.begin()) {
    Serial.println(F("Error: Could not detect DS3231 RTC"));
    delay(3000);
  }

  Serial.println(F("Current RTC date and time:"));
  printDateTime();
  Serial.println(F("Set new RTC date and time..."));
  setDateTime();
  Serial.println(F("New RTC date and time:"));
}

void loop() {
  printDateTime();
  delay(1000);
}

static void setDateTime() {
  static DS3231_DateTime dt = {.second = 0,
                               .minute = 41,
                               .hour = 9,
                               .dayWeek = 36,
                               .dayMonth = 4,
                               .month = 9,
                               .year = 2020};
  rtc.setDateTime(&dt);
}

static void printDateTime() {
  DS3231_DateTime dt;
  char buf[32];
  if (rtc.getDateTime(&dt)) {
    Serial.println(F("Error: Read date time failed"));
    return;
  }
  snprintf(buf, sizeof(buf), "%d %02d-%02d-%d %d:%02d:%02d", dt.dayWeek,
           dt.dayMonth, dt.month, dt.year, dt.hour, dt.minute, dt.second);
  Serial.println(buf);
}
