#include "NesCore.h"
#include "config.h"

const uint8_t NesCore::g_palette[64*2] PROGMEM =
{
    0x73, 0xae, 0x20, 0x71, 0x00, 0x15, 0x40, 0x13, 0x88, 0x0e, 0xa8, 0x02, 0xa0, 0x00, 0x78, 0x60, 0x41, 0xe0, 0x02, 0xe0, 0x02, 0x20, 0x01, 0xe2, 0x19, 0xeb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbd, 0x97, 0x03, 0x7d, 0x21, 0x7d, 0x80, 0x1e, 0xb8, 0x17, 0xe0, 0x0b, 0xd9, 0x60, 0xca, 0xe1, 0x8b, 0x60, 0x04, 0xe0, 0x05, 0x60, 0x04, 0x67, 0x04, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0x3d, 0xff, 0x5c, 0xff, 0xa4, 0x7f, 0xf3, 0x7f, 0xfb, 0xf6, 0xfb, 0xec, 0xfc, 0x67, 0xf5, 0xe7, 0x86, 0x62, 0x4e, 0xe9, 0x5f, 0x13, 0x07, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xaf, 0xff, 0xc6, 0xff, 0xd6, 0x7f, 0xfe, 0xff, 0xfe, 0xfb, 0xfd, 0xf6, 0xfe, 0x75, 0xff, 0xf4, 0xe7, 0xf4, 0xaf, 0x77, 0xb7, 0xf9, 0x9f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

NesCore::NesCore() :
    m_charset(0), m_palette(0),
    m_block_id(0), m_block_palette(0),
    m_palette_id(255)
{}

void NesCore::InitChr( const uint8_t* charset, const uint8_t* palette )
{
    m_charset = charset;
    m_palette = palette;
    m_palette_id = 255;
}

void NesCore::InitBlock( const uint8_t* block_id, const uint8_t* block_palette )
{
    m_block_id = block_id;
    m_block_palette = block_palette;
}

void NesCore::SetPaletteId( uint8_t id )
{
    if ( m_palette_id == id )
        return;
    m_palette_id = id;
    for ( uint8_t p = 0; p < 4; ++p )
    {
        uint8_t pl = pgm_read_byte_near(m_palette + id*4 + p);
        m_color[p*2+0] = pgm_read_byte_near(g_palette + pl*2 + 0);
        m_color[p*2+1] = pgm_read_byte_near(g_palette + pl*2 + 1);
    }
}

void NesCore::DrawChrSafe( int16_t x, int16_t y, uint16_t id, uint8_t mirror )
{

}

void NesCore::DrawChrUnsafe( int16_t x, int16_t y, uint16_t id, uint8_t mirror )
{
    SetWindow( x, y, x+7, y+7 );
    StreamStart();
    SendCmd(0x2c);
    TFT_DATA_MODE
    if ( mirror == 0 )
    {
        for ( uint8_t yi = 0; yi < 8; ++yi )
        {
            uint8_t b0 = pgm_read_byte_near(m_charset+id*16+yi+0);
            uint8_t b1 = pgm_read_byte_near(m_charset+id*16+yi+8);
            for ( uint8_t xi = 0; xi < 8; ++xi )
            {
                uint8_t ix = ((b0>>6)&2) | ( (b1>>5) & 4);
                TFT_DATAPIN_SET(m_color[ix+0]);
                TFT_SWAP_DATA_WR
                TFT_DATAPIN_SET(m_color[ix+1]);
                TFT_SWAP_DATA_WR
                b0 <<= 1;
                b1 <<= 1;
            }
        }
    } else if ( mirror == MirrorH )
    {
        for ( uint8_t yi = 0; yi < 8; ++yi )
        {
            uint8_t b0 = pgm_read_byte_near(m_charset+id*16+yi+0);
            uint8_t b1 = pgm_read_byte_near(m_charset+id*16+yi+8);
            for ( uint8_t xi = 0; xi < 8; ++xi )
            {
                uint8_t ix = ((b0&1) << 1) | ( (b1&1) << 2);
                TFT_DATAPIN_SET(m_color[ix+0]);
                TFT_SWAP_DATA_WR
                TFT_DATAPIN_SET(m_color[ix+1]);
                TFT_SWAP_DATA_WR
                b0 >>= 1;
                b1 >>= 1;
            }
        }
    } else if ( mirror == MirrorV )
    {
        for ( uint8_t yi = 0; yi < 8; ++yi )
        {
            uint8_t b0 = pgm_read_byte_near(m_charset+id*16+(7-yi)+0);
            uint8_t b1 = pgm_read_byte_near(m_charset+id*16+(7-yi)+8);
            for ( uint8_t xi = 0; xi < 8; ++xi )
            {
                uint8_t ix = ((b0>>6)&2) | ( (b1>>5) & 4);
                TFT_DATAPIN_SET(m_color[ix+0]);
                TFT_SWAP_DATA_WR
                TFT_DATAPIN_SET(m_color[ix+1]);
                TFT_SWAP_DATA_WR
                b0 <<= 1;
                b1 <<= 1;
            }
        }
    } else if ( mirror == (uint8_t)(MirrorH | MirrorV) )
    {
        for ( uint8_t yi = 0; yi < 8; ++yi )
        {
            uint8_t b0 = pgm_read_byte_near(m_charset+id*16+(7-yi)+0);
            uint8_t b1 = pgm_read_byte_near(m_charset+id*16+(7-yi)+8);
            for ( uint8_t xi = 0; xi < 8; ++xi )
            {
                uint8_t ix = ((b0&1) << 1) | ( (b1&1) << 2);
                TFT_DATAPIN_SET(m_color[ix+0]);
                TFT_SWAP_DATA_WR
                TFT_DATAPIN_SET(m_color[ix+1]);
                TFT_SWAP_DATA_WR
                b0 >>= 1;
                b1 >>= 1;
            }
        }
    }
}

void NesCore::DrawChr( int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t mirror )
{
    if ( x >= m_width || y >= m_height || x+8 < 0 || y+8 < 0 )
        return;
    SetPaletteId(pal);
    if ( x >= 0 && x+8 <= m_width && y >= 0 && y+8 <= m_height )
        DrawChrUnsafe( x, y, id, mirror );
    else
        DrawChrSafe( x, y, id, mirror );
}

void NesCore::DrawBlock( int16_t x, int16_t y, uint8_t block_id )
{
    for ( uint8_t yi = 0; yi <= 1; ++yi )
    {
        for ( uint8_t xi = 0; xi <= 1; ++xi )
            DrawChr( x+xi*8, y+yi*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+yi + xi*2), pgm_read_byte_near( m_block_palette + block_id ), 0 );
    }
}
