YJ-16002     connector     color
              pinout

VDD             1          while
GND             2          black
P0.12 GPIO0     3          grey    GPIO0
P0.11 LED0      4          violet --|>|--|330|--> GND
P0.14 GPIO1     5          blue    GPIO1
P0.13 GPIO2     6          green   GPIO2
P0.16 TX        7          yellow
P0.15 RTS       8          orange
P0.18 RX        9          red
P0.17 CTS       10         brown

P0.21 reset     14      --+--|10k|--> VDD
                          |
                          |   -|-
                          +--*   *--> GND

P0.20 SDA/GPIO3 11                 GPIO3
P0.19 SCL/GPIO4 12                 GPIO4

// low power / low frequency (see 20.2 GPIO located near the RADIO in the nRF52832 Product Specification v1.4)
P0.24 GPIO5     17                 GPIO5
P0.23 GPIO6     18                 GPIO6

                          st-link

                           1st var  2d var

SWDCLK          13         violet  (yellow)
SWDIO           16         gray    (green)
GND                        black   (blue)
