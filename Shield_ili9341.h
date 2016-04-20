#pragma once
#include <stdint.h>
#include <avr/pgmspace.h>

struct glyph_param
{
    uint16_t offset;
    uint8_t width;
    uint8_t height;
    int8_t posx;
    int8_t posy;
    int8_t stepx;
};

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
  int16_t m_tft_width;
  int16_t m_tft_height;
  int16_t m_width;
  int16_t m_height;

  void DrawHLine_safe( int16_t x0, int16_t y0, int16_t x1, uint16_t color );
  void DrawHLine_unsafe( int16_t x0, int16_t y0, int16_t x1, uint16_t color );

  void DrawLine_safe( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color );
  void DrawLine_unsafe( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color );

  void DrawCircle_safe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color );
  void DrawCircle_unsafe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color );

  void DrawCircleFill_safe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color );
  void DrawCircleFill_unsafe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color );

public:
  Shield_ili9341();
  void Init( int16_t tft_width, int16_t tft_height, uint8_t mode );
  int16_t Width() const;
  int16_t Height() const;

  void ResetHw();
  void ResetSw();

  void SetWindow( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 );
  void SetColumn( uint16_t x0, uint16_t x1 );
  void SetPage( uint16_t y0, uint16_t y1 ); 
  void VerticalScrollingDefinition( uint16_t top_fixed, uint16_t v_scroll, uint16_t bot_fixed );
  void VerticalScrollingStartAddress( uint16_t address );
  void PartialArea( uint16_t area_start, uint16_t area_end );
  void PartialMode();
  void NormalMode();
  void TearingEffectLineOn();
  void TearingEffectLineOff();
  void MemoryAccessControl( uint8_t mode );

  static uint16_t RGB16( uint8_t r, uint8_t g, uint8_t b );

  void FillFast( uint8_t color8 );
  void Fill( uint16_t color );

  //void DrawRectFast( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color8 );
  void DrawRect( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color );

  void DrawPixelFast( int16_t x, int16_t y, uint8_t color8 );
  void DrawPixel( int16_t x, int16_t y, uint16_t color );
  void DrawPixel_unsafe( int16_t x, int16_t y, uint16_t color );

  void DrawHLine( int16_t x0, int16_t y0, int16_t x1, uint16_t color );
  void DrawLine( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color );
  void DrawCircle( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color );
  void DrawCircleFill( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color );

  void StreamStart();
  void StreamPixel( uint16_t color );
  void StreamPixel8( uint8_t color8 );
  void StreamPixels( uint16_t color, uint16_t count );
  void StreamPixels8( uint8_t color8, uint16_t count );

  void DrawText( const String& str, int16_t x, int16_t y, uint16_t color, const PROGMEM uint8_t* font_data, const PROGMEM glyph_param* font_info );
};
