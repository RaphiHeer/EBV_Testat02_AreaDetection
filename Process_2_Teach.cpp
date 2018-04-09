#include "Process_2_Teach.h"
#include "ProcessingDbgImages.h"
#include "ProcessingTeachImageData.h"

namespace HSLU
{
	Process_2_Teach::Process_2_Teach():
		debugImage0("Debug Image 0"),
		debugImage1("Debug Image 1"),
		debugImage2("Debug Image 2"),
		mParams(NULL)
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
		
		//example debug message
		addDebugMessage("Calculate inverse image.");
		
		//initialize processing result (can be skipped if opencv function is used)
		mProcImage = cv::Mat(inputImage.rows, inputImage.cols, inputImage.type());
		
		//"manually" invert the gray scale image		
		//loop over rows and cols and do sth. with pixel		
		for (int rows = 0; rows < inputImage.rows; rows++) {
			for (int cols = 0; cols < inputImage.cols; cols++) {
				//access element at position (rows, cols) in the array and cast as unsigned char
				mProcImage.at<unsigned char>(rows, cols) = 255 - inputImage.at<unsigned char>(rows, cols);
			}
		}

		//this would be the short version using opencv function of inverse calculation (mProcImage could be empty)
		//cv::subtract(255, inputImage, mProcImage);


		//here the result images to be shown in the VCA Web GUI are set
		//currently only one entry (mProcImage) is used
		if(mProcessingDbgImages) {
			mProcessingDbgImages->addDebugImage(debugImage0, mProcImage);
			//two additional debug images can be added to be shown on VCA Web GUI
			//mProcessingDbgImages->addDebugImage(debugImage1, ???);	 
			//mProcessingDbgImages->addDebugImage(debugImage2, ???);
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