#pragma once

#include "Shield_ili9341.h"

class NesCore : public Shield_ili9341
{
    static const uint8_t g_palette[64*2] PROGMEM;

    const uint8_t* m_charset;
    const uint8_t* m_palette;

    const uint8_t* m_block_id;
    const uint8_t* m_block_palette;

public:
    enum EMirror
    {
        MirrorH = 1,
        MirrorV = 2
    };
public:
    void InitChr( const uint8_t* charset, const uint8_t* palette );
    void DrawChr( int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t mirror );

    void InitBlock( const uint8_t* block_id, const uint8_t* block_palette );
};
