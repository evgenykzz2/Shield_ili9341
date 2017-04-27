#pragma once

#include "Shield_ili9341.h"

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

    enum ESpriteFlag
    {
        SpriteFlag_Update      = 4,
        SpriteFlag_Visible     = 8,
        SpriteFlag_PrevVisible = 16
    };

    class Sprite
    {
        int16_t  m_prev_x;
        int16_t  m_prev_y;
        int16_t  m_x;
        int16_t  m_y;
        uint16_t m_sprite_id;
        uint8_t  m_pal;
        uint8_t  m_flag;
    private:
        friend class NesScrollGame;
        void _Sync();
        bool PrevVisible() const;
        bool Updated() const;
    public:
        void Move( int16_t x, int16_t y );
        void SetVisible( bool visible );
        bool Visible() const;
        void SetPalette( uint8_t pal_id );
        void SetId( uint16_t id );
        void SetMirror( uint8_t mirror );
        uint8_t Mirror() const;
    };

    enum EMirror
    {
        MirrorH = 1,
        MirrorV = 2,
    };

    static const uint8_t g_sprite_max = 64;
    Sprite  m_sprite_buffer[g_sprite_max];
protected:
    static const uint8_t g_palette[64*2] PROGMEM;

    const uint8_t* m_charset;
    const uint8_t* m_palette;

    uint8_t m_palette_id;
    uint8_t m_color[8];
    
    void DrawChrSafe( int16_t x, int16_t y, uint16_t id, uint8_t mirror );
    void DrawChrUnsafe( int16_t x, int16_t y, uint16_t id, uint8_t mirror );

public:
    NesCore();

    void InitChr( const uint8_t* charset, const uint8_t* palette );
    void DrawChr( int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t mirror );

    void SetPaletteId( uint8_t id );
};
