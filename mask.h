//
// Created by Yuval Rashman (Id: 214616161), Shacked Dror (Id: 326300548), Yanir Shmulevich (Id: 209952308) on 11/11/2022.
//

#include "definesLib.h"

#define FULL_NIBBLE 0xF
#define NIBBLE_SIZE 4

#define IS_ALL_BITS_OFF(mask) mask == ZERO
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

int copyNibbleByTimes(unsigned short usNibble, unsigned short usTimes);

unsigned int decimalAsHex(int nNum);

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
//                                                    copyNibbleByTimes
//                                                    -----------------
//
// General : this function will copy the last nibble to the nibbles before him
// in the usTimes that we want
// for example:
// usNibble = 0xf (1111)
// usTimes = 3
// result = (1111 1111 1111 1111)
//
//
// Parameters :
// usNibble - the number we will copy his last nibble
// usTimes - the usTimes that we want to copy
//
// Return Value : the new number with the nibble
//--------------------------------------------------------------------------------------------------------------------
int copyNibbleByTimes(unsigned short usNibble, unsigned short usTimes) {
    int newNumBin = usNibble;
    for (; usTimes; usTimes--) {
        newNumBin <<= NIBBLE_SIZE;
        newNumBin += usNibble;
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
// nNum = 1234 (0100 1101 0010) or 0x4D2
// will turn to: 4660 (0001 0010 0011 0100 ) or 0x1234
//
// Parameters :
// nNum - the number we relocated
//
// Return Value : the relocated number / the new number
//--------------------------------------------------------------------------------------------------------------------
unsigned int decimalAsHex(int nNum) {
    unsigned int numBin = ZERO;
    while (!(numBin & FULL_NIBBLE)) // while the last nibble is bigger than 0, represent the number in hex.
    {
        numBin >>= NIBBLE_SIZE;
        numBin |= ((nNum % TEN) << 28);
        nNum /= TEN;
    }
    return numBin;
}

