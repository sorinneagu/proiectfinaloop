#pragma once
#include "Repository.h"
#include "Song.h"

class SongController
{
public:
	SongController(Repository& repository);
		
	void addSong(const std::string& title, const std::string& artist, const std::string& lyrics = "");
		
	const Song& searchSong(const std::string& title, const std::string& artist);

	std::vector<Song> getAllSongsSortedByArtist(bool ascending = true);

	std::vector<Song> getAllSongsSortedByTitle(bool ascending = true);

private:
	Repository& repository;
};

