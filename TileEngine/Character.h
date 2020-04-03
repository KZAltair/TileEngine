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
	float characterLeft;
	float characterTop;
	float newCharacterX = 0.0f;
	float newCharacterY = 0.0f;
	float velX = 0.0f;
	float velY = 0.0f;
	float width;
	float height;
	TileMap map;
};