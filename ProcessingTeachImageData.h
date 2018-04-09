/**
***************************************************************************
*
*  @brief       Project specific data example.
*
*--------------------------------------------------------------------------
*
*  @author      Jonas Hofstetter
*
*  @copyright   CC Intelligent Sensors and Networks
*				Lucerne University of Applied Sciences
*               and Arts T&A, Switzerland.
*
***************************************************************************
*/

#include "VcaProcBaseData.h"
#include "opencv.hpp"

#ifndef PROCESSING_TEACH_IMAGE_DATA_H
#define PROCESSING_TEACH_IMAGE_DATA_H

namespace HSLU
{
	class ProcessingTeachImageData : public VcaProcBaseData
	{
	public:

		/**
		* @brief Constructor
		*/
		ProcessingTeachImageData() {};

		/**
		* @brief Destructor
		*/
		virtual ~ProcessingTeachImageData() {};

		/**
		* @brief Also pass original image e.g. for visualization purposes.
		*/
		cv::Mat ImageOriginal;

		/**
		* @brief OpenCV image as project specific data.
		*/
		cv::Mat ImageProcess;

		/**
		* @brief Add process specific visualization of result here.
		*/
		cv::Mat ImageResult;
	};
}

#endif // PROCESSING_TEACH_IMAGE_DATA_H