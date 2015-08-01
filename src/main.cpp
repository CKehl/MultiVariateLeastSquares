/*
 * main.cpp
 *
 *  Created on: 22 jul. 2015
 *      Author: christian
 */
#include "main.h"

int main(int argc, char* argv[])
{
	std::string input_filepath_mat, input_filepath_vec, output_filepath;
	options_description desc("Allowed options", strlen("Allowed Options"));
	desc.add_options()
		("help", "help messages")
	    ("input_pmat", value<std::string>(), "defines input matrix file for X")
	    ("input_vec", value<std::string>(), "defines input vector file for Y")
		("output", value<std::string>(), "defines the output matrix file.");

	variables_map vm;
	store(parse_command_line(argc,argv,desc), vm);
	notify(vm);

	if(vm.count("help"))
	{
		std::cout << desc << std::endl;
		return 1;
	}

	if (vm.count("input_pmat"))
	{
		input_filepath_mat = vm["input_pmat"].as<std::string>();
	}

	if(vm.count("input_vec"))
	{
		input_filepath_vec = vm["input_vec"].as<std::string>();
	}

	if(vm.count("output"))
	{
		output_filepath = vm["output"].as<std::string>();
	}


	/*
	 * our model:
	 * long: Y_i = a*X_0i + b*X_1i + c*X_2i + d*X_3i (X_0i = 1)
	 * short: Y = aX
	 */
	VectorXf Y = VectorXf::Constant(102,0);
	MatrixXf X = MatrixXf::Constant(102,4,0);

	/*
	 * Load data - M file
	 */
	MatrixReaderM data_reader;
	data_reader.SetFileName(input_filepath_mat);
	data_reader.read();
	X = data_reader.GetMatrix();
#ifdef DEBUG
	std::cout << "X ready" << std::endl;
#endif

	VectorReaderM vec_reader;
	vec_reader.SetFileName(input_filepath_vec);
	vec_reader.read();
	Y = vec_reader.GetVector();
#ifdef DEBUG
	std::cout << "Y ready" << std::endl;
#endif

	VectorXf a = VectorXf::Constant(4,0);
	/*
	 * solve least squares using normal equation
	 */
#ifdef DEBUG
	std::cout << "start Least Squares optimization" << std::endl;
#endif
	a = (X.transpose() * X).ldlt().solve(X.transpose() * Y);
#ifdef DEBUG
	std::cout << "a ready" << std::endl;
#endif

	/*
	 * Write Result in vector file - M file
	 */
	VectorWriterM data_writer;
	data_writer.SetFileName(output_filepath);
	data_writer.SetMatrix(a);
	data_writer.write();
#ifdef DEBUG
	std::cout << "Y written" << std::endl;
#endif
}



