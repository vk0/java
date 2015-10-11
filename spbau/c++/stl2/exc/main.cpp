#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>

template <class T, class V>
struct mycmp {
	bool operator()(const std::pair<T, V> &f, const std::pair<T, V> &s) const {
		return f.first < s.first;
	}
};

template <class T, class V>
struct itercmp {
	bool operator()(const typename std::set<std::pair<T, V> >::iterator &f, const typename std::set<std::pair<T, V> >::iterator &s) const {
		return f->second < s->second;
	}
};

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "file name and arg expected" << std::endl;
		return 1;
	}
	std::set<std::pair<std::string, std::string>, struct mycmp<std::string, std::string> > s1;
	std::set<std::set<std::pair<std::string, std::string>, struct mycmp<std::string, std::string> >::iterator, struct itercmp<std::string, std::string> > s2;
	std::fstream in(argv[1]);
	std::string firstname, secondname;
	while (in >> secondname >> firstname) {
		s2.insert(s1.insert(std::make_pair(secondname, firstname)).first);
	}

	for (std::set<std::pair<std::string, std::string> >::iterator i = s1.begin(); i != s1.end(); ++i)
		std::cout << i->first << " " << i->second << std::endl;
	std::cout << std::endl;
	
	for (std::set<std::set<std::pair<std::string, std::string>, struct mycmp<std::string, std::string> >::iterator, struct itercmp<std::string, std::string> >::iterator i = s2.begin(); i != s2.end(); ++i)
		std::cout << (*i)->first << " " << (*i)->second << std::endl;

	return 0;
}