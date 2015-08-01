/*
 * MatrixWriterM.cpp
 *
 *  Created on: 25 jul. 2015
 *      Author: christian
 */

#include "MatrixWriterM.h"

MatrixWriterM::MatrixWriterM() : MatrixWriter() {
	// TODO Auto-generated constructor stub

}

MatrixWriterM::~MatrixWriterM() {
	// TODO Auto-generated destructor stub
}

void MatrixWriterM::write(void)
{
	std::ofstream dat_file;
	dat_file.open(_filename.c_str(), std::ios::out|std::ios::trunc);
	if(dat_file.is_open())
	{
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				dat_file << _matrix(i,j) << " ";
			}
			dat_file << std::endl;
		}
		dat_file.close();
	}
	else
		std::cout << "Cannot open DAT file." << std::endl;
}
