#include "array.h"


auto RD::array<int>::size_view() const noexcept-> size_t {
	return this->size;
};