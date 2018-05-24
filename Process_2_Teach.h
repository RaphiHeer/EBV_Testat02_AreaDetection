/**
***************************************************************************
*
*  @brief       Project specific process example.
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

#include "VcaProcBaseProcess.h"
#include "ProcessingTeachParams.h"
#include "ProcessingRoiData.h"

#ifndef PROCESS_2_TEACH_H
#define PROCESS_2_TEACH_H

namespace HSLU
{
	class ProcessingDbgImages;

	class Process_2_Teach : public VcaProcBaseProcess
	{
	public:

		/**
		* @brief Constructor
		*/
		Process_2_Teach();
		Process_2_Teach(ProcessingDbgImages* dbgImg);

		/**
		* @brief Destructor
		*/
		virtual ~Process_2_Teach();

		/**
		* @brief Called once in order to initialize the process at the beginning.
		*/
		virtual void initialize(VcaParamHandler* inParams);

		/**
		* @brief Called for every single step.
		*/
		virtual VcaProcBaseData* processStep(VcaProcBaseData* data, std::vector<VcaProcBaseProcess*> *baseDetectorListPtr = 0);

		/**
		* @brief	Called prior to process step.
		*/
		virtual void preProcessStep() {}

		/**
		* @brief	Function called after process step.
		*/
		virtual void postProcessStep();

		/**
		* @brief Returns an object of itself. Necessary for class factory.
		*/
		virtual VcaProcBaseProcess* getInstance();

		/**
		* @brief List of debug image identifiers.
		*/
		std::string debugImage0;
		std::string debugImage1;
		std::string debugImage2;

		cv::Mat mPrevImage;

		cv::Mat mEstimatedBackground;

	private:
		/**
		* @brief  Pointer to parameters.
		*/
		ProcessingTeachParams* mParams;		

		/**
		* @brief Save for example some processing image data.
		*/
		cv::Mat mProcImage;

		/**
		* @brief reference to ProcessingDbgImages
		*/
		ProcessingDbgImages* mProcessingDbgImages;
	};
}

#endif // PROCESS_2_TEACH_H
