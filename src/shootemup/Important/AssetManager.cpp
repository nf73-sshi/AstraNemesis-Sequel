#include "AssetManager.h"
#include "GameManager.h"
#include <iostream>
#include <string>

AssetManager* AssetManager::instance = nullptr;

AssetManager::~AssetManager()
{
    if (mTextures.size() > 0)
    {
        for (std::map<std::string, sf::Texture*>::iterator it = mTextures.begin(); it != mTextures.end(); it++)
        {
            delete it->second;
        }
        mTextures.clear();
    }

    mSounds.clear();
    mSoundBuffers.clear();
}

AssetManager* AssetManager::Get()
{
    if (instance == nullptr)
    {
        instance = new AssetManager();
    }

    return instance;
}

bool AssetManager::LoadTexture(std::string alias, std::string path)
{
    sf::Texture* pTexture = new sf::Texture();

    if (!pTexture->loadFromFile(path))
    {
        if (!pTexture->loadFromFile("../../../" + path)) 
        {
            delete pTexture;
            return false;
        }
     
    }

    mTextures[alias] = pTexture;

    return true;
}

bool AssetManager::LoadSound(std::string alias, std::string path)
{
    sf::SoundBuffer soundBuffer;

    if (!soundBuffer.loadFromFile(path))
    {
        if (!soundBuffer.loadFromFile("../../../" + path))
        {
            return false;
        }
    }

    mSoundBuffers[alias] = soundBuffer;

    sf::Sound sound;

    sound.setBuffer(mSoundBuffers[alias]);
    mSounds[alias] = sound;

    return true;
}

bool AssetManager::LoadMusic(std::string alias, std::string path)
{
    auto music = std::make_unique<sf::Music>();

    if (!music->openFromFile(path)) 
    {
        if (!music->openFromFile("../../../" + path))
        {
            return false;
        }
    }

    mMusics[alias] = std::move(music);

    return true;
}

sf::Texture* AssetManager::GetTexture(std::string alias)
{
    auto it = mTextures.find(alias);
    if (it != mTextures.end())
    {
        return it->second;
    }

    return nullptr; // Alias inconnu
}

sf::Sound* AssetManager::GetSound(std::string alias)
{
    auto it = mSounds.find(alias);
    if (it != mSounds.end())
    {
        return &(it->second);
    }

    return nullptr; // Alias inconnu
}

sf::Music* AssetManager::GetMusic(std::string alias)
{
    auto it = mMusics.find(alias);
    if (it != mMusics.end())
    {
        return it->second.get();
    }

    return nullptr; // Alias inconnu
}

void AssetManager::StopAllSounds()
{
    for (auto it = mSounds.begin(); it != mSounds.end(); ++it)
    {
        if (it->second.getStatus() == sf::Sound::Status::Stopped) 
            continue;

        it->second.stop();
    }
}

void AssetManager::StopAllMusics()
{
    for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
    {
        if (it->second.get()->getStatus() == sf::Music::Status::Stopped) 
            continue;

        it->second.get()->stop();
    }
}

void AssetManager::PauseOrDePauseAll()
{
    if (GameManager::GetInstance()->pause == true)
    {
        for (auto it = mSounds.begin(); it != mSounds.end(); ++it)
        {
            if (it->second.getStatus() == sf::Sound::Status::Playing)
                it->second.pause();

        }

        for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
        {
            if (it->second.get()->getStatus() == sf::Music::Status::Playing) 
                it->second.get()->pause();
        }
    }
    else
    {
        for (auto it = mSounds.begin(); it != mSounds.end(); ++it)
        {
            if (it->second.getStatus() == sf::Sound::Status::Playing)
                it->second.pause();
        }
        for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
        {
            if (it->second.get()->getStatus() == sf::Music::Status::Playing)
                it->second.get()->pause();
        }
    }

}

void AssetManager::ResetPitchAllMusic()
{
    for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
    {
        it->second.get()->setPitch(1);
    }
}
