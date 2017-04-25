#include "NesScrollGame.h"
#include "config.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NesScrollGame::NesScrollGame() :
    m_block_id(0), m_block_palette(0), m_scroll_x(0), m_scroll_prev_x(0), m_block_map(0)
{}

void NesScrollGame::InitBlock( RequestBlock_func block_func, const uint8_t* block_id, const uint8_t* block_palette )
{
    m_block_id = block_id;
    m_block_palette = block_palette;
    m_block_request = block_func;

    if ( m_block_map != 0 )
        delete [] m_block_map;
    if ( m_block_flag != 0 )
        delete [] m_block_flag;

    m_block_width  = Width() / 16;
    m_block_height = Height() / 16;
    m_block_map = new uint8_t[m_block_width*m_block_height];
    m_block_flag = new uint8_t[m_block_width*m_block_height];
    m_block_x = new int16_t[m_block_width];
    memset( m_block_flag, 0, m_block_width*m_block_height );
    for ( int n = 0; n < m_block_width; ++n )
        m_block_x[n] = n;
}

uint8_t NesScrollGame::BlockWidth() const
{
    return m_block_width;
}

uint8_t NesScrollGame::BlockHeight() const
{
    return m_block_height;
}

void NesScrollGame::BlockDraw( int16_t x, int16_t y, uint8_t block_id )
{
    for ( uint8_t yi = 0; yi <= 1; ++yi )
    {
        for ( uint8_t xi = 0; xi <= 1; ++xi )
            DrawChr( x+xi*8, y+yi*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+yi + xi*2), pgm_read_byte_near( m_block_palette + block_id ), 0 );
    }
}

void NesScrollGame::BlockRedraw()
{
  for ( int y = 0; y < m_block_height; ++y )
  {
    int yx = y*m_block_width;
    for ( int x = 0; x < m_block_width; ++x )
    {
      uint8_t block = m_block_request(x, y);
      m_block_map[x + yx] = block;
      BlockDraw( x*16, y*16, block );
    }
  }
}


void NesScrollGame::DrawBlockOverlayChr( int16_t x_world, int16_t x, int16_t y, uint16_t id, uint8_t pal, uint8_t overlay_sprites )
{
    uint8_t overlay = 0;
    for ( uint8_t n = 0; n < overlay_sprites; ++n )
    {
        uint8_t idd = m_sprite_of_interest[n];
        if ( m_sprite_buffer[idd].m_y+7 >= y && m_sprite_buffer[idd].m_y <= y+7 &&
             m_sprite_buffer[idd].m_x+7 >= x_world && m_sprite_buffer[idd].m_x <= x_world+7 )
        {
            m_sprite_at_block[overlay++] = idd;
            if (overlay >= g_sprite_per_block_max)
                break;
        }
    }

    //No overlay at block
    if ( overlay == 0 )
    {
        DrawChr( x, y, id, pal, 0 );
        return;
    }

    SetPaletteId(pal);
    SetWindow( x, y, x+7, y+7 );
    StreamStart();
    SendCmd(0x2c);
    TFT_DATA_MODE

    /*if ( overlay == 1 )
    {
        uint8_t idd = m_sprite_at_block[0];
        uint16_t sprite_idd = m_sprite_buffer[idd].m_sprite_id*16;
        int16_t sprite_x = m_sprite_buffer[idd].m_x;
        int16_t sprite_y = m_sprite_buffer[idd].m_y;

        for ( uint8_t yi = 0; yi < 8; ++yi )
        {
            uint8_t b0 = pgm_read_byte_near(m_charset+id*16+yi+0);
            uint8_t b1 = pgm_read_byte_near(m_charset+id*16+yi+8);
            for ( uint8_t xi = 0; xi < 8; ++xi )
            {
                uint8_t effect_ix = ((b0>>6)&2) | ( (b1>>5) & 4);
                uint8_t effect_pal = pal;
                
                int16_t ov_y = y+yi - sprite_y;
                int16_t ov_x = x_world+xi - sprite_x;
                if ( ov_x >= 0 && ov_x < 8 && ov_y >= 0 && ov_y < 8 )
                {
                    uint8_t sprite_b0 = pgm_read_byte_near(m_charset+sprite_idd+ov_y+0) << ov_x;
                    uint8_t sprite_b1 = pgm_read_byte_near(m_charset+sprite_idd+ov_y+8) << ov_x;
                    uint8_t ix = ((sprite_b0>>6)&2) | ( (sprite_b1>>5) & 4);
                    if ( ix != 0 )
                    {
                        effect_ix = ix;
                        effect_pal = m_sprite_buffer[idd].m_pal;
                    }
                }

                if ( pal == effect_pal )
                {
                    TFT_DATAPIN_SET(m_color[effect_ix+0]);
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET(m_color[effect_ix+1]);
                    TFT_SWAP_DATA_WR
                } else
                {
                    m_palette_id = id;
                    uint8_t pl = pgm_read_byte_near(m_palette + effect_pal*4 + (effect_ix >> 1));
                    TFT_DATAPIN_SET( pgm_read_byte_near(g_palette + pl*2 + 0) )
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET( pgm_read_byte_near(g_palette + pl*2 + 1) )
                    TFT_SWAP_DATA_WR
                }
                b0 <<= 1;
                b1 <<= 1;
            }
        }
    } else*/
    {
        for ( uint8_t yi = 0; yi < 8; ++yi )
        {
            uint8_t b0 = pgm_read_byte_near(m_charset+id*16+yi+0);
            uint8_t b1 = pgm_read_byte_near(m_charset+id*16+yi+8);
            for ( uint8_t xi = 0; xi < 8; ++xi )
            {
                uint8_t effect_ix = ((b0>>6)&2) | ( (b1>>5) & 4);
                uint8_t effect_pal = pal;

                for ( uint8_t n = 0; n < overlay; ++n )
                {
                    uint8_t idd = m_sprite_at_block[n];
                    int16_t ov_y = y+yi - m_sprite_buffer[idd].m_y;
                    int16_t ov_x = x_world+xi - m_sprite_buffer[idd].m_x;
                    if ( ov_x >= 0 && ov_x < 8 && ov_y >= 0 && ov_y < 8 )
                    {
                        if ( m_sprite_buffer[idd].Mirror() & MirrorV )
                            ov_y = 7-ov_y;
                        if ( m_sprite_buffer[idd].Mirror() & MirrorH )
                            ov_x = 7-ov_x;
                        uint8_t sprite_b0 = pgm_read_byte_near(m_charset+m_sprite_buffer[idd].m_sprite_id*16+ov_y+0) << ov_x;
                        uint8_t sprite_b1 = pgm_read_byte_near(m_charset+m_sprite_buffer[idd].m_sprite_id*16+ov_y+8) << ov_x;
                        uint8_t ix = ((sprite_b0>>6)&2) | ( (sprite_b1>>5) & 4);
                        if ( ix != 0 )
                        {
                            effect_ix = ix;
                            effect_pal = m_sprite_buffer[idd].m_pal;
                        }
                    }
                }

                if ( pal == effect_pal )
                {
                    TFT_DATAPIN_SET(m_color[effect_ix+0]);
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET(m_color[effect_ix+1]);
                    TFT_SWAP_DATA_WR
                } else
                {
                    m_palette_id = id;
                    uint8_t pl = pgm_read_byte_near(m_palette + effect_pal*4 + (effect_ix >> 1));
                    TFT_DATAPIN_SET( pgm_read_byte_near(g_palette + pl*2 + 0) )
                    TFT_SWAP_DATA_WR
                    TFT_DATAPIN_SET( pgm_read_byte_near(g_palette + pl*2 + 1) )
                    TFT_SWAP_DATA_WR
                }

                b0 <<= 1;
                b1 <<= 1;
            }
        }
    }
}

void NesScrollGame::Refresh()
{
    int16_t block_ofs = m_scroll_x / 16;
    int16_t block_prev_ofs = m_scroll_prev_x / 16;
    int16_t block_last = block_ofs+BlockWidth()-1;
    for ( int y = 0; y < m_block_height; ++y )
    {
        int yx = y*m_block_width;
        for ( int x = 0; x < m_block_width; ++x )
            m_block_flag[x+yx] = 0;
    }
    m_scroll_prev_x = m_scroll_x;

    if ( block_ofs > block_prev_ofs )
    {
        int16_t draw_x = block_last % BlockWidth();
        m_block_x[draw_x] = block_last;
        for ( int y = 0; y < m_block_height; ++y )
        {
            int yx = y*m_block_width;
            uint8_t block = m_block_request(block_last, y);
            m_block_map[draw_x+yx] = block;
            m_block_flag[draw_x+yx] = BlockFlag_Refresh;
        }
    }

    for ( uint8_t i = 0; i < g_sprite_max; ++i )
    {
        if ( !m_sprite_buffer[i].Updated() )
            continue;

        //Erase on previous position
        if ( m_sprite_buffer[i].PrevVisible() )
        {
            int16_t xp = m_sprite_buffer[i].m_prev_x / 16;
            int16_t yp = m_sprite_buffer[i].m_prev_y / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Refresh;
            xp = (m_sprite_buffer[i].m_prev_x+7) / 16;
            yp = m_sprite_buffer[i].m_prev_y / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Refresh;
            xp = m_sprite_buffer[i].m_prev_x / 16;
            yp = (m_sprite_buffer[i].m_prev_y+7) / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Refresh;
            xp = (m_sprite_buffer[i].m_prev_x+7) / 16;
            yp = (m_sprite_buffer[i].m_prev_y+7) / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Refresh;
        }

        //Draw on new position
        if ( m_sprite_buffer[i].Visible() )
        {
            int16_t xp = m_sprite_buffer[i].m_x / 16;
            int16_t yp = m_sprite_buffer[i].m_y / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Sprite;
            xp = (m_sprite_buffer[i].m_x+7) / 16;
            yp = m_sprite_buffer[i].m_y / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Sprite;
            xp = m_sprite_buffer[i].m_x / 16;
            yp = (m_sprite_buffer[i].m_y+7) / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Sprite;
            xp = (m_sprite_buffer[i].m_x+7) / 16;
            yp = (m_sprite_buffer[i].m_y+7) / 16;
            if ( xp >= block_ofs && xp <= block_last && yp >= 0 && yp < m_block_height )
                m_block_flag[xp%BlockWidth()+yp*m_block_width] |= BlockFlag_Sprite;
        }
    }

    for ( int y = 0; y < m_block_height; ++y )
    {
        uint8_t sprite_num = 0;
        int yx = y*m_block_width;

        for ( uint8_t i = 0; i < g_sprite_max; ++i )
        {
            if ( !m_sprite_buffer[i].Visible() )
                continue;
            if ( m_sprite_buffer[i].m_y+7 >= y*16 && m_sprite_buffer[i].m_y <= y*16+15 &&
                 m_sprite_buffer[i].m_x+7 >= m_scroll_x && m_sprite_buffer[i].m_x < m_scroll_x+Width() )
            {
                m_sprite_of_interest[sprite_num++] = i;
                if (sprite_num >= g_sprite_per_line_max)
                    break;
            }
        }
        

        //Now draw
        for ( int x = 0; x < m_block_width; ++x )
        {
            uint8_t f = m_block_flag[x+yx];
            if ( f == 0 )
                continue;

            uint8_t block_id = m_block_map[x+yx];
            if ( (uint8_t)( f & (BlockFlag_Sprite | BlockFlag_Refresh )) != 0 )
            {
                uint8_t pal = pgm_read_byte_near( m_block_palette + block_id );
                if ( (uint8_t)( f & (BlockFlag_Sprite) ) != 0 )
                {
                    DrawBlockOverlayChr( m_block_x[x]*16+0*8, x*16+0*8, y*16+0*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+0 + 0*2), pal, sprite_num );
                    DrawBlockOverlayChr( m_block_x[x]*16+1*8, x*16+1*8, y*16+0*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+0 + 1*2), pal, sprite_num );
                    DrawBlockOverlayChr( m_block_x[x]*16+0*8, x*16+0*8, y*16+1*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+1 + 0*2), pal, sprite_num );
                    DrawBlockOverlayChr( m_block_x[x]*16+1*8, x*16+1*8, y*16+1*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+1 + 1*2), pal, sprite_num );
                } else
                {
                    //Blank background
                    DrawChr( x*16+0*8, y*16+0*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+0 + 0*2), pal, 0 );
                    DrawChr( x*16+1*8, y*16+0*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+0 + 1*2), pal, 0 );
                    DrawChr( x*16+0*8, y*16+1*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+1 + 0*2), pal, 0 );
                    DrawChr( x*16+1*8, y*16+1*8, 256 + pgm_read_byte_near(m_block_id + block_id*4+1 + 1*2), pal, 0 );
                }
            }
        }
    }

    //DrawSprite
    /*for ( uint8_t i = 0; i < g_sprite_max; ++i )
    {
        if ( !m_sprite_buffer[i].Visible() )
            continue;
        DrawChr( m_sprite_buffer[i].m_x, m_sprite_buffer[i].m_y, m_sprite_buffer[i].m_sprite_id, m_sprite_buffer[i].m_pal, m_sprite_buffer[i].Mirror() );
    }*/

    for ( uint8_t i = 0; i < g_sprite_max; ++i )
    {
        if ( !m_sprite_buffer[i].Updated() )
            continue;
        m_sprite_buffer[i]._Sync();
    }
}

void NesScrollGame::SetScroll( int16_t x )
{
    m_scroll_x = x;
    VerticalScrollingStartAddress( x % Width() );
}
