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

    case 26:
        for ( uint8_t w = 6; w <= 7; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*6; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        break;

    case 27:
        for ( uint8_t w = 5; w <= 7; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        break;

    case 28:
        for ( uint8_t w = 4; w <= 7; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        break;

    case 29:
        for ( uint8_t w = 3; w <= 7; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        break;

    case 30:
        for ( uint8_t w = 2; w <= 7; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        break;

    case 31:
        for ( uint8_t w = 1; w <= 7; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        break;

    case 32:
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }

        for ( uint8_t w = 1; w <= 7; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 33:
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }

        for ( uint8_t w = 1; w <= 6; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;
    case 34:
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }

        for ( uint8_t w = 1; w <= 5; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 35:
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }

        for ( uint8_t w = 1; w <= 4; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 36:
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }

        for ( uint8_t w = 1; w <= 3; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 37:
        for ( uint8_t i = 0; i < 8*6; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }

        for ( uint8_t w = 1; w <= 2; w++ )
        {
            for ( uint8_t i = 0; i < w; ++i )
            { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
            for ( uint8_t i = 0; i < 8-w; ++i )
            { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        }
        break;

    case 38:
        for ( uint8_t i = 0; i < 5+8*0; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5+8*6; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 39:
        for ( uint8_t i = 0; i < 5+8*1; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5+8*5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 40:
        for ( uint8_t i = 0; i < 5+8*2; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5+8*4; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 41:
        for ( uint8_t i = 0; i < 5+8*3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5+8*3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 42:
        for ( uint8_t i = 0; i < 5+8*4; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5+8*2; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 43:
        for ( uint8_t i = 0; i < 5+8*5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5+8*1; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;

    case 44:
        for ( uint8_t i = 0; i < 5+8*6; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5+8*0; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;


    case 45:
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*6; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    case 46:
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    case 47:
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    case 48:
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    case 49:
        for ( uint8_t i = 0; i < 8*4; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*2; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    case 50:
        for ( uint8_t i = 0; i < 8*5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 8*1; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        break;
    case 51:
        for ( uint8_t i = 0; i < 8*6; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 5; ++i )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
        for ( uint8_t i = 0; i < 3; ++i )
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
        break;
    }
}

void VideoDecoder::Decode4x4( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t l2, uint8_t h2,   uint8_t l3, uint8_t h3 )
{
    for ( uint8_t i = 0; i < 4; ++i )
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
    for ( uint8_t i = 0; i < 4; ++i )
    {
        TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR

        TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR
    }
}

void VideoDecoder::Decode8x8_mono16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   const uint8_t* bin )
{
    for ( uint8_t y = 0; y < 8; ++y )
    {
        uint8_t v = bin[y];
        if ( (v & 1) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

        if ( (v & 2) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

        if ( (v & 4) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

        if ( (v & 8) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

        if ( (v & 16) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

        if ( (v & 32) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

        if ( (v & 64) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

        if ( (v & 128) != 0 )
        { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
        { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
    }
}

void VideoDecoder::Decode8x8_Primitive4x2( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,  uint8_t v )
{
    if ( (v & 1) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 2) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 1) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 2) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

     if ( (v & 4) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 4) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 4) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 8) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

     if ( (v & 16) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 32) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 16) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 32) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

     if ( (v & 64) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 128) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 64) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (v & 128) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
}

void VideoDecoder::Decode8x8_cnt16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t c0 )
{
    for ( uint8_t x = 0; x < c0; ++x )
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    c0 = 32-c0;
    for ( uint8_t x = 0; x < c0; ++x )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR 
      TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR }
}
