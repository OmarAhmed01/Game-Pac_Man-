#include "Main_Menu.h"

Main_Menu::Main_Menu()
{
	s_high.loadFromFile("textures/button-highlighted.png");
	s_none.loadFromFile("textures/button.png");

	sound_on.loadFromFile("textures/sound.png");
	sound_off.loadFromFile("textures/sound-mute.png");

	sound_on_h.loadFromFile("textures/sound-high.png");
	sound_off_h.loadFromFile("textures/sound-mute-high.png");

	e_high.loadFromFile("textures/exit-highlighted.png");
	e_none.loadFromFile("textures/exit.png");

	skn_high.loadFromFile("textures/skins-high.png");
	skn_none.loadFromFile("textures/skins.png");

	artistic_texture.loadFromFile("textures/art.png");

	cover_texture.loadFromFile("textures/menu-background.png");

	start_b.setPosition(Vector2f(60, 220));
	skins_b.setPosition(Vector2f(60, 300));
	exit_b.setPosition(Vector2f(60, 380));
	sound_b.setPosition(Vector2f(358, 436));

	start_b.setTexture(s_high);
	sound_b.setTexture(sound_on);
	exit_b.setTexture(e_none);
	skins_b.setTexture(skn_none);
	artistic.setTexture(artistic_texture);
	cover.setTexture(cover_texture);


}

void Main_Menu::draw(RenderWindow& x, bool& f)
{

	if (selection == 4 && f)
		sound_b.setTexture(sound_on_h);
	else if (selection != 4 && f)
		sound_b.setTexture(sound_on);
	else if (selection == 4 && !f)
		sound_b.setTexture(sound_off_h);
	else if (selection != 4 && !f)
		sound_b.setTexture(sound_off);

	x.clear();
	x.draw(cover);
	x.draw(start_b);
	x.draw(skins_b);
	x.draw(exit_b);
	x.draw(sound_b);
	x.display();
}

void Main_Menu::down()
{
	selection++;
	if (selection > pos)
		selection = 1;

	if (selection == 1)
		start_b.setTexture(s_high);
	else if (selection != 1)
		start_b.setTexture(s_none);
	if (selection == 2)
		skins_b.setTexture(skn_high);
	else if (selection != 2)
		skins_b.setTexture(skn_none);
	if (selection == 3)
		exit_b.setTexture(e_high);
	else if (selection != 3)
		exit_b.setTexture(e_none);
}

void Main_Menu::up()
{
	selection--;
	if (selection < 1)
		selection = pos;

	if (selection == 1)
		start_b.setTexture(s_high);
	else if (selection != 1)
		start_b.setTexture(s_none);
	if (selection == 2)
		skins_b.setTexture(skn_high);
	else if (selection != 2)
		skins_b.setTexture(skn_none);
	if (selection == 3)
		exit_b.setTexture(e_high);
	else if (selection != 3)
		exit_b.setTexture(e_none);
}

void Main_Menu::art(RenderWindow & x)
{
	x.clear();
	x.draw(artistic);
	x.display();
}

void Main_Menu::enter(bool& f, bool& g, bool& t, bool& s)
{
	if (selection == 1)
		g = true;

	if (selection == 4)
		f = !f;

	if (selection == 3)
		t = true;

	if (selection == 2)
		s = true;
}

Main_Menu::~Main_Menu()
{
}
