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

#ifndef PROCESSING_ROI_DATA_H
#define PROCESSING_ROI_DATA_H

namespace HSLU
{
	class ProcessingRoiData : public VcaProcBaseData
	{
	public:

		/**
		* @brief Constructor
		*/
		ProcessingRoiData() {};

		/**
		* @brief Destructor
		*/
		virtual ~ProcessingRoiData() {};

		/**
		* @brief Also pass original image e.g. for visualization purposes.
		*/
		cv::Mat ImageOriginal;

		/**
		* @brief OpenCV rect as project specific data.
		*/
		std::vector<cv::Rect> roiList;

		/**
		* @brief Add process specific visualization of result here.
		*/
		cv::Mat ImageResult;
	};
}

#endif // PROCESSING_ROI_DATA_H