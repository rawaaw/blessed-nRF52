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

LCD            yj16002  nRF    14 pin connector
                board
1  GND    GND                      1  black 
2  VCC    +5v                      2  white 
3  SCK    GPIO1   8    P0.15       4  brown 
4  SDA    GPIO2   6    P0.13       5  red   
5  RES    GPIO4   5    P0.14       6  orange
6  RS(DC) GPIO3   4    P0.11       9  yellow
7  CS     GPIO0   3    P0.12       10 green 
8  LEDA   +3.3v                    11 gray  

          GND                      12 black
       BUTTON RST 14   P0.21       13 white
       BUTTON 1   L1   P0.09       14 grey
       BUTTON 2   L2   P0.10       15 violet
          


P0.21 reset     14      --+--|10k|--> VDD
                          |
                          |   -|-
                          +--*   *--> GND
                           BUTTON RST

                                8 pin connector

GND                                1
SWDIO            16                2
SWDCLK           13                3
+3.3v            N/A               4
Rx               9    P0.18        5
Tx               7    P0.16        6
GND                                7
GND                                8

