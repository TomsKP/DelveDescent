#include "Entity.h"
#include <vector>

struct level1 {
	std::vector<std::vector<int>> map1 = { {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0} };
	Entity enemy0 = Entity(1, 1, 4, 1, 1, "assets/images/enemy1.png");
};