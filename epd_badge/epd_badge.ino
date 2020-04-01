
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>

GxEPD2_BW<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16));

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  delay(100);
  display.init(115200);

  nameTag();
  
  delay(1000);
  Serial.println("setup done");
}

void loop()
{
}

const char butchHoward[] = "Butch Howard";
const char notInigo[] = "(Not Inigo Montoya)";

void writeName()
{
  display.setFont(&FreeMonoBold18pt7b);
  int16_t tbxName, tbyName; 
  uint16_t tbwName, tbhName;
  display.getTextBounds(butchHoward, 0, 0, &tbxName, &tbyName, &tbwName, &tbhName);
  uint16_t xName = ((display.width() - tbwName) / 2) - tbxName;
  uint16_t yName = ((display.height() - tbhName) / 2) - tbhName - tbhName;
  display.setCursor(xName, yName);
  display.print(butchHoward);


  display.setFont(&FreeMonoBold9pt7b);
  int16_t tbxInigo, tbyInigo; 
  uint16_t tbwInigo, tbhInigo;
  display.getTextBounds(notInigo, 0, 0, &tbxInigo, &tbyInigo, &tbwInigo, &tbhInigo);
  uint16_t xInigo = ((display.width() - tbwInigo) / 2) - tbxInigo;
  uint16_t yInigo = yName + tbhName + 4;
  display.setCursor(xInigo, yInigo);
  display.print(notInigo);
}


const char socialVegan[] = "Social Vegan";
const char avoidsMeet[] = "(Avoids MEET)";

void writeTitle()
{
  display.setFont(&FreeMonoBold18pt7b);
  int16_t tbxName, tbyName; 
  uint16_t tbwName, tbhName;
  display.getTextBounds(socialVegan, 0, 0, &tbxName, &tbyName, &tbwName, &tbhName);
  uint16_t xName = ((display.width() - tbwName) / 2) - tbxName;
  uint16_t yName = ((display.height() - tbhName) / 2) + tbhName + tbhName;
  display.setCursor(xName, yName);
  display.print(socialVegan);

  display.setFont(&FreeMonoBold9pt7b);
  int16_t tbxTag, tbyTag; 
  uint16_t tbwTag, tbhTag;
  display.getTextBounds(avoidsMeet, 0, 0, &tbxTag, &tbyTag, &tbwTag, &tbhTag);
  uint16_t xTag = ((display.width() - tbwTag) / 2) - tbxTag;
  uint16_t yTag = yName + tbhName + 4;
  display.setCursor(xTag, yTag);
  display.print(avoidsMeet);
}


void nameTag()
{
  display.setFullWindow();
  display.setRotation(1);
  display.setTextColor(GxEPD_BLACK);
  display.fillScreen(GxEPD_WHITE);

  writeName();
  display.drawLine(0, display.height()/2, display.width(), display.height()/2, GxEPD_BLACK);
  writeTitle();

  display.display();
}
