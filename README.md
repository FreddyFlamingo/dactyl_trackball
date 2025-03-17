# Dactyl Trackball

A customized split ergonomic keyboard based on mjohns Dactyl CC with integrated trackball functionality using the PWM3389 sensor and RP2040-based controllers.

![Dactyl trackball](https://i.imgur.com/ebR42UL.jpeg)

## Overview

This project modifies the original Dactyl CC design to integrate a 34mm trackball, allowing for cursor control without moving your hands from the keyboard. The design uses Pi Pico microcontrollers and the PWM3389 sensor for accurate trackball motion tracking.

### Features

* Split ergonomic design based on Dactyl CC
* 34mm trackball for cursor control
* RP2040-based controllers (Pi Pico)
* PWM3389 optical sensor for tracking
* QMK firmware with custom keymaps and trackball functionality
* Home row mods
* Multiple layers for different use cases (base, mod, mouse, calculator, code, etc.)

```
+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
|  ESC   |   1    |   2    |   3    |   4    |   5    |                          |   6    |   7    |   8    |   9    |   0    |  MINS  |
+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
|  TAB   |   Q    |   W    |   E    |   R    |   T    |                          |   Y    |   U    |   I    |   O    |   P    |  LBRC  |
+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
|  CAPS  |   A    |   S    |   D    |   F    |   G    |                          |   H    |   J    |   K    |   L    |  SCLN  |  QUOT  |
+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
|  LSFT  |   Z    |   X    |   C    |   V    |   B    |                          |   N    |   M    |  COMM  |  DOT   |  SLSH  |  RSFT  |
+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
         |  EQL   | NUBSS  |TO(CALC)|TO(PROG)|                                            |TO(NORM)|TO(CODE)|  NUHS  |  RBRC  |
         +--------+--------+--------+--------+                                            +--------+--------+--------+--------+

                                             +--------+--------+        +--------+--------+
                                             |  LCTL  |  LALT  |        |  RALT  |  RCTL  |
                                    +--------+--------+--------+        +--------+--------+--------+
                                    |        |        |  HOME  |        |  PGUP  |        |        |
                                    |  BSPC  |  DEL   +--------+        +--------+  ENT   |  SPC   |
                                    |        |        |  END   |        |  PGDN  |        |        |
                                    +--------+--------+--------+        +--------+--------+--------+
```

## Hardware Requirements

### Components

* 2× Raspberry Pi Pico microcontrollers
* PWM3389 trackball sensor (available on Tindie)
* 34mm trackball
* 3× roller bearings (3×6×2.5mm)
* 3× M3×6mm pins/dowels for roller bearings
* 2× 2.5/3.5mm TRRS jacks (PJ-320A recommended)
* TRRS cable for split communication
* 2× M2.5 screws and thread inserts for the motion sensor
* Diodes (1N4148)
* 26 AWG wire
* and more...

## Wiring Guide

The keyboard uses a standard matrix wiring approach with diodes. The trackball sensor connects to the controller via SPI. See the top left corner of the first picture below.

![Wire picture](https://i.imgur.com/fAKTb3D_d.webp?maxwidth=760&fidelity=grand)
![Wires](https://i.imgur.com/S0rAHqz.jpeg)
![More wires](https://i.imgur.com/YsM7Rai.jpeg)
![Mcu](https://i.imgur.com/yIDgMUQ.jpeg)

## Build Process

I used [ntarocco's guide](https://github.com/ntarocco/dactyl-cc) as a base for the build, along with this [build log](https://medium.com/@kincade/track-beast-build-log-a-trackball-dactyl-manuform-19eaa0880222) of a trackball-integrated Dactyl Manuform.

### Case Modifications

I modified mjohns' original [Dactyl_CC](https://github.com/mjohns/dactyl-cc) STL files to:

1. Add a trackball holder to accommodate the 34mm ball
2. Edit the MCU holder to fit the Pi Pico controllers

### Lessons Learned and Recommendations

If you're building this keyboard, consider these recommendations:

- **Add protection for the motion controller**: The current design has the PWM3389 sensor exposed. Consider designing a cover or case for it.

- **Test all connections thoroughly before assembly**: Due to the tight space constraints with the Pi Pico, it's very difficult to fix wiring issues after assembly. The controller is quite long, requiring 90-degree bends in the wiring at solder points to fit inside the case.

## Components and Sourcing

I sourced components from various places:

- Most general components from Amazon and AliExpress
- PWM3389 trackball sensor from Tindie
- 34mm trackball from a variety of sources (suitable billiard balls or trackball replacements work well)

### Credits

- [mjohns](https://github.com/mjohns) for the original Dactyl CC design
- [ntarocco](https://github.com/ntarocco) for the build guide
- Kincade for the trackball integration inspiration
- [QMK Firmware](https://github.com/qmk/qmk_firmware) team for the keyboard firmware
