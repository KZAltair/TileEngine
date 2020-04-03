#include "Character.h"
#include <string>

Character::Character(float x, float y, TileMap* map)
	:
	map(map),
	characterX(x),
	characterY(y)
{
	width = 0.75f * map->GetTileMap().TileWidth;
	height = map->GetTileMap().TileHeight;
	characterLeft = characterX - 0.5f * width;
	characterTop = characterY - height;
}

void Character::Draw(Graphics& gfx)
{
	gfx.DrawRectangle(characterLeft, characterTop, width, height, Color(1.0f, 1.0f, 0.0f));

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
	velX *= 150.0f;
	velY *= 150.0f;

	newCharacterX = characterX + velX * dt;
	newCharacterY = characterY + velY * dt;

	if (map->IsTileMapPointEmpty(&map->GetTileMap(), (int)newCharacterX, (int)newCharacterY))
	{
		//Move actual x and y of the character
		characterX = newCharacterX;
		characterY = newCharacterY;
		//Construct rect around player from selected bottom center to draw from this coordinates
		characterLeft = characterX - 0.5f * width;
		characterTop = characterY - height;
	}

	/*if (map.CheckForValidMovement((int)((newCharacterX - map.GetMapLeftLoc()) / map.GetSize()),
		(int)((newCharacterY - map.GetMapTopLoc()) / map.GetSize())) &&
		map.CheckForValidMovement((int)(((newCharacterX -0.5f *width) - map.GetMapLeftLoc()) / map.GetSize()),
		(int)((newCharacterY - map.GetMapTopLoc()) / map.GetSize())) &&
		map.CheckForValidMovement((int)(((newCharacterX + 0.5f * width) - map.GetMapLeftLoc()) / map.GetSize()),
		(int)((newCharacterY - map.GetMapTopLoc()) / map.GetSize())))
	{
		//Move actual x and y of the character
		characterX = newCharacterX;
		characterY = newCharacterY;
		//Construct rect around player from selected bottom center to draw from this coordinates
		characterLeft = characterX - 0.5f * width;
		characterTop = characterY - height;

	}
	*/

}
