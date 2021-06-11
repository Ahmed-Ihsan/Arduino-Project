#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  Serial.println("Adafruit MLX90614 test");  
  mlx.begin();  
  
}

void loop() {
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Ambient = "); display.print(mlx.readAmbientTempC());
  display.setCursor(0, 20);
  display.print("*C\tObject = "); display.print(mlx.readObjectTempC()); display.println("*C");
  display.setCursor(0, 30);
  display.print("Ambient = "); display.print(mlx.readAmbientTempF()); 
  display.setCursor(0, 40);
  display.print("*F\tObject = "); display.print(mlx.readObjectTempF()); display.println("*F");
  display.display(); 
  delay(500);
}
