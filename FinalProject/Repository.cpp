#include "Repository.h"

#include <iostream>
#include <vector>
#include <algorithm>


void Repository::store(const Song& s)
{
    auto it = std::find_if(songs.begin(), songs.end(),
        [&s](const Song& song) {
            return song.getTitle() == s.getTitle() && song.getArtist() == s.getArtist();
        });
    if (it != songs.end()) {
        throw SongException(("A song " + s.getTitle() + " by " + s.getArtist() + " already exists").c_str());
    }

    songs.push_back(s);
    save();
}

const Song& Repository::find(std::string title, std::string artist)
{
    auto it = std::find_if(songs.begin(), songs.end(),
        [&title, &artist](const Song& song) {
            return song.getTitle() == title && song.getArtist() == artist;
        });
    if (it == songs.end()) {
        throw SongException(("The song " + title + " by " + artist + " does not exist").c_str());
    }
    return *it;
}

void Repository::remove(const Song& s)
{
    auto it = std::find_if(songs.begin(), songs.end(),
        [&s](const Song& song) {
            return song.getTitle() == s.getTitle() && song.getArtist() == s.getArtist();
        });
    if (it == songs.end()) {
        throw SongException(("The song " + s.getTitle() + " by " + s.getArtist() + " does not exist").c_str());
    }
    songs.erase(it);
    save();
}

const std::vector<Song>& Repository::getAllSongs() const
{
    return songs;
}

void Repository::load()
{
}

void Repository::save()
{
}

