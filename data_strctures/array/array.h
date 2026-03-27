#pragma once

namespace RD
{
struct array
{
	int* data = nullptr;
	size_t size = 0;

	array() = default;

	int view_size();
};


}