#include "VideoDecoder.h"
#include "config.h"

VideoDecoder::VideoDecoder()
{}


void VideoDecoder::Decode32x32Gradient( uint16_t color_base, uint8_t d0, uint8_t d1 )
{
	uint8_t r = (color_base >> 11) & 0x1F;	//5
    uint8_t g = (color_base >> 5) & 0x3F;	//6
    uint8_t b = (color_base) & 0x1F;	//5
	
	for (uint8_t y = 0; y < 32; ++y)
	{
		uint8_t rr = r;
		uint8_t gg = g;
		uint8_t bb = b;
		
		uint8_t h = (rr << 3) | (gg >> 3);
		uint8_t l = (gg << 5) | bb;
		//for (uint8_t x = 0; x < 8; ++x)
		{
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
			TFT_DATAPIN_SET(h); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l); TFT_SWAP_DATA_WR
		}
		r += 1;
		g += 2;
		b += 1;
	}
}

void VideoDecoder::Decode4x4Raw(const uint8_t* ptr)
{
    TFT_SWAP_FAST_PREPARE
    for ( uint16_t i = 0; i < 16; ++i )
    {
        TFT_DATAPIN_SET(ptr[i*2+0]);
        TFT_SWAP_FAST
        TFT_DATAPIN_SET(ptr[i*2+1]);
        TFT_SWAP_FAST
    }
}

void VideoDecoder::Decode8x8BinPtr( const uint8_t* ptr )
{
	uint8_t l0 = ptr[4];
    uint8_t h0 = ptr[5];
	uint8_t l1 = ptr[6];
    uint8_t h1 = ptr[7];
	
	uint8_t l2 = ptr[8];
    uint8_t h2 = ptr[9];
	uint8_t l3 = ptr[10];
    uint8_t h3 = ptr[11];

    uint8_t a_0 = ptr[0];
    uint8_t b_0 = ptr[1];
	uint8_t a_1 = ptr[2];
    uint8_t b_1 = ptr[3];

	{
		if ( (b_0 & 1) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 2) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 4) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 8) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (a_1 & 1) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 2) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 4) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 8) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}
	
	{
		if ( (b_0 & 16) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 32) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 64) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 128) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (a_1 & 16) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 32) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 64) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 128) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}

	{
		if ( (b_0 & 1) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 2) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 4) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 8) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (b_1 & 1) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 2) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 4) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 8) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}
	
	{
		if ( (b_0 & 16) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 32) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 64) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 128) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (b_1 & 16) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 32) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 64) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 128) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}
	
	/*l0 = ptr[16];
    h0 = ptr[17];
	l1 = ptr[18];
    h1 = ptr[19];
	
	l2 = ptr[20];
    h2 = ptr[21];
	l3 = ptr[22];
    h3 = ptr[23];*/

    a_0 = ptr[12];
    b_0 = ptr[13];
	a_1 = ptr[14];
    b_1 = ptr[15];

	{
		if ( (b_0 & 1) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 2) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 4) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 8) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (a_1 & 1) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 2) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 4) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 8) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}
	
	{
		if ( (b_0 & 16) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 32) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 64) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 128) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (a_1 & 16) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 32) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 64) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (a_1 & 128) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}

	{
		if ( (b_0 & 1) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 2) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 4) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 8) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (b_1 & 1) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 2) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 4) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 8) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}
	
	{
		if ( (b_0 & 16) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 32) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 64) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

		if ( (b_0 & 128) != 0 )
		{ TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
	}
	
	
	{
		if ( (b_1 & 16) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 32) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 64) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }

		if ( (b_1 & 128) != 0 )
		{ TFT_DATAPIN_SET(h3); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l3); TFT_SWAP_DATA_WR } else
		{ TFT_DATAPIN_SET(h2); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l2); TFT_SWAP_DATA_WR }
	}
}


void VideoDecoder::Decode4x4BinPtr( const uint8_t* ptr )
{
	uint8_t l0 = ptr[0];
    uint8_t h0 = ptr[1];
	uint8_t l1 = ptr[2];
    uint8_t h1 = ptr[3];
    uint8_t a = ptr[4];
    uint8_t b = ptr[5];

	if ( (a & 1) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (a & 2) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (a & 4) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 8) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 16) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 32) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 64) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 128) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 1) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (b & 2) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (b & 4) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 8) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 16) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 32) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 64) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 128) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
}

void VideoDecoder::Decode4x4Primitive(const uint8_t* ptr)
{
	uint8_t l0 = ptr[0];
    uint8_t h0 = ptr[1];
	uint8_t l1 = ptr[2];
    uint8_t h1 = ptr[3];

    TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
    TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
	
	TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
    TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR

	TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
    TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
	
	TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
    TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
	TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
}

void VideoDecoder::Decode4x4Bin( uint8_t a, uint8_t b, uint8_t l0, uint8_t h0, uint8_t l1, uint8_t h1 )
{
    if ( (a & 1) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (a & 2) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (a & 4) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 8) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 16) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 32) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 64) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (a & 128) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 1) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (b & 2) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

    if ( (b & 4) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 8) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 16) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 32) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 64) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }

	if ( (b & 128) != 0 )
    { TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR } else
    { TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR }
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

static const uint8_t g_primitive[] PROGMEM =
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
    0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,
    0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,
    0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xc0,
    0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xf0,
    0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xf8,
    0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x7e,
    0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,
    0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,
    0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,
    0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0f,
    0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1f,
    0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,
    0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xe0,
    0x00,0x00,0x00,0x00,0x00,0xc0,0xf0,0xfc,
    0x00,0x00,0x00,0x00,0x00,0xe0,0xe0,0xe0,
    0x00,0x00,0x00,0x00,0x00,0xe0,0xf8,0xff,
    0x00,0x00,0x00,0x00,0x00,0x18,0x7e,0xff,
    0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,
    0x00,0x00,0x00,0x00,0x00,0x03,0x0f,0x3f,
    0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x07,
    0x00,0x00,0x00,0x00,0x00,0x07,0x1f,0xff,
    0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x00,
    0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,
    0x00,0x00,0x00,0x00,0x80,0x80,0xc0,0xc0,
    0x00,0x00,0x00,0x00,0x80,0xc0,0xe0,0xf0,
    0x00,0x00,0x00,0x00,0xc0,0xf0,0xfc,0xff,
    0x00,0x00,0x00,0x00,0xe0,0xf8,0xff,0xff,
    0x00,0x00,0x00,0x00,0xf0,0xf0,0xf0,0xf0,
    0x00,0x00,0x00,0x00,0x18,0x7e,0xff,0xff,
    0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,
    0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0f,
    0x00,0x00,0x00,0x00,0x03,0x0f,0x3f,0xff,
    0x00,0x00,0x00,0x00,0x07,0x1f,0xff,0xff,
    0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x0f,
    0x00,0x00,0x00,0x00,0xff,0xff,0x00,0x00,
    0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,
    0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,
    0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,
    0x00,0x00,0x00,0x80,0x80,0x80,0xc0,0xf8,
    0x00,0x00,0x00,0x80,0x80,0xc0,0xc0,0xc0,
    0x00,0x00,0x00,0x80,0xc0,0xe0,0xf0,0xf8,
    0x00,0x00,0x00,0xc0,0xf0,0xfc,0xff,0xff,
    0x00,0x00,0x00,0xe0,0xf8,0xff,0xff,0xff,
    0x00,0x00,0x00,0x18,0x7e,0xff,0xff,0xff,
    0x00,0x00,0x00,0xf8,0xf8,0xf8,0xf8,0xf8,
    0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,
    0x00,0x00,0x00,0x01,0x01,0x01,0x03,0x1f,
    0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x03,
    0x00,0x00,0x00,0x01,0x03,0x07,0x0f,0x1f,
    0x00,0x00,0x00,0x03,0x0f,0x3f,0xff,0xff,
    0x00,0x00,0x00,0x07,0x1f,0xff,0xff,0xff,
    0x00,0x00,0x00,0x1f,0x1f,0x1f,0x1f,0x1f,
    0x00,0x00,0x00,0xff,0xff,0x00,0x00,0x00,
    0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,
    0x00,0x00,0x00,0xff,0xff,0xff,0xff,0x00,
    0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,
    0x00,0x00,0x80,0x80,0x80,0xc0,0xe0,0xfc,
    0x00,0x00,0x80,0x80,0xc0,0xc0,0xe0,0xe0,
    0x00,0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,
    0x00,0x00,0xc0,0xf0,0xfc,0xff,0xff,0xff,
    0x00,0x00,0xe0,0xf8,0xff,0xff,0xff,0xff,
    0x00,0x00,0x18,0x7e,0xff,0xff,0xff,0xff,
    0x00,0x00,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,
    0x00,0x00,0x01,0x01,0x01,0x03,0x07,0x3f,
    0x00,0x00,0x01,0x01,0x03,0x03,0x07,0x07,
    0x00,0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,
    0x00,0x00,0x03,0x0f,0x3f,0xff,0xff,0xff,
    0x00,0x00,0x07,0x1f,0xff,0xff,0xff,0xff,
    0x00,0x00,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,
    0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,
    0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,
    0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00,
    0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,
    0x00,0x80,0x80,0xc0,0xc0,0x80,0x80,0x00,
    0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,
    0x00,0xc0,0xf0,0xfc,0xff,0xff,0xff,0xff,
    0x00,0xe0,0xf8,0xff,0xff,0xff,0xff,0xff,
    0x00,0x18,0x7e,0xff,0xff,0xff,0xff,0xff,
    0x00,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0x00,0x01,0x01,0x03,0x03,0x01,0x01,0x00,
    0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,
    0x00,0x03,0x0f,0x3f,0xff,0xff,0xff,0xff,
    0x00,0x07,0x1f,0xff,0xff,0xff,0xff,0xff,
    0x00,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,
    0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,
    0x00,0xff,0xff,0xff,0xff,0x00,0x00,0x00,
    0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
    0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
    0x80,0x80,0x80,0xc0,0xc0,0xe0,0xe0,0xe0,
    0x80,0x80,0xc0,0xc0,0xe0,0xe0,0xf0,0xf0,
    0x80,0x80,0xc0,0xc0,0xe0,0xf0,0xfc,0xff,
    0x80,0xc0,0xc0,0xe0,0xe0,0xc0,0xc0,0x80,
    0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff,
    0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xc0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
    0xc0,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
    0xc0,0xc0,0x80,0x80,0x00,0x00,0x00,0x00,
    0xc0,0xc0,0xc0,0x80,0x80,0x00,0x00,0x00,
    0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,
    0xc0,0xc0,0xc0,0xe0,0xe0,0xf0,0xf0,0xf0,
    0xc0,0xc0,0xe0,0xe0,0xf0,0xf0,0xf8,0xf8,
    0xc0,0xc0,0xe0,0xe0,0xf0,0xfc,0xff,0xff,
    0xc0,0xe0,0xe0,0xf0,0xf0,0xe0,0xe0,0xc0,
    0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff,0xff,
    0xc0,0xf0,0xfc,0xff,0xff,0xff,0xff,0xff,
    0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
    0xe0,0xc0,0x80,0x00,0x00,0x00,0x00,0x00,
    0xe0,0xe0,0xc0,0xc0,0x80,0x80,0x00,0x00,
    0xe0,0xe0,0xe0,0x00,0x00,0x00,0x00,0x00,
    0xe0,0xe0,0xe0,0xc0,0xc0,0x80,0x80,0x80,
    0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,
    0xe0,0xe0,0xe0,0xf0,0xf0,0xf8,0xf8,0xf8,
    0xe0,0xe0,0xf0,0xf0,0xf8,0xf8,0xfc,0xfc,
    0xe0,0xe0,0xf0,0xf8,0xfc,0xff,0xff,0xff,
    0xe0,0xf0,0xf0,0xf8,0xf8,0xf0,0xf0,0xe0,
    0xe0,0xf0,0xf8,0xfc,0xfe,0xff,0xff,0xff,
    0xe0,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,
    0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
    0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,
    0xf0,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
    0xf0,0xe0,0xc0,0x80,0x00,0x00,0x00,0x00,
    0xf0,0xf0,0xe0,0xe0,0xc0,0xc0,0x80,0x80,
    0xf0,0xf0,0xf0,0xe0,0xe0,0xc0,0xc0,0xc0,
    0xf0,0xf0,0xf0,0xf0,0x00,0x00,0x00,0x00,
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
    0xf0,0xf0,0xf0,0xf8,0xf8,0xfc,0xfc,0xfc,
    0xf0,0xf0,0xf8,0xf8,0xfc,0xfc,0xfe,0xfe,
    0xf0,0xf0,0xf8,0xfc,0xff,0xff,0xff,0xff,
    0xf0,0xf8,0xf8,0xfc,0xfc,0xf8,0xf8,0xf0,
    0xf0,0xf8,0xfc,0xfe,0xff,0xff,0xff,0xff,
    0xf0,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
    0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
    0x18,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,
    0x38,0x38,0x38,0x38,0x38,0x38,0x38,0x38,
    0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,
    0xf8,0xc0,0x80,0x80,0x80,0x00,0x00,0x00,
    0xf8,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
    0xf8,0xf0,0xe0,0xc0,0x80,0x00,0x00,0x00,
    0xf8,0xf8,0xf0,0xf0,0xe0,0xe0,0xc0,0xc0,
    0xf8,0xf8,0xf8,0xf0,0xf0,0xe0,0xe0,0xe0,
    0xf8,0xf8,0xf8,0xf8,0xf8,0x00,0x00,0x00,
    0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,
    0xf8,0xf8,0xf8,0xfc,0xfc,0xfe,0xfe,0xfe,
    0xf8,0xf8,0xfc,0xfc,0xfe,0xfe,0xff,0xff,
    0xf8,0xf8,0xfc,0xff,0xff,0xff,0xff,0xff,
    0xf8,0xfc,0xfc,0xfe,0xfe,0xfc,0xfc,0xf8,
    0xf8,0xfc,0xfe,0xff,0xff,0xff,0xff,0xff,
    0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,
    0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,
    0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,
    0xfc,0xe0,0xc0,0x80,0x80,0x80,0x00,0x00,
    0xfc,0xf0,0xc0,0x00,0x00,0x00,0x00,0x00,
    0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00,0x00,
    0xfc,0xfc,0xf8,0xf8,0xf0,0xf0,0xe0,0xe0,
    0xfc,0xfc,0xfc,0xf8,0xf8,0xf0,0xf0,0xf0,
    0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0x00,0x00,
    0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,
    0xfc,0xfc,0xfc,0xfe,0xfe,0xff,0xff,0xff,
    0xfc,0xfc,0xfe,0xfe,0xff,0xff,0xff,0xff,
    0xfc,0xfe,0xfe,0xff,0xff,0xfe,0xfe,0xfc,
    0xfc,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,
    0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
    0x0e,0x0e,0x0e,0x0e,0x0e,0x0e,0x0e,0x0e,
    0x1e,0x1e,0x1e,0x1e,0x1e,0x1e,0x1e,0x1e,
    0x7e,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
    0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00,
    0xfe,0xfe,0xfc,0xfc,0xf8,0xf8,0xf0,0xf0,
    0xfe,0xfe,0xfe,0xfc,0xfc,0xf8,0xf8,0xf8,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x00,
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
    0xfe,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,
    0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
    0x01,0x01,0x03,0x03,0x07,0x0f,0x3f,0xff,
    0x01,0x03,0x03,0x07,0x07,0x03,0x03,0x01,
    0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
    0x03,0x03,0x07,0x07,0x0f,0x3f,0xff,0xff,
    0x03,0x07,0x07,0x0f,0x0f,0x07,0x07,0x03,
    0x07,0x07,0x07,0x00,0x00,0x00,0x00,0x00,
    0x07,0x07,0x0f,0x1f,0x3f,0xff,0xff,0xff,
    0x07,0x0f,0x0f,0x1f,0x1f,0x0f,0x0f,0x07,
    0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,
    0x0f,0x0f,0x1f,0x3f,0xff,0xff,0xff,0xff,
    0x0f,0x1f,0x1f,0x3f,0x3f,0x1f,0x1f,0x0f,
    0x1f,0x03,0x01,0x01,0x01,0x00,0x00,0x00,
    0x1f,0x1f,0x1f,0x1f,0x1f,0x00,0x00,0x00,
    0x1f,0x1f,0x3f,0xff,0xff,0xff,0xff,0xff,
    0x1f,0x3f,0x3f,0x7f,0x7f,0x3f,0x3f,0x1f,
    0x3f,0x07,0x03,0x01,0x01,0x01,0x00,0x00,
    0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x00,0x00,
    0x3f,0x7f,0x7f,0xff,0xff,0x7f,0x7f,0x3f,
    0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x00,
    0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,
    0xff,0xfc,0xf0,0xe0,0xc0,0xc0,0x80,0x80,
    0xff,0x7e,0x18,0x00,0x00,0x00,0x00,0x00,
    0xff,0x3f,0x0f,0x07,0x03,0x03,0x01,0x01,
    0xff,0xff,0xfc,0xf0,0xe0,0xe0,0xc0,0xc0,
    0xff,0xff,0x7e,0x18,0x00,0x00,0x00,0x00,
    0xff,0xff,0x3f,0x0f,0x07,0x07,0x03,0x03,
    0xff,0xff,0xff,0xfc,0xf8,0xf0,0xe0,0xe0,
    0xff,0xff,0xff,0x7e,0x18,0x00,0x00,0x00,
    0xff,0xff,0xff,0x3f,0x1f,0x0f,0x07,0x07,
    0xff,0xff,0xff,0xff,0xfc,0xf8,0xf0,0xf0,
    0xff,0xff,0xff,0xff,0x7e,0x18,0x00,0x00,
    0xff,0xff,0xff,0xff,0x3f,0x1f,0x0f,0x0f,
    0xff,0xff,0xff,0xff,0xff,0xfc,0xf8,0xf8,
    0xff,0xff,0xff,0xff,0xff,0x7e,0x18,0x00,
    0xff,0xff,0xff,0xff,0xff,0x3f,0x1f,0x1f,
    0xff,0xff,0xff,0xff,0xff,0xff,0x7e,0x18,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7e,
};

void VideoDecoder::Decode8x8_monoP16( uint8_t l0, uint8_t h0,   uint8_t l1, uint8_t h1,   uint8_t idd )
{
    const uint8_t* primitive = g_primitive + (uint16_t)idd * 8;
    for ( uint8_t y = 0; y < 8; ++y )
    {
        uint8_t v = pgm_read_byte(primitive + y);

        /*if ( v == 0 )
        {
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
            continue;
        }

        if ( v == 255 )
        {
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
            continue;
        }*/
        
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

void VideoDecoder::Decode8x8_bin4x( const uint8_t* color, const uint8_t* bin )
{
    for ( uint8_t y = 0; y < 8; ++y )
    {
        uint8_t c;

        c = (bin[0] & 0x3) << 1;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        c = (bin[0] & 0xC) >> 1;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        c = (bin[0] & 0x30) >> 3;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        c = (bin[0] & 0xC0) >> 5;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        bin ++;

        c = (bin[0] & 0x3) << 1;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        c = (bin[0] & 0xC) >> 1;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        c = (bin[0] & 0x30) >> 3;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        c = (bin[0] & 0xC0) >> 5;
        { TFT_DATAPIN_SET( color[c+1] ); TFT_SWAP_DATA_WR TFT_DATAPIN_SET( color[c] ); TFT_SWAP_DATA_WR }

        bin ++;
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

    if ( (v & 8) != 0 )
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
    {
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h0); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l0); TFT_SWAP_DATA_WR
    }

    c0 = 8-c0;
    for ( uint8_t x = 0; x < c0; ++x )
    {
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
        TFT_DATAPIN_SET(h1); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(l1); TFT_SWAP_DATA_WR
    }
}

void VideoDecoder::Decode8x8_Gradient( uint16_t color )
{
    for ( uint8_t y = 0; y < 8; ++y )
    {
        for ( uint8_t x = 0; x < 8; ++x )
        {
            TFT_DATAPIN_SET(color >> 8); TFT_SWAP_DATA_WR TFT_DATAPIN_SET(color & 0xFF); TFT_SWAP_DATA_WR
        }
        color += 1 + 64 + 2048;
    }
}
