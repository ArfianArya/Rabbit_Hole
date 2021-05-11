#pragma once
#include "Collidable.h"
#include "AnimationHolder.h"
#include "Player.h"
class Bat :
	public Collidable
{
private:
	const static float movementSpeed;												//variabel yang menyimpan kecepatan gerakan lawan
	AnimationHolder *animation;														//variabel yang menyimpan animasi lawan
	void draw(sf::RenderTarget & target, sf::RenderStates state) const override;	//fungsi melakukan render pada animasi
public:
	Bat(sf::Vector2f _position, sf::Vector2f _size);
	void addAnimation(sf::Texture&_texture, sf::Time _duration, unsigned int _frameNumber, bool _repeat);	//fungsi yang menambahkan animasi
	void updateAnimation(sf::Time _dt);										//fungsi yang memperbarui animasi
	void resolveCollision(Entity &other) override;							//fungsi yang memecahkan tabrakan objek dengan objek lain
	void update(sf::Time _dt);												//fungsi yang memperbarui gerakan lawan
	~Bat();
};

