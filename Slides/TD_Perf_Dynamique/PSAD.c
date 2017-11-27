#define PIXEL_SAD_C( name, lx, ly ) \
int name( uint8_t *pix1, int i_stride_pix1,  \
                 uint8_t *pix2, int i_stride_pix2 ) \
{                                                   \
    int i_sum = 0;                                  \
    int x, y;                                       \
    for( y = 0; y < ly; y++ )                       \
    {                                               \
        for( x = 0; x < lx; x++ )                   \
        {                                           \
            i_sum += abs( pix1[x] - pix2[x] );      \
        }                                           \
        pix1 += i_stride_pix1;                      \
        pix2 += i_stride_pix2;                      \
    }                                               \
    return i_sum;                                   \
}
