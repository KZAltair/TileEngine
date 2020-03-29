#pragma once
#include "Graphics.h"
#include <vector>

class TileMap
{
private:
	struct world
	{

	};
public:
	TileMap(float left, float top, float TileSize);
	void Draw(Graphics& gfx);
	float GetSize() const;
	float GetMapLeftLoc() const;
	float GetMapTopLoc() const;
	bool CheckForValidMovement(int tileX, int tileY) const;

	//For testing and further refactoring
	bool isWorldPointEmpty(world* world, int tileMapX, int tileMapY, int testX, int testY) const;

private:
	float TileSize;
	float UpperLeft;
	float UpperTop;
	int TileArraySizeX;
	int TileArraySizeY;
	//Temporary cretae simple maps in class, later load it from file
	std::vector<std::vector<int>> tiles01;
	std::vector<std::vector<int>> tiles00;
	std::vector<std::vector<int>> tiles10;
	std::vector<std::vector<int>> tiles11;
};