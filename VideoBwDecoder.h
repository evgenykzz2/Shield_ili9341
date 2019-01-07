#pragma once

#include "Shield_ili9341.h"

class VideoBwDecoder : public Shield_ili9341
{
public:
    VideoBwDecoder();
    void Decode4x4Bin( uint8_t a, uint8_t b );
};
