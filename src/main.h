/*
 * main.h
 *
 *  Created on: 22 jul. 2015
 *      Author: christian
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace Eigen;

#include <boost/program_options.hpp>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/config.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/version.hpp>


#include <boost/filesystem.hpp>

using namespace boost::program_options;
using namespace boost::filesystem;

#include "MatrixReaderM.h"
#include "MatrixWriterDAT.h"
#include "MatrixWriterM.h"
#include "VectorReaderM.h"
#include "VectorWriterM.h"

#endif /* MAIN_H_ */
