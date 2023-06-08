#include "FileRepository.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>


FileRepository::FileRepository(const std::string& filepath)
{
	this->filepath = filepath;
}

void FileRepository::load()
{
    
    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file");
    }

    songs.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::string title, artist, lyrics;

        // Format: title;artist;lyrics
        std::size_t pos = 0;
        std::size_t delimiterPos;
        delimiterPos = line.find(';');
        title = line.substr(pos, delimiterPos - pos);
        pos = delimiterPos + 1;

        delimiterPos = line.find(';', pos);
        artist = line.substr(pos, delimiterPos - pos);
        pos = delimiterPos + 1;


        delimiterPos = line.find(';', pos);
        lyrics = line.substr(pos, delimiterPos - pos);
        pos = delimiterPos + 1;


        songs.emplace_back(title, artist, lyrics);
    }

    file.close();
}

void FileRepository::save()
{
    std::ofstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file");
    }

    for (const auto& song : songs) {
        file << song.getTitle() << ';' << song.getArtist() << ';';

        const auto& lyrics = song.getLyrics();
        for (const auto& line : lyrics) {
            file << line << '\n';
        }
    }

    file.close();
}
