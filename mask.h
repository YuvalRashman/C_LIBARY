//
// Created by Yuval Rashman (Id: 214616161), Shacked Dror (Id: 326300548), Yanir Shmulevich (Id: 209952308) on 11/11/2022.
//

#include "definesLib.h"

#define MASK_MAX_SIZE 32

#define IS_ALL_BITS_OFF(mask) mask == 0
#define IS_ALL_BITS_ON(mask) IS_ALL_BITS_OFF(~mask)

#define TURN_ON_BIT(size) (ONE << (size - ONE))

typedef unsigned int typ; // we chose max 32 bits can be change

//--------------------------------------------------------------------------------------------------------------------
//                                                      initMask
//                                                      --------
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
//                                                    turnOnUnusedBits
//                                                    ----------------
//
// General : The function turn on all the bits after the mask size.
//
// Parameters :
// mask - pointer to the mask we are going to initialize (In)
// usSize - the size of the mask (In)
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void turnOnUnusedBits(typ *mask, unsigned short usSize) {
    initMask(mask, usSize);
    *mask = ~(*mask);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    turnOnUnusedBits
//                                                    ----------------
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
    return mask & (TURN_ON_BIT(usBitIndex)));
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    combineMasks
//                                                    ------------
//
// General : The function check if  a bit is on.
//
// Parameters :
// mask - pointer to the mask we are going to  (In)
// usBitIndex - the index of the bit (In)
//
// Return Value : boolean that indicated if the bit is on or off.
//
//--------------------------------------------------------------------------------------------------------------------
void combineMasks(typ mask1, typ mask2, typ *result) {
    result = (mask1 | mask2);
}

//----------------------------------------------------------------------
//                      turnOnBit
//
// General : this function will turn on the bit in the place we want
// for example:
// NBitIndex  = 0
// we want to turn on the 4 bit ( 8 - 1000)
// indexOfBit = 4
//
//
//
//
// Parameters :
// NBitIndex - the regular number
// indexOfBit - our mask
//
// Return Value : the same number with the turned on bit
//----------------------------------------------------------------------
void turnOnBit(typ *mask, int usBitIndex) {
    *mask |= TURN_ON_BIT(usBitIndex);
}

void turnOffBit(typ *mask, int usBitIndex) {
    *mask &= ~TURN_ON_BIT(usBitIndex);
}

void changeBit(typ *mask, int usBitIndex) {
    *mask ^= TURN_ON_BIT(usBitIndex);
}

int shiftMaskLeft(typ mask, unsigned int nN) {
    return (mask << nN) | (mask >> (MASK_MAX_SIZE - nN));
}

//----------------------------------------------------------------------
//                      copyNibleByLengthOfNum
//
// General : this function will copy the last nible to the nibles before him
// in the length that we want
// for example:
// numBin = 0xf    (0000 0000 0000 0000 0000 0000 0000 1111)
// length = 3
//
//                 (0000 0000 0000 0000 1111 1111 1111 1111)
//
//
// Parameters :
// numBin - the number we will copy his last nible
// length - the length that we want to copy
//
// Return Value : the new number with the nibles
//----------------------------------------------------------------------

int copyNibleByLengthOfNum(int numBin, int length) {
    int count, shift = 4, newNumBin = numBin;
    for (count = 0; count < length; shift += 4, count++) {
        int tmp = numBin
                << shift; // we move the original nibles as the length, every time shift will grow by 4 so we go to the nible before the last one
        // for example: 0xf << 8
        // 0xf00

        newNumBin |= tmp;
    }
    return newNumBin;
}

//----------------------------------------------------------------------
//                      decimalToHex
//
// General : this function will convert a decimal number to hex number
// this means that each decimal digit will be relocated into a nible
// for example:
// num = 1234     ( 0000 0000 0000 0000 0000 0100 1101 0010 ) or 0x4D2
// will return numBin:
// numBin = 4660      ( 0000 0000 0000 0000 0001 0010 0011 0100 ) or 0x1234
//
// the reason I do it is that now each decimal digit is located in its own nible
//
//
// Parameters :
// num - the number we relocated
//
// Return Value : the relocated number
//----------------------------------------------------------------------
unsigned int decimalToHex(int num) {
    unsigned int numBin = 0;
    typ mask = 0xf;

    while ((numBin & mask) ==
           0) // while the last nibel is bigger then 0, represent the nmber in hex, keep the same number
    {
        numBin >>= 4;
        numBin |= ((num % TEN) << 28);
        num /= TEN;
    }

    return numBin;
}
