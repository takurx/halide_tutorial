#include <Halide.h>
#include <iostream>

int main()
{
	Halide::Func gradient;
	Halide::Var x, y;
	gradient(x, y) = x + y;
	Halide::Buffer<int32_t> output = gradient.realize(3, 3);

	for (int i = 0; i < output.height(); i++)
	{
		for (int j = 0; j < output.width(); j++)
		{
			std::cout << output(i, j) << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}