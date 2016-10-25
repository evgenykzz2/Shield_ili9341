#pragma once

#include "Shield_ili9341.h"

class VideoDecoder : public Shield_ili9341
{
public:
    VideoDecoder();
    void Decode4x4( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t l2, uint8_t h2,   uint8_t l3, uint8_t h3 );

    void Decode8x8_mono16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   const uint8_t* bin );
    void Decode8x8_monoP16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t idd );

    void Decode8x8_cnt16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t c0 );
    void Decode8x8_Primitive4x2( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,  uint8_t v );
};
