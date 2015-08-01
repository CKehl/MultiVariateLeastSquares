/*
 * MatrixReader.h
 *
 *  Created on: 20 maart 2015
 *      Author: christian
 */

#ifndef MATRIXREADER_H_
#define MATRIXREADER_H_

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

class MatrixReader
{
protected:
	Eigen::MatrixXf _matrix;
	std::string _filename;

public:
	inline MatrixReader() : _matrix(Eigen::MatrixXf()), _filename("") {}
	inline virtual ~MatrixReader() {}
	inline void SetFileName(std::string filename) { _filename = filename; }
	inline Eigen::MatrixXf GetMatrix() { return _matrix; }
	virtual void read(void);
};

#endif /* MATRIXREADER_H_ */
