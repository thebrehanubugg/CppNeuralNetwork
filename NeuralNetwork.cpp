/* Neural Network C++ Library written in C++
   Created by Brehanu Bugg
   A mini-learning project
*/

/* Importing the string, printing, and Matrix libraries */
#include <iostream>
#include <string>
#include "matrix.h"

/* Initializing a Neural Network class */
class NeuralNetwork {

	/* Our public variables (items that anything can access) */
	public:
		int input_nodes, hidden_nodes, output_nodes;
		Matrix weights_ih, weights_ho;

		float learning_rate;

		void init(int i_nodes, int h_nodes, int o_nodes, float lr);
		vector<float> predict(vector<float> inputs_arr);

		NeuralNetwork();
};

/* Constructor method: required, but doesn't have to do anything */
NeuralNetwork::NeuralNetwork() {
	int nn = 0;
};

/* Initialization method: set all of the empty variables */
void NeuralNetwork::init(int i_nodes, int h_nodes, int o_nodes, float lr) {
	input_nodes = i_nodes;
	hidden_nodes = h_nodes;
	output_nodes = o_nodes;

	weights_ih.init(hidden_nodes, input_nodes);
	weights_ho.init(output_nodes, hidden_nodes);

	learning_rate = lr;
};

/* Feedforward Algorithm */
vector<float> NeuralNetwork::predict(vector<float> inputs_arr) {
	Matrix inputs;
	inputs.from_array(inputs_arr);

	Matrix hidden_inputs = weights_ih.dot(inputs);
	Matrix hidden_outputs = hidden_inputs.activate();

	Matrix final_inputs = weights_ho.dot(hidden_outputs);
	Matrix final_outputs = final_inputs.activate();

	vector<float> prediction = final_outputs.to_array();

	return prediction;
};

/* Print vector function (easier to call) */
void printVector(vector<float> vec) {
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " " << endl;
	}
};

/* The required 'int main()' function */
int main() {
	NeuralNetwork brain;
	brain.init(2, 3, 1, 0.3);

	vector<float> inputs = {0, 1};
	vector<float> answer = brain.predict(inputs);

	printVector(answer);

	return 0;
}; 
