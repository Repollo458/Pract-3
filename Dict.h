#ifndef DICT_H
#define DICT_H
#include <string>

template <typename V>
class Dict{
	public:
		virtual void insert(std::stringkey, V value);
		virtual V search(std::stringkey);
		virtual V remove(std::stringkey);
		virtual int entries();
};

#endif
