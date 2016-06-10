#include "Adafruit_mfGFX.h"
#include "Adafruit_HX8357.h"
#include "SdFat.h"

#define SD_CS D6
#define TFT_RST A0
#define TFT_DC A1
#define TFT_CS A2
#define pinLite D3

SdFat sd;
Adafruit_HX8357 display = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);

void pinInitialization()
{
	//*** Initialize Photon Pin Modes
	pinMode(TFT_RST, OUTPUT);
	pinMode(SD_CS, OUTPUT);
	pinMode(TFT_DC, OUTPUT);
	pinMode(TFT_CS, OUTPUT);
	pinMode(A3, OUTPUT); //CLK
	pinMode(A5, OUTPUT); //MOSI

	//*** Initialize Photon Pin Values
	digitalWrite(TFT_RST, LOW);
	digitalWrite(SD_CS, LOW);
	digitalWrite(TFT_DC, LOW);
	digitalWrite(TFT_CS, LOW);
	digitalWrite(A3, LOW); //CLK
	digitalWrite(A5, LOW); //MOSI
}

STARTUP( pinInitialization() );

void setup() {
  //Initialize LCD
  analogWrite(pinLite, 250); // Needs to go before screen initializes
	display.begin(HX8357D);
	display.setRotation(1);
	display.setTextSize(7);
	display.setFont(GLCDFONT);
	display.fillRect(0, 0, 480, 320, HX8357_BLACK);

  //Initialize SD
  if (!sd.begin(SD_CS)) {
    display.println(" Error: SD Init");
  }
	display.println("Font type 1");

	//Write font "COMICS_8" to SD Card

  //Load font "COMICS_8" from SD Card

  //Test second font
	display.setFont(COMICS_8);
	display.println("Font type 2");
}

void loop() {
  // nothing happens after setup
}
