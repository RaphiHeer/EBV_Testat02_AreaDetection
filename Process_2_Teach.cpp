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
		
		if(mEstimatedBackground.size() != cv::Size()) // mPrevImage.size() != cv::Size()
		{
			// Processing image
			addDebugMessage("Calculating image");

			int32_t threshold = mParams->Process2Teach_binaryThreshold.getValueAsInt();

			// Differenzbild
			cv::Mat diffImage;
			cv::absdiff(inputImage, mPrevImage, diffImage);

			// Binarisierung
			cv::Mat binaryImage;
			cv::threshold(diffImage, binaryImage, threshold, 255, CV_THRESH_BINARY);

			// Morphologie
			cv::Mat kernel = cv::Mat::ones(5, 5, CV_8UC1);
			cv::Mat BackgroundDifferences;
			cv::morphologyEx(binaryImage, BackgroundDifferences, cv::MORPH_CLOSE, kernel);

			// Region labeling
			cv::Mat stats, centroids, labelImage;
			cv::connectedComponentsWithStats(BackgroundDifferences, labelImage, stats, centroids);

			// Image with detected objects marked
			cv::Mat DetectedObjectImage = inputImage.clone();

			for(int i = 1; i < stats.rows; i++) {
				
				int topLeftx = stats.at<int>(i, 0);
				int topLefty = stats.at<int>(i, 1);
				int width = stats.at<int>(i, 2);
				int height = stats.at<int>(i, 3);

				int area = stats.at<int>(i, 4);

				double cx = centroids.at<double>(i, 0);
				double cy = centroids.at<double>(i, 1);

				cv::Rect rect(topLeftx, topLefty, width, height);
				cv::rectangle(DetectedObjectImage, rect, cv::Scalar(255, 0, 0));

				cv::Point2d cent(cx, cy);
				cv::circle(DetectedObjectImage, cent, 5, cv::Scalar(128,0,0), -1);
				//addDebugMessage(sprintf("Labeling Region %i: Area(%i), centroid(%i, %i)", i, area, cx, cy));
			}

			if(mProcessingDbgImages)
			{
				mProcessingDbgImages->addDebugImage(debugImage0, mEstimatedBackground);
				mProcessingDbgImages->addDebugImage(debugImage1, BackgroundDifferences);
				mProcessingDbgImages->addDebugImage(debugImage1, DetectedObjectImage);
			}

			// Estimate Background
			
		}
		else
		{
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
