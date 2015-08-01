/*
 * VectorWriterM.cpp
 *
 *  Created on: 25 jul. 2015
 *      Author: christian
 */

#include "VectorWriterM.h"

VectorWriterM::VectorWriterM() : VectorWriter() {
	// TODO Auto-generated constructor stub

}

VectorWriterM::~VectorWriterM() {
	// TODO Auto-generated destructor stub
}

void VectorWriterM::write(void)
{
	std::ofstream dat_file;
	dat_file.open(_filename.c_str(), std::ios::out|std::ios::trunc);
	if(dat_file.is_open())
	{
		for(int i = 0; i < 4; i++)
		{
			dat_file << _matrix(i) << " ";
			dat_file << std::endl;
		}
		dat_file.close();
	}
	else
		std::cout << "Cannot open DAT file." << std::endl;
}

