#include "Arduino.h" 

#define TFT_WIDTH 320
#define TFT_HEIGHT 240

//#define TFT_WIDTH 480
//#define TFT_HEIGHT 320

#if defined(__AVR_ATmega328P__) // Arduino Uno

static const int LCDpin[8] = {8, 9, 2, 3, 4, 5, 6, 7};

#define RESET A4
#define CS A3
#define RS A2
#define WR A1
#define RD A0

#define TFT_SWAP_DATA_WR    PORTC = 1+4+16; PORTC = 1+2+4+16;
#define TFT_SWAP        PORTC &= ~2;PORTC |= 2;
#define TFT_SWAP_RD     PORTC &= ~1;PORTC |= 1;
#define TFT_CMD_MODE    PORTC &= ~4;
#define TFT_DATA_MODE    PORTC |= 4;
#define TFT_DATAPIN_SET(v) PORTD=v&0xFC;PORTB=v&3;

#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // Mega 1280 & 2560

static const int LCDpin[8] = {22, 23, 24, 25, 26, 27, 28, 29};

#define RESET 33
#define CS 34
#define RS 35
#define WR 36
#define RD 37

#define TFT_SWAP_DATA_WR    PORTC = 1+4+16; PORTC = 1+2+4+16;
#define TFT_SWAP        PORTC &= ~2; PORTC |= 2;
#define TFT_CMD_MODE    PORTC &= ~4;
#define TFT_DATA_MODE    PORTC |= 4;
#define TFT_DATAPIN_SET(v) PORTA=v;

// RD WR RS CS RST
// 1  0  1  0  1

#elif defined(__SAM3X8E__)  //due

static const int LCDpin[8] = {25, 26, 27, 28, 14, 15, 29, 11};

#define RESET 33
#define CS 34
#define RS 35
#define WR 36
#define RD 37

// RESET CS RS WR   RD
//  2    4   8  16  32

#define TFT_SWAP_DATA_WR    REG_PIOC_ODSR = 32+8+2; REG_PIOC_ODSR = 32+8+2+16;
//#define TFT_SWAP_DATA_WR        REG_PIOC_ODSR &= ~16; REG_PIOC_ODSR |= 16;
#define TFT_SWAP        REG_PIOC_ODSR &= ~16; REG_PIOC_ODSR |= 16;
#define TFT_CMD_MODE    REG_PIOC_ODSR &= ~8;
#define TFT_DATA_MODE    REG_PIOC_ODSR |= 8;
#define TFT_DATAPIN_SET(v) REG_PIOD_ODSR = v;

#endif
