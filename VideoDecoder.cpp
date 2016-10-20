#include "VideoDecoder.h"
#include "config.h"

VideoDecoder::VideoDecoder()
{}

void VideoDecoder::DecodePrimitive( uint8_t id, uint8_t l0, uint8_t h0, uint8_t l1, uint8_t h1 )
{
    switch ( id )
    {
    case 0:
        for ( uint8_t i = 0; i < 8; ++i )
        {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        }
        break;

    case 1:
        for ( uint8_t i = 0; i < 8; ++i )
        {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        }
        break;

    case 2:
        for ( uint8_t i = 0; i < 8; ++i )
        {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        }
        break;

    case 3:
        for ( uint8_t i = 0; i < 8; ++i )
        {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        }
        break;

    case 4:
        for ( uint8_t i = 0; i < 8; ++i )
        {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        }
        break;

    case 5:
        for ( uint8_t i = 0; i < 8; ++i )
        {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        }
        break;

    case 6:
        for ( uint8_t i = 0; i < 8; ++i )
        {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        }
        break;

    case 7:
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*7; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 8:
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*6; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 9:
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 10:
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 11:
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 12:
        for ( uint8_t i = 0; i < 8*6; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 13:
        for ( uint8_t i = 0; i < 8*7; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 14:
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        for ( uint8_t i = 0; i < 6; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }

        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        for ( uint8_t i = 0; i < 8*6+7; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    case 15:
        for ( uint8_t w = 3; w >= 1; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 16:
        for ( uint8_t w = 4; w >= 1; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 17:
        for ( uint8_t w = 5; w >= 1; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    
    case 18:
        for ( uint8_t w = 6; w >= 1; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 19:
        for ( uint8_t w = 7; w >= 1; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 20:
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t w = 7; w >= 1; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 21:
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t w = 7; w >= 2; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 22:
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t w = 7; w >= 3; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 23:
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t w = 7; w >= 4; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 24:
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t w = 7; w >= 5; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 25:
        for ( uint8_t i = 0; i < 8*6; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t w = 7; w >= 6; w-- )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    }
}