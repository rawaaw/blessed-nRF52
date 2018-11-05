beacon:

YJ-16002     connector
              pinout

right 2x9:               
VDD             1          +3.3v
GND             2          G
P0.11 LED0      4          *L-L*-|>|--|330|--> GND
P0.16 TX        7          Tx
P0.18 RX        9          Rx

P0.21 reset     14      --+--|10k|--> VDD
                          |
                          |   -|-
                          +--*   *--> GND

P0.14 SDA       5          SDA
P0.13 SCL       6          SCL

left 2x9:
P0.09 GPIO9     L1         GP9
P0.10 GPIO10    L2         GP10

                          st-link (1x6 connector)

SWDCLK          13         SWDCLK
SWDIO           16         SWDIO
GND                        G

2x5 connector:
+---+
|   |
*   * jumper
L   L

*   * ground
G   G

*   * uart
Rx  Tx

*   * i2c
SDA SCL

*   * gpio
GP9 GP10


1x6 connector:    +-----+
                  |     |
*     *     *     *     *
G  SWDIO SWDCLK  3.3v   BATT
                   jumper

==========================================================

receiver:

YJ-16002     connector     color
              pinout

VDD             1          while
GND             2          black
P0.12 GPIO0     3          grey    GPIO0
P0.11 LED0      4          violet --|>|--|330|--> GND
P0.14 GPIO1     5          blue    GPIO1
P0.13 GPIO2     6          green   GPIO2
P0.16 TX        7          yellow
P0.18 RX        9          red

P0.21 reset     14      --+--|10k|--> VDD
                          |
                          |   -|-
                          +--*   *--> GND

                          st-link

                           1st var  2d var

SWDCLK          13         violet  (yellow)
SWDIO           16         gray    (green)
GND                        black   (blue)
