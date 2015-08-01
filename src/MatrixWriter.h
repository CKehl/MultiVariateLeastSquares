/*
 * MatrixWriter.h
 *
 *  Created on: 25 jul. 2015
 *      Author: christian
 */

#ifndef MATRIXWRITER_H_
#define MATRIXWRITER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <eigen3/Eigen/Dense>

class MatrixWriter {
public:
	MatrixWriter();
	virtual ~MatrixWriter();
	inline void SetFileName(std::string filename) { _filename = filename; }
	inline Eigen::MatrixXf GetMatrix() { return _matrix; }
	inline void SetMatrix(Eigen::MatrixXf matrix) { _matrix = matrix; }
	virtual void write(void);

protected:
	Eigen::MatrixXf _matrix;
	std::string _filename;
};

#endif /* MATRIXWRITER_H_ */
