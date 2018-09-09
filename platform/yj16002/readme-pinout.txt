YJ-16002   connector     color
            pinout

VDD           1          while
GND           2          black
P0.12 LED1    3          grey     LED
P0.11 LED0    4          violet --|>|--|330|--> GND
P0.14 BUTT1   5          blue
P0.13 BUTT0   6          green
P0.16 TX      7          yellow
P0.15 RTS     8          orange
P0.18 RX      9          red
P0.17 CTS     10         brown

P0.21 reset   14      --+--|10k|--> VDD 
                        |
                        |   -|-
                        +--*   *--> GND


                         st-link

SWDCLK        13         yellow
SWDIO         16         green
GND                      blue
