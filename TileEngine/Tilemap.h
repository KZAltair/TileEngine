#pragma once
#include "Graphics.h"
#include <vector>

struct tile_map
{
	int CountX;
	int CountY;

	float UpperLeftX;
	float UpperLeftY;
	float TileWidth;
	float TileHeight;

	int* Tiles;
};

class TileMap
{
public:
	TileMap(float x, float y, float TileWidth, float TileHeight);
	void Draw(Graphics& gfx);
	int GetTileValueUnchecked(tile_map* TileMap, int TileX, int TileY) const;
	bool IsTileMapPointEmpty(tile_map* TileMap, int tileX, int tileY) const;
	tile_map GetTileMap() const;

private:

	//Temporary cretae simple maps in class, later load it from file
	int tiles00[12][16] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1}
	};
	std::vector<std::vector<int>> tiles01;
	std::vector<std::vector<int>> tiles10;
	std::vector<std::vector<int>> tiles11;
	tile_map mapTile;
};