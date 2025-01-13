#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define MQ2pin A0
float sensorValue;  //variable to store sensor value
int buzzer=4;
void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  pinMode(buzzer,OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  delay(10);
  Serial.println("MQ2 warming up!");
  delay(20000); // allow the MQ2 to warm up
}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if(sensorValue>300)
  {
    digitalWrite(buzzer,HIGH);
    }
  else
  {
      digitalWrite(buzzer,LOW);
    }
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("Gas Value");
  display.setTextSize(3);
  display.setCursor(0, 35);
  display.print(sensorValue);
  display.display();
  delay(2000); // wait 2s for next reading
}
