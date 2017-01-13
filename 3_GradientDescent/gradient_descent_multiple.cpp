/*
	multiple constraints일 땐?
	그대로 에러를 싹 다 더해서 평균내

	Mean Squared Error
	E = 1/2N * sigma[0..N-1](y_taget_i - y(x_i))^2

	MSE 를 이용해 최적화를 시키는 GD 메서드는
	: 여러개를 평균적으로 만족시킬수 있는 에러펑션을 정의하고
	거기에 대해서 트레이닝을 해

	cf) stochastic GD : 여러 샘플에 대해 하나의 샘플을 골라서 트레이닝시켜 랜덤하게
	트레이닝 횟수가 많고, 분포가 균등하다면 MSE를 사용했을 때와 비슷해질것

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

	// number of constraints
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
		// 평균을 내서 (여러개를 각각 만족시키기보단 전반적으로 만족하게 솔루션을 찾아)
		mf.a_ -= alpha * Ea_sum / (float)num_const;
		mf.b_ -= alpha * Eb_sum / (float)num_const;
	}
	return 0;
}
