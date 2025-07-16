#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

class AssetManager
{
	static AssetManager* instance;

	//Stock avec les noms
	std::map<std::string, sf::Texture*> mTextures;
	std::map<std::string, sf::SoundBuffer> mSoundBuffers;
	std::map<std::string, sf::Sound> mSounds;
	std::map<std::string, std::unique_ptr<sf::Music>> mMusics;

public:
	~AssetManager();
	static AssetManager* Get();

	bool LoadTexture(std::string alias, std::string path);
	bool LoadSound(std::string alias, std::string path);
	bool LoadMusic(std::string alias, std::string path);

	sf::Texture* GetTexture(std::string alias);
	sf::Sound* GetSound(std::string alias);
	sf::Music* GetMusic(std::string alias);

	void StopAllSounds();
	void StopAllMusics();

	void PauseOrDePauseAll();
	void ResetPitchAllMusic();
};

