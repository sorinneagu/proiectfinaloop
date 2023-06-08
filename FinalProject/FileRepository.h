#pragma once
#include "Repository.h"

class FileRepository: public Repository
{
public:

	FileRepository(const std::string& filepath);


	void load();
	void save();

private:
	std::string filepath;
};

