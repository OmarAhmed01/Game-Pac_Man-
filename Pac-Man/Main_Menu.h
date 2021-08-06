#pragma once
#include <SFML/Graphics.hpp>

#define pos 4

using namespace sf;

class Main_Menu
{
public:
	Main_Menu();

	void draw(RenderWindow &x, bool &f);
	void down();
	void up();
	void skin(bool &pac, bool &vatt, bool &sars, RenderWindow &x);
	void art(RenderWindow &x);

	void enter (bool &f, bool &g, bool &t, bool &s);

	~Main_Menu();

private:
	int selection = 1;

	Sprite start_b, sound_b, skins_b, exit_b, artistic, cover;

	Texture s_high, s_none, e_high, e_none, sound_on, sound_off, sound_on_h, sound_off_h, skn_none, skn_high, artistic_texture, cover_texture;
};

