/**
***************************************************************************
*
*  @brief       Implementation of VcaProcBaseProcess in order to use
*				OpenCV.
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

#ifndef VCA_PROC_IMAGE_PROCESS_H
#define VCA_PROC_IMAGE_PROCESS_H

/**************************** Include Files ******************************/

#include <string>
#include <map>
#include <stdint.h>

#include "opencv.hpp"

/************************* Constant Definitions **************************/

/*************************************************************************/

namespace HSLU
{
    class ProcessingDbgImages 
    {
    public:

        /**
        * @brief Constructor
        */
        ProcessingDbgImages();

        /**
        * @brief Destructor
        */
        virtual ~ProcessingDbgImages();

		/**
		* @brief	clears debug image list.
		*/
		void ClearDebugImageList() { mDebugImagesList.clear(); }

		/**
		* @brief	Returns debug image list.
		*/
		std::vector<std::pair<std::string, cv::Mat> >* getDebugImageList();

		/**
		* @brief	Adds an image to debug image list.
		*           scaleAmplitude changes image to 8 bit and scales amplitude between minValue and maxValue.
		*           If minValue and maxValue are 0, amplitude is automatically scaled.
		*/
		void addDebugImage(std::string imageName, cv::Mat& image, bool scaleAmplitude = false, float minValue = 0, float maxValue = 0);

    private:

		/**
		* @brief	List of images for debugging.
		*			<imageName, image>
		*/
		std::vector<std::pair<std::string, cv::Mat> > mDebugImagesList;
    };
}

#endif // VCA_PROC_IMAGE_PROCESS_H
