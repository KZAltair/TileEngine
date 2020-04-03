#include "Character.h"
#include <string>

Character::Character(float x, float y, const TileMap& map)
	:
	map(map),
	characterX(x),
	characterY(y)
{
	width = 0.75f * map.GetSize();
	height = map.GetSize();
	characterLeft = characterX - 0.5f * width;
	characterTop = characterY - height;
}

void Character::Draw(Graphics& gfx)
{
	gfx.DrawRectangle(characterLeft + characterX, characterTop + characterY, width, height, Color(1.0f, 1.0f, 0.0f));

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

	/*newCharacterX = characterX + velX * dt;
	newCharacterY = characterY + velY * dt;
	*/

	newCharacterX = characterX + velX * dt;
	newCharacterY = characterY + velY * dt;


	if (map.CheckForValidMovement((int)(newCharacterX), (int)(newCharacterY)))
	{
		characterX = newCharacterX;
		characterY = newCharacterY;

		OutputDebugStringA(std::to_string(characterLeft).c_str());
		OutputDebugStringA("\n");

	}

}
