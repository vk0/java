#ifndef _MY_FILE_H_
#define _MY_FILE_H_

#include <string>
#include <cstdio>

class file {
	private:
		FILE *_file;
		std::string _name;
		file(const file &_file) {};
	public:
		file(const std::string &name);
		~file();

		void open();
		void close();

		void writeint(int num);
		void writestring(const std::string &str);

		file& operator<<(int num);
		file& operator<<(const std::string &str);
};

#endif /* _MY_FILE_H_ */

