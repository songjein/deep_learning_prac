#include <iostream>

float getF(const float& x){
	const float a = 0.5;
	const float b = 0.1;

	return a * x + b;
}

int main(){
	const float x = 1.0;
	const float dx = 0.1;
	const float df = getF(x + dx) - getF(x);
	const float dfdx = df / dx;

	const float f_target = 0.7;
	const float dx_target = (f_target - getF(x)) / dfdx;

	std::cout << "f_target = " << f_target << std::endl;
	std::cout << "f(x + dx_target) = " << getF(x + dx_target) << std::endl;
	std::cout << "dx_taget = " << dx_target << std::endl;
	return 0;
}
