#pragma once
#pragma once

namespace RD
{
	// no templates 
	struct vector
	{
	private:
		int* data = nullptr;
		size_t size = 0;
	public:
		//default 
		vector() {};
		//custom constructors
		explicit vector(size_t n) :data(new int[n]), size(n) {};

		//copy const
		vector(const vector& other) :data(new int[other.size]), size(other.size) {
			for (size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}
		//copy asign
		vector& operator=(const vector& other) {
			if (this == &other) {
				return *this;
			} //self-asign check

			delete[] data;

			size = other.size;
			data = new int[size];

			for (size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
			return *this;
		};
		//move const
		vector(vector&& other) noexcept : data(other.data), size(other.size)
		{
			other.size = 0;
			other.data = nullptr;

		};
		//move asign
		vector& operator=(vector&& other) noexcept 
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
		~vector() { delete[] data; }
		
		//access
		int& operator[](size_t i) { return data[i]; }
		const int& operator[](size_t i) const { return data[i]; }

		[[nodiscard]] size_t size_view() const noexcept;

	};

}