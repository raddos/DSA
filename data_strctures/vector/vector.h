#pragma once

namespace RD
{
	// templated
	template<typename data_type>
	struct Vector
	{
		//default 
		Vector() = default;
		//custom constructors
		explicit Vector(size_t n) :data(new data_type[n]), size(n) {};

		//copy const
		Vector(const Vector& other) :data(new data_type[other.size]), size(other.size) {
			for (size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}
		//copy asign
		Vector& operator=(const Vector& other) {
			if (this == &other) {
				return *this;
			} //self-asign check

			delete[] data;

			size = other.size;
			data = new data_type[size];

			for (size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
			return *this;
		};
		//move const
		Vector(Vector&& other) noexcept : data(other.data), size(other.size)
		{
			other.size = 0;
			other.data = nullptr;

		};
		//move asign
		Vector& operator=(Vector&& other) noexcept
		{
			if (this == &other) {
				return *this;
			} // self-move ownership

			delete[] data;

			size = other.size;
			data = other.data;
			other.size = 0;
			other.data = nullptr;
			return *this;
		};
		~Vector() { delete[] data; }

		//Access view 
		data_type& operator[](size_t i) { return data[i]; }
		const data_type& operator[](size_t i) const { return data[i]; }

		[[nodiscard]] auto size_view() const noexcept -> size_t;

	private:
		data_type* data = nullptr;
		size_t size = 0;


	};

	template<typename data_type>
	auto Vector<data_type>::size_view() const noexcept -> size_t {
		return this->size;
	};
}
