#include "ProcessingTeachMain.h"

#include <stdint.h>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>  

#include "Process_2_Teach.h"

namespace HSLU
{
	ProcessingTeachMain::ProcessingTeachMain():
		mIsFactoryCalled(false),
		mParams(NULL)
	{

	}

	VcaProcMain::vcaProcErrorCode ProcessingTeachMain::classFactory()
	{
		try
		{
			clearMessages();
			addDebugMessage("classFactory() called.");
			
			if (mIsFactoryCalled == false)
			{
				if (mParams == NULL) mParams = new ProcessingTeachParams();

				// Use predefined enum in order to make sure that process indices do not change during development.
				registerProcess(ProcessingTeachParams::PROCESS_2_TEACH, new HSLU::Process_2_Teach(&mProcessingDbgImages));

				mIsFactoryCalled = true;
			}
			else
			{
				addWarningMessage("classFactory() already called.");
			}

		}
		catch (std::exception &exception)
		{
			setErrorMessage(exception.what(), false);
			return VCA_PROC_ERROR;
		}

		return VCA_PROC_SUCCESS;
	}

	VcaProcMain::vcaProcErrorCode ProcessingTeachMain::initialize()
	{
		try
		{
			clearMessages();
			initializeMain(mParams, mParams->general_processCascade.getValueAsIntVector());
			SetMeasureTime(mParams->general_MeasureTime.getValueAsBool());
		}
		catch (std::exception &exception)
		{
			setErrorMessage(exception.what());
			return VCA_PROC_ERROR;
		}

		return VCA_PROC_SUCCESS;
	}

	VcaParamHandler* ProcessingTeachMain::getParamHandler()
	{
		return mParams;
	}

	ProcessingTeachMain::~ProcessingTeachMain()
	{
		delete mParams;
	}
}