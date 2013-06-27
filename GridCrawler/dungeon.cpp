#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "utilities.h"

#include "gameplay.h"


int main() {

	GamePlay* g = new GamePlay();
	g->play();

	delete g;
	return 0;
}