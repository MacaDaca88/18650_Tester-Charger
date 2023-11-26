#ifndef PINS_H
#define PINS_H


#ifdef __AVR__
#define BATT1 A0
#define BATT2 A1
#define BATT3 A2
#define BATT4 A3

#define DISCHARGE A7

#define LED 13

#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4


#define MOSI 9   // data
#define MISO 11  //dc
#define SCK 10   // clock
#define SS 12    // cs
#define RES 6    // res


#endif
#ifdef UNO
#warning "no A7 u dumb dumb"
#endif

#ifdef ESP32
#define BATT1 32
#define BATT2 33
#define BATT3 12
#define BATT4 14

#define DISCHARGE 13

#define LED 2

#define BUTTON1 15
#define BUTTON2 0
#define BUTTON3 4


#define RES 27    // res

#endif
#endif
