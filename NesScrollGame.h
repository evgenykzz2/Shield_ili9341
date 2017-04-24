#pragma once

#include "NesCore.h"

class NesScrollGame : public NesCore
{
public:
    typedef uint8_t(* RequestBlock_func)(int16_t x, int16_t y);
protected:
    const uint8_t*  m_block_id;
    const uint8_t*  m_block_palette;

    int16_t             m_scroll_x;
    uint8_t             m_block_width;
    uint8_t             m_block_height;
    uint8_t*            m_block_map;
    uint8_t*            m_block_flag;
    RequestBlock_func   m_block_request;
    static const uint8_t       g_sprite_per_line_max = 32;
    uint8_t             m_sprite_of_interest[g_sprite_per_line_max];

    static const uint8_t    g_sprite_per_block_max = 4;
    uint8_t                 m_sprite_at_block[g_sprite_per_block_max];

    enum EBlockFlag
    {
        BlockFlag_Refresh = 1,
        BlockFlag_Sprite  = 2
    };

    void DrawBlockOverlayChr( int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t overlay_sprites );

public:
    NesScrollGame();
    void InitBlock( RequestBlock_func block_func, const uint8_t* block_id, const uint8_t* block_palette );
    uint8_t BlockWidth() const;
    uint8_t BlockHeight() const;
    void BlockDraw( int16_t x, int16_t y, uint8_t block_id );
    void BlockRedraw();
    void Refresh();
    void SetScroll( int16_t x );
};
