#include "SongController.h"
#include <iostream>
#include <vector>
#include <algorithm>

SongController::SongController(Repository& repository)
	: repository(repository) {}


void SongController::addSong(const std::string& title, const std::string& artist, const std::string& lyrics)
{
	Song newSong(title, artist, lyrics);
	repository.store(newSong);
}

const Song& SongController::searchSong(const std::string& title, const std::string& artist)
{
	return repository.find(title, artist);
}

std::vector<Song> SongController::getAllSongsSortedByArtist(bool ascending)
{
    std::vector<Song> sortedSongs = repository.getAllSongs();
    std::sort(sortedSongs.begin(), sortedSongs.end(),
        [ascending](const Song& song1, const Song& song2) {
            if (ascending) {
                return song1.getArtist() < song2.getArtist();
            }
            else {
                return song1.getArtist() > song2.getArtist();
            }
        });
    return sortedSongs;
}

std::vector<Song> SongController::getAllSongsSortedByTitle(bool ascending)
{
    std::vector<Song> sortedSongs = repository.getAllSongs();
    std::sort(sortedSongs.begin(), sortedSongs.end(),
        [ascending](const Song& song1, const Song& song2) {
            if (ascending) {
                return song1.getTitle() < song2.getTitle();
            }
            else {
                return song1.getTitle() > song2.getTitle();
            }
        });
    return sortedSongs;
}
