#include "Song.h"

Song::Song(const std::string& title, const std::string& artist, const std::string lyrics)
	: title(title), artist(artist), lyrics(splitLyrics(lyrics)) {}

std::string Song::getArtist() const
{
	return this->artist;
}

std::string Song::getTitle() const
{
	return this->title;
}

std::vector<std::string> Song::getLyrics() const
{
	return this->lyrics;
}

std::vector<std::string> Song::splitLyrics(const std::string& lyrics)
{
    std::vector<std::string> words;
    std::string word;

    for (char c : lyrics) {
        if (std::isalpha(c)) {
            word += std::tolower(c);
        }
        else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

//void Song::setLyrics(const std::vector<std::string>& lyrics)
//{
//    this->lyrics = lyrics;
//}
