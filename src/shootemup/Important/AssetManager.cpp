#include "AssetManager.h"
#include "AssetManager.h"
#include <iostream>
#include <string>

AssetManager* AssetManager::instance = nullptr;

AssetManager::~AssetManager()
{
    if (mTextures.size() > 0)
    {
        for (std::map<const char*, sf::Texture*>::iterator it = mTextures.begin(); it != mTextures.end(); it++)
        {
            delete it->second;
        }
        mTextures.clear();
    }

    if (mSounds.size() > 0)
    {
        for (std::map<const char*, sf::Sound*>::iterator it = mSounds.begin(); it != mSounds.end(); it++)
        {
            delete it->second;
        }
        mSounds.clear();
    }

    if (mMusics.size() > 0)
    {
        for (std::map<const char*, sf::Music*>::iterator it = mMusics.begin(); it != mMusics.end(); it++)
        {
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

sf::Texture* AssetManager::LoadTexture(const char* alias, std::string path)
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

sf::Sound* AssetManager::LoadSound(const char* alias, std::string path) 
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

sf::Music* AssetManager::LoadMusic(const char* alias, std::string path)
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

sf::Texture* AssetManager::GetTexture(const char* alias)
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

sf::Sound* AssetManager::GetSound(const char* alias)
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

sf::Music* AssetManager::GetMusic(const char* alias)
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
