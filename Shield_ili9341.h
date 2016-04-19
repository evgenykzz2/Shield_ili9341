#pragma once
#include <stdint.h>

class Shield_ili9341
{
  void SendCmd( uint8_t cmd );
  void SendData( uint8_t data );
public:
    enum EMemoryAccessControl
    {
        MemoryAccessControl_Rotate = 32,
        MemoryAccessControl_FlipX = 128,
        MemoryAccessControl_FlipY = 64
    };

    enum EColor8
    {
        Color8_Black = 0,
        Color8_White = 0xFF,
        Color8_Green = 7,
        Color8_Blue = 192,
        Color8_Red = 24,
        Color8_Yellow = 63,
        Color8_Magenta = 184,
        Color8_Cyan = 231
    };

    enum EColor
    {
        Color_Black = 0x0000,
        Color_White = 0xFFFF,
        Color_Green = 0x07E0,
        Color_Blue = 0x001F,
        Color_Red = 0xF800,
        Color_Yellow = 0xFFE0,
        Color_Magenta = 0xF81F,
        Color_Cyan = 0x07FF
    };

private:
  uint8_t m_mode;
public:
  Shield_ili9341();
  void Init( uint8_t mode );
  void ResetHw();
  void ResetSw();

  void SetWindow( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 );
  void VerticalScrollingDefinition( uint16_t top_fixed, uint16_t v_scroll, uint16_t bot_fixed );
  void VerticalScrollingStartAddress( uint16_t address );
  void PartialArea( uint16_t area_start, uint16_t area_end );
  void PartialMode();
  void NormalMode();
  void TearingEffectLineOn();
  void TearingEffectLineOff();
  void MemoryAccessControl( uint8_t mode );

  void FillFast( uint8_t color8 );
  void Fill( uint16_t color );

  void DrawRectFast( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t color8 );
  void DrawRect( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color );

  void DrawPixelFast( uint16_t x, uint16_t y, uint8_t color8 );
  void DrawPixel( uint16_t x, uint16_t y, uint16_t color );
};
