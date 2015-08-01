/*
 * MatrixReaderMAT.h
 *
 *  Created on: 18 maart 2015
 *      Author: christian
 */

#ifndef MATRIXREADERM_H_
#define MATRIXREADERM_H_

#include "MatrixReader.h"

class MatrixReaderM : public MatrixReader
{
public:
	inline MatrixReaderM() : MatrixReader() {}
	inline virtual ~MatrixReaderM() {}
	virtual void read(void);
};

#endif /* MATRIXREADERM_H_ */
