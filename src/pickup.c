#include "global.h"
#include "random.h"
#include "constants/items.h"

#define PICKUP_ODDS 2
#define PICKUP_LEVELRANGE_1 21
#define PICKUP_LEVELRANGE_2 41

struct PickupItem
{
    u16 itemId;
    u8 chance;
};

static const struct PickupItem sPickupItemsRange1[] = {
    {ITEM_POKE_BALL, 20},
    {ITEM_POTION, 60},
    {ITEM_SUPER_POTION, 70},
    {ITEM_FULL_HEAL, 80},
    {ITEM_REPEL, 100},
    {ITEM_NONE, 0}
};

static const struct PickupItem sPickupItemsRange2[] = {
    {ITEM_GREAT_BALL, 20},
    {ITEM_SUPER_POTION, 40},
    {ITEM_FULL_HEAL, 50},
    {ITEM_REVIVE, 60},
    {ITEM_MAX_ETHER, 70},
    {ITEM_RARE_CANDY, 75},
    {ITEM_PP_UP, 80},
    {ITEM_MAX_REPEL, 90},
    {ITEM_NUGGET, 100},
    {ITEM_NONE, 0}
};

static const struct PickupItem sPickupItemsRange3[] = {
    {ITEM_ULTRA_BALL, 20},
    {ITEM_HYPER_POTION, 50},
    {ITEM_REVIVE, 60},
    {ITEM_MAX_REVIVE, 65},
    {ITEM_MAX_ELIXIR, 75},
    {ITEM_RARE_CANDY, 80},
    {ITEM_PP_UP, 85},
    {ITEM_SUN_STONE, 87},
    {ITEM_MOON_STONE, 89},
    {ITEM_NUGGET, 99},
    {ITEM_LEFTOVERS, 100},
    {ITEM_NONE, 0}
};

u16 GetPickupItem(u16 level)
{
	const struct PickupItem *itemList;
    u8 i;
    u16 rnd;

    rnd = Random() % PICKUP_ODDS;
    if(rnd != 0)
        return ITEM_NONE;

	if(level < PICKUP_LEVELRANGE_1)
        itemList = sPickupItemsRange1;
	else if(level < PICKUP_LEVELRANGE_2)
        itemList = sPickupItemsRange2;
	else
        itemList = sPickupItemsRange3;

	rnd = Random() % 100;

    for (i = 0 ; itemList[i].itemId != ITEM_NONE && itemList[i].chance < rnd ; i++);

    return itemList[i].itemId;
} 