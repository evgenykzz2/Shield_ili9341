#pragma once
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

#define TFT_SWAP_FAST_PREPARE
#define TFT_SWAP_FAST           TFT_SWAP_DATA_WR

#define TOUCH_YP A1
#define TOUCH_XM A2
#define TOUCH_YM 7
#define TOUCH_XP 6
#define TOUCH_CONFICT

#define TOUCH_ENABLED

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

#define TFT_SWAP_FAST_PREPARE
#define TFT_SWAP_FAST           TFT_SWAP_DATA_WR

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

#define TFT_SWAP_FAST_PREPARE
#define TFT_SWAP_FAST           TFT_SWAP_DATA_WR

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

#define TFT_SWAP_FAST_PREPARE
#define TFT_SWAP_FAST           TFT_SWAP_DATA_WR

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

// TODO !!
//REG_PIOC_SODR   Set Output Data Register
//REG_PIOC_CODR   Clear Output Data Register
//REG_PIOC_ODSR   Output Data Status Register

#define TFT_SWAP            REG_PIOC_CODR = 16; REG_PIOC_SODR = 16;
#define TFT_CMD_MODE        REG_PIOC_CODR = 8;
#define TFT_DATA_MODE       REG_PIOC_SODR = 8;
//Fast most 75fps
//#define TFT_DATAPIN_SET(v)  REG_PIOD_ODSR = v;
//Strict 55fps
#define TFT_DATAPIN_SET(v)  REG_PIOD_CODR = (uint8_t)(~(v)); REG_PIOD_SODR = (uint8_t)(v);
//Slow & Strict 35fps
//#define TFT_DATAPIN_SET(v)  REG_PIOD_ODSR = (REG_PIOD_ODSR & 0xFFFFFF00) | v;

#define TFT_SWAP_DATA_WR    TFT_DATA_MODE TFT_SWAP
#define TFT_SWAP_CMD_WR     TFT_CMD_MODE  TFT_SWAP

#define TFT_SWAP_FAST_PREPARE   TFT_DATA_MODE
#define TFT_SWAP_FAST           TFT_SWAP

#elif defined(ESP8266)

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {0, 1, 2, 3, 4, 5, 12, 13};


//RESET ->4.7k-> VCC
//CS    ->4.7k-> GND
#define RS 14
#define WR 15
//RD    ->4.7k-> VCC

#define TFT_SWAP          GPOC = 1 << WR; GPOS = 1 << WR;
#define TFT_CMD_MODE      GPOC = 1 << RS;
#define TFT_DATA_MODE     GPOS = 1 << RS;

#define TFT_SWAP_DATA_WR  TFT_DATA_MODE TFT_SWAP
#define TFT_SWAP_CMD_WR   TFT_CMD_MODE  TFT_SWAP

//Has no effect
//#define TFT_DIRECT_GPIO_REG(v)   uint32_t GPIO_SET_##v   = (v&0x3F) | ((v&0xC0) << 6); uint32_t GPIO_CLEAR_##v = ( (~v) &0x3F) | (( (~v)&0xC0) << 6);
//#define TFT_DIRECT_DATAPIN(v)   GPOS = GPIO_SET_##v; GPOC = GPIO_CLEAR_##v;

#define TFT_DATAPIN_SET(v) GPOS = (v&0x3F) | ((v&0xC0) << 6); GPOC = ( (~v) &0x3F) | (( (~v)&0xC0) << 6);

#define TFT_SWAP_FAST_PREPARE   TFT_DATA_MODE
#define TFT_SWAP_FAST           TFT_SWAP

#elif defined(ARDUINO_ARCH_ESP32)

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {12, 13, 14, 15, 16, 17, 18, 19};

#define RESET 21
#define CS 22
#define RS 23
#define WR 4
#define RD 5

#define TFT_SWAP            GPIO.out_w1tc |= ((uint32_t)1 << WR); GPIO.out_w1ts = ((uint32_t)1 << WR);
#define TFT_SWAP_RD         GPIO.out_w1tc |= ((uint32_t)1 << RD); GPIO.out_w1ts = ((uint32_t)1 << RD);
#define TFT_CMD_MODE        GPIO.out_w1tc |= ((uint32_t)1 << RS);
#define TFT_DATA_MODE       GPIO.out_w1ts |= ((uint32_t)1 << RS);
#define TFT_SWAP_DATA_WR    TFT_DATA_MODE TFT_SWAP
#define TFT_SWAP_CMD_WR     TFT_CMD_MODE TFT_SWAP

#define TFT_DATAPIN_SET(v) GPIO.out_w1tc = ((uint32_t)((~v) & 0xFF) << 12); GPIO.out_w1ts = (((uint32_t)v) << 12);

#define TFT_SWAP_FAST_PREPARE   TFT_DATA_MODE
#define TFT_SWAP_FAST           GPIO.out_w1tc  = ((uint32_t)1 << WR); GPIO.out_w1ts = ((uint32_t)1 << WR);

#elif defined(__STM32F1__)

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7};

#define RESET PB3
#define CS    PB4
#define RS    PB5
#define WR    PB6
#define RD    PB7

#define TFT_SWAP            GPIOB->regs->BSRR = (uint32_t)1U << (6+16); GPIOB->regs->BSRR = (uint32_t)1U << 6;
#define TFT_SWAP_RD         GPIOB->regs->BSRR = (uint32_t)1U << (7+16); GPIOB->regs->BSRR = (uint32_t)1U << 7;
#define TFT_CMD_MODE        GPIOB->regs->BSRR = (uint32_t)1U << (5+16);
#define TFT_DATA_MODE       GPIOB->regs->BSRR = (uint32_t)1U << 5;
#define TFT_DATAPIN_SET(v)  GPIOA->regs->BSRR = ((uint32_t)(v)) | ( (uint32_t)((~(v)) & 0xFF) << (16) );

#define TFT_SWAP_DATA_WR    TFT_DATA_MODE  TFT_SWAP
#define TFT_SWAP_CMD_WR     TFT_CMD_MODE   TFT_SWAP

#define TFT_SWAP_FAST_PREPARE    TFT_DATA_MODE
#define TFT_SWAP_FAST            TFT_SWAP

#elif defined(__SAMD21G18A__) 

#define TFT_PIN_COUNT 8
static const int LCDpin[TFT_PIN_COUNT] = {8, 9, 2, 3, 4, 5, 6, 7};

#define RESET A4
#define CS A3
#define RS A2
#define WR A1
#define RD A0

#define TFT_SWAP            PORT->Group[1].OUTCLR.reg = 1<<8; PORT->Group[1].OUTSET.reg = 1 << 8;
#define TFT_CMD_MODE        PORT->Group[1].OUTCLR.reg = 1<<9;
#define TFT_DATA_MODE       PORT->Group[1].OUTSET.reg = 1<<9;

//0  1  2  3  4  5  6  7
//6  7  8  9  14 15 20 21
//1  2  4  8  16 32 64 128

//6 7 14 9 8  15 20 21 ???

//#define TFT_DATAPIN_SET(v)  for ( uint8_t __n__ = 0; __n__ < 8; ++__n__ ) { if ((uint8_t)(v&(1<<__n__))) digitalWrite(LCDpin[__n__], HIGH); else digitalWrite(LCDpin[__n__], LOW); };
#define TFT_DATAPIN_SET(v)  \
    PORT->Group[0].OUTCLR.reg = (((~v)&(1+2+4+8))<<6) | (((~v)&(16+32))<<10) | (((~v)&(64+128))<<14); \
    PORT->Group[0].OUTSET.reg = ((v&(1+2+4+8))<<6)    | ((v&(16+32))<<10)    | ((v&(64+128))<<14);

#define TFT_SWAP_DATA_WR    TFT_DATA_MODE TFT_SWAP
#define TFT_SWAP_CMD_WR     TFT_CMD_MODE  TFT_SWAP

#define TFT_SWAP_FAST_PREPARE   TFT_DATA_MODE
#define TFT_SWAP_FAST           TFT_SWAP

#endif