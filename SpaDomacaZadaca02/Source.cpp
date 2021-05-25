#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "cell.h"
#include<iostream>
int window_sizex = 1680;
int window_sizey = 1050;
float xscale;
float yscale;
//bool space = false;
void check_neighbours(std::vector<cell>& cells)
{
	//If i<10 ||i>90 || i%10==0 || i%10==9 special cases 0 i 99
	for (int i = 0;i < 100;i++)
	{
		int x = 0;
		//setupat tako da se pazi na prvi red prvi stupac,zadnji red,zadnji stupac
		if (i < 9 && i != 0)
		{

			if (cells[i + 10 - 1].get_curr_state() == true)
				x++;
			if (cells[i + 10].get_curr_state() == true)
				x++;
			if (cells[i + 10 + 1].get_curr_state() == true)
				x++;
			if (cells[i + 1].get_curr_state() == true)
				x++;
			if (cells[i - 1].get_curr_state() == true)
				x++;

		}
		else if (i > 90 && i != 99)
		{
			if (cells[i - 10 - 1].get_curr_state() == true)
				x++;
			if (cells[i - 10].get_curr_state() == true)
				x++;
			if (cells[i - 10 + 1].get_curr_state() == true)
				x++;
			if (cells[i + 1].get_curr_state() == true)
				x++;
			if (cells[i - 1].get_curr_state() == true)
				x++;

		}
		else if (i == 0)
		{

			if (cells[i + 10 + 1].get_curr_state() == true)
				x++;
			if (cells[i + 1].get_curr_state() == true)
				x++;
			if (cells[i + 10].get_curr_state() == true)
				x++;

		}
		else if (i == 99)
		{


			if (cells[i - 10 - 1].get_curr_state() == true)
				x++;
			if (cells[i - 1].get_curr_state() == true)
				x++;
			if (cells[i - 10].get_curr_state() == true)
				x++;

		}
		else if (i == 9)
		{
			if (cells[i - 1].get_curr_state() == true)
				x++;
			if (cells[i + 10].get_curr_state() == true)
				x++;
			if (cells[i + 10 - 1].get_curr_state() == true)
				x++;
		}
			

		else if (i == 90)
		{
			if (cells[i - 10].get_curr_state() == true)
				x++;
			if (cells[i + 1].get_curr_state() == true)
				x++;
			if (cells[i - 10 + 1].get_curr_state() == true)
				x++;
		}
		
		else if (i%10==0 && i>=10 && i<90)
		{
			if (cells[i + 10 + 1].get_curr_state() == true)
				x++;
			if (cells[i + 1].get_curr_state() == true)
				x++;
			if (cells[i - 10 + 1].get_curr_state() == true)
				x++;
			if (cells[i + 10].get_curr_state() == true)
				x++;
			if (cells[i - 10].get_curr_state() == true)
				x++;
			
		}
		else if (i%10==9  && i>=10 && i<90)
		{
			
			if (cells[i - 10 - 1].get_curr_state() == true)
				x++;
			if (cells[i - 1].get_curr_state() == true)
				x++;
			if (cells[i + 10 - 1].get_curr_state() == true)
				x++;

			if (cells[i + 10].get_curr_state() == true)
				x++;
			if (cells[i - 10].get_curr_state() == true)
				x++;
			
		}
		else {
			/*
			for (int j = x-1;j <= x+1;j++)
			{
				for (int k = x-1;k <= x+1;k++)
				{
					std::cout << j << " " << k << std::endl;
					if (cells[(j * 10) + k].get_curr_state() == 1)
					{
						x++;
					}
				}
			}
			*/
			
			if (cells[i + 1].get_curr_state() == true)
				x++;
			if (cells[i - 1].get_curr_state() == true)
				x++;
			if (cells[i + 10 ].get_curr_state() == true)
				x++;
			if (cells[i - 10 ].get_curr_state() == true)
				x++;
			if (cells[i + 10 - 1].get_curr_state() == true)
				x++;
			if (cells[i + 10 + 1].get_curr_state() == true)
				x++;
			if (cells[i - 10 - 1].get_curr_state() == true)
				x++;
			if (cells[i - 10 + 1].get_curr_state() == true)
				x++;
			
		}
	
	
		
		if (x>1 && x<4 && cells[i].get_curr_state() == true)
		{
			cells[i].set_next_state(true);
		}
		
		else if (x > 3)
		{
			cells[i].set_next_state(false);
		}
		 else if (x <= 1)
		{
			cells[i].set_next_state(false);
		}
		 if (cells[i].get_curr_state() == false && x == 3)
		 {
			 cells[i].set_next_state(true);
		 }

	}
	
}
void setup_vek(std::vector<cell>& cells, sf::Clock& c)
{
	int x;


	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			//int rnd;
			//rnd = rand() % 4;
			cell x2(c, xscale, yscale, j, i);




			cells.push_back(x2);
			//cells.emplace_back(c, xscale, yscale, j, i);

			x = rand() % 4;
			if (x == 0)
			{

				cells[(i* 10) + j].set_curr_state(1);
				cells[(i * 10) + j].set_next_state(1);

				cells[(i * 10) + j].set_texture();


			}
			else {
				cells[(i * 10) + j].set_curr_state(0);
				cells[(i * 10) + j].set_next_state(0);

				cells[(i * 10) + j].set_texture();

			}


		}
	}

}

void get_sprite_scale( float &xscale, float &yscale)
{
	
	sf::Sprite sp;
	sf::Texture tx;
	tx.loadFromFile("dead.png");
	sp.setTexture(tx);
	float sprite_size_x = window_sizex / 10;
	float sprite_size_y = window_sizey / 10;
	const sf::Vector2f spriteSize(
		sp.getTexture()->getSize().x * sp.getScale().x,
		sp.getTexture()->getSize().y * sp.getScale().y);
	//std::cout << spriteSize.x << " " << spriteSize.y;
	//std::cout << std::endl << sprite_size_x << " " << sprite_size_y;
	xscale = sprite_size_x / spriteSize.x;
	yscale = sprite_size_y / spriteSize.y;
	
	
}
int main()
{
	
	
	
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(window_sizex, window_sizey), "Game of Life");
	get_sprite_scale(xscale, yscale);
	//std::cout << "x " << xscale << " " << "y " << yscale;

	window.setFramerateLimit(60);
	sf::Clock c;
	std::vector<cell> cells;
	cells.reserve(100);



	
	
	//std::cout << cells.size()<<" ";
	setup_vek(cells, c);

	cell x2(c, xscale, yscale, 1, 1);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			space = true;
			check_neighbours(cells);
			for (int i = 0;i < 100;i++)
			{
				//cells[i].update();
			}
			c.restart();
			space = false;

		}
		*/

		if (c.getElapsedTime().asSeconds() >= 2.f)
		{
			c.restart();
			
			
				check_neighbours(cells);
			
			
			
			for (int i = 0;i < 100;i++)
			{
				cells[i].update();
			}
			
		}
			window.clear();
			
			
			
			

			for (int i = 0;i < 100;i++)
			{
				window.draw(cells[i].get_sprite());
			}


			
			
			window.display();
		
	
	
	}

	return 0;
}