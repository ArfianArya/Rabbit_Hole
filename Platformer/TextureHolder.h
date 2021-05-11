#pragma once
#include <map>
#include <SFML/Graphics.hpp>
namespace Texture {
	enum ID{PlayerIdle,PlayerMove,PlayerJump,PlayerFall,PlayerDie,PlayerCrouch,Platform, Spikes, SpawnPoint, Bat, Bat2, Coin, PortalMove, PortalIdle, Background};
														//jenis enumerasi yang menyimpan id tekstur
}
class TextureHolder
{
private:
	std::map<Texture::ID, std::unique_ptr<sf::Texture>> textureMap;	//peta yang menyimpan semua tekstur dalam game dengan id yang sesuai
public:
	void load(Texture::ID _id, const std::string &filename);	//fungsi menambahkan tekstur pada peta
	sf::Texture& get(Texture::ID _id);							//fungsi yang mengembalikan tekstur dengan id yang diberikan
	const sf::Texture& get(Texture::ID _id) const;				//kelebihan statis dari fungsi di atas
};

