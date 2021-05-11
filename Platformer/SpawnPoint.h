#pragma once
#include "Entity.h"
#include "AnimationHolder.h"
class SpawnPoint :
	public Entity
{
private:
	AnimationHolder *animation;
	bool isEnabled;				//variabel yang menyimpan bendera apakah itu spawn pemain saat ini
	void draw(sf::RenderTarget & target, sf::RenderStates state) const override;//fungsi yang menggantikan fungsi menggambar perpustakaan
public:
	SpawnPoint(sf::Vector2f _position, sf::Vector2f _size);
	~SpawnPoint();
	void setEnabled(bool _isEnabled);	
	void addAnimation(sf::Texture&_texture, sf::Time _duration, unsigned int _frameNumber, bool _repeat);//fungsi yang menambahkan animasi
	void updateAnimation(sf::Time _dt);//fungsi yang memperbarui animasi
};

