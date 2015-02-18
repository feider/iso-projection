#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

class Tile
{
protected:
public:
	int type;
	int x, y, z;
	Tile(int x, int y, int z, int type)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->type = type;
	}
};

bool comp_tile_height(Tile * a, Tile * b);


typedef std::vector<Tile*> Tile_Pile;

class Tilemap
{
protected:
	Tile_Pile * tilemap = nullptr;
	int size_x, size_y;
public:
	Tilemap(int x, int y, int type)
	{
		size_x = x;
		size_y = y;

		tilemap = new Tile_Pile[size_x * size_y];

		for(int ix = 0; ix<x; ix++)
		{
			for(int iy = 0; iy<y; iy++)
			{
				add_tile(ix, iy, 0, type);
			}
		}
	}

	void add_tile(int x, int y, int z,  int type)
	{
		auto i = get_index(x, y);
		bool found = false;
		for(auto & t : tilemap[i])
		{
			if(t->z == z)
			{
				found = true;
				t->type = type;
			}
		}
		if(!found)
		{
			tilemap[i].push_back(new Tile(x, y, z, type));
			std::sort(tilemap[i].begin(), tilemap[i].end(), comp_tile_height);
		}
	}

	void remove_tile(int x, int y, int z)
	{
		auto i = get_index(x, y);
		for(auto iter = tilemap[i].begin(); iter != tilemap[i].end(); iter++)
		{
			if((*iter)->z == z)
			{
				delete *iter;
				tilemap[i].erase(iter);
				iter = tilemap[i].end();
			}
		}
	}

	inline int get_index(int x, int y)
	{
		return (y*size_x) + x;
	}

	~Tilemap()
	{
		delete [] tilemap;
	}

	inline int get_size_x(){return size_x;}
	inline int get_size_y(){return size_y;}
	inline Tile_Pile & get_tile(int x, int y){return tilemap[get_index(x, y)]; }
};


#endif 
