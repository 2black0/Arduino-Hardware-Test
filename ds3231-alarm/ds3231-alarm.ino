#include <ErriezDS3231.h>
#include <Wire.h>

#define INT_PIN 27

static DS3231 rtc;
static DS3231_DateTime dt;

static volatile bool alarmInterrupt = false;

static void setAlarm1();
static void setAlarm2();
static void alarmHandler();
static void printDateTimeShort();

void setup() {
  Serial.begin(115200);
  Serial.println(F("DS3231 RTC alarm interrupt example\n"));

  Wire.begin();
  Wire.setClock(400000);

  while (rtc.begin()) {
    Serial.println(F("Error: Could not detect DS3231 RTC"));
    delay(3000);
  }

  if (rtc.isOscillatorStopped()) {
    Serial.println(
        F("Error: DS3231 RTC oscillator stopped. Program new date/time."));
    while (1) {
      ;
    }
  }

  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), alarmHandler, FALLING);

  setAlarm1();
  setAlarm2();

  Serial.print(F("Current date and time: "));
  printDateTimeShort();
  Serial.println(F("Waiting for a alarm interrupts..."));
}

void loop() {
  if (alarmInterrupt) {
    if (rtc.getAlarmFlag(Alarm1)) {
      Serial.print(F("Alarm 1 interrupt: "));
      printDateTimeShort();
      rtc.clearAlarmFlag(Alarm1);
    }

    if (rtc.getAlarmFlag(Alarm2)) {
      Serial.print(F("Alarm 2 interrupt: "));
      printDateTimeShort();
      setAlarm2();
      rtc.clearAlarmFlag(Alarm2);
    }

    alarmInterrupt = false;
  }
}

static void setAlarm1() {
  Serial.println(F("Set Alarm 1 at every 30 seconds"));
  rtc.setAlarm1(Alarm1MatchSeconds, 0, 0, 0, 30);
  rtc.alarmInterruptEnable(Alarm1, true);
}

static void setAlarm2() {
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
  rtc.getTime(&hour, &minute, &second);
  minute += 2;
  minute %= 60;
  Serial.println(F("Set Alarm 2 at every hour at 2 minutes"));
  rtc.setAlarm2(Alarm2MatchMinutes, 0, 0, minute);
  rtc.alarmInterruptEnable(Alarm2, true);
}

static void alarmHandler() { alarmInterrupt = true; }

static void printDateTimeShort() {
  char buf[10];
  if (rtc.getDateTime(&dt)) {
    Serial.println(F("Error: Read date time failed"));
    return;
  }

  Serial.print(dt.dayWeek);
  Serial.print(F(" "));
  Serial.print(dt.dayMonth);
  Serial.print(F("-"));
  Serial.print(dt.month);
  Serial.print(F("-"));
  Serial.print(dt.year);
  Serial.print(F("  "));

  snprintf(buf, sizeof(buf), "%d:%02d:%02d", dt.hour, dt.minute, dt.second);
  Serial.println(buf);
}
