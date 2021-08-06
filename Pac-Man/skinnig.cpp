#include "skinnig.h"

skinnig::skinnig()
{
	background.loadFromFile("textures/skin-back.png");

	pac_h.loadFromFile("textures/pac-h.png");
	pac_n.loadFromFile("textures/pac-n.png");
	pac_h_on.loadFromFile("textures/pac-h-on.png");
	pac_n_on.loadFromFile("textures/pac-n-on.png");

	sarscov_h.loadFromFile("textures/sars-h.png");
	sarscov_n.loadFromFile("textures/sars-n.png");
	sarscov_h_on.loadFromFile("textures/sars-h-on.png");
	sarscov_n_on.loadFromFile("textures/sars-n-on.png");

	ghstly_h.loadFromFile("textures/gstly-h.png");
	ghstly_n.loadFromFile("textures/gstly-n.png");
	ghstly_h_on.loadFromFile("textures/gstly-h-on.png");
	ghstly_n_on.loadFromFile("textures/gstly-n-on.png");

	back_h.loadFromFile("textures/back-high.png");
	back_n.loadFromFile("textures/back.png");

	back.setTexture(background);

	pac_b.setTexture(pac_h_on);
	sarscov_b.setTexture(sarscov_n);
	back_b.setTexture(back_n);

	back_b.setScale(.8, .8);

	pac_b.setPosition(Vector2f(323, 10));
	sarscov_b.setPosition(Vector2f(323, 140));
	ghstly_b.setPosition(Vector2f(323, 275));
	back_b.setPosition(Vector2f(353, 430));
}

void skinnig::draw(RenderWindow& x, bool& pac, bool& sars, bool& ghst)
{
	if (selection == 1 && pac)
		pac_b.setTexture(pac_h_on);
	else if (selection == 1 && !pac)
		pac_b.setTexture(pac_h);
	else if (selection != 1 && pac)
		pac_b.setTexture(pac_n_on);
	else if (selection != 1 && !pac)
		pac_b.setTexture(pac_n);

	if (selection == 2 && sars)
		sarscov_b.setTexture(sarscov_h_on);
	else if (selection == 2 && !sars)
		sarscov_b.setTexture(sarscov_h);
	else if (selection != 2 && sars)
		sarscov_b.setTexture(sarscov_n_on);
	else if (selection != 2 && !sars)
		sarscov_b.setTexture(sarscov_n);

	if (selection == 3 && ghst)
		ghstly_b.setTexture(ghstly_h_on);
	else if (selection == 3 && !ghst)
		ghstly_b.setTexture(ghstly_h);
	else if (selection != 3 && ghst)
		ghstly_b.setTexture(ghstly_n_on);
	else if (selection != 3 && !ghst)
		ghstly_b.setTexture(ghstly_n);

	if (selection == 4)
		back_b.setTexture(back_h);
	else if (selection != 4)
		back_b.setTexture(back_n);

	x.clear();
	x.draw(back);
	x.draw(pac_b);
	x.draw(sarscov_b);
	x.draw(ghstly_b);
	x.draw(back_b);
	x.display();
}

void skinnig::up()
{
	selection--;
	if (selection < 1)
		selection = pos;
}

void skinnig::down()
{
	selection++;
	if (selection > pos)
		selection = 1;
}

void skinnig::enter(bool& pac, bool& sars, bool& ghst, bool& ret)
{
	if (selection == 1)
	{
		pac = true;
		sars = false;
		ghst = false;
	}
	if (selection == 2)
	{
		sars = true;
		pac = false;
		ghst = false;

	}
	if (selection == 3)
	{
		ghst = true;
		pac = false;
		sars = false;
	}
	if (selection == 4)
	{
		ret = !ret;
	}
}

skinnig::~skinnig()
{
}
