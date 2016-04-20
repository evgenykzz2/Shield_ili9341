#include "Shield_ili9341.h"

Shield_ili9341 tft;

void setup()
{
  Serial.begin(9600);
  tft.Init( 320, 240, Shield_ili9341::MemoryAccessControl_Rotate );
}

void loop()
{
  //Fast fill 8bit color
  {
    unsigned long time0 = micros();
    int frame_count = 64;
    for ( int i = 0; i < frame_count; ++i )
      tft.FillFast( rand() % 256 );
    unsigned long time1 = micros();
    Serial.print("Fast fill: frame: ");
    Serial.print( (time1-time0)/frame_count );
    Serial.print(" fps: ");
    Serial.println( 1000000.0f*float(frame_count)/float(time1-time0) );
  }

  //Fill 16bit color
  {
    unsigned long time0 = micros();
    int frame_count = 64;
    for ( int i = 0; i < frame_count; ++i )
      tft.Fill( rand() );
    unsigned long time1 = micros();
    Serial.print("Full fill: frame: ");
    Serial.print( (time1-time0)/frame_count );
    Serial.print(" fps: ");
    Serial.println( 1000000.0f*float(frame_count)/float(time1-time0) );
  }

  //Lines
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int j = 0; j < 10; ++j )
    {
      for ( int i = 0; i < 360; i += 1 )
      {
        tft.DrawLine( 160, 120, 160 + 120*cos((float)i*0.01745f), 120 + 120*sin((float)i*0.01745f), rand() );
      }
    }
    unsigned long time1 = micros();
    Serial.print("Lines: ");
    Serial.println( time1-time0 );
  }

  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 40000; ++i )
      tft.DrawPixel_unsafe( rand()%320, rand()%240, rand() );
    unsigned long time1 = micros();
    Serial.print("Pixels: ");
    Serial.println( time1-time0 );
  }

  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 1000; ++i )
      tft.DrawRect( rand()%tft.Width(), rand()%tft.Height(), rand()%tft.Width(), rand()%tft.Height(), rand() );
    unsigned long time1 = micros();
    Serial.print("DrawRect: ");
    Serial.println( time1-time0 );
  }
  
  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 1000; ++i )
      tft.DrawCircle( rand()%tft.Width(), rand()%tft.Height(), rand()%120, rand() );
    unsigned long time1 = micros();
    Serial.print("DrawCircle: ");
    Serial.println( time1-time0 );
  }

  {
    tft.FillFast( Shield_ili9341::Color8_Black );
    unsigned long time0 = micros();
    for ( int32_t i = 0; i < 400; ++i )
      tft.DrawCircleFill( rand()%tft.Width(), rand()%tft.Height(), rand()%120, rand() );
    unsigned long time1 = micros();
    Serial.print("DrawCircleFill: ");
    Serial.println( time1-time0 );
  }
}
