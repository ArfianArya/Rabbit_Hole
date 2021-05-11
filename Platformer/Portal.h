#pragma once
#include "Entity.h"
#include "AnimationHolder.h"
class Portal :
	public Entity
{
private: 
	bool open;						//variabel yang menahan bendera apakah portal terbuka atau tidak
	AnimationHolder *animations[2]; //variabel yang menyimpan semua animasi portal
	Animation::Type currAnimation;	//variabel yang menampung jenis pembaruan animasi
	void draw(sf::RenderTarget & target, sf::RenderStates state) const override;//fungsi melakukan render pada animasi
public:
	Portal(sf::Vector2f _position, sf::Vector2f _size); 
	void addAnimation(Animation::Type _animType, sf::Texture&_texture, sf::Time _duration, unsigned int _frameNumber, bool _repeat);//fungsi yang menambahkan animasi 
	void updateAnimation(sf::Time _dt);//fungsi yang memperbarui animasi
	bool isOpen();	   //fungsi mengembalikan bendera sebenarnya saat portal terbuka
	void openPortal(); //fungsi yang membuka portal tertentu
	~Portal();

};

