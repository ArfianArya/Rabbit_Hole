#pragma once
#include <map>
#include "Collidable.h"
#include "AnimationHolder.h"
#include "SpawnPoint.h"
#include "Coin.h"
#include "Portal.h"
namespace Key {
	enum Type { Left, Right, Down, Up, Attack, Enter }; //jenis enumerasi yang menentukan tombol yang saat ini dipilih pada keyboard
}
class Player :
	public Collidable
{
private:
	int health, score;									//variabel yang menyimpan kehidupan dan poin pemain
	static const float movementSpeed,gravityForce;		//variabel yang menyimpan kecepatan pemain bergerak dan jatuh
	static const int maximalJump,jumpPause, minimalJump;//variabel yang menyimpan ketinggian maksimum dan minimum serta waktu suspensi di udara lompatan
	static const int startingHealth, invulnerabilityLength; //variabel yang menyimpan masa awal dan lamanya ketidakpekaan setelah menerima cedera
	int jumpCounter, totalJumpCounter;					//variabel yang menyimpan waktu lompatan saat ini dan seluruh panjang lompatan saat ini 
	int	invulnerabilityCounter;							//variabel yang menyimpan panjang ketidakpekaan saat ini
	bool jumping ,falling, onGround,crouching, finishedLevel; //bendera untuk menunjukkan jika pemain melompat, jatuh, di tanah, berjongkok dan memiliki
	Animation::Type currAnimation;						//variabel yang menyimpan jenis animasi saat ini
	AnimationHolder *animations[7];						//variabel yang menyimpan semua animasi pemain
	sf::Vector2f currSpawnPosition;						//variabel yang menyimpan posisi spawn pemain saat ini
	sf::Vector2f  previousPosition;						//variabel yang menahan posisi pemain satu frame yang lalu
	SpawnPoint *currSpawnPoint;							//variabel yang menyimpan penunjuk ke spawn pemain saat ini



	void draw(sf::RenderTarget & target, sf::RenderStates state) const override;//fungsi yang menggantikan fungsi menggambar perpustakaan
	void crouch();		//fungsi yang mendukung pemain berjongkok
	void stand();		//fungsi yang mendukung pemicuan setelah pemain berjongkok

public:
	Player(sf::Vector2f _position, sf::Vector2f _size);
	~Player();



	void resolveCollision(Entity &other) override;

	void addAnimation(Animation::Type _type, sf::Texture&_texture, sf::Time _duration, unsigned int _frameNumber, bool _repeat);//fungsi yang menambahkan animasi
	void update(sf::Time _dt, bool keyPressed[6]);	//fungsi yang memperbarui gerakan pemain
	void updateAnimation(sf::Time _dt);				//fungsi yang memperbarui animasi

	void jump();			//fungsi yang menangani lompatan pemain
	bool isJumping();		//fungsi yang mengembalikan nilai true saat pemain melompat
	void checkGround();		//sebuah fungsi yang mengembalikan nilai true saat pemain berada di tanah
	void allowNextJump();	//fitur yang memungkinkan pemain melakukan lompatan baru

	int remainingLives();	//fungsi yang mengembalikan kehidupan pemain saat ini
	void hurt();			//sebuah fungsi yang menangani kerusakan pada pemain
	bool respawn();			//sebuah fungsi yang mendukung respawn pemain

	bool hasMoved();		//fungsi yang mengembalikan nilai true jika pemain telah pindah sejak bingkai sebelumnya
	int getScore();
	void addScore(int points); //fitur yang menambahkan poin ke pemain
	bool finishedCurrLevel();  //sebuah fungsi yang mengembalikan nilai true ketika pemain telah menyelesaikan level
};

