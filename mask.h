//
// Created by Yuval Rashman (Id: 214616161), Shacked Dror (Id: 326300548), Yanir Shmulevich (Id: 209952308) on 11/11/2022.
//

#include "definesLib.h"

#define IS_ALL_BITS_OFF(mask) mask == 0
#define IS_ALL_BITS_ON(mask) IS_ALL_BITS_OFF(~mask)
#define TURN_ON_BIT(size) (ONE << (size - ONE))

typedef unsigned int typ; // we chose max 32 bits can be change


void initMask(typ *mask, unsigned short usSize);

void turnOnUnusedBits(typ *mask, unsigned short usSize);

BOOL isIndexBitOn(typ mask, unsigned short usBitIndex);

void combineMasks(typ mask1, typ mask2, typ *result);

void andMasks(typ mask1, typ mask2, typ *result);

void turnOnBit(typ *mask, unsigned short usBitIndex);

void turnOffBit(typ *mask, unsigned short usBitIndex);

void changeBit(typ *mask, unsigned short usBitIndex);

int copyNibbleByLengthOfNum(int numBin, int length);

unsigned int decimalAsHex(int num);

//--------------------------------------------------------------------------------------------------------------------
//                                                         initMask
//                                                         --------
//
// General : The function initialize mask (put 1 in all bits) by specific usSize.
//
// Parameters :
// mask - pointer to the mask we are going to initialize (In)
// usSize - the size of the mask (In)
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void initMask(typ *mask, unsigned short usSize) {
    //*mask = (1 << usSize) - 1; problem if usSize equal to typ size
    typ temp = TURN_ON_BIT(usSize);
    *mask = temp;
    temp = ~(~temp + ONE);
    *mask |= temp;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                      turnOnUnusedBits
//                                                      ----------------
//
// General : The function turn on all the bits after the mask size.
//
// Parameters :
// mask - pointer to the mask we are going to change (In)
// usSize - the size of the mask (In)
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void turnOnUnusedBits(typ *mask, unsigned short usSize) {
    typ temp;
    initMask(&temp, usSize);
    *mask |= ~(temp);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        isIndexBitOn
//                                                        ------------
//
// General : The function check if  a bit is on.
//
// Parameters :
// mask - pointer to the mask we are going to initialize (In)
// usBitIndex - the index of the bit (In)
//
// Return Value : boolean that indicated if the bit is on or off.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL isIndexBitOn(typ mask, unsigned short usBitIndex) {
    return mask & (TURN_ON_BIT(usBitIndex));
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        combineMasks
//                                                        ------------
//
// General : The function combine to masks into one.
// for example: 0011 | 1101 =  1111
//
// Parameters :
// mask1 - first mask (In)
// mask2 - second mask (In)
// result - pointer to mask that we will save the result in (In)
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void combineMasks(typ mask1, typ mask2, typ *result) {
    *result = (mask1 | mask2);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                          andMaks
//                                                          -------
//
// General : The function do and operator between two masks.
// for example: 0011 & 1101 =  0001
//
// Parameters :
// mask1 - first mask (In)
// mask2 - second mask (In)
// result - pointer to mask that we will save the result in (In)
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void andMasks(typ mask1, typ mask2, typ *result) {
    *result = (mask1 & mask2);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                          turnOnBit
//                                                          --------
//
// General : this function will turn on the bit in the place of usBitIndex.
//
// Parameters :
// usBitIndex - the regular number
// mask - pointer to the mask
//
// Return Value : None.
//--------------------------------------------------------------------------------------------------------------------
void turnOnBit(typ *mask, unsigned short usBitIndex) {
    *mask |= TURN_ON_BIT(usBitIndex);
}


//--------------------------------------------------------------------------------------------------------------------
//                                                         turnOffBit
//                                                         ----------
//
// General : this function will turn off the bit in the place of usBitIndex.
//
// Parameters :
// usBitIndex - the regular number
// mask - pointer to the mask
//
// Return Value : None.
//--------------------------------------------------------------------------------------------------------------------
void turnOffBit(typ *mask, unsigned short usBitIndex) {
    *mask &= ~TURN_ON_BIT(usBitIndex);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                         changeBit
//                                                         ---------
//
// General : this function will change the value of the bit regardless if he on or off like xor.
//
// Parameters :
// usBitIndex - the bit index number
// mask - pointer to the mask
//
// Return Value : None.
//--------------------------------------------------------------------------------------------------------------------
void changeBit(typ *mask, unsigned short usBitIndex) {
    *mask ^= TURN_ON_BIT(usBitIndex);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  copyNibbleByLengthOfNum
//                                                  -----------------------
//
// General : this function will copy the last nibble to the nibbles before him
// in the length that we want
// for example:
// numBin = 0xf    (0000 0000 0000 0000 0000 0000 0000 1111)
// length = 3
//
//                 (0000 0000 0000 0000 1111 1111 1111 1111)
//
//
// Parameters :
// numBin - the number we will copy his last nibble
// length - the length that we want to copy
//
// Return Value : the new number with the nibble
//--------------------------------------------------------------------------------------------------------------------
int copyNibbleByLengthOfNum(int numBin, int length) {
    int count, shift = 4, newNumBin = numBin;
    for (count = 0; count < length; shift += 4, count++) {
        int tmp = numBin
                << shift; // we move the original nibbles as the length, every time shift will grow by 4, so we go to the nibble before the last one
        // for example: 0xf << 8
        // 0xf00

        newNumBin |= tmp;
    }
    return newNumBin;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                      decimalAsHex
//                                                      ------------
//
// General : this function will convert a decimal number to hex number
// this means that each decimal digit will be relocated into a nibble
// for example:
// num = 1234     ( 0000 0000 0000 0000 0000 0100 1101 0010 ) or 0x4D2
// will return numBin:
// numBin = 4660      ( 0000 0000 0000 0000 0001 0010 0011 0100 ) or 0x1234
//
// the reason I do it is that now each decimal digit is located in its own nibble
//
//
// Parameters :
// num - the number we relocated
//
// Return Value : the relocated number
//--------------------------------------------------------------------------------------------------------------------
unsigned int decimalAsHex(int num) {
    unsigned int numBin = 0;
    typ mask = 0xf;

    while ((numBin & mask) ==
           0) // while the last nibble is bigger than 0, represent the number in hex, keep the same number
    {
        numBin >>= 4;
        numBin |= ((num % TEN) << 28);
        num /= TEN;
    }

    return numBin;
}

