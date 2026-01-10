#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <unordered_map>

class AssetManager
{
	static AssetManager* instance;

	//Stock avec les noms
	std::unordered_map<std::string, sf::Texture*> mTextures;
	std::unordered_map<std::string, sf::SoundBuffer> mSoundBuffers;
	std::unordered_map<std::string, sf::Sound> mSounds;
	std::unordered_map<std::string, std::unique_ptr<sf::Music>> mMusics;

public:
	// VITAL
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

	void PlayMusic(std::string alias);
	void PlayMusicIfNotAlreadyPlayed(std::string alias);

	void InitMusic(std::string alias, std::string path, float volume, bool loop = true); 
	void InitSound(std::string alias, std::string path, float volume); 
};

