#pragma once
#include "Tilemap.h"
#include "Keyboard.h"

class Character
{
public:
	Character(float x, float y, const TileMap& map);
	void Draw(Graphics& gfx);
	void Update(float dt, Keyboard& kbd);

private:
	float characterX;
	float characterY;
	float velX;
	float velY;
	float width;
	float height;
	TileMap map;
};