/* 수치 적분 예쩨 */
#include <iostream>

float getF(const float& x){
	const float a = 0.5;
	const float b = 0.1;

	return a * x + b;
}

int main(){
	const float x = 1.0;
	const float dx = 0.1; // 미분값을 추정하기 위한 difference
	const float dx_target = 0.2; // 추정하고 싶은 위치

	const float df = getF(x + dx) - getF(x);
	const float dfdx = df / dx;

	// 추측하고자 하는 값
	const float f_new = getF(1.0) + dfdx * dx_target;

	std::cout << "f(1.2) = " << getF(x + dx_target) << std::endl;
	std::cout << "f(1) + dfdx * 0.2 = " << f_new << std::endl;
	return 0;
}

// 요런식으로 다음값을 예측하는데도 활용할 수 있겠구나
