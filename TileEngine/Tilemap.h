#pragma once
#include "Graphics.h"
#include <vector>

class TileMap
{
public:
	TileMap(float left, float top, float TileSize);
	void Draw(Graphics& gfx);
	float GetSize() const;

private:
	float TileSize;
	float UpperLeft;
	float UpperTop;
	std::vector<std::vector<int>> newMap;
};