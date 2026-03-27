#pragma once

namespace RD
{
// T_v->int,float,double..
template<typename T_v>
struct array
{
	T_v* data = nullptr;
	size_t size = 0;

	//default 
	array() = default;

	//custom constructors
	template<int>
	explicit(sizeof(T_v>0)) array(size_t n) :data(new T_v[n]),size(n) { if (data) data = new int[size]; };
	
	//move const

	//copy const

	//move asign

	//copy asign

	[[nodiscard]] size_t size_view() const noexcept;

};

}