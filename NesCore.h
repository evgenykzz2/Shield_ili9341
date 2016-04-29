#pragma once

#include "Shield_ili9341.h"

class NesOffscreen
{
    uint8_t* m_buffer;
    int16_t  m_width;
    int16_t  m_height;

    friend class NesCore;
public:
    NesOffscreen();
    ~NesOffscreen();
    void Init( int16_t width, int16_t height );
};

class NesCore : public Shield_ili9341
{
public:
    class FpsController
    {
        uint64_t m_time;
        uint32_t m_delta;
    public:
        FpsController( uint8_t fps );
        void FrameWait();
    };

    enum EMirror
    {
        MirrorH = 1,
        MirrorV = 2
    };
protected:
    static const uint8_t g_palette[64*2] PROGMEM;

    const uint8_t* m_charset;
    const uint8_t* m_palette;

    const uint8_t* m_block_id;
    const uint8_t* m_block_palette;

    uint8_t m_palette_id;
    uint8_t m_color[8];

    uint8_t m_palette_ofs_id;
    uint8_t m_color_ofs[4];

    void SetPaletteOffScreenId( uint8_t id );

    void DrawChrSafe( int16_t x, int16_t y, uint16_t id, uint8_t mirror );
    void DrawChrUnsafe( int16_t x, int16_t y, uint16_t id, uint8_t mirror );

    void DrawOffScreenChrSafe( NesOffscreen& offscreen, int16_t x, int16_t y, uint16_t id, uint8_t mirror );
    void DrawOffScreenChrUnsafe( NesOffscreen& offscreen, int16_t x, int16_t y, uint16_t id, uint8_t mirror );

public:
    NesCore();

    void InitChr( const uint8_t* charset, const uint8_t* palette );
    void DrawChr( int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t mirror );

    void SetPaletteId( uint8_t id );

    void InitBlock( const uint8_t* block_id, const uint8_t* block_palette );
    void DrawBlock( int16_t x, int16_t y, uint8_t block_id );

    void DrawOffScreenChr( NesOffscreen& offscreen, int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t mirror );
    //void DrawOffscreenChrAlpha( NesOffscreen& offscreen, int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t mirror );
    void DrawOffscreenBuffer( NesOffscreen& offscreen, int16_t x, int16_t y );
};
