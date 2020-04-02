# Explorations using Arduino IDE with ESP8266

## Blink

A copy of the Blink example. Used to get the IDE and device configured

## epd_badge

Using the e-Paper ESP8266 Driver from Waveshare and the [GxEDP2](https://www.arduinolibraries.info/libraries/gx-epd2) library from [ZinggJM](https://github.com/ZinggJM/GxEPD2) to write some text to a 2.7inch e-Paper screen from Waveshare.

This was created mainly my grabbing bits from the exmaples in the GxEPD2 source. This was fairly straight forward.


# Waveshare Loader Demo application

The Loader demo is part of the Waveshare demo code for the [E-Paper ESP8266 Driver Board](https://www.waveshare.com/wiki/E-Paper_ESP8266_Driver_Board).

It is found if the demo code archive at "`../E-Paper_ESP8266_Driver_Board_Code/Loader`".


**Getting the waveshare demo (image loader) to work**

* Do not use 5G WiFi

* Change the IP address to something served by the local router (mine does not use `192.168.x.x`):
  ```
  IP4_ADDR(&info.ip, 10,10,1,180);
  IP4_ADDR(&info.gw, 10,10,1,1);
  ```

After that (and the Python fix below), the loader worked well enough. It only does images, but does those reasonably well.


# Arduino ESP8266 Fixes

**Get esp8266 package to find python3 (setup using pyenv global)**

```
which python3
--> /Users/butch.howard/.pyenv/shims/python3
cd  ~/Library/Arduino15/packages/esp8266/tools/python3/3.7.2-post1/
rm ./python3
ln -s /Users/butch.howard/.pyenv/shims/python3 python3
```
