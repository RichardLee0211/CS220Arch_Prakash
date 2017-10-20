#ifndef BITS_H
#define BITS_H

typedef unsigned int uint;

/* return 000100...00B or say 2^n */
#define BIT(n) (1<<(n))
/* set bits with | */
#define BIT_SET(v, mask) (v |= (mask))
/* clear bits with & */
#define BIT_CLEAR(v, mask) (v &= ~(mask))
/* flip bits with ^, that means 1->0, 0->1 */
#define BIT_FLIP(v, mask) (v ^= (mask))

/* if any of the bits in the mask are set, return no-zero */
#define IS_SET_ANY(v, mask) (v & (mask))
/* if any of the bits in the mask are cleared, return no-zero */
#define IS_CLEAR_ANY(v, mask) (v ^ (mask))

/**
 * this is a bad API for getting bitfeild
 * TODO: ??why do we need start and mask??, start should be with length
 */
#define GET_BITFIELD(val, start, mask) ((val>>start)&mask)
#define SET_BITFIELD(val, start, mask, p) ( val = (val&!mask) | ((p&mask)<<start) )

/* create a 00011111...1111B */
#define BIT_MASK(len) (BIT(len)-1)
/* create a bitfield mask of length len starting at bit start */
/* say, 0001111..1100000B */
#define BF_MASK(start, len) (BIT_MASK(len)<<(start))
/**
 * prepare a bitmask for insertion
 * this like get bits and shift to right position
 */
#define BF_PREP(x, start, len) ( ((x)&BIT_MASK(len))<<(start) )

/**
 * exitract a bitfield of length "len" starting at bit "start"
 */
#define BF_GET_WITH_MASK(y, mask) ((y) & (mask))
#define BF_GET(y, start, len) ((y&(BF_MASK(start, len)))>>start)

/**
 * insert a bitfield x of "len" bits starting at "start" pointion into y
 */
#define BF_SET_WITH_MASK(y, prep_x, mask) ( (y) = ((y)&~(mask)) | ((prep_x)&(mask)) )
//#define BF_SET_WITH_READY_X(y, x, start, len) ((y) = ((y)&~(BF_MASK(start, len))) | ((x)&(BF_MASK(start, len))))
#define BF_SET(y, x, start, len) (BF_SET_WITH_MASK(y, BF_PREP(x, start, len), BF_MASK(start, len)))

void print_in_binary(unsigned int x);

/**
 * Virtual address is 32 bits wide
 * (a) Bits 0 through 11 constitute the PAGE OFFSET
 * (b) Bits 12, 13 and 14 constitute TLB ID.
 * (c) Bits 15 through 23 are unused.
 * (d) Bits 24 through 31 constitute TLB Tag.
 */

unsigned int get_page_offset(unsigned int address);
unsigned int get_tlb_id(unsigned int address);
unsigned int get_tlb_tag(unsigned int address);
unsigned int set_page_offset (unsigned int address, unsigned int new_offset);
unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id);
unsigned int set_tlb_tag(unsigned int address, unsigned int new_ag);

#endif
