/*
 * VectorWriterM.h
 *
 *  Created on: 25 jul. 2015
 *      Author: christian
 */

#ifndef VECTORWRITERM_H_
#define VECTORWRITERM_H_

#include "VectorWriter.h"

class VectorWriterM : public VectorWriter {
public:
	VectorWriterM();
	virtual ~VectorWriterM();
	virtual void write(void);
};

#endif /* VECTORWRITERM_H_ */
