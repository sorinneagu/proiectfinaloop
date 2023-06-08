#pragma once
#include <string>
#include <vector>
class Song
{

public:
	Song(const std::string& title, const std::string& artist, const std::string lyrics);
	
	std::string getArtist() const;
	std::string getTitle() const;
	std::vector<std::string> getLyrics() const;
	std::vector<std::string> splitLyrics(const std::string& lyrics);
	//void setLyrics(const std::vector<std::string>& lyrics);
private:
	std::string artist;
	std::string title;
	std::vector<std::string> lyrics;

};