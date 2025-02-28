#include "hidden_power.h"

u8 GetHiddenPowerType(u8 hpIV, u8 attackIV, u8 defenseIV, u8 speedIV, u8 spAttackIV, u8 spDefenseIV)
{
    u16 typeBits;
    u8 type;

    typeBits  = ((hpIV & 1) << 0)
              | ((attackIV & 1) << 1)
              | ((defenseIV & 1) << 2)
              | ((speedIV & 1) << 3)
              | ((spAttackIV & 1) << 4)
              | ((spDefenseIV & 1) << 5);

    // Subtract 3 instead of 1 below because 2 types are excluded (TYPE_NORMAL and TYPE_MYSTERY)
    // The final + 1 skips past Normal, and the following conditional skips TYPE_MYSTERY
    type = ((NUMBER_OF_MON_TYPES - 3) * typeBits) / 63 + 1;
    if (type >= TYPE_MYSTERY)
        type++;
    return type;
}