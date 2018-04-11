#include "ProcessingDbgImages.h"
#include <stdint.h>
#include <stdexcept>

namespace HSLU
{
	ProcessingDbgImages::ProcessingDbgImages()
	{
	}

	ProcessingDbgImages::~ProcessingDbgImages()
	{}

    void ProcessingDbgImages::addDebugImage(std::string imageName, cv::Mat& image, bool scaleAmplitude, float minValue, float maxValue)
    {
        cv::Mat imageSave = image.clone();

        if(scaleAmplitude == true)
        { 
            double minVal = minValue;
            double maxVal = maxValue;

            if(minValue == 0 && maxVal == 0)
            {
                cv::minMaxLoc(imageSave, &minVal, &maxVal);
            }

            double alpha = UCHAR_MAX / (maxVal - minVal);
            double beta =  - minVal * alpha;

            if(image.channels() == 1)
            {
                imageSave.convertTo(imageSave, CV_8UC1, alpha, beta);
            }
            else if(image.channels() == 3)
            {
                imageSave.convertTo(imageSave, CV_8UC3, alpha, beta);
            }            
        }

        mDebugImagesList.push_back(std::pair<std::string, cv::Mat>(imageName, imageSave));
    }

	std::vector<std::pair<std::string, cv::Mat> >* ProcessingDbgImages::getDebugImageList() 
	{
		return &mDebugImagesList;
	}
}
