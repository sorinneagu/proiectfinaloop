#pragma once
#include "Song.h"
#include "SongException.h"

class Repository
{
public:
	Repository() = default;
	Repository(const Repository&) = delete;

	void store(const Song& s);
	const Song& find(std::string title, std::string artist);
	void remove(const Song& s);
	const std::vector<Song>& getAllSongs() const;
	void load();
	void save();

//private:
	std::vector<Song> songs;

};

