/*
 * MatrixWriterDAT.h
 *
 *  Created on: Apr 24, 2015
 *      Author: christian
 */

#ifndef MATRIXWRITERDAT_H_
#define MATRIXWRITERDAT_H_

#include "MatrixWriter.h"

class MatrixWriterDAT : public MatrixWriter {
public:
	MatrixWriterDAT();
	virtual ~MatrixWriterDAT();
	virtual void write(void);
};

#endif /* MATRIXWRITERDAT_H_ */
