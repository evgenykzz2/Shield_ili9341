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
        Color8_Green = 71,
        Color8_Blue = 24,
        Color8_Red = 224
    };
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
};
