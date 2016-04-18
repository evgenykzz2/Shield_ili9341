#include "config.h"
#include "Shield_ili9341.h"

Shield_ili9341::Shield_ili9341()
{}

void Shield_ili9341::Init( uint8_t mode )
{
  //PinSetup
  pinMode(RESET, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(WR, OUTPUT);
  pinMode(RD, OUTPUT);
  for ( int i = 0; i < 8; ++i )
    pinMode(LCDpin[i], OUTPUT);
  digitalWrite( RD, HIGH );
  digitalWrite( WR, HIGH );
  digitalWrite( CS, LOW );

  ResetHw();
  ResetSw();

  SendCmd(0xB6);    // Display Function Control 
  SendData(0x08); 
  SendData(0x82);
  SendData(0x27);

  SendCmd(0x3A);  //Pixel Format 16bpp only
  SendData(0x55); //RGB
 
  SendCmd(0xC0);    //Power control 
  SendData(0x23);   // 4.6v 
  //SendData(0x03);   // 3.0v
  //SendData(0x2B);   // 5.0v
 
  SendCmd(0xC1);    //Power control 
  SendData(0x10);
 
  SendCmd(0xC5);    //VCM control 
  SendData(0x3e);   //4.2 v
  SendData(0x28); 
  SendCmd(0xC7);    //VCM control2 
  SendData(0x86);
  
  SendCmd(0x11);  //Sleep off
  delay(5);
  SendCmd(0x29);
  SendCmd(0x13);
  SendCmd(0x38);

  MemoryAccessControl( mode );
}

void Shield_ili9341::ResetHw()
{
  digitalWrite(RESET, LOW);
  delay(12);
  digitalWrite(RESET, HIGH);
  delay(12);
}

void Shield_ili9341::ResetSw()
{
  SendCmd(0x1);
  delay(120);
}

void Shield_ili9341::MemoryAccessControl( uint8_t mode )
{
  SendCmd(0x36);
  SendData(mode);
}

void Shield_ili9341::VerticalScrollingDefinition( uint16_t top_fixed, uint16_t v_scroll, uint16_t bot_fixed )
{
  SendCmd(0x33);
  SendData(top_fixed >> 8);
  SendData(top_fixed&0xFF);
  SendData(v_scroll >> 8);
  SendData(v_scroll&0xFF);
  SendData(bot_fixed >> 8);
  SendData(bot_fixed&0xFF);
}

void Shield_ili9341::VerticalScrollingStartAddress( uint16_t address )
{
  SendCmd(0x37);
  SendData(address >> 8);
  SendData(address & 0xFF);
}

void Shield_ili9341::PartialArea( uint16_t area_start, uint16_t area_end )
{
  SendCmd(0x30);
  SendData(area_start >> 8);
  SendData(area_start & 0xFF);
  SendData(area_end >> 8);
  SendData(area_end & 0xFF);
}

void Shield_ili9341::PartialMode()
{
  SendCmd(0x12);
}

void Shield_ili9341::NormalMode()
{
  SendCmd(0x13);
}

void Shield_ili9341::TearingEffectLineOn()
{
  SendCmd(0x35);
}

void Shield_ili9341::TearingEffectLineOff()
{
  SendCmd(0x34);
}

void Shield_ili9341::SendCmd( uint8_t cmd )
{
  TFT_CMD_MODE
  TFT_DATAPIN_SET(cmd);
  TFT_SWAP
}

void Shield_ili9341::SendData( uint8_t data )
{
  TFT_DATA_MODE
  TFT_DATAPIN_SET(data);
  TFT_SWAP
}

void Shield_ili9341::SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  SendCmd(0x2A);
  SendData(x0>>8);
  SendData(x0&0xFF);
  SendData(x1>>8);
  SendData(x1&0xFF);

  SendCmd(0x2B);
  SendData(y0>>8);
  SendData(y0);
  SendData(y1>>8);
  SendData(y1);
}

void Shield_ili9341::FillFast( uint8_t color8 )
{
  SetWindow(0, 0, TFT_WIDTH-1, TFT_HEIGHT-1);
  SendCmd(0x2c);
  TFT_DATA_MODE
  TFT_DATAPIN_SET(color8);
  for ( uint16_t w = 0; w < TFT_WIDTH/4; ++w )
  {
    for ( uint16_t h = 0; h < TFT_HEIGHT; ++h )
    {
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
    }
  }
}

void Shield_ili9341::Fill( uint16_t color )
{
  uint8_t h = color >> 8;
  uint8_t l = color & 0xFF;
  SetWindow(0, 0, TFT_WIDTH-1, TFT_HEIGHT-1);
  SendCmd(0x2c);
  TFT_DATA_MODE
  for ( uint16_t w = 0; w < TFT_WIDTH/2; ++w )
  {
    for ( uint16_t h = 0; h < TFT_HEIGHT; ++h )
    {
      TFT_DATAPIN_SET(h);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(l);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(l);
      TFT_SWAP_DATA_WR
    }
  }
}
