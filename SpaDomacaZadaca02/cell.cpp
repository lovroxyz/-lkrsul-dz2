#include "cell.h"
#include <iostream>

cell::cell(sf::Clock& clock, float window_size_x, float window_size_y, int i, int j)
{
	
	
	tx.loadFromFile("dead.png");
	
	sp.setTexture(tx);
	
	
	next_state = 0;
	num_neigh = 0;
	sprite_size_x = window_size_x/50;
	sprite_size_y = window_size_y/50;
	tx.setSmooth(true);
	sp.setScale(window_size_x, window_size_y);
	std::cout << (sp.getTexture()->getSize().x * sp.getScale().x) * i << " " << (sp.getTexture()->getSize().y * sp.getScale().y) * j << std::endl;
	sp.setPosition((sp.getTexture()->getSize().x * sp.getScale().x) * i, (sp.getTexture()->getSize().y * sp.getScale().y) * j);
	
	

	
}






sf::Sprite cell::get_sprite()
{
	return sp;
}

void cell::set_curr_state(const bool state)
{
	curr_state = state;
}

void cell::set_next_state(const bool state)
{
	next_state = state;
}

bool cell::get_next_state() const
{
	return next_state;
}

bool cell::get_curr_state() const
{
	return curr_state;
}

void cell::set_texture() 
{
	if (curr_state == true)
	{
		tx.loadFromFile("human.png");
	}
	else
	{
		tx.loadFromFile("dead.png");
	}
		
	sp.setTexture(tx);
	
}

sf::Texture cell::get_texture()
{
	return tx;
}

void cell::update()
{
	curr_state = next_state;
	set_texture();
}


void cell::set_num_neighbours(const int num)
{
	num_neigh = num;
}
