#include "Arduino.h" 

#if defined(__AVR_ATmega328P__) // Arduino Uno

//generic china UNO shield
#if 1

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {8, 9, 2, 3, 4, 5, 6, 7};

#define RESET A4
#define CS A3
#define RS A2
#define WR A1
#define RD A0

#define TFT_SWAP_DATA_WR    PORTC = 1+4+16; PORTC = 1+2+4+16;
#define TFT_SWAP_CMD_WR     PORTC = 1+16; PORTC = 1+2+16;
#define TFT_SWAP            PORTC &= ~2;PORTC |= 2;
#define TFT_SWAP_RD         PORTC &= ~1;PORTC |= 1;
#define TFT_CMD_MODE        PORTC &= ~4;
#define TFT_DATA_MODE       PORTC |= 4;
#define TFT_DATAPIN_SET(v)  PORTD=v&0xFC;PORTB=v&3;
#define TFT_DATAPIN_LO_HI
#define TFT_DATAPIN_SET_LO(v)  PORTB=v&3;
#define TFT_DATAPIN_SET_HI(v)  PORTD=v&0xFC;

#define TOUCH_YP A1
#define TOUCH_XM A2
#define TOUCH_YM 7
#define TOUCH_XP 6
#define TOUCH_CONFICT

#else

//Hacked UNO/nano shield
#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7};

#define RESET 12
#define CS 11
#define RS 10
#define WR 9
#define RD 8

// RD WR RS CS RST
// 0  1  2  3  4
// 1  2  4  8 16

#define TFT_SWAP_DATA_WR    PORTB = 1+4+16; PORTB = 1+2+4+16;
#define TFT_SWAP_CMD_WR     PORTB = 1+16; PORTB = 1+2+16;
#define TFT_SWAP            PORTB &= ~2;PORTB |= 2;
#define TFT_SWAP_RD         PORTB &= ~1;PORTB |= 1;
#define TFT_CMD_MODE        PORTB &= ~4;
#define TFT_DATA_MODE       PORTB |= 4;
#define TFT_DATAPIN_SET(v)  PORTD=v;

#endif

#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // Mega 1280 & 2560

#if 0

#define TFT_PIN_COUNT 16
//                                        0   1   2   3   4   5   6   7      8  9   10  11  12  13  14  15
//                                                     PC                           PA
static const int LCDpin[TFT_PIN_COUNT] = {37, 36, 35, 34, 33, 32, 31, 30,   22, 23, 24, 25, 26, 27, 28, 29};

#define RESET 41
#define CS 40
#define RS 38
#define WR 39
#define RD 42

#define TFT_SWAP_DATA_WR    PORTG = 1; PORTG = 1+4;
#define TFT_SWAP_CMD_WR     PORTG = 1; PORTG = 1+4;
#define TFT_SWAP            PORTG &= ~4; PORTG |= 4;
#define TFT_CMD_MODE        PORTD &= ~128;
#define TFT_DATA_MODE       PORTD |= 128;
#define TFT_DATAPIN_SET(v)  PORTA=v;

// RD  WR RS  CS RST
// L7  G2 D7  G1 G0
// 128 4  128 2  1


#else

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {22, 23, 24, 25, 26, 27, 28, 29};

#define RESET 33
#define CS 34
#define RS 35
#define WR 36
#define RD 37

#define TFT_SWAP_DATA_WR    PORTC = 1+4+16; PORTC = 1+2+4+16;
#define TFT_SWAP_CMD_WR     PORTC = 1+16; PORTC = 1+2+16;
#define TFT_SWAP            PORTC &= ~2; PORTC |= 2;
#define TFT_CMD_MODE        PORTC &= ~4;
#define TFT_DATA_MODE       PORTC |= 4;
#define TFT_DATAPIN_SET(v)  PORTA=v;

// RD WR RS CS RST
// 1  0  1  0  1
// 1  2  4  8  16

#endif

#elif defined(__SAM3X8E__)  //due

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {25, 26, 27, 28, 14, 15, 29, 11};

#define RESET 33
#define CS 34
#define RS 35
#define WR 36
#define RD 37

// RESET CS RS WR   RD
//  2    4   8  16  32

#define TFT_SWAP_DATA_WR    REG_PIOC_ODSR = 32+8+2; REG_PIOC_ODSR = 32+8+2+16;
#define TFT_SWAP_CMD_WR     REG_PIOC_ODSR = 32+2; REG_PIOC_ODSR = 32+2+16;
#define TFT_SWAP            REG_PIOC_ODSR &= ~16; REG_PIOC_ODSR |= 16;
#define TFT_CMD_MODE        REG_PIOC_ODSR &= ~8;
#define TFT_DATA_MODE       REG_PIOC_ODSR |= 8;
#define TFT_DATAPIN_SET(v)  REG_PIOD_ODSR = v;

#elif defined(ESP8266)

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {D3, D10, D4, D9, D2, D1, D6, D7};

#define RESET D0
#define CS D0
#define RS D5
#define WR D8
#define RD D0

// RESET CS RS     WR    RD
//           4000  8000

//FIX me
#define TFT_SWAP_DATA_WR  GPO &= ~0x8000; GPO |= 0x8000;
#define TFT_SWAP_CMD_WR   GPO &= ~0x8000; GPO |= 0x8000;
#define TFT_SWAP          GPO &= ~0x8000; GPO |= 0x8000;
#define TFT_CMD_MODE      GPO &= ~0x4000;
#define TFT_DATA_MODE     GPO |= 0x4000;

#define TFT_DATAPIN_SET(v) GPO = (GPO&0xFFFFCFC0) | ( v&0x3F) | ((v&0xC0) << 6);

#endif
