#include <iostream>
#include <cstdlib>
#include <ctime>

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
	MyFunction mf, mg;
	
	srand(time(NULL));

	mf.a_ = (float)rand() / RAND_MAX;
	mf.b_ = (float)rand() / RAND_MAX;
	mg.a_ = (float)rand() / RAND_MAX;
	mg.b_ = (float)rand() / RAND_MAX;
	
	const float y_t0 = 1.0f;
	const float x_0 = 0.0f;

	const float alpha = 0.01f;

	std::cout << "Before training y = " << mf.getValue(mg.getValue(x_0)) << std::endl;
	std::cout << mf.a_ << " " << mf.b_ << " " << mg.a_ << " " << mg.b_ << std::endl;

	for (int i = 0; i < 1000; i++){
		const float error = y_t0 - mf.getValue(mg.getValue(x_0));
		const float sqr_error = 0.5 * error * error;

		std::cout << "Squared Error = " << sqr_error << std::endl;

		// 에러가 어느정도 이하로 떨어지면 멈추게
		if (sqr_error < 1e-5) break;

		const float Eaf = -error * mg.getValue(x_0);
		const float Ebf = -error * 1.0f;

		const float Eag = -error * mf.a_ * x_0;
		const float Ebg = -error * mf.a_ * 1.0f;

		// E가 있을 때, 각각에 대한 편미분(chain rule)
		mf.a_ -= alpha * Eaf;
		mf.b_ -= alpha * Ebf;
		mg.a_ -= alpha * Eag;
		mg.b_ -= alpha * Ebg;
	}

	std::cout << "After training y = " << mf.getValue(mg.getValue(x_0)) << std::endl;
	std::cout << mf.a_ << " " << mf.b_ << " " << mg.a_ << " " << mg.b_ << std::endl;
	return 0;
}

