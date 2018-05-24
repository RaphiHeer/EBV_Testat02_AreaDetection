#include "Process_2_Teach.h"
#include "ProcessingDbgImages.h"
#include "ProcessingTeachImageData.h"

namespace HSLU
{
	Process_2_Teach::Process_2_Teach():
		debugImage0("Debug Image 0"),
		debugImage1("Debug Image 1"),
		debugImage2("Debug Image 2"),
		mParams(NULL),
		mProcessingDbgImages(NULL)
	{
		mProcessName = "Process2Teach";
		// Do not add functionality here which can go wrong.
		// In order to have a controlled setup, define it in initialize().
	}

	Process_2_Teach::Process_2_Teach(ProcessingDbgImages* dbgImg) :
		debugImage0("Debug Image 0"),
		debugImage1("Debug Image 1"),
		debugImage2("Debug Image 2"),
		mParams(NULL),
		mProcessingDbgImages(dbgImg)
	{
		mProcessName = "Process2Teach";
		// Do not add functionality here which can go wrong.
		// In order to have a controlled setup, define it in initialize().
	}

	Process_2_Teach::~Process_2_Teach()
	{
	}

	void Process_2_Teach::initialize(VcaParamHandler* inParams)
	{
		// Put your initialization here.
		// It will be called once at the beginning.

		// Place your code here.

		// Cast params to specific parameter implementation.
		mParams = dynamic_cast<HSLU::ProcessingTeachParams*>(inParams);
		if (mParams == NULL) setErrorMessage("Unexpected parameter class type.");
	}

	VcaProcBaseData* Process_2_Teach::processStep(VcaProcBaseData* data, std::vector<VcaProcBaseProcess*> *baseDetectorListPtr)
	{
		// Check input data type which is expected for the given process.
		HSLU::ProcessingTeachImageData* imageData = dynamic_cast<HSLU::ProcessingTeachImageData*>(data);
		if (imageData == NULL) setErrorMessage("Unexpected input data.");
		cv::Mat inputImage = imageData->ImageOriginal;
		//in case input is color image
		if (inputImage.channels() == 3) cv::cvtColor(inputImage, inputImage, CV_BGR2GRAY);

		// *********************************
		// Place your code below 
		// *********************************
		
		// get threshold
		int32_t threshold = mParams->Process2Teach_binaryThreshold.getValueAsInt();

		/* this functionality will only be executed, if we have a background
		 * since we take the first image as our background, we execute this 
		 * part on the second image and everyone after
		 */
		if(mEstimatedBackground.size() != cv::Size())
		{
			// print processing image message
			addDebugMessage("Calculating image");

			// create diff between (estimated) background and input image image
			cv::Mat diffImage;
			cv::absdiff(inputImage, mEstimatedBackground, diffImage);

			// create binary image out of it
			cv::Mat binaryImage;
			cv::threshold(diffImage, binaryImage, threshold, 255, CV_THRESH_BINARY);

			// use morph functionality
			cv::Mat kernel = cv::Mat::ones(5, 5, CV_8UC1);
			cv::Mat BackgroundDifferences;
			cv::morphologyEx(binaryImage, BackgroundDifferences, cv::MORPH_CLOSE, kernel);

			// create vars with type declarations I found on stackoverflow
			std::vector<std::vector<cv::Point> > contours;
			std::vector<cv::Vec4i> hierarchy;

			// on this image, the detected objects and text will be drawn
			cv::Mat DetectedObjectImage = inputImage.clone();

			// find contours
			cv::findContours(BackgroundDifferences, contours, hierarchy, CV_RETR_EXTERNAL , CV_CHAIN_APPROX_SIMPLE); 

			// Print foundet contours on image
			for(unsigned int idx = 0 ; idx < contours.size(); idx++ ) { 
				//area 
				double area = cv::contourArea(contours[idx]); 

				//bounding rectangle 
				cv::Rect rect = cv::boundingRect(contours[idx]); 

				// calculate center of mass (centroid)
				cv::Moments moment = cv::moments(contours[idx]); 
				double cx = moment.m10 / moment.m00; 
				double cy = moment.m01 / moment.m00; 

				// draw rectangle for shape on image
				cv::rectangle(DetectedObjectImage, rect, cv::Scalar(255, 0, 0));

				// draw contours for shape on image
				cv::drawContours(DetectedObjectImage, contours, idx, cv::Scalar(255), 1, 8 ); 

				// draw region text on image
				char buf[12];
				snprintf(buf, 12, "Region: %i", idx);
				cv::putText(DetectedObjectImage, buf, cv::Point(cx, cy), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 0, 0));
				
				// print debug message with data of the detected region
				char output[80];
				snprintf(output, 80, "Labeling Region %i: Area(%.2f), centroid(%.2f, %.2f)", idx, area, cx, cy);
				addDebugMessage(output);
			}

			// output images to website
			if(mProcessingDbgImages)
			{
				mProcessingDbgImages->addDebugImage(debugImage0, mEstimatedBackground);
				mProcessingDbgImages->addDebugImage(debugImage1, BackgroundDifferences);
				mProcessingDbgImages->addDebugImage(debugImage1, DetectedObjectImage);
			}

			// estimate background
			double alpha = 0.9;
			cv::addWeighted(mEstimatedBackground, alpha, inputImage, 1 - alpha, 0, mEstimatedBackground);
		}
		else
		{
			// first background = first taken image
			mEstimatedBackground = inputImage;
		}
			
		return imageData;
	}

	void Process_2_Teach::postProcessStep()
	{
	}

	VcaProcBaseProcess* Process_2_Teach::getInstance()
	{
		//  Returns an object of itself. Necessary for class factory.
		return new Process_2_Teach(mProcessingDbgImages);
	}
};
