#pragma once
#include "DxLibPlusObject.h"
#include <queue>
template<typename T, typename Container = std::deque<T>>
class DxIterableQueue :
	public DxLibPlusObject,public std::queue<T,Container>
{
public:
	DxIterableQueue<T,Container>();
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};