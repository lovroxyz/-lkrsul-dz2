#include<SFML/Graphics.hpp>
#pragma once
class cell
{
	bool curr_state;
	bool next_state;
	int num_neigh;
	float sprite_size_x;
	float sprite_size_y;
	sf::Sprite sp;
	sf::Texture tx;
	
	

	
public:
	cell(sf::Clock &clock, float windowsize_x,float windowsize_y,int i,int j);
	void check_neigh();
	
	sf::Sprite get_sprite();
	void set_curr_state( const bool state);
	void set_next_state(const bool state);
	bool get_next_state() const;
	bool get_curr_state() const;
	void set_texture() ;
	sf::Texture get_texture();
	void update();
	
	void set_num_neighbours(int num);


	

};

