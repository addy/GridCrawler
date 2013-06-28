#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "gameplay.h"


int main() {

	GamePlay* g = new GamePlay();
	g->play();

	delete g;
	return 0;
}