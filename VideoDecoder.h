#pragma once

#include "Shield_ili9341.h"

class VideoDecoder : public Shield_ili9341
{
public:
    VideoDecoder();
	void Decode32x32Gradient( uint16_t color_base, uint8_t d0, uint8_t d1 );
	
	void Decode8x8BinPtr( const uint8_t* ptr );
	
	void Decode4x4Raw( const uint8_t* ptr);
	void Decode4x4Bin( uint8_t a, uint8_t b, uint8_t l0, uint8_t h0, uint8_t l1, uint8_t h1 );
	void Decode4x4BinPtr( const uint8_t* ptr );
	void Decode4x4Primitive( const uint8_t* ptr );
	void Decode4x4Primitive4C( const uint8_t* ptr );	//0.0178875
	void Decode4x4PrimitiveBlend( const uint8_t* ptr );
	
	void Decode8x8PrimitiveBlend( const uint8_t* ptr );	//0.0416

    void Decode4x4( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t l2, uint8_t h2,   uint8_t l3, uint8_t h3 );

    void Decode8x8_mono16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   const uint8_t* bin );
    void Decode8x8_monoP16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t idd );
    void Decode8x8_bin4x( const uint8_t* color, const uint8_t* bin );

    void Decode8x8_cnt16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t c0 );
    void Decode8x8_Primitive4x2( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,  uint8_t v );

    

    void Decode8x8_Gradient( uint16_t color );
};
