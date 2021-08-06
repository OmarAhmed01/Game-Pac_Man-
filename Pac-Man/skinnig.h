#pragma once
#include <SFML/Graphics.hpp>

#define pos 4

using namespace sf;

class skinnig
{
public:
	skinnig();

	void draw(RenderWindow &x, bool& pac, bool& sars, bool& ghst);
	void up();
	void down();

	void enter(bool &pac, bool &sars, bool& ghst, bool &ret);

	~skinnig();
private:

	int selection = 1;

	Sprite back, pac_b, sarscov_b, ghstly_b, back_b;

	Texture background, pac_h, pac_n, pac_h_on, pac_n_on, sarscov_h, sarscov_n, sarscov_h_on, sarscov_n_on, ghstly_h, ghstly_n, ghstly_h_on, ghstly_n_on, back_h, back_n;
	
};

