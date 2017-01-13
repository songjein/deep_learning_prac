#include <iostream>
#define MAX2(a, b) (a) > (b) ? (a) : (b)

class Neuron{
public:
	double w_;
	double b_;

	double activation(const double& x){
		// for linear or identity activation function
		return x;

		// for ReLu activation functions
		//return MAX2(0.0, x);
	}

	double feedForward(const double& input){
		// output y = f(\sigma)
		// \sigma = w_ * input + b_
		// for multiple inputs,
		// \sigma = w0_ * x0_ + w1_ * x1_ + ... + b_

		const double sigma = w_ * input + b_;

		return activation(sigma);
	}
};

int main(){
	Neuron my_neuron;
	my_neuron.w_ = 2.0;
	my_neuron.b_ = 1.0;

	std::cout << "input = 1.0 " << my_neuron.feedForward(1.0) << std::endl;
	std::cout << "input = 1.0 " << my_neuron.feedForward(2.0) << std::endl;
	std::cout << "input = 1.0 " << my_neuron.feedForward(3.0) << std::endl;

	return 0;
}
