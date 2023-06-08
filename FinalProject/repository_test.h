#pragma once
#ifndef REPOSITORY_TEST_H
#define REPOSITORY_TEST_H

#include "Repository.h"
#include <cassert>

class RepositoryTest {
public:
    void test() {
        Repository repository;

        // Test storing songs
        Song song1("Song 1", "Artist 1", "Lyrics 1");
        Song song2("Song 2", "Artist 2", "Lyrics 2");
        Song song3("Song 3", "Artist 1", "Lyrics 3");

        repository.store(song1);
        repository.store(song2);
        repository.store(song3);

        // Test finding songs
        const Song& foundSong1 = repository.find("Song 1", "Artist 1");
        assert(foundSong1.getTitle() == "Song 1");
        assert(foundSong1.getArtist() == "Artist 1");

        const Song& foundSong2 = repository.find("Song 2", "Artist 2");
        assert(foundSong2.getTitle() == "Song 2");
        assert(foundSong2.getArtist() == "Artist 2");

        // Test removing songs
        repository.remove(song2);
        try {
            repository.find("Song 2", "Artist 2");
            assert(false);  // Should throw an exception
        }
        catch (const SongException&) {
            // Expected exception thrown
        }

        // Test getting all songs
        const std::vector<Song>& allSongs = repository.getAllSongs();
        assert(allSongs.size() == 2);
        assert(allSongs[0].getTitle() == "Song 1");
        assert(allSongs[0].getArtist() == "Artist 1");
        assert(allSongs[1].getTitle() == "Song 3");
        assert(allSongs[1].getArtist() == "Artist 1");
    }
};

#endif  // REPOSITORY_TEST_H
