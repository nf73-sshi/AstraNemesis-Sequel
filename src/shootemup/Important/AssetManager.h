#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio.hpp>
#include <string>

class AssetManager
{
	static AssetManager* instance;

	//Stock avec les noms
	std::map<std::string, sf::Texture*> mTextures;
	std::map<std::string, sf::Sound*> mSounds;
	std::map<std::string, sf::Music*> mMusics;

	//Nom puis le Path
	std::map<std::string, std::string> mTexturesPaths;
	std::map<std::string, std::string> mSoundsPaths;
	std::map<std::string, std::string> mMusicPaths;

public:
	~AssetManager();
	static AssetManager* Get();

	//Il faut Load la texture avant de pouvoir la Get correctement
	sf::Texture* LoadTexture(std::string alias, std::string path);
	sf::Sound* LoadSound(std::string alias, std::string path);
	sf::Music* LoadMusic(std::string alias, std::string path);

	sf::Texture* GetTexture(std::string alias);
	sf::Sound* GetSound(std::string alias);
	sf::Music* GetMusic(std::string alias);

	void StopAllSounds();
	void StopAllMusics();

	void PauseOrDePauseAll();
	void ResetPitchAllMusic();
};

