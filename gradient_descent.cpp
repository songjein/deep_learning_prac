#include <iostream>

// linear hypothesis
class MyFunction{
public:
	double a_;
	double b_;

	MyFunction()
		: a_(0.0f), b_(0.0f)
	{}

	double getValue(const double& x){
		return a_ * x + b_;	
	}
};

int main(){
	MyFunction mf;

	const float y_t0 = 1.0f; // target
	const float x_0 = 0.0f;

	const float alpha = 0.01f;

	for (int i = 0 ; i < 100; i++){
		// y = ax + b
		// E = 1/2 * (y_taget - y) ^ 2
		// E : squared error
		// 아래 error 는 squared error 이전에 그냥 error
		const float error = y_t0 - mf.getValue(x_0);

		std::cout << "a : " << mf.a_ << " b : " << mf.b_ << std::endl;
		std::cout << "Squared Error = " << 0.5 * error * error << std::endl;

		// 편미분 하면 이렇게 정리 됨
		const float Ea = error * -x_0;	// dE/da ; a를 바꿨을 때 E를 얼마나 바꿀 수 있는가
		const float Eb = error * -1;		// 마찬가지

		mf.a_ -= alpha * Ea;
		mf.b_ -= alpha * Eb;
	}

	return 0;
}
// 이걸 직접 계산할 수 있는 정도라도 되니 너무 좋다
// 나는 무식하게 ax + b 를 y로 치환한 뒤 전개해서 풀었는데
// chain rule 을 이용하면 더 편하게 계산이 될 수 있는듯? 합성함수 이니까
