/*
 * MatrixReaderM.cpp
 *
 *  Created on: 18 maart 2015
 *      Author: christian
 */

#include "MatrixReaderM.h"

void MatrixReaderM::read()
{
#ifdef DEBUG
	std::cout << "Read matrix file ..." << std::endl;
#endif
	std::string line;
	std::ifstream file(_filename.c_str());
	std::vector<std::string> strs;
	uint row_num = 0;
	std::vector< Eigen::VectorXf > temp;

	if(file.is_open()==true)
	{

		//while(! ptsfile.eof())
		std::getline(file,line);
		while(file.good()==true)
		{
			if(line.at(0) == '#')
			{
				std::getline(file,line);
				continue;
			}

			Eigen::VectorXf v = Eigen::VectorXf::Zero(4,1);
			line = boost::trim_left_copy(line);
			line = boost::trim_right_copy(line);

			boost::split(strs, line, boost::is_any_of(" "));
			for(uint k = 0; k < strs.size(); k++)
				strs.at(k) = boost::algorithm::trim_copy(strs.at(k));
			if(strs.at(0).empty())
			{
				v(0) = double(atof(strs.at(1).c_str()));
				v(1) = double(atof(strs.at(2).c_str()));
				v(2) = double(atof(strs.at(3).c_str()));
				v(3) = double(atof(strs.at(4).c_str()));
			}
			else
			{
				v(0) = double(atof(strs.at(0).c_str()));
				v(1) = double(atof(strs.at(1).c_str()));
				v(2) = double(atof(strs.at(2).c_str()));
				v(3) = double(atof(strs.at(3).c_str()));
			}

			strs.clear();
			//_matrix(row_num,0) = v(0);
			//_matrix(row_num,1) = v(1);
			//_matrix(row_num,2) = v(2);
			temp.push_back(v);

			std::getline(file,line);
			if(file.eof()==true)
				break;
			row_num++;
		}
#ifdef DEBUG
		std::cout << "File reading operation done." << std::endl;
#endif
		file.close();
		_matrix = Eigen::MatrixXf::Zero(temp.size(),4);
		for(uint i = 0; i < temp.size(); i++)
		{
			_matrix(i,0) = temp.at(i)(0);
			_matrix(i,1) = temp.at(i)(1);
			_matrix(i,2) = temp.at(i)(2);
			_matrix(i,3) = temp.at(i)(3);
		}
		temp.clear();
	}
	else
		std::cout << "Unable to open empty matrix file" << std::endl;
	//_matrix = arma::Mat<double>(data, 4, 4);
	//_matrix = Eigen::MatrixXf()
}
