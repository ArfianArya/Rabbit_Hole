#pragma once
#include "Entity.h"
namespace Collision
{
	enum Type { NoCollision, Top, Bottom, Left, Right };	//jenis pencacahan yang menentukan jenis tabrakan,
															//Misalnya, saat sebuah benda bertabrakan dengan bagian atas benda lain
															//maka jenis tabrakan akan menjadi Top
}

class Collidable :
	public Entity
{	
protected:
	sf::Vector2f velocity;	//variabel yang menyimpan vektor kecepatan objek saat ini
public:
	Collidable(sf::Vector2f _position, sf::Vector2f _size, Object::Type _objType);	
	Collision::Type isColliding(Entity other, sf::Vector2f velocity);				//fungsi yang mengembalikan tipe tabrakan antara objek ini dan lainnya,
																					//bila tidak terjadi tabrakan, ia mengembalikan NoCollision
	void setVelocity(sf::Vector2f _velocity);								
	sf::Vector2f getVelocity();
	void move(sf::Vector2f _velocity);									//fungsi yang memindahkan objek dengan vektor subjek
	virtual void resolveCollision(Entity &other)=0;						//fungsi virtual yang memecahkan tabrakan
	
};

