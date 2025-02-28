#ifndef GUARD_MAP_PREVIEW_SCREEN_H
#define GUARD_MAP_PREVIEW_SCREEN_H

struct MapPreviewScreen
{
    u8 mapsec;
    const void *tilesptr;
    const void *tilemapptr;
    const void *palptr;
};

const struct MapPreviewScreen * GetDungeonMapPreviewScreenInfo(u8 mapsec);

#endif //GUARD_MAP_PREVIEW_SCREEN_H
