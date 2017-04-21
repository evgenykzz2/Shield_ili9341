#include "Shield_ili9341.h"
#include "font/arial_14.h"

//#define USE_SERIAL

#if defined(ESP8266)
  #define DISABLE_WATCHDOG ESP.wdtDisable();
#else
  #define DISABLE_WATCHDOG
#endif

Shield_ili9341 tft;

void setup()
{
  #ifdef USE_SERIAL
  Serial.begin(115200);
  #endif
  tft.Init( 320, 240, Shield_ili9341::MemoryAccessControl_Rotate );
  //tft.Init( 480, 320, Shield_ili9341::MemoryAccessControl_Rotate );
}

void Transform( float x, float y, float z, const float* mt, float& xt, float& yt, float& zt )
{
  xt = mt[0]*x + mt[4]*y + mt[8 ]*z;// + mt[12];
  yt = mt[1]*x + mt[5]*y + mt[9 ]*z;// + mt[13];
  zt = mt[2]*x + mt[6]*y + mt[10]*z;// + mt[14];
}

void loop()
{
  DISABLE_WATCHDOG
  unsigned long time_text = 0;
  {
    unsigned long time0 = micros();
    tft.FillFast( Shield_ili9341::Color8_Black );
    for ( int i = 0; i < 10000; ++i )
      tft.DrawText( "Test", rand()%tft.Width(), rand()%tft.Height(), rand(), g_font_data, g_font_info );
    unsigned long time1 = micros();
    time_text = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("Text: ");
    Serial.println( time_text );
    #endif
  }

  DISABLE_WATCHDOG
  unsigned long time_move_text = 0;
  {
    unsigned long time0 = micros();
    tft.FillFast( Shield_ili9341::Color8_Black );

    const String text = "*Move Text*";
    const int16_t s = 4;

    for ( int i = 0; i < tft.Height(); ++i )
    {
      tft.DrawTextScaleBorder( text, s, i, i, 0xFFFF,  1, 0x0, g_font_data, g_font_info );
    }

    unsigned long time1 = micros();
    time_move_text = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("Move Text: ");
    Serial.println( time_move_text );
    #endif
  }

  DISABLE_WATCHDOG
  //Fast fill 8bit color
  int fill_frame_count = 64;
  unsigned long time_fill8 = 0;
  {
    unsigned long time0 = micros();
    for ( int i = 0; i < fill_frame_count; ++i )
      tft.FillFast( rand() % 256 );
    unsigned long time1 = micros();
    time_fill8 = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("Fast fill: frame: ");
    Serial.print( time_fill8/fill_frame_count );
    Serial.print(" fps: ");
    Serial.println( 1000000.0f*float(fill_frame_count)/float(time_fill8) );
    #endif
  }

  DISABLE_WATCHDOG
  //Fill 16bit color
  unsigned long time_fill16 = 0;
  {
    unsigned long time0 = micros();
    for ( int i = 0; i < fill_frame_count; ++i )
      tft.Fill( rand() );
    unsigned long time1 = micros();
    time_fill16 = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("Full fill: frame: ");
    Serial.print( (time_fill16)/fill_frame_count );
    Serial.print(" fps: ");
    Serial.println( 1000000.0f*float(fill_frame_count)/float(time_fill16) );
    #endif
  }

  DISABLE_WATCHDOG
  //Lines
  unsigned long time_lines = 0;
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int j = 0; j < 10; ++j )
    {
      for ( int i = 0; i < 360; i += 1 )
      {
        tft.DrawLine( tft.Width()/2, tft.Height()/2, tft.Width()/2 + 120*cos((float)i*0.01745f), tft.Height()/2 + 120*sin((float)i*0.01745f), rand() );
      }
    }
    unsigned long time1 = micros();
    time_lines = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("Lines: ");
    Serial.println( time_lines );
    #endif
  }

  DISABLE_WATCHDOG
  unsigned long time_pixels = 0;
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 40000; ++i )
      tft.DrawPixel_unsafe( rand()%tft.Width(), rand()%tft.Height(), rand() );
    unsigned long time1 = micros();
    time_pixels = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("Pixels: ");
    Serial.println( time_pixels );
    #endif
  }

  DISABLE_WATCHDOG
  unsigned long time_rect = 0;
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 1000; ++i )
      //tft.DrawRect( rand()%tft.Width(), rand()%tft.Height(), rand()%tft.Width(), rand()%tft.Height(), rand() );
      tft.DrawRectFast( rand()%tft.Width(), rand()%tft.Height(), rand()%tft.Width(), rand()%tft.Height(), rand() );
    unsigned long time1 = micros();
    time_rect = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("DrawRect: ");
    Serial.println( time_rect );
    #endif
  }

  DISABLE_WATCHDOG
  unsigned long time_circle = 0;
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 1000; ++i )
    {
      tft.DrawCircle( rand()%tft.Width(), rand()%tft.Height(), rand()%120, rand() );
      //delay(1000);
    }
    unsigned long time1 = micros();
    time_circle = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("DrawCircle: ");
    Serial.println( time_circle );
    #endif
  }

  DISABLE_WATCHDOG
  unsigned long time_circle_fill = 0;
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 400; ++i )
    {
      tft.DrawCircleFill( rand()%tft.Width(), rand()%tft.Height(), rand()%120, rand() );
      //delay(1000);
    }
    unsigned long time1 = micros();
    time_circle_fill = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("DrawCircleFill: ");
    Serial.println( time_circle_fill );
    #endif
  }

  DISABLE_WATCHDOG
  unsigned long time_3d = 0;
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    unsigned long time_calc = 0;
    unsigned long time_draw = 0;
    
    static const int line_count = 12;
    static const int vertex_count = 8;
    //                            0       1       2       3          4        5       6        7
    static const float g_x[] = { -1.0f,   1.0f,   1.0f,  -1.0f,      -1.0f,   1.0f,   1.0f,  -1.0f };
    static const float g_y[] = { -1.0f,  -1.0f,   1.0f,   1.0f,      -1.0f,  -1.0f,   1.0f,   1.0f };
    static const float g_z[] = { -1.0f,  -1.0f,  -1.0f,  -1.0f,       1.0f,   1.0f,   1.0f,   1.0f };

    static const int g_index[] = { 0,1,  1,2,  2,3,  3,0,     4,5,  5,6, 6,7,  7,4,   0,4, 1,5, 2,6, 3,7 };

    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;

    float wf = tft.Width()/2;
    float hf = tft.Height()/2;

    int16_t draw_x[ vertex_count ];
    int16_t draw_y[ vertex_count ];

    int16_t draw_x_old[ vertex_count ];
    int16_t draw_y_old[ vertex_count ];

    for ( int i = 0; i < vertex_count; ++i )
    {
      draw_x_old[i] = 0;
      draw_y_old[i] = 0;
    }

    for ( int32_t t = 0; t < 200; ++t )
    {
        unsigned long t0 = micros();
        float cosa = cos(a);
        float cosb = cos(b);
        float cosg = cos(c);

        float sina = sin(a);
        float sinb = sin(b);
        float sing = sin(c);

        float matrix[16];

        matrix[0 ] = cosa*cosb;
        matrix[1 ] = sina*cosb;
        matrix[2 ] = sinb;
        matrix[3 ] = 0.0f;

        matrix[4 ] =-sina*cosg - cosa*sinb*sing;
        matrix[5 ] = cosa*cosg - sina*sinb*sing;
        matrix[6 ] = cosb*sing;
        matrix[7 ] = 0.0f;

        matrix[8 ] = sina*sing - cosa*sinb*cosg;
        matrix[9 ] =-cosa*sing - sina*sinb*cosg;
        matrix[10] = cosb*cosg;
        matrix[11] = 0.0f;

        matrix[12] = 0.0f;
        matrix[13] = 0.0f;
        matrix[14] = 0.0f;
        matrix[15] = 1.0f;

        for ( int i = 0; i < vertex_count; ++i )
        {
          float xt, yt, zt;
          Transform( g_x[i], g_y[i], g_z[i], matrix, xt, yt, zt );
          zt = 1.0f/(zt+3.0f); xt = wf + wf*xt*zt; yt = hf + wf*yt*zt;
          draw_x[i] = (int16_t)xt;
          draw_y[i] = (int16_t)yt;
        }

        unsigned long t1 = micros();
        for ( int i = 0; i < line_count; ++i )
        {
          int a = g_index[i*2];
          int b = g_index[i*2+1];
          tft.DrawLine( draw_x_old[a], draw_y_old[a], draw_x_old[b], draw_y_old[b], 0x0000 );
          tft.DrawLine( draw_x[a], draw_y[a], draw_x[b], draw_y[b], 0xFFFF );
        }
        
        for ( int i = 0; i < vertex_count; ++i )
        {
          draw_x_old[i] = draw_x[i];
          draw_y_old[i] = draw_y[i];
        }

        unsigned long t2 = micros();

        time_calc += t1-t0;
        time_draw += t2-t1;

        a += 0.02f;
        b += 0.03f;
        c += 0.04f;
    }

    unsigned long time1 = micros();
    time_3d = time1-time0;
    #ifdef USE_SERIAL
    Serial.print("Linear 3d cube: ");
    Serial.print( time_3d );
    Serial.print(" Calc: ");
    Serial.print( time_calc );
    Serial.print(" Draw: ");
    Serial.println( time_draw );
    #endif
  }

  DISABLE_WATCHDOG
  //Show result
  {
    String text;
    tft.FillFast( Shield_ili9341::Color8_Black );

    int pos = 0;
    int step = 10;
    
    text = "Text: " + String(time_text);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;
    
    text = "Move Text: " + String(time_move_text);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "Fill8: " + String(time_fill8) + " fps:" + String(1000000.0f*float(fill_frame_count)/float(time_fill8));
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "Fill16: " + String(time_fill16) + " fps:" + String(1000000.0f*float(fill_frame_count)/float(time_fill16));
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "Lines: " + String(time_lines);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "Pixels: " + String(time_pixels);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "Rect: " + String(time_rect);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "Circle: " + String(time_circle);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "CircleFill: " + String(time_circle_fill);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;

    text = "3D: " + String(time_3d);
    tft.DrawText( text, 0, pos, Shield_ili9341::Color_White, g_font_data, g_font_info );
    pos += step;
    
    delay(5000);
  }
}

