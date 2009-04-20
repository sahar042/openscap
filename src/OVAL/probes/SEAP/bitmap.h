#pragma once
#ifndef BITMAP_H
#define BITMAP_H

#if !defined(_A)
# if !defined(NDEBUG)
#  include <assert.h>
#  define _A(x) assert(x)
# else
#  define _A(x)
# endif
#endif

#include <stdint.h>

typedef uint32_t bitmap_cell_t;
typedef uint16_t bitmap_size_t;
typedef int32_t  bitmap_bitn_t;

typedef struct {
#if defined(THREADS)
        uint8_t   locked;
#endif
        bitmap_size_t  size;  /* bit capacity = size * BITMAP_CELLSIZE */
        bitmap_size_t  realsize;
        bitmap_cell_t *cells;
} bitmap_t;

#define BITMAP_CELLSIZE (sizeof (bitmap_cell_t) * 8)

bitmap_t *bitmap_new (bitmap_size_t size);
int      *bitmap_init (bitmap_t *bitmap, bitmap_size_t size);
int      *bitmap_reinit (bitmap_t *bitmap, bitmap_size_t size);
int       bitmap_set (bitmap_t *bitmap, bitmap_bitn_t bitn);
int       bitmap_cas (bitmap_t *bitmap, bitmap_bitn_t bitn, int v);
int       bitmap_unset (bitmap_t *bitmap, bitmap_bitn_t bitn);
int       bitmap_clear (bitmap_t *bitmap);
bitmap_bitn_t bitmap_setfree (bitmap_t *bitmap);
bitmap_bitn_t bitmap_getfree (bitmap_t *bitmap);
void      bitmap_free (bitmap_t *bitmap);

#endif
