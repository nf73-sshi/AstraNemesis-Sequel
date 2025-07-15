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

    if (mSounds.size() > 0)
    {
        for (std::map<std::string, sf::Sound*>::iterator it = mSounds.begin(); it != mSounds.end(); it++)
        {
            it->second->stop();
            delete it->second;
        }
        mSounds.clear();
    }

    if (mMusics.size() > 0)
    {
        for (std::map<std::string, sf::Music*>::iterator it = mMusics.begin(); it != mMusics.end(); it++)
        {
            it->second->stop();
            delete it->second;
        }
        mMusics.clear();
    }

    mTexturesPaths.clear();
    mSoundsPaths.clear();
    mMusicPaths.clear();
}

AssetManager* AssetManager::Get()
{
    if (instance == nullptr)
    {
        instance = new AssetManager();
    }

    return instance;
}

sf::Texture* AssetManager::LoadTexture(std::string alias, std::string path)
{
    sf::Texture* pTexture = new sf::Texture();

    if (!pTexture->loadFromFile(path))
    {
        if (!pTexture->loadFromFile("../../../" + path)) 
        {
            delete pTexture;
            return nullptr;
        }
     
    }

    mTextures[alias] = pTexture;
    mTexturesPaths[alias] = path;

    return pTexture;
}

sf::Sound* AssetManager::LoadSound(std::string alias, std::string path)
{
    sf::SoundBuffer* pSoundBuffer = new sf::SoundBuffer();
    sf::Sound* pSound = new sf::Sound();

    if (!pSoundBuffer->loadFromFile(path))
    {
        if (!pSoundBuffer->loadFromFile("../../../" + path))
        {
            delete pSoundBuffer; // Éviter les fuites mémoire
            delete pSound; // Éviter les fuites mémoire
            return nullptr;
        }
    }

    pSound->setBuffer(*pSoundBuffer);
    mSounds[alias] = pSound;
    mSoundsPaths[alias] = path;

    return pSound;
}

sf::Music* AssetManager::LoadMusic(std::string alias, std::string path)
{
    sf::Music* pMusic = new sf::Music();

    if (!pMusic->openFromFile(path))
    {
        if (!pMusic->openFromFile("../../../" + path))
        {
            delete pMusic; // Éviter les fuites mémoire
            return nullptr;
        }
    }

    // Stocker la musique et son alias
    mMusics[alias] = pMusic;
    mMusicPaths[alias] = path;

    return pMusic;
}

sf::Texture* AssetManager::GetTexture(std::string alias)
{
    auto it = mTextures.find(alias);
    if (it != mTextures.end())
    {
        return it->second;
    }

    auto pathIt = mTexturesPaths.find(alias);
    if (pathIt != mTexturesPaths.end())
    {
        return LoadTexture(alias, pathIt->second);
    }

    return nullptr; // Alias inconnu
}

sf::Sound* AssetManager::GetSound(std::string alias)
{
    auto it = mSounds.find(alias);
    if (it != mSounds.end())
    {
        return it->second;
    }

    auto pathIt = mSoundsPaths.find(alias);
    if (pathIt != mSoundsPaths.end())
    {
        return LoadSound(alias, pathIt->second);
    }

    return nullptr; // Alias inconnu
}

sf::Music* AssetManager::GetMusic(std::string alias)
{
    auto it = mMusics.find(alias);
    if (it != mMusics.end())
    {
        return it->second;
    }

    // Charger la musique si elle n'est pas en mémoire
    auto pathIt = mMusicPaths.find(alias);
    if (pathIt != mMusicPaths.end())
    {
        return LoadMusic(alias, pathIt->second);
    }

    return nullptr; // Alias inconnu
}

void AssetManager::StopAllSounds()
{
    for (auto it = mSounds.begin(); it != mSounds.end(); ++it)
    {
        if ((*it).second->getStatus() == sf::Sound::Status::Stopped) 
            continue;

        (*it).second->stop();
    }
}

void AssetManager::StopAllMusics()
{
    for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
    {
        if ((*it).second->getStatus() == sf::Music::Status::Stopped) 
            continue;

        (*it).second->stop();
    }
}

void AssetManager::PauseOrDePauseAll()
{
    if (GameManager::GetInstance()->pause == true)
    {
        for (auto it = mSounds.begin(); it != mSounds.end(); ++it)
        {
            if ((*it).second->getStatus() == sf::Sound::Status::Playing)
                (*it).second->pause();

        }

        for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
        {
            if ((*it).second->getStatus() == sf::Music::Status::Playing) 
                (*it).second->pause();
        }
    }
    else
    {
        for (auto it = mSounds.begin(); it != mSounds.end(); ++it)
        {
            if ((*it).second->getStatus() == sf::Sound::Status::Paused)
                (*it).second->play();
        }

        for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
        {
            if ((*it).second->getStatus() == sf::Music::Status::Paused)
                (*it).second->play();
        }
    }

}

void AssetManager::ResetPitchAllMusic()
{
    for (auto it = mMusics.begin(); it != mMusics.end(); ++it)
    {
        (*it).second->setPitch(1);
    }
}
