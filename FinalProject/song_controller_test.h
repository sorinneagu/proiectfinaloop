#pragma once
#include "SongController.h"
#include "Repository.h"
#include <cassert>

class SongControllerTest {
public:
    void test() {
        Repository repository;
        SongController songController(repository);

        // Test adding songs
        songController.addSong("Song 1", "Artist 1", { "Lyrics 1" });
        songController.addSong("Song 2", "Artist 2", { "Lyrics 2" });
        songController.addSong("Song 3", "Artist 1", { "Lyrics 3" });

        // Test searching for a song
        const Song& song = songController.searchSong("Song 2", "Artist 2");
        assert(song.getTitle() == "Song 2");
        assert(song.getArtist() == "Artist 2");
        assert(song.getLyrics()[0] == "Lyrics 2");

        // Test getting all songs sorted by artist in ascending order
        std::vector<Song> songsByArtist = songController.getAllSongsSortedByArtist();
        assert(songsByArtist.size() == 3);
        assert(songsByArtist[0].getTitle() == "Song 1");
        assert(songsByArtist[1].getTitle() == "Song 3");
        assert(songsByArtist[2].getTitle() == "Song 2");

        // Test getting all songs sorted by title in descending order
        std::vector<Song> songsByTitle = songController.getAllSongsSortedByTitle(false);
        assert(songsByTitle.size() == 3);
        assert(songsByTitle[0].getTitle() == "Song 3");
        assert(songsByTitle[1].getTitle() == "Song 2");
        assert(songsByTitle[2].getTitle() == "Song 1");
    }
};
