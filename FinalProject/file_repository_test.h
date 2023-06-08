
#ifndef FILE_REPOSITORY_TEST_H
#define FILE_REPOSITORY_TEST_H

#include "FileRepository.h"
#include <cassert>

class FileRepositoryTest {
public:

    void test() {
        FileRepository fileRepository("songs_test.txt");

        // Test loading and saving songs
        fileRepository.load();
        assert(fileRepository.getAllSongs().size() == 0);

        Song song1("Song 1", "Artist 1", "Lyrics 1");
        Song song2("Song 2", "Artist 2", "Lyrics 2");
        Song song3("Song 3", "Artist 1", "Lyrics 3");

        fileRepository.store(song1);
        fileRepository.store(song2);
        fileRepository.store(song3);

        fileRepository.save();

        // Test loading the saved songs
        FileRepository loadedRepository("songs_test.txt");
        loadedRepository.load();

        const std::vector<Song>& allSongs = loadedRepository.getAllSongs();
        assert(allSongs.size() == 3);
        assert(allSongs[0].getTitle() == "Song 1");
        assert(allSongs[0].getArtist() == "Artist 1");
        assert(allSongs[1].getTitle() == "Song 2");
        assert(allSongs[1].getArtist() == "Artist 2");
        assert(allSongs[2].getTitle() == "Song 3");
        assert(allSongs[2].getArtist() == "Artist 1");
    }
};

#endif  // FILE_REPOSITORY_TEST_H
