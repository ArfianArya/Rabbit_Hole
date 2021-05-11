#pragma once
#include <SFML/Graphics.hpp>
namespace Animation
{
	enum Direction{Left, Right};						//enumerasi yang menentukan sisi mana yang dihadapi animasi
	enum Type{Idle,Move,Jump,Fall,Death,Hit,Crouch};	//enumerasi yang menentukan jenis animasi
}
class AnimationHolder :
	public sf::Drawable,
	public sf::Transformable
{
private:
	sf::Sprite mSprite;						//variabel yang menahan bingkai dan tekstur animasi saat ini dan ditampilkan di layar
	sf::Vector2u frameSize;					//variabel yang menampung ukuran satu bingkai animasi
	std::size_t frameNumber;				//variabel yang menampung jumlah frame dalam animasi
	std::size_t currFrame;					//variabel yang menyimpan jumlah bingkai animasi saat ini
	sf::Time animDuration;					//variabel yang menahan durasi seluruh animasi
	sf::Time elapsedTime;					//variabel yang menyimpan berapa lama waktu yang telah berlalu sejak dimulainya animasi
	Animation::Direction animDirection;		//variabel yang menahan halaman tempat animasi dikembalikan

	bool repeat, finished;					//variabel yang menahan apakah animasi harus diulang dan apakah sudah selesai
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //fungsi melakukan render pada animasi

public:
	AnimationHolder(sf::Texture&_texture, sf::Time _duration, unsigned int _frameNumber, bool _repeat);


	void setColor(sf::Color _color);
	void setPosition(sf::Vector2f _pos);
	void update(sf::Time dt);				//fungsi yang memperbarui animasi bergantung pada berapa lama waktu telah berlalu
	void swap();							//fungsi yang akan mengubah arah animasi
	void restart();							//fungsi yang memulai ulang animasi
	bool isFinished();

	Animation::Direction getDirection();
};

