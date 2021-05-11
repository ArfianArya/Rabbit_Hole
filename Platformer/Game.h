#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "World.h"

using namespace std;
class Game
{
	
private:
	enum GameState { Menu, PlayGame, Finished };	//jenis enumerasi yang menentukan status aplikasi saat ini
	
	GameState currGameState;						//variabel yang menyimpan status aplikasi saat ini

	bool resized;									//variabel yang menyimpan nilai apakah nilai jendela telah berubah sejak pembaruan terakhir atau tidak
	sf::Font fontNormal, fontTitle;					//variabel yang menyimpan font yang digunakan dalam game					
	sf::Text gameText[2], menuText[2], gameTitle, resultText[3];	//variabel yang menyimpan teks yang digunakan dalam game

	World mWorld;								//variabel yang menyimpan level saat ini dalam game dan semua objek di dalamnya
	sf::RenderWindow mWindow;					//variabel yang menyimpan jendela aplikasi
	float mapTop, mapBottom, mapLeft, mapRight; //variabel yang menyimpan posisi tepi peta
	static const sf::Time timePerFrame;			//variabel yang menahan waktu yang dialokasikan ke satu frame
	bool keyPressed[6] = { false };				//variabel yang menahan tombol mana yang telah ditekan
	
	void menu();								//fungsi untuk menangani menu game
	void handleEvents();						//fungsi yang menangani keyboard serta menutup dan mengubah ukuran jendela
	void handlePlayerInput(sf::Keyboard::Key keyCode, bool isPressed);	//fungsi yang mengatur nilai tabel keyPressed sesuai dengan tombol yang ditekan
	void updateView();							//fungsi yang mengoperasikan kamera di dalam game
	void renderGame();							//fungsi yang menampilkan permainan di layar
	void updateGameText();						//fungsi yang memperbarui teks yang ditampilkan selama permainan
	void openLevel(string levelName);			//fungsi yang membuka level yang terdapat dalam file .lvl
	void run();									//fungsi yang mendukung gameplay di level tertentu
	void gameResult(bool levelComplete, int score);//fungsi layar skor pasca-pertandingan
public:
	Game(sf::VideoMode _resolution, string _title);
	void start();	//fungsi yang memulai permainan
};

