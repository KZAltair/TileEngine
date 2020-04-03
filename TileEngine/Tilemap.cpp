#include "Tilemap.h"

TileMap::TileMap(float x, float y, float TileWidth, float TileHeight)
{

	//TODO: Make reading from file or custom defined place
	//Movement based on Y and X in the array access!!!


	tiles10 = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1}
	};

	tiles01 = {
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
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

	tiles11 = {
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
	};

	//Init tile maps here
	mapTile.CountX = 16;
	mapTile.CountY = 12;
	mapTile.TileHeight = TileHeight;
	mapTile.TileWidth = TileWidth;
	mapTile.UpperLeftX = x;
	mapTile.UpperLeftY = y;
	mapTile.Tiles = (int*)tiles11.data();
}

void TileMap::Draw(Graphics& gfx)
{
	
	for (int Row = 0; Row < mapTile.CountY; ++Row)
	{
		for (int Column = 0; Column < mapTile.CountX; ++Column)
		{

			int TileID = GetTileValueUnchecked(&mapTile, Column, Row);
			float tileColor = 1.0f;
			if (TileID == 1)
			{
				tileColor = 0.5f;
			}

			float MinX = mapTile.UpperLeftX + ((float)Column) * mapTile.TileWidth;
			float MinY = mapTile.UpperLeftY + ((float)Row) * mapTile.TileHeight;
			float MaxX = MinX + mapTile.TileWidth;
			float MaxY = MinY + mapTile.TileHeight;
			gfx.DrawRectangle(MinX, MinY, MaxX, MaxY,
				Color(tileColor, tileColor, tileColor));
		}
	}
}


int TileMap::GetTileValueUnchecked(tile_map* TileMap, int TileX, int TileY) const
{
	int TileMapValue = TileMap->Tiles[TileY * TileMap->CountX + TileX];
	return TileMapValue;
}

bool TileMap::IsTileMapPointEmpty(tile_map* TileMap, int TestX, int TestY) const
{
	bool Empty = false;

	int PlayerTileX = (int)((TestX - TileMap->UpperLeftX) / TileMap->TileWidth);
	int PlayerTileY = (int)((TestY - TileMap->UpperLeftY) / TileMap->TileHeight);
	if ((PlayerTileX >= 0) && (PlayerTileX < TileMap->CountX) && (PlayerTileY >= 0) && (PlayerTileY < TileMap->CountY))
	{
		int TileMapValue = GetTileValueUnchecked(TileMap, PlayerTileX, PlayerTileY);
		Empty = (TileMapValue == 0);
		
	}
	return Empty;
}

tile_map TileMap::GetTileMap() const
{
	return mapTile;
}
