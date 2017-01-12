/*
	multiple constraints일 땐?
	그대로 다 더해서 평균내
	Mean Squared Error
	E = 1/2N * sigma[0..N-1](y_taget_i - y(x_i))^2

	http://blog.naver.com/atelierjpro/220755873110
*/
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

	const int num_const = 3;
	const float y_t[num_const] = {1.0f, 1.5f, 2.0f};
	const float x[num_const] = {0.0f, 0.5f, 1.0f};
	const float alpha = 0.01f;

	for (int i = 0; i < 1000; i++){
		float sqr_error_sum = 0.0f;
		float Ea_sum = 0.0f;
		float Eb_sum = 0.0f;
		for (int c = 0 ; c < num_const; c++){
			const float	error = y_t[c] - mf.getValue(x[c]);
			// 어차피 + 로 결합되어 있으니까, 각각하면 되나봄
			const float Ea = error * -x[c];
			const float Eb = error * -1;
			sqr_error_sum += error * error;
			Ea_sum += Ea;
			Eb_sum += Eb;
		}
		std::cout << "Squared Error = " << 0.5f * sqr_error_sum << std::endl;
		
		// 각각을 가지고 하는게 아니라 한 스텝의 모든 트레이닝 데이터를 가지고
		// 기울기의 합을 통해 한방에 업뎃하네
		mf.a_ -= alpha * Ea_sum / (float)num_const;
		mf.b_ -= alpha * Eb_sum / (float)num_const;
	}
	return 0;
}
