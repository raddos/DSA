#include <print>
#include "data_strctures/array/array.h"
//DSA architecture and stuff


auto main() -> int {
	RD::array<int> ar[4]; 

	ar[0].data = new int{ 20 };
	ar[1].data = new int{ 42 };
	ar[2].data = new int{ 11 };
	ar[3].data = new int{ 41 };

	std::println("Print");
	std::println("{}", ar[1].size_view());
	std::println("{}", sizeof(ar));

	for (auto& n : ar) {
		std::println("{}", *n.data);
	}
};