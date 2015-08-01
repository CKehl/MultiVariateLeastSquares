/*
 * VectorReaderM.cpp
 *
 *  Created on: 29 jul. 2015
 *      Author: christian
 */

#include "VectorReaderM.h"

VectorReaderM::VectorReaderM() {
	// TODO Auto-generated constructor stub

}

VectorReaderM::~VectorReaderM() {
	// TODO Auto-generated destructor stub
}

void VectorReaderM::read()
{
#ifdef DEBUG
	std::cout << "Read vector file ..." << std::endl;
#endif
	std::string line;
	std::ifstream file(_filename.c_str());
	std::vector<std::string> strs;
	uint row_num = 0;
	std::vector<float> temp;


	if(file.is_open()==true)
	{

		//while(! ptsfile.eof())
		std::getline(file,line);
		while(file.good()==true)
		{
//#ifdef DEBUG
//			std::cout << line << std::endl;
//#endif
			if(line.at(0) == '#')
			{
				std::getline(file,line);
				continue;
			}

			line = boost::trim_left_copy(line);
			line = boost::trim_right_copy(line);

			boost::split(strs, line, boost::is_any_of(" "));
			for(uint k = 0; k < strs.size(); k++)
				strs.at(k) = boost::algorithm::trim_copy(strs.at(k));

			if(strs.at(0).empty())
			{
				if(strs.size() < 3)
				{
					//_vec(row_num) = atof(strs.at(1).c_str());
					temp.push_back(atof(strs.at(1).c_str()));
				}
				else
				{
					_vec = Eigen::VectorXf::Zero(strs.size()-1,1);
					for(uint i=1; i<(strs.size()); i++)
					{
						_vec(i-1) = atof(strs.at(i).c_str());
					}
					break;
				}
			}
			else
			{
				if(strs.size() < 2)
				{
					//_vec(row_num) = atof(strs.at(1).c_str());
					temp.push_back(atof(strs.at(0).c_str()));
				}
				else
				{
					_vec = Eigen::VectorXf::Zero(strs.size(),1);
					for(uint i=0; i<(strs.size()); i++)
					{
						_vec(i) = atof(strs.at(i).c_str());
					}
					break;
				}
			}

			strs.clear();

			std::getline(file,line);
			if(file.eof()==true)
				break;
			row_num++;
		}
#ifdef DEBUG
		std::cout << "File reading operation done." << std::endl;
#endif
		file.close();
		if( (temp.size()>0) && (_vec.rows()<1) )
		{
			_vec = Eigen::MatrixXf::Zero(temp.size(),1);
			for(uint i = 0; i < temp.size(); i++)
			{
				_vec(i,0) = temp.at(i);
			}
			temp.clear();
		}
	}
	else
		std::cout << "Unable to open empty vector file" << std::endl;
}
