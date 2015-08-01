/*
 * VectorWriter.h
 *
 *  Created on: 25 jul. 2015
 *      Author: christian
 */

#ifndef VECTORWRITER_H_
#define VECTORWRITER_H_

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

class VectorWriter {
public:
	VectorWriter();
	virtual ~VectorWriter();
	inline void SetFileName(std::string filename) { _filename = filename; }
	inline Eigen::VectorXf GetMatrix() { return _matrix; }
	inline void SetMatrix(Eigen::VectorXf matrix) { _matrix = matrix; }
	virtual void write(void);
	virtual void read(void);

protected:
	Eigen::VectorXf _matrix;
	std::string _filename;
};

#endif /* VECTORWRITER_H_ */
