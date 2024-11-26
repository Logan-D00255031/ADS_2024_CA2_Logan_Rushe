#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& vector)
{
	os << "[";
	for (size_t i = 0; i < vector.size(); i++)
	{
		os << vector[i];
		if (i < vector.size() - 1)
		{
			os << ", ";
		}
	}
	os << "]";
	return os;
}
