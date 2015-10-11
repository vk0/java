#include "file.h"

file::file(const std::string &name): _file(NULL), _name(name)
{
	open();
}

file::~file()
{
	close();
}

void file::open()
{
	_file = fopen(_name.c_str(), "r");
}

void file::close()
{
	fclose(_file);
}

void file::writeint(int num)
{
	fprintf(_file, "%d", num);
}

void file::writestring(const std::string &str)
{
	fprintf(_file, "%s", str.c_str());
}

file& file::operator<<(int num)
{
	this->writeint(num);
	return *this;
}

file& file::operator<<(const std::string &str)
{
	this->writestring(str);
	return *this;
}
