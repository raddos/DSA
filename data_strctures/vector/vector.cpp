#pragma once
#include "vector.h"

auto RD::vector::size_view() const noexcept-> size_t {
	return this->size;
};