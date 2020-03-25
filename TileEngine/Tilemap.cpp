#include "Tilemap.h"

TileMap::TileMap(float left, float top, float TileSize)
	:
	UpperLeft(left),
	UpperTop(top),
	TileSize(TileSize)
{
	//TODO: Make reading from file or custom defined place
	newMap = {
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
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
	};
}

void TileMap::Draw(Graphics& gfx)
{
	
	for (int Row = 0; Row < newMap.size(); ++Row)
	{
		for (int Column = 0; Column < newMap[Row].size(); ++Column)
		{
			int TileID = newMap[Row][Column];
			float tileColor = 1.0f;
			if (TileID == 1)
			{
				tileColor = 0.5f;
			}
			gfx.DrawRectangle(UpperLeft + (float)(Column * TileSize),
				UpperTop + (float)(Row * TileSize),
				TileSize,
				TileSize,
				Color(tileColor, tileColor, tileColor));
		}
	}
}
