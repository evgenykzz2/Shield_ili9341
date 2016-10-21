#include "config.h"
#include "Shield_ili9341.h"

Shield_ili9341::Shield_ili9341() : m_mode(0), m_tft_width(0), m_tft_height(0), m_width(0), m_height(0)
{}

int16_t Shield_ili9341::Width() const
{
    return m_width;
}

int16_t Shield_ili9341::Height() const
{
    return m_height;
}

void Shield_ili9341::Init( int16_t tft_width, int16_t tft_height, uint8_t mode )
{
  m_tft_width = tft_width;
  m_tft_height = tft_height;

  //PinSetup
  pinMode(RESET, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(WR, OUTPUT);
  pinMode(RD, OUTPUT);
  for ( int i = 0; i < TFT_PIN_COUNT; ++i )
    pinMode(LCDpin[i], OUTPUT);
  digitalWrite( RD, HIGH );
  digitalWrite( WR, HIGH );
  digitalWrite( CS, LOW );

  ResetHw();
  ResetSw();

  /*SendCmd(0xB6);    // Display Function Control 
  SendData(0x08); 
  SendData(0x82);
  SendData(0x27);*/

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

  MemoryAccessControl( 8 + mode );
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
  m_mode = mode;
  if ( uint8_t(m_mode & MemoryAccessControl_Rotate) != 0 )
  {
      m_width = m_tft_width;
      m_height = m_tft_height;
  } else
  {
      m_height = m_tft_width;
      m_width = m_tft_height;
  }

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
  TFT_DATAPIN_SET(cmd);
  TFT_SWAP_CMD_WR
}

void Shield_ili9341::SendData( uint8_t data )
{
  TFT_DATAPIN_SET(data);
  TFT_SWAP_DATA_WR
}

void Shield_ili9341::SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  SendCmd(0x2A);
  TFT_DATAPIN_SET(x0>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(x0&0xFF);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(x1>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(x1&0xFF);
  TFT_SWAP_DATA_WR

  SendCmd(0x2B);
  TFT_DATAPIN_SET(y0>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(y0&0xFF);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(y1>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(y1&0xFF);
  TFT_SWAP_DATA_WR
}

void Shield_ili9341::SetColumn( uint16_t x0, uint16_t x1 )
{
  SendCmd(0x2A);
  TFT_DATAPIN_SET(x0>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(x0&0xFF);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(x1>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(x1&0xFF);
  TFT_SWAP_DATA_WR
}

void Shield_ili9341::SetPage( uint16_t y0, uint16_t y1 )
{
  SendCmd(0x2B);
  TFT_DATAPIN_SET(y0>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(y0&0xFF);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(y1>>8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(y1&0xFF);
  TFT_SWAP_DATA_WR
}

uint16_t Shield_ili9341::RGB16( uint8_t r, uint8_t g, uint8_t b )
{
    return ( (((r&0xF8)|(g>>5)) << 8) | ((g<<5)&0xE0) | (b>>3) );
}

void Shield_ili9341::FillFast( uint8_t color8 )
{
  SetWindow(0, 0, m_width-1, m_height-1);
  SendCmd(0x2c);
  TFT_DATAPIN_SET(color8);
  uint16_t sq = ( int32_t(m_width)*int32_t(m_height)/16 );
  for ( uint16_t i = 0; i < sq; ++i )
  {
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR

      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR

      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR

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

void Shield_ili9341::Fill( uint16_t color )
{
  uint8_t hi = color >> 8;
  uint8_t lo = color & 0xFF;
  if ( lo == hi )
  {
      FillFast(lo);
      return;
  }
  SetWindow(0, 0, m_width-1, m_height-1);
  SendCmd(0x2c);
  uint16_t sq = ( int32_t(m_width)*int32_t(m_height)/8 );
  for ( uint16_t i = 0; i < sq; ++i )
  {
      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR

      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR

      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR

      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR
  }
}

void Shield_ili9341::DrawRectFast( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color8 )
{
  if (x0>x1) { int16_t t=x0; x0=x1; x1=t; }
  if (y0>y1) { int16_t t=y0; y0=y1; y1=t; }
  if ( y1 < 0 || x1 < 0 || x0 >= m_width || y0 >= m_height )
      return;
  if (x0<0) x0=0;
  if (y0<0) y0=0;
  if (x1>=m_width)  x1=m_width-1;
  if (y1>=m_height) y1=m_height-1;
  SetWindow(x0, y0, x1, y1);
  SendCmd(0x2c);
  TFT_DATAPIN_SET(color8);
  uint16_t sq = ( int32_t(y1-y0+1)*int32_t(x1-x0+1) );
  StreamPixels8( color8, sq );
}

void Shield_ili9341::DrawRect( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color )
{
  if (x0>x1) { int16_t t=x0; x0=x1; x1=t; }
  if (y0>y1) { int16_t t=y0; y0=y1; y1=t; }
  if ( y1 < 0 || x1 < 0 || x0 >= m_width || y0 >= m_height )
      return;
  if (x0<0) x0=0;
  if (y0<0) y0=0;
  if (x1>=m_width)  x1=m_width-1;
  if (y1>=m_height) y1=m_height-1;
  SetWindow(x0, y0, x1, y1);
  uint8_t hi = color >> 8;
  uint8_t lo = color & 0xFF;
  SendCmd(0x2c);
  for ( uint16_t w = y0; w <= y1; ++w )
  {
    for ( uint16_t h = x0; h <= x1; ++h )
    {
      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR
    }
  }
}

void Shield_ili9341::DrawPixelFast( int16_t x, int16_t y, uint8_t color8 )
{
  if ( x < 0 || y < 0 || x >= m_width || y >= m_height )
    return;
  SetWindow(x, y, x, y);
  TFT_DATAPIN_SET(0x2C);
  TFT_SWAP_CMD_WR
  TFT_DATAPIN_SET(color8);
  TFT_SWAP_DATA_WR
  TFT_SWAP_DATA_WR
}

void Shield_ili9341::DrawPixel( int16_t x, int16_t y, uint16_t color )
{
  if ( x < 0 || y < 0 || x >= m_width || y >= m_height )
      return;
  SetWindow(x, y, x, y);
  TFT_DATAPIN_SET(0x2C);
  TFT_SWAP_CMD_WR
  TFT_DATAPIN_SET(color >> 8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(color & 0xFF);
  TFT_SWAP_DATA_WR
}

void Shield_ili9341::DrawPixel_unsafe( int16_t x, int16_t y, uint16_t color )
{
  SetWindow(x, y, x, y);
  TFT_DATAPIN_SET(0x2C);
  TFT_SWAP_CMD_WR
  TFT_DATAPIN_SET(color >> 8);
  TFT_SWAP_DATA_WR
  TFT_DATAPIN_SET(color & 0xFF);
  TFT_SWAP_DATA_WR
}

void Shield_ili9341::DrawHLine_safe( int16_t x0, int16_t y0, int16_t x1, uint16_t color )
{
  if ( y0 < 0 || y0 >= m_height || x1 < 0 || x0 >= m_width )
      return;
  if ( x0 < 0 )
      x0 = 0;
  if ( x1 >= m_width )
      x1 = m_width-1;

  SetWindow(x0, y0, x1, y0);
  StreamStart();
  StreamPixels( color, x1-x0+1 );
}

void Shield_ili9341::DrawHLine_unsafe( int16_t x0, int16_t y0, int16_t x1, uint16_t color )
{
  SetWindow(x0, y0, x1, y0);
  StreamStart();
  StreamPixels( color, x1-x0+1 );
}

void Shield_ili9341::DrawHLine( int16_t x0, int16_t y0, int16_t x1, uint16_t color )
{
    if ( y0 < 0 || y0 >= m_height )
        return;
    if ( x0 > x1 )
    {
        int16_t t = x0; x0 = x1; x1 = t;
    }
    if ( x0 < 0 || x1 >= m_width )
        DrawHLine_safe( x0, y0, x1, color );
    else
        DrawHLine_unsafe( x0, y0, x1, color );
}

void Shield_ili9341::DrawLine_safe( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color )
{
    int16_t dx = x0-x1;
    int16_t dy = y0-y1;
    if ( abs(dx) > abs(dy) )
    {
        if ( x0 > x1 )
        {
            int16_t t;
            t=x0; x0=x1; x1=t;
            t=y0; y0=y1; y1=t;
        }
        int32_t ys = (1024*int32_t(y1-y0))/int32_t(x1-x0);
        int32_t yt = int32_t(y0)*1024;
        int16_t x = x0;
        while ( x < 0 )
        {
            x++;
            yt += ys;
        }
        if ( x1 >= m_width )
            x1 = m_width-1;
        while ( x <= x1 )
        {
            int16_t y = yt >> 10;
            if ( y >= 0 && y < m_height )
            {
                SetWindow(x, y, x, y);
                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                TFT_DATAPIN_SET(color >> 8);
                TFT_SWAP_DATA_WR
                TFT_DATAPIN_SET(color & 0xFF);
                TFT_SWAP_DATA_WR
            }
            yt += ys;
            x++;
        }
    } else
    {
        if ( y0 > y1 )
        {
            int16_t t;
            t=x0; x0=x1; x1=t;
            t=y0; y0=y1; y1=t;
        }
        int32_t xs = (1024*int32_t(x1-x0))/int32_t(y1-y0);
        int32_t xt = int32_t(x0)*1024;

        int16_t y = y0;
        while ( y < 0 )
        {
            y++;
            xt += xs;
        }
        if ( y1 >= m_height )
            y1 = m_height-1;
        while ( y <= y1 )
        {
            int16_t x = xt >> 10;
            if ( x >= 0 && x < m_width )
            {
                SetWindow(x, y, x, y);
                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                TFT_DATAPIN_SET(color >> 8);
                TFT_SWAP_DATA_WR
                TFT_DATAPIN_SET(color & 0xFF);
                TFT_SWAP_DATA_WR
            }
            y++;
            xt += xs;
        }
    }
}

void Shield_ili9341::DrawLine_unsafe_fast( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color8 )
{
    int16_t dx = x0-x1;
    int16_t dy = y0-y1;
    if ( abs(dx) > abs(dy) )
    {
        if ( y0 > y1 )
        {
            int16_t t;
            t=x0; x0=x1; x1=t;
            t=y0; y0=y1; y1=t;
        }
        int32_t xs = (1024*int32_t(x1-x0))/int32_t(y1-y0);
        int32_t xt = int32_t(x0)*1024;
        if ( x1 > x0 )
        {
            for ( int16_t y = y0; y <= y1; ++y )
            {
                SetPage(y, y);
                int16_t x = xt >> 10;
                SetColumn( x0, x );

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                TFT_DATAPIN_SET(color8);
                for ( int16_t xx = x0; xx < x; ++xx )
                {
                    TFT_SWAP_DATA_WR
                    TFT_SWAP_DATA_WR
                }
                x0 = x;            
                xt += xs;
            }
        } else
        {
            for ( int16_t y = y0; y <= y1; ++y )
            {
                SetPage(y, y);
                int16_t x = xt >> 10;
                SetColumn( x, x0 );

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                TFT_DATAPIN_SET(color8);
                for ( int16_t xx = x; xx < x0; ++xx )
                {
                    TFT_SWAP_DATA_WR
                    TFT_SWAP_DATA_WR
                }
                x0 = x;            
                xt += xs;
            }
        }
    } else
    {
        if ( x0 > x1 )
        {
            int16_t t;
            t=x0; x0=x1; x1=t;
            t=y0; y0=y1; y1=t;
        }
        int32_t ys = (1024*int32_t(y1-y0))/int32_t(x1-x0);
        int32_t yt = int32_t(y0)*1024;
        if ( y1 > y0 )
        {
            for ( int16_t x = x0; x <= x1; ++x )
            {
                SetColumn( x, x );
                int16_t y = yt >> 10;
                SetPage(y0, y);

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                TFT_DATAPIN_SET(color8);
                for ( int16_t yy = y0; yy < y; ++yy )
                {
                    TFT_SWAP_DATA_WR
                    TFT_SWAP_DATA_WR
                }
                y0 = y;
                yt += ys;
            }
        } else
        {
            for ( int16_t x = x0; x <= x1; ++x )
            {
                SetColumn( x, x );
                int16_t y = yt >> 10;
                SetPage(y, y0);

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                TFT_DATAPIN_SET(color8);
                for ( int16_t yy = y; yy < y0; ++yy )
                {
                    TFT_SWAP_DATA_WR
                    TFT_SWAP_DATA_WR
                }
                y0 = y;
                yt += ys;
            }
        }
    }
}

void Shield_ili9341::DrawLine_unsafe( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color )
{
    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;
    if ( hi == lo )
    {
        DrawLine_unsafe_fast( x0, y0, x1, y1, lo );
        return;
    }

    int16_t dx = x0-x1;
    int16_t dy = y0-y1;
    if ( abs(dx) > abs(dy) )
    {
        if ( y0 > y1 )
        {
            int16_t t;
            t=x0; x0=x1; x1=t;
            t=y0; y0=y1; y1=t;
        }
        int32_t xs = (1024*int32_t(x1-x0))/int32_t(y1-y0);
        int32_t xt = int32_t(x0)*1024;
        if ( x1 > x0 )
        {
            for ( int16_t y = y0; y <= y1; ++y )
            {
                SetPage(y, y);
                int16_t x = xt >> 10;
                SetColumn( x0, x );

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                for ( int16_t xx = x0; xx < x; ++xx )
                {
                    TFT_DATAPIN_SET(hi);
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET(lo);
                    TFT_SWAP_DATA_WR
                }
                x0 = x;            
                xt += xs;
            }
        } else
        {
            for ( int16_t y = y0; y <= y1; ++y )
            {
                SetPage(y, y);
                int16_t x = xt >> 10;
                SetColumn( x, x0 );

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                for ( int16_t xx = x; xx < x0; ++xx )
                {
                    TFT_DATAPIN_SET(hi);
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET(lo);
                    TFT_SWAP_DATA_WR
                }
                x0 = x;            
                xt += xs;
            }
        }
    } else
    {
        if ( x0 > x1 )
        {
            int16_t t;
            t=x0; x0=x1; x1=t;
            t=y0; y0=y1; y1=t;
        }
        int32_t ys = (1024*int32_t(y1-y0))/int32_t(x1-x0);
        int32_t yt = int32_t(y0)*1024;
        if ( y1 > y0 )
        {
            for ( int16_t x = x0; x <= x1; ++x )
            {
                SetColumn( x, x );
                int16_t y = yt >> 10;
                SetPage(y0, y);

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                for ( int16_t yy = y0; yy < y; ++yy )
                {
                    TFT_DATAPIN_SET(hi);
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET(lo);
                    TFT_SWAP_DATA_WR
                }
                y0 = y;
                yt += ys;
            }
        } else
        {
            for ( int16_t x = x0; x <= x1; ++x )
            {
                SetColumn( x, x );
                int16_t y = yt >> 10;
                SetPage(y, y0);

                TFT_DATAPIN_SET(0x2C);
                TFT_SWAP_CMD_WR
                for ( int16_t yy = y; yy < y0; ++yy )
                {
                    TFT_DATAPIN_SET(hi);
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET(lo);
                    TFT_SWAP_DATA_WR
                }
                y0 = y;
                yt += ys;
            }
        }
    }
}

void Shield_ili9341::DrawLine( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color )
{
    if ( x0 >= 0 && x1 >= 0 && y0 >= 0 && y1 >= 0 && x0 < m_width && x1 < m_width && y0 < m_height && y1 < m_height )
        DrawLine_unsafe( x0, y0, x1, y1, color );
    else
        DrawLine_safe( x0, y0, x1, y1, color );
}

void Shield_ili9341::DrawCircle_safe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color )
{
    int16_t x0 = x_center;
    int16_t y0 = y_center;

    int16_t x = rad;
    int16_t y = 0;
    int16_t radiusError = 1-x;

    while(x >= y)
    {
        int16_t yd0 = y+y0;
        int16_t yd1 = x+y0;
        int16_t yd2 = -y+y0;
        int16_t yd3 = -x+y0;

        int16_t xd0 = x+x0;
        int16_t xd1 = y+x0;
        int16_t xd2 = -x+x0;
        int16_t xd3 = -y+x0;

        if ( yd0 >= 0 && yd0 < m_height )
        {
            if ( xd0 >= 0 && xd0 < m_width )
                DrawPixel_unsafe( xd0, yd0, color );
            if ( xd2 >= 0 && xd2 < m_width )
                DrawPixel_unsafe( xd2, yd0, color );
        }

        if ( yd1 >= 0 && yd1 < m_height )
        {
            if ( xd1 >= 0 && xd1 < m_width )
                DrawPixel_unsafe( xd1, yd1, color );
            if ( xd3 >= 0 && xd3 < m_width )
                DrawPixel_unsafe( xd3, yd1, color );
        }

        if ( yd2 >= 0 && yd2 < m_height )
        {
            if ( xd2 >= 0 && xd2 < m_width )
                DrawPixel_unsafe( xd2, yd2, color );
            if ( xd0 >= 0 && xd0 < m_width )
                DrawPixel_unsafe( xd0, yd2, color );
        }

        if ( yd3 >= 0 && yd3 < m_height )
        {
            if ( xd1 >= 0 && xd1 < m_width )
                DrawPixel_unsafe( xd1, yd3, color );
            if ( xd3 >= 0 && xd3 < m_width )
                DrawPixel_unsafe( xd3, yd3, color );
        }

        y++;        
        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

void Shield_ili9341::DrawCircle_unsafe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color )
{
    int16_t x0 = x_center;
    int16_t y0 = y_center;

    int16_t x = rad;
    int16_t y = 0;
    int16_t radiusError = 1-x;

    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;

    while(x >= y)
    {
        int16_t yd0 = y+y0;
        int16_t yd1 = x+y0;
        int16_t yd2 = -y+y0;
        int16_t yd3 = -x+y0;

        int16_t xd0 = x+x0;
        int16_t xd1 = y+x0;
        int16_t xd2 = -x+x0;
        int16_t xd3 = -y+x0;

        SetPage(yd0, yd0);
        SetColumn(xd0, xd0);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }
        SetColumn(xd2, xd2);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }
        SetPage(yd2, yd2);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }
        SetColumn(xd0, xd0);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }


        SetPage(yd1, yd1);
        SetColumn(xd1, xd1);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }
        SetColumn(xd3, xd3);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }
        SetPage(yd3, yd3);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }
        SetColumn(xd1, xd1);
        {
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            TFT_DATAPIN_SET(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(lo);
            TFT_SWAP_DATA_WR
        }

        y++;        
        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

void Shield_ili9341::DrawCircle( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color )
{
    if ( x_center-rad < 0 || x_center + rad >= m_width || y_center-rad < 0 || y_center + rad >= m_height )
        DrawCircle_safe( x_center, y_center, rad, color );
    else
        DrawCircle_unsafe( x_center, y_center, rad, color );
}

void Shield_ili9341::DrawCircleFill_safe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color )
{
    int16_t x0 = x_center;
    int16_t y0 = y_center;

    int16_t x = rad;
    int16_t y = 0;
    int16_t radiusError = 1-x;

    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;

    while(x >= y)
    {
        int16_t yd0 = y+y0;
        int16_t yd1 = x+y0;
        int16_t yd2 = -y+y0;
        int16_t yd3 = -x+y0;

        int16_t xd0 = x+x0;
        int16_t xd1 = y+x0;
        int16_t xd2 = -x+x0;
        int16_t xd3 = -y+x0;

        if ( xd2 < 0 ) xd2 = 0;
        if ( xd3 < 0 ) xd3 = 0;
        if ( xd1 >= m_width ) xd1 = m_width-1;
        if ( xd0 >= m_width ) xd0 = m_width-1;

        if ( yd0 >= 0 && yd0 < m_height && xd0 >= 0 && xd2 < m_width )
            DrawHLine_unsafe( xd2, yd0, xd0, color );
        if ( yd1 >= 0 && yd1 < m_height && xd1 >= 0 && xd3 < m_width )
            DrawHLine_unsafe( xd3, yd1, xd1, color );
        if ( yd2 >= 0 && yd2 < m_height && xd0 >= 0 && xd2 < m_width )
            DrawHLine_unsafe( xd2, yd2, xd0, color );
        if ( yd3 >= 0 && yd3 < m_height && xd1 >= 0 && xd3 < m_width )
            DrawHLine_unsafe( xd3, yd3, xd1, color );

        y++;
        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

void Shield_ili9341::DrawCircleFill_unsafe( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color )
{
    int16_t x0 = x_center;
    int16_t y0 = y_center;

    int16_t x = rad;
    int16_t y = 0;
    int16_t radiusError = 1-x;

    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;

    while(x >= y)
    {
        int16_t yd0 = y+y0;
        int16_t yd1 = x+y0;
        int16_t yd2 = -y+y0;
        int16_t yd3 = -x+y0;

        int16_t xd0 = x+x0;
        int16_t xd1 = y+x0;
        int16_t xd2 = -x+x0;
        int16_t xd3 = -y+x0;

        SetColumn( xd2, xd0 );
        {
            uint16_t count = xd0-xd2+1;
            SetPage( yd0, yd0 );
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            StreamPixels( color, count );

            SetPage( yd2, yd2 );
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            StreamPixels( color, count );
        }

        SetColumn( xd3, xd1 );
        {
            uint16_t count = xd1-xd3+1;
            SetPage( yd1, yd1 );
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            StreamPixels( color, count );

            SetPage( yd3, yd3 );
            TFT_DATAPIN_SET(0x2C);
            TFT_SWAP_CMD_WR
            StreamPixels( color, count );
        }

        y++;
        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

void Shield_ili9341::DrawCircleFill( int16_t x_center, int16_t y_center, int16_t rad, uint16_t color )
{
    if ( x_center-rad < 0 || x_center + rad >= m_width || y_center-rad < 0 || y_center + rad >= m_height )
        DrawCircleFill_safe( x_center, y_center, rad, color );
    else
        DrawCircleFill_unsafe( x_center, y_center, rad, color );
}

void Shield_ili9341::StreamStart()
{
    TFT_DATAPIN_SET(0x2C);
    TFT_SWAP_CMD_WR
}

void Shield_ili9341::StreamPixel16( uint8_t lo, uint8_t hi )
{
    TFT_DATAPIN_SET(hi);
    TFT_SWAP_DATA_WR
    TFT_DATAPIN_SET(lo);
    TFT_SWAP_DATA_WR
}

void Shield_ili9341::StreamPixel( uint16_t color )
{
    TFT_DATAPIN_SET(color >> 8);
    TFT_SWAP_DATA_WR
    TFT_DATAPIN_SET(color & 0xFF);
    TFT_SWAP_DATA_WR
}

void Shield_ili9341::StreamPixel8( uint8_t color8 )
{
    TFT_DATAPIN_SET(color8);
    TFT_SWAP_DATA_WR
    TFT_SWAP_DATA_WR
}

void Shield_ili9341::StreamPixels( uint16_t color, uint16_t count )
{
    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;
    for ( uint16_t i = 0; i < count; ++i )
    {
        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR
    }
}

void Shield_ili9341::StreamPixels_16( uint16_t color )
{
    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;

#ifdef TFT_DATAPIN_LO_HI
    if ( (uint8_t)(lo&3) == (uint8_t)(hi&3) )
    {
        TFT_DATAPIN_SET_LO(lo);
        for ( uint8_t i = 0; i < 4; ++i )
        {
            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR
        }
    } else if ( (uint8_t)(lo&0xFC) == (uint8_t)(hi&0xFC) )
    {
        TFT_DATAPIN_SET_HI(hi);
        for ( uint8_t i = 0; i < 4; ++i )
        {
            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR
        }
    } else
#endif
    {
    //Full
    for ( uint8_t i = 0; i < 4; ++i )
    {
        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR
    }

    }
}

void Shield_ili9341::StreamPixels_64( uint16_t color )
{
    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;

#ifdef TFT_DATAPIN_LO_HI
    if ( (uint8_t)(lo&3) == (uint8_t)(hi&3) )
    {
        TFT_DATAPIN_SET_LO(lo);
        for ( uint8_t i = 0; i < 16; ++i )
        {
            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR
        }
    } else if ( (uint8_t)(lo&0xFC) == (uint8_t)(hi&0xFC) )
    {
        TFT_DATAPIN_SET_HI(hi);
        for ( uint8_t i = 0; i < 16; ++i )
        {
            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR
        }
    } else
#endif
    {
    //Full
    for ( uint8_t i = 0; i < 16; ++i )
    {
        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR
    }

    }
}

void Shield_ili9341::StreamPixels_256( uint16_t color )
{
    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;

#ifdef TFT_DATAPIN_LO_HI
    if ( (uint8_t)(lo&3) == (uint8_t)(hi&3) )
    {
        TFT_DATAPIN_SET_LO(lo);
        for ( uint8_t i = 0; i < 64; ++i )
        {
            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_HI(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_HI(lo);
            TFT_SWAP_DATA_WR
        }
    } else if ( (uint8_t)(lo&0xFC) == (uint8_t)(hi&0xFC) )
    {
        TFT_DATAPIN_SET_HI(hi);
        for ( uint8_t i = 0; i < 64; ++i )
        {
            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR

            TFT_DATAPIN_SET_LO(hi);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET_LO(lo);
            TFT_SWAP_DATA_WR
        }
    } else
#endif
    {
    //Full
    for ( uint8_t i = 0; i < 64; ++i )
    {
        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(hi);
        TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(lo);
        TFT_SWAP_DATA_WR
    }

    }
}

void Shield_ili9341::StreamPixels8( uint8_t color8, uint16_t count )
{
    TFT_DATAPIN_SET(color8);
    uint16_t i = 0;
    while ( i+3 < count )
    {
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        i += 4;
    }
    while ( i < count )
    {
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR
        i ++;
    }
}

void Shield_ili9341::StreamPixels8_16( uint8_t color8 )
{
    TFT_DATAPIN_SET(color8);
    for ( uint8_t i = 0; i < 2; ++i )
    {
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

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

void Shield_ili9341::StreamPixels8_64( uint8_t color8 )
{
    TFT_DATAPIN_SET(color8);
    for ( uint8_t i = 0; i < 8; ++i )
    {
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

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

void Shield_ili9341::StreamPixels8_256( uint8_t color8 )
{
    TFT_DATAPIN_SET(color8);
    for ( uint8_t i = 0; i < 32; ++i )
    {
        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

        TFT_SWAP_DATA_WR
        TFT_SWAP_DATA_WR

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


void Shield_ili9341::TextRect( const String& str, int16_t& rect_left, int16_t& rect_top, int16_t& rect_right, int16_t& rect_bot, const uint8_t* font_data, const glyph_param* font_info )
{
    rect_left = 999;
    rect_right = 0;
    rect_top = -999;
    rect_bot = 999;
    int16_t x = 0;
    for ( int i = 0; i < str.length(); ++i )
    {
        char ch = str.charAt(i);
        if  ( ch < 32 || ch > 128 )
            continue;
        const uint8_t* info = (const uint8_t*)(font_info + ch - 32);

        int16_t draw_x = x + (int8_t)pgm_read_byte(info+4);
        int16_t draw_y = -(int8_t)pgm_read_byte(info+5);

        uint8_t w = pgm_read_byte(info+2);
        uint8_t h = pgm_read_byte(info+3);


        if ( draw_x < rect_left )
            rect_left = draw_x;

        rect_right = draw_x+w;

        if ( draw_y < rect_bot )
            rect_bot = draw_y;
        if ( draw_y+h > rect_top )
            rect_top = draw_y+h;

        x += (int8_t)pgm_read_byte(info+6);
    }
}

void Shield_ili9341::DrawText( const String& str, int16_t x, int16_t y, uint16_t color, const uint8_t* font_data, const glyph_param* font_info )
{
    uint8_t hi = color >> 8;
    uint8_t lo = color & 0xFF;

    for ( int i = 0; i < str.length(); ++i )
    {
        char ch = str.charAt(i);
        if  ( ch < 32 || ch > 128 )
            continue;
        const uint8_t* info = (const uint8_t*)(font_info + ch - 32);

        int16_t draw_x = x + (int8_t)pgm_read_byte(info+4);
        int16_t draw_y = y - (int8_t)pgm_read_byte(info+5);

        uint8_t w = pgm_read_byte(info+2);
        uint8_t h = pgm_read_byte(info+3);

        uint16_t ofs = pgm_read_word(info+0);
        uint8_t line_size = (w+7)/8;
        for ( uint8_t yi = 0; yi < h; ++yi )
        {
            int16_t yline = draw_y+yi;
            if ( yline < 0 )
            {
                ofs += line_size;
                continue;
            } else if ( yline >= m_height )
                break;

            SetPage( yline, yline ); 
            if ( draw_x >= 0 && draw_x+w < m_width )
            {
                //Fast line
                uint16_t so = ofs;
                uint8_t m = 0x80;
                uint8_t d = pgm_read_byte( font_data+so );
                for ( uint8_t xi = 0; xi < w; ++xi )
                {
                    uint8_t b = d & m;
                    if ( b != 0 )
                    {
                        int16_t xline = draw_x+xi;
                        SetColumn( xline, xline );
                        TFT_DATAPIN_SET(0x2C);
                        TFT_SWAP_CMD_WR
                        TFT_DATAPIN_SET(hi);
                        TFT_SWAP_DATA_WR
                        TFT_DATAPIN_SET(lo);
                        TFT_SWAP_DATA_WR
                    }
                    m = m >> 1;
                    if ( m == 0 )
                    {
                        so ++;
                        m = 0x80;
                        d = pgm_read_byte(font_data+so);
                    }
                }
            } else if ( draw_x >= m_width || draw_x+w < 0 )
            {
                //no line
            } else
            {
                //Safe line
                uint16_t so = ofs;
                uint8_t m = 0x80;
                uint8_t d = pgm_read_byte( font_data+so );
                for ( uint8_t xi = 0; xi < w; ++xi )
                {
                    int16_t xline = draw_x+xi;
                    if ( xline >= m_width )
                        break;
                    if ( xline >= 0 )
                    {
                        uint8_t b = d & m;
                        if ( b != 0 )
                        {
                            SetColumn( xline, xline );
                            TFT_DATAPIN_SET(0x2C);
                            TFT_SWAP_CMD_WR
                            TFT_DATAPIN_SET(hi);
                            TFT_SWAP_DATA_WR
                            TFT_DATAPIN_SET(lo);
                            TFT_SWAP_DATA_WR
                        }
                    }
                    m = m >> 1;
                    if ( m == 0 )
                    {
                        so ++;
                        m = 0x80;
                        d = pgm_read_byte(font_data+so);
                    }
                }
            }
            ofs += line_size;
        }

        x += (int8_t)pgm_read_byte(info+6);
    }
}

void Shield_ili9341::DrawTextScale( const String& str, int scale, int16_t x, int16_t y, uint16_t color, const uint8_t* font_data, const glyph_param* font_info )
{
    for ( int i = 0; i < str.length(); ++i )
    {
        char ch = str.charAt(i);
        if  ( ch < 32 || ch > 128 )
            continue;
        const uint8_t* info = (const uint8_t*)(font_info + ch - 32);

        int16_t draw_x = x + (int8_t)pgm_read_byte(info+4)*scale;
        int16_t draw_y = y - (int8_t)pgm_read_byte(info+5)*scale;

        uint8_t w = pgm_read_byte(info+2);
        uint8_t h = pgm_read_byte(info+3);

        uint16_t ofs = pgm_read_word(info+0);
        uint8_t line_size = (w+7)/8;
        for ( uint8_t yi = 0; yi < h; ++yi )
        {
            int16_t yline = draw_y+yi*scale;
            if ( yline < 0 )
            {
                ofs += line_size;
                continue;
            } else if ( yline >= m_height )
                break;

            {
                //Safe line
                uint16_t so = ofs;
                uint8_t m = 0x80;
                uint8_t d = pgm_read_byte( font_data+so );
                for ( uint8_t xi = 0; xi < w; ++xi )
                {
                    int16_t xline = draw_x+xi*scale;
                    if ( xline >= m_width )
                        break;
                    if ( xline >= 0 )
                    {
                        uint8_t b = d & m;
                        if ( b != 0 )
                            DrawRect( xline, yline, xline+scale-1, yline+scale-1, color );
                    }
                    m = m >> 1;
                    if ( m == 0 )
                    {
                        so ++;
                        m = 0x80;
                        d = pgm_read_byte(font_data+so);
                    }
                }
            }
            ofs += line_size;
        }

        x += (int8_t)pgm_read_byte(info+6) * scale;
    }
}


void Shield_ili9341::DrawTextScaleBorder( const String& str, int scale, int16_t x, int16_t y, uint16_t color, int16_t border_size, uint16_t border_color, const uint8_t* font_data, const glyph_param* font_info )
{
    int16_t rect_left, rect_top, rect_right, rect_bot;
    TextRect( str, rect_left, rect_top, rect_right, rect_bot, font_data, font_info );

    rect_bot = rect_bot*scale + y - border_size;
    rect_top = rect_top*scale + y + border_size;
    rect_right = rect_right*scale + x + border_size;

    int16_t x_last_draw = x-border_size-1;

    for ( int i = 0; i < str.length(); ++i )
    {
        char ch = str.charAt(i);
        if  ( ch < 32 || ch > 128 )
            continue;
        const uint8_t* info = (const uint8_t*)(font_info + ch - 32);

        int16_t draw_x = x + (int8_t)pgm_read_byte(info+4)*scale;
        int16_t draw_y = y - (int8_t)pgm_read_byte(info+5)*scale;

        uint8_t w = pgm_read_byte(info+2);
        uint8_t h = pgm_read_byte(info+3);

        if ( w == 0 && h == 0 )
        {

        } else
        {
            if ( draw_x > x_last_draw+1 )
                DrawRect( x_last_draw+1, rect_bot, draw_x-1, rect_top-1, border_color );
            x_last_draw = draw_x+w*scale-1;
            if ( draw_y > rect_bot )
                DrawRect( draw_x, rect_bot, draw_x+w*scale-1, draw_y-1, border_color );

            if ( draw_y+h*scale < rect_top )
                DrawRect( draw_x, draw_y+h*scale, draw_x+w*scale-1, rect_top-1, border_color );

            uint16_t ofs = pgm_read_word(info+0);
            uint8_t line_size = (w+7)/8;
            for ( uint8_t yi = 0; yi < h; ++yi )
            {
                int16_t yline = draw_y+yi*scale;
                if ( yline < 0 )
                {
                    ofs += line_size;
                    continue;
                } else if ( yline >= m_height )
                    break;

                {
                    //Safe line
                    uint16_t so = ofs;
                    uint8_t m = 0x80;
                    uint8_t d = pgm_read_byte( font_data+so );
                    for ( uint8_t xi = 0; xi < w; ++xi )
                    {
                        int16_t xline = draw_x+xi*scale;
                        if ( xline >= m_width )
                            break;
                        if ( xline >= 0 )
                        {
                            uint8_t b = d & m;
                            if ( b != 0 )
                                DrawRect( xline, yline, xline+scale-1, yline+scale-1, color );
                            else
                                DrawRect( xline, yline, xline+scale-1, yline+scale-1, border_color );
                        }
                        m = m >> 1;
                        if ( m == 0 )
                        {
                            so ++;
                            m = 0x80;
                            d = pgm_read_byte(font_data+so);
                        }
                    }
                }
                ofs += line_size;
            }
        }

        x += (int8_t)pgm_read_byte(info+6) * scale;
    }

    if ( rect_right > x_last_draw+1 )
        DrawRect( x_last_draw+1, rect_bot, rect_right-1, rect_top-1, border_color );
}
