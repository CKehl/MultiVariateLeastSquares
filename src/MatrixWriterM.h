/*
 * MatrixWriterM.h
 *
 *  Created on: 25 jul. 2015
 *      Author: christian
 */

#ifndef MATRIXWRITERM_H_
#define MATRIXWRITERM_H_

#include "MatrixWriter.h"

class MatrixWriterM : public MatrixWriter {
public:
	MatrixWriterM();
	virtual ~MatrixWriterM();
	virtual void write(void);
};

#endif /* MATRIXWRITERM_H_ */
