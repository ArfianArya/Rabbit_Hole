#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include "Player.h"
#include "Collidable.h"
#include "Entity.h"
#include "TextureHolder.h"
#include "Bat.h"
#include "Coin.h"
#include "Portal.h"

class World:
	public sf::Drawable
{
private:
	const static int pointTreshold;		//variabel yang menyimpan jumlah koin yang dibutuhkan untuk membuka portal
	sf::View currView;					//variabel yang menyimpan tampilan kamera saat ini
	TextureHolder textures;				//variabel yang menampung semua tekstur dalam game
	sf::Sprite background;				//variabel latar belakang
	Player *mPlayer;					//variabel yang menahan penunjuk ke pemutar
	std::vector<Entity*> mBlocks;		//variabel yang menyimpan vektor pointer ke semua objek statis
	std::vector<SpawnPoint*> mSpawnPoints; //variabel memegang vektor pointer ke semua bibit
	std::vector<Bat*> mEnemies;			//variabel yang menyimpan vektor pointer ke semua lawan
	std::vector<Coin*> mCoins;			//variabel yang menyimpan vektor pointer untuk semua koin
	Portal *mPortal;					//variabel yang menahan penunjuk ke portal



	void multithreadEnemyCollisions(std::vector<Bat*> enemies, int firstIndex, int n); //fungsi yang memecahkan tabrakan lawan menggunakan multi-threading
	void handleBetterEnemyCollisions();	//sebuah fungsi yang memanggil fungsi multi-utas untuk memecahkan tabrakan lawan
	void updateEnemies(sf::Time _dt);	//fungsi yang memperbarui pergerakan semua lawan
	void handlePlayerCollisions();		//sebuah fungsi yang menyelesaikan benturan pemain
	void updateAnimations(sf::Time _dt);//fitur yang memperbarui semua animasi objek dalam game
	void cleanCoins();					//sebuah fungsi yang menghilangkan koin yang terkumpul
	void draw(sf::RenderTarget & target, sf::RenderStates state) const override;//fungsi yang menggantikan fungsi menggambar perpustakaan
	void updateBackground();			//fungsi yang menciptakan latar belakang

public:

	World();
	~World();

	bool update(sf::Time _dt, bool keyPressed[5]);
	sf::Vector2f getPlayerPostition();
	void loadTextures();				//fungsi yang memuat semua tekstur yang diperlukan
	void addObject(Player *newPlayer);	//fitur yang menambah dunia pemain
	void addObject(Entity *newBlock);	//fungsi yang menambahkan objek statis ke dunia
	void addObject(SpawnPoint *newSpawnPoint); //fitur yang menambahkan spawn ke dunia pemain
	void addObject(Bat *newEnemy);		//fungsi yang menambah dunia lawan
	void addObject(Coin *newCoin);		//fungsi yang menambahkan uang ke dunia
	void addObject(Portal *newPortal);	//fitur yang menambahkan portal ke dunia
	int playerHealth();					//fungsi yang mengambil nyawa pemain dan mengembalikannya
	int playerScore();					//fungsi yang mengambil poin pemain dan mengembalikannya
	void setCurrView(sf::View _currView);
	int getPointTreshold();
	bool playerVictory();				//sebuah fungsi yang mengambil bendera kemenangan pemain dan mengembalikannya
	sf::Vector2f getPlayerVelocity();	//fungsi yang mengambil vektor kecepatan pemain dan mengembalikannya
};


