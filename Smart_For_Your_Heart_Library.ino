#include <FastLED.h>

#define LED_PIN     53
#define NUM_LEDS    544
#define BRIGHTNESS  48
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

//set up LEDs

int pirPin = 9;
int pirValue;

//set up motion sensor

#include <PCD8544.h>
PCD8544 lcd;

//set up lcd screen

#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PulseWire = 0;
int Threshold = 550;
PulseSensorPlayground pulseSensor;

//set up pulse sensor

void setup() {
  Serial.begin(9600);
  lcd.begin(84, 48);

  delay( 500 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  FastLED.clear();
  FastLED.show();
  //currentPalette = RainbowColors_p;
  //currentBlending = LINEARBLEND;

  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);
  if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");
    lcd.clear();
    lcd.setCursor(0, 0);
    //lcd.print("Let's see whatyour heart hasto say...");
  }

  while (digitalRead(pirPin) == LOW)
  {

    Serial.println("No motion.");
    lcd.setCursor(0, 0);
    lcd.print("Anyone here?");
    //lcd.clear();
  }

  Serial.println("Motion!");
 lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Let's see whatyour heart hasto say...");
  //delay(6000);
  IdlePalette();
}

void loop() {

  //ChangePalettePeriodically();


  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  FillLEDsFromPaletteColors( startIndex);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);


  int myBPM = pulseSensor.getBeatsPerMinute();

  if (pulseSensor.sawStartOfBeat()) {
    Serial.print("BPM: ");
    Serial.println(myBPM);

    if (myBPM <= 30) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are confident!");
      PaletteUpTo30();
      currentBlending = LINEARBLEND; 
    }
    if (myBPM > 30 && myBPM <= 40) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are beautiful!");
      PaletteUpTo40();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 40 && myBPM <= 50) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are loved!");
      PaletteUpTo50();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 50 && myBPM <= 60) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are succesful!");
      PaletteUpTo60();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 60 && myBPM <= 70 && myBPM != 69) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are powerful!");
      PaletteUpTo70();
      currentBlending = LINEARBLEND;
    }
    if (myBPM == 69) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nice ;)");
      SetupTotallyRandomPalette();
      currentBlending = NOBLEND;
    }
    if (myBPM > 70 && myBPM <= 80) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are needed!");
      PaletteUpTo80();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 80 && myBPM <= 90) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are an unstoppable force of nature!");
      PaletteUpTo90();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 90 && myBPM <= 100) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are a living, breathing example of motivation!");
      PaletteUpTo100();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 100 && myBPM <= 110) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are living with abundance!");
      PaletteUpTo110();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 110 && myBPM <= 120) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are worthy!");
      PaletteUpTo120();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 120 && myBPM <= 130) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are inspiring people through your work!");
      PaletteUpTo130();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 130 && myBPM <= 140) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Today is a phenomenal day!");
      PaletteUpTo140();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 140 && myBPM <= 150) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are filled with focus!");
      PaletteUpTo150();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 150 && myBPM <= 160) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are not pushed by your problems; You are led by your dreams!");
      PaletteUpTo160();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 160 && myBPM <= 170) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are independent and self-sufficient!");
      PaletteUpTo170();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 170 && myBPM <= 180) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You can be whatever you want to be!");
      PaletteUpTo180();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 180 && myBPM <= 190) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are intelligent and focused!");
      PaletteUpTo190();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 190 && myBPM <= 200) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Each and every day, You are getting closer to achieving your goals!");
      PaletteUpTo200();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 200 && myBPM <= 210) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are constantly growing and evolving into a better person!");
      PaletteUpTo210();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 210 && myBPM <= 220) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You are healing and strengthening every day!");
      PaletteUpTo220();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 220 && myBPM <= 230) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Your soul radiates from the inside and warms the souls of others!");
      PaletteUpTo230();
      currentBlending = LINEARBLEND;
    }
    if (myBPM > 230 && myBPM <= 240) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Happiness is a choice, and today You choose to be happy!");
      PaletteUpTo240();
      currentBlending = LINEARBLEND;
    }

  }

  delay(1);
}


void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 255;

  for ( int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}


void ChangePalettePeriodically()
{
    uint8_t secondHand = (millis() / 1000) % 110;
    static uint8_t lastSecond = 110;
    
    if( lastSecond != secondHand) {
        lastSecond = secondHand;
        if( secondHand ==  0)  { PaletteUpTo30();  currentBlending = LINEARBLEND;  Serial.println(30);}
        if( secondHand ==  5)  { PaletteUpTo40();      currentBlending = LINEARBLEND;  Serial.println(40);}
        if( secondHand == 10)  { PaletteUpTo50();      currentBlending = LINEARBLEND;  Serial.println(50);}
        if( secondHand == 15)  { PaletteUpTo60();      currentBlending = LINEARBLEND;  Serial.println(60);}
        if( secondHand == 20)  { PaletteUpTo70();      currentBlending = LINEARBLEND;  Serial.println(70);}
        if( secondHand == 25)  { PaletteUpTo80();      currentBlending = LINEARBLEND;  Serial.println(80);}
        if( secondHand == 30)  { PaletteUpTo90();      currentBlending = LINEARBLEND;  Serial.println(90);}
        if( secondHand == 35)  { PaletteUpTo100();     currentBlending = LINEARBLEND;  Serial.println(100);}
        if( secondHand == 40)  { PaletteUpTo110();     currentBlending = LINEARBLEND;  Serial.println(110);}
        if( secondHand == 45)  { PaletteUpTo120();     currentBlending = LINEARBLEND;  Serial.println(120);}
        if( secondHand == 50)  { PaletteUpTo130();     currentBlending = LINEARBLEND;  Serial.println(130);}
        if( secondHand == 55)  { PaletteUpTo140();     currentBlending = LINEARBLEND;  Serial.println(140);}
        if( secondHand == 60)  { PaletteUpTo150();     currentBlending = LINEARBLEND;  Serial.println(150);}
        if( secondHand == 65)  { PaletteUpTo160();     currentBlending = LINEARBLEND;  Serial.println(160);}
        if( secondHand == 70)  { PaletteUpTo170();     currentBlending = LINEARBLEND;  Serial.println(170);}
        if( secondHand == 75)  { PaletteUpTo180();     currentBlending = LINEARBLEND;  Serial.println(180);}
        if( secondHand == 80)  { PaletteUpTo190();     currentBlending = LINEARBLEND;  Serial.println(190);}
        if( secondHand == 85)  { PaletteUpTo200();     currentBlending = LINEARBLEND;  Serial.println(200);}
        if( secondHand == 90)  { PaletteUpTo210();     currentBlending = LINEARBLEND;  Serial.println(210);}
        if( secondHand == 95)  { PaletteUpTo220();     currentBlending = LINEARBLEND;  Serial.println(220);}
        if( secondHand == 100) { PaletteUpTo230();     currentBlending = LINEARBLEND;  Serial.println(230);}
        if( secondHand == 105) { PaletteUpTo240();     currentBlending = LINEARBLEND;  Serial.println(240);}
    }
}


void IdlePalette()
{
  SetupBlackAndWhiteStripedPalette();
  currentBlending = LINEARBLEND;
}

void SetupTotallyRandomPalette()
{
  for ( int i = 0; i < 16; ++i) {
    currentPalette[i] = CHSV( random8(), 255, random8());
  }
}

void SetupBlackAndWhiteStripedPalette()
{
  // 'black out' all 16 palette entries...
  fill_solid( currentPalette, 16, CRGB::Black);
  // and set every fourth one to white.
  currentPalette[0] = CRGB::White;
  currentPalette[4] = CRGB::White;
  currentPalette[8] = CRGB::White;
  currentPalette[12] = CRGB::White;

}

void PaletteUpTo30()
{
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;
  CRGB color4  = CRGB::DarkBlue;

  currentPalette = CRGBPalette16(
                     green,  green,  black,  black,
                     purple, purple, black,  black,
                     green,  green,  black,  black,
                     purple, purple, color4,  color4 );
}

void PaletteUpTo40()
{
  CRGB color1 = CRGB::DarkBlue;
  CRGB color2 = CRGB::Black;
  CRGB color3 = CRGB::SeaGreen;
  CRGB color4 = CRGB::DeepSkyBlue;
  CRGB color5 = CRGB::DarkTurquoise;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color5 );
}

void PaletteUpTo50()
{
  CRGB color1 = CRGB::Maroon;
  CRGB color2 = CRGB::Orange;
  CRGB color3 = CRGB::Green;
  CRGB color4 = CRGB::GreenYellow;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}

void PaletteUpTo60()
{
  CRGB color1 = CHSV(255,246,45);
  CRGB color2 = CHSV(255,149,77);
  CRGB color3 = CHSV(85,255,182);
  CRGB color4 = CHSV(29,192,255);

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}

void PaletteUpTo70()
{
  CRGB color1 = CHSV(15,190,205);
  CRGB color2 = CHSV(204,131,255);
  CRGB color3 = CHSV(46,200,204);
  CRGB color4 = CHSV(255,140,221);

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}

void PaletteUpTo80()
{
  CRGB color1 = CRGB::PeachPuff;
  CRGB color2 = CRGB::DeepPink;
  CRGB color3 = CRGB::MediumVioletRed;
  CRGB color4 = CRGB::MediumOrchid;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}

void PaletteUpTo90()
{
  CRGB color1 = CHSV(3,190,227);
  CRGB color2 = CHSV(194,21,229);
  CRGB color3 = CHSV(0,54,18);
  CRGB color4 = CHSV(182,145,176);

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}

void PaletteUpTo100()
{ CRGB color1 = CHSV(232,112,156);
  CRGB color2 = CHSV(217,102,209);
  CRGB color3 = CHSV(147,227,129);
  CRGB color4 = CHSV(99,208,156);

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}

void PaletteUpTo110()
{
  CRGB color1 = CRGB::HotPink;
  CRGB color3 = CRGB::SkyBlue;
  CRGB color2 = CRGB::Peru;
  CRGB color4 = CRGB::SteelBlue;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}

void PaletteUpTo120()
{
  CRGB color1 = CRGB::Goldenrod;
  CRGB color3 = CRGB::FloralWhite;
  CRGB color2 = CRGB::DeepSkyBlue;
  CRGB color4 = CRGB::SeaGreen;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo130()
{
  CRGB color1 = CHSV(64, 146, 191);
  CRGB color3 = CHSV(233, 222, 200);
  CRGB color2 = CHSV(128, 250, 250);
  CRGB color4 = CHSV(144, 104, 125);

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo140()
{
  CRGB color1 = CRGB::LawnGreen;
  CRGB color2 = CRGB::Olive;
  CRGB color3 = CRGB::Khaki;
  CRGB color4 = CRGB::DarkOliveGreen;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo150()
{
  CRGB color1  = CHSV( HUE_YELLOW, 255, 255);
  CRGB color2  = CHSV( HUE_PINK, 255, 255);
  CRGB color3  = CRGB::DeepPink;
  CRGB color4  = CRGB::Honeydew;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo160()
{
  CRGB color1 = CRGB::Peru;
  CRGB color2 = CRGB::Coral;
  CRGB color3 = CRGB::Gold;
  CRGB color4 = CRGB::OrangeRed;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo170()
{
  CRGB color1 = CRGB::SkyBlue;
  CRGB color4 = CRGB::Aqua;
  CRGB color3 = CRGB::DarkCyan;
  CRGB color2 = CRGB::Aquamarine;
  CRGB color5 = CRGB::CadetBlue;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color5,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color5 );
}
void PaletteUpTo180()
{
  CRGB color1 = CRGB::Plaid;
  CRGB color3 = CRGB::Bisque;
  CRGB color2 = CRGB::Sienna;
  CRGB color4 = CRGB::Beige;
  CRGB color5 = CRGB::Coral;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color5,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color5 );
}
void PaletteUpTo190()
{
  CRGB color1 = CRGB::ForestGreen;
  CRGB color2 = CRGB::DarkGreen;
  CRGB color3 = CRGB::Yellow;
  CRGB color4 = CRGB::YellowGreen;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo200()
{
  CRGB color1 = CRGB::SteelBlue;
  CRGB color2 = CRGB::Azure;
  CRGB color3 = CRGB::DarkBlue;
  CRGB color4 = CRGB::Cyan;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo210()
{
  CRGB color1 = CRGB::DarkRed;
  CRGB color2 = CRGB::Maroon;
  CRGB color3 = CRGB::Crimson;
  CRGB color4 = CRGB::DarkSalmon;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo220()
{
  CRGB color1 = CHSV(319,249,230);
  CRGB color2 = CHSV(289,210,249);
  CRGB color3 = CHSV(267,255,249);
  CRGB color4 = CHSV(267,160,249);
  CRGB color5 = CRGB::Gold;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color5 );
}
void PaletteUpTo230()
{
  CRGB color1 = CRGB::GreenYellow;
  CRGB color2 = CRGB::DarkCyan;
  CRGB color3 = CRGB::Chartreuse;
  CRGB color4 = CRGB::DarkGreen;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
void PaletteUpTo240()
{
  CRGB color1 = CRGB::ForestGreen;
  CRGB color2 = CRGB::Aquamarine;
  CRGB color3 = CRGB::GreenYellow;
  CRGB color4 = CRGB::LightGreen;

  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4,
                     color1,  color1,  color3,  color3,
                     color2, color2, color4,  color4 );
}
