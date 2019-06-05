#include <Adafruit_NeoPixel.h>

const int numPixels = 60;

// An array of the pin numbers for the strips
int neoPixelPin = 6;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

const uint32_t Blue = Adafruit_NeoPixel::Color(10, 10, 255);
const uint32_t Pink = Adafruit_NeoPixel::Color(100, 255, 50);


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  setAllStrips(Blue);
}

void loop() {
  delay(3000);
  crossFade(Blue, Pink, 10UL);
  delay(3000);
  crossFade(Pink, Blue, 10UL);
}

void setAllStrips(const uint32_t color) {
  byte red = (color >> 16) & 0xff;
  byte green = (color >> 8) & 0xff;
  byte blue = color & 0xff;
  setAllStrips(red, green, blue);
}

void setAllStrips(byte red, byte green, byte blue) {
  // for each strip
    // for each pixel
    for (int pixel = 0; pixel < numPixels; pixel++) {
      strip.setPixelColor(pixel, red, green, blue);
    }
    strip.show(); // Output to strip
}

void crossFade(const uint32_t startColor, const uint32_t endColor, unsigned long speed) {
  byte startRed = (startColor >> 16) & 0xff;
  byte startGreen = (startColor >> 8) & 0xff;
  byte startBlue = startColor & 0xff;

  byte endRed = (endColor >> 16) & 0xff;
  byte endGreen = (endColor >> 8) & 0xff;
  byte endBlue = endColor & 0xff;

  // for each step in the cross-fade
  for (int step = 0; step < 256; step++) {
    byte red = map(step, 0, 255, startRed, endRed);
    byte green = map(step, 0, 255, startGreen, endGreen);
    byte blue = map(step, 0, 255, startBlue, endBlue);
    setAllStrips(red, green, blue);
    delay(speed);
  }
}
