# C++ Toy Neural Network Library
**(c) 2018, Brehanu Bugg**

This is a simple Neural Network written entirely in C++. The purpose of this project was to understand the inner workings of a Neural Network and how it works. If you are interested, keep reading.

This project is divided into 3 simple files. There's the *Matrix.cpp* file, the *Network.cpp* file, and the *compute.cpp* file. Here's how they work together:

  *Matrix.cpp*: This file is the blueprint for what a Matrix data structure is and how it acts. It is created by using an n-dimensional array based on the specified rows and columns that are fed into it. Here are the operations you can perform on it:
  
    - Addition: element-wise addition of two matricies
    
    - Subtraction: element-wise subtraction of two matricies
    
    - Sub: subtracts a scalar from a Matrix object (used for Gradient Descent: 1.0 - final_outputs)
    
    - Scale: scales a Matrix by a scalar number (used for learning rate)
            
    - Activate: pass in activation function, and it applies it to given Matrix
                
    - Print: prints out the matrix in a human-readable format (similar to Numpy)
            
    - To Matrix: takes an array and creates an **n**x1 Matrix where **n** is the length of the array
    
    - To Array: converts the Matrix to an array by making it one dimensional
    
    - Dot: performs the dot product between two matricies (performs Transpose for you)

  *Network.cpp*: This file is the blueprint for what a Neural Network is and how it works. It is dependent on the *Matrix.cpp* file in order for it to work. Here are how it works:
  
    - Initialization Method: creates the weights and biases based on the Network size the user passes in (number of input, hidden, and output nodes)
    
    - Feedforward Method: Neural Network feedforward algorithm (read more about it below)
    
    - Train Method: Neural Network training algorithm (algorithm description coming later)
    
  *compute.py*: This file is where you initialize your data and pass it through the Neural Network. It is NOT dependent of the *Matrix.cpp* file, but it IS dependent of the *Network.cpp* file.

*Feedforward Algorithm Walkthrough*
The method ``(NeuralNetwork instance).predict(vector<float> inputs)`` expects a float vector for the inputs. Here is the code walkthrough.

``inputs.from_array(inputs_arr);`` converts the given float vector and creates a Nx1 Matrix where N is the amount of items in the array. If passed in ``[0.275, 0.382, 0.231]``, it would make a 3x1 Matrix.

``Matrix hidden_inputs = weights_ih.dot(inputs);`` performs the dot product between the weights between the input and hidden, and the given data. The dot product method in the Matrix library returns a Matrix, so it is stored in ``hidden_inputs``.

``Matrix hidden_outputs = hidden_inputs.activate([WILL MODIFY LATER]);`` applies the activation function (which is passed in the Neural Network constructor function [SOON]) on a specified Matrix. This returns a Matrix, so it is stored in ``hidden_outputs``.

``Matrix final_inputs = weights_ho.dot(hidden_outputs);`` performs the dot product between the weights between the hidden and output, and the hidden output. The dot product method in the Matrix library returns a Matrix, so it is stored in ``final_inputs``.

``Matrix final_outputs = final_inputs.activate([WILL MODIFY LATER]);`` applies the activation function (which is passed in the Neural Network constructor function [SOON]) on a specified Matrix. This returns a Matrix, so it is stored in ``final_outputs``.

``vector<float> prediction = final_outputs.to_array();`` converts to output (from Matrix form) into a float vector, just so it's easier to read. You could also return the ``final_outputs`` then (when you got the returned value) run ``(variable with the prediction).print()``.

``return prediction`` returns the Network's guess! To see the output, do the following:

```c++
NeuralNetwork brain;
brain.init(2, 3, 1, 0.3);

vector<float> inputs = {0, 1};
vector<float> answer = brain.predict(inputs);

printVector(answer);  # [0.284652]
```

You could, instead of ``printVector(answer);`` do ``answer.print();`` *ONLY IF* you do ``return final_outputs;`` in the ``predict()`` method in the class.

This is not meant to be an advanced project, whatsoever. It's just to learn about the inner workings of a Neural Network and how it works. 
