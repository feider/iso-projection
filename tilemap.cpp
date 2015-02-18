#include "tilemap.h"

bool comp_tile_height(Tile * a, Tile * b)
{
	return a->z < b->z;
}
