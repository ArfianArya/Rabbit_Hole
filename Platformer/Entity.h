#pragma once
#include <SFML/Graphics.hpp>

namespace Object
{
	enum Type { Wall, Player, Coin, SpawnPoint, Spikes, Enemy, Portal};		//jenis enum yang menentukan jenis objek
}

class Entity : public sf::Drawable
{
protected:
	
	sf::RectangleShape obj;		//variabel yang menahan persegi panjang yang membatasi benturan objek, dan tekstur untuk objek tanpa animasi
	bool destructionFlag;		//variabel yang menyimpan nilai bendera yang menentukan apakah objek rusak atau tidak
	Object::Type objType;		//variabel yang menampung tipe objek
private:
	void draw(sf::RenderTarget & target, sf::RenderStates state) const override;//fungsi melakukan render pada animasi
public:
	Entity(sf::Vector2f _position, sf::Vector2f _size, Object::Type _objType);
	void setPosition(sf::Vector2f _position);
	void setXPosition(float _x);
	void setYPosition(float _y);
	bool isDestroyed();
	void destroy();												//sebuah fungsi yang menyetel tanda kehancuran ke true
	Object::Type getType();
	sf::Vector2f getPosition();
	sf::FloatRect getBoundingRect();							//fungsi yang mengembalikan cakupan kotak pembatas tabrakan itu sendiri
	sf::RectangleShape getRectangle();							//fungsi yang mengembalikan persegi panjang yang membatasi tabrakan objek
	float getLeft();											//fungsi yang mengembalikan tepi kiri suatu objek
	float getRight();											//fungsi yang mengembalikan tepi kanan suatu objek
	float getTop();												//fungsi yang mengembalikan tepi atas suatu objek
	float getBottom();											//fungsi yang mengembalikan tepi bawah suatu objek
	sf::Vector2f getSize();
	sf::Vector2f getOrigin();									//fungsi yang mengembalikan pusat objek
	void setTexture(sf::Texture &_texture, bool _repeated);		//fungsi yang mengatur tekstur objek
	void setColor(sf::Color _color);							//fungsi yang mengatur warna tekstur suatu objek
	bool onScreen(sf::View _currView);							//sebuah fungsi yang mengembalikan nilai true ketika sebuah objek atau bagian darinya ada di layar
};


