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
	
	for (int Row = 0; (unsigned int)Row < newMap.size(); ++Row)
	{
		for (int Column = 0; (unsigned int)Column < newMap[Row].size(); ++Column)
		{
			TileArraySizeY = (int)newMap.size();
			TileArraySizeX = (int)newMap[Row].size();
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

float TileMap::GetSize() const
{
	return TileSize;
}

float TileMap::GetMapLeftLoc() const
{
	return UpperLeft;
}

float TileMap::GetMapTopLoc() const
{
	return UpperTop;
}

bool TileMap::CheckForValidMovement(int tileX, int tileY) const
{
	bool isValid = false;
	if ((tileX >= 0) && (tileX < 16/*TileArraySizeX*/) && (tileY >= 0) && (tileY < 12 /*TileArraySizeY*/))
	{
		int TileMapValue = newMap[tileY][tileX];
		if (TileMapValue == 0)
		{
			isValid = true;
		}
		
	}
	return isValid;
}
