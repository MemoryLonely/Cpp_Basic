#include <boost/sort/sort.hpp>
#include <algorithm>
#include <vector>
#include"BoostCommon.h"

using namespace std;

void boostMain() {

	vector<int> arr;

	while (arr.size() < 100) arr.push_back(std::rand());

	boost::sort::block_indirect_sort(std::begin(arr), std::end(arr));

	for_each(std::begin(arr), std::end(arr), [](int& a) {
		cout << a << "\t";
	});
}