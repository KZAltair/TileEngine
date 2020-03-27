#include "Character.h"

Character::Character(float x, float y, const TileMap& map)
	:
	map(map),
	characterX(x),
	characterY(y)
{
	width = 0.75f * map.GetSize();
	height = map.GetSize();
	characterX = x - 0.5f * width;
	characterY = x - height;
}

void Character::Draw(Graphics& gfx)
{
	gfx.DrawRectangle(characterX, characterY, width, height, Color(1.0f, 1.0f, 0.0f));
}

void Character::Update(float dt, Keyboard& kbd)
{
	velX = 0.0f;
	velY = 0.0f;
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		velX = -1.0f;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		velX = 1.0f;
	}
	if (kbd.KeyIsPressed(VK_UP))
	{
		velY = -1.0f;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		velY = 1.0f;
	}
	velX *= 300.0f;
	velY *= 300.0f;
	characterX += velX * dt;
	characterY += velY * dt;
}
