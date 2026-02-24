#pragma once

class Entity {
public:
	Entity(int xCoord, int yCoord, int health, int damage, int movRange, const char* spriteFile);

	int GetX();
	int GetY();
	void SetX(int newX);
	void SetY(int newY);

	int GetHealth();
	void SetHealth(int newHealth);

	int GetDamage();
	void SetDamage(int damage);

	int GetMovRange();
	void SetMovRange(int movRange);

	const char* GetSprite();
	void SetSprite(const char* spriteFile);

private:
	int xCoord;
	int yCoord;
	int health;
	int damage;
	int movRange;
	const char* spriteFile;
};