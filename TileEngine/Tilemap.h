#pragma once
#include "Graphics.h"
#include <vector>

class TileMap
{
public:
	TileMap(float left, float top, float TileSize);
	void Draw(Graphics& gfx);
	float GetSize() const;
	float GetMapLeftLoc() const;
	float GetMapTopLoc() const;
	bool CheckForValidMovement(int tileX, int tileY) const;

private:
	float TileSize;
	float UpperLeft;
	float UpperTop;
	int TileArraySizeX;
	int TileArraySizeY;
	std::vector<std::vector<int>> newMap;
};