#include "Entity.h"

Entity::Entity(int xCoord, int yCoord, int health, int damage, int movRange, const char* spriteFile) : xCoord(xCoord), yCoord(yCoord), health(health), damage(damage), movRange(movRange), spriteFile(spriteFile) {};

int Entity::GetX() {
	return xCoord;
}

int Entity::GetY() {
	return yCoord;
}

void Entity::SetX(int newX) {
	xCoord = newX;
}

void Entity::SetY(int newY) {
	yCoord = newY;
}

int Entity::GetHealth() {
	return health;
}

void Entity::SetHealth(int newHealth) {
	health = newHealth;
}

int Entity::GetDamage() {
	return damage;
}

void Entity::SetDamage(int newDamage) {
	damage = newDamage;
}

int Entity::GetMovRange() {
	return movRange;
}

void Entity::SetMovRange(int newMovRange) {
	movRange = newMovRange;
}

const char* Entity::GetSprite() {
	return spriteFile;
}

void Entity::SetSprite(const char* newSpriteFile) {
	spriteFile = newSpriteFile;
}