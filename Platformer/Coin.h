#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "AnimationHolder.h"
class Coin :
	public Entity
{
private:
	int value;														//variabel yang menyimpan nilai koin
	AnimationHolder *animation;														
	void draw(sf::RenderTarget & target, sf::RenderStates state) const override;	//fungsi melakukan render pada animasi
public:
	Coin(sf::Vector2f _position, sf::Vector2f _size);								
	Coin(sf::Vector2f _position, sf::Vector2f _size, int _value);
	~Coin();

	void addAnimation(sf::Texture&_texture, sf::Time _duration, unsigned int _frameNumber, bool _repeat);//fungsi yang menambahkan animasi
	void updateAnimation(sf::Time _dt);		//fungsi yang memperbarui animasi
	int getValue();							//fungsi yang mengembalikan nilai koin
};

