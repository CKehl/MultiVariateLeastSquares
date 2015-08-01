/*
 * VectorReaderM.h
 *
 *  Created on: 29 jul. 2015
 *      Author: christian
 */

#ifndef VECTORREADERM_H_
#define VECTORREADERM_H_

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

class VectorReaderM {
public:
	VectorReaderM();
	virtual ~VectorReaderM();
	inline void SetFileName(std::string filename) { _filename = filename; }
	inline std::string GetFileName(void) { return _filename; }
	inline Eigen::VectorXf GetVector() { return _vec; }
	virtual void read(void);

protected:
	Eigen::VectorXf _vec;
	std::string _filename;
};

#endif /* VECTORREADERM_H_ */
