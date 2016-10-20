#pragma once

#include "Shield_ili9341.h"

class VideoDecoder : public Shield_ili9341
{
public:
    VideoDecoder();
    void DecodePrimitive( uint8_t id, uint8_t l0, uint8_t h0, uint8_t l1, uint8_t h1 );
};
