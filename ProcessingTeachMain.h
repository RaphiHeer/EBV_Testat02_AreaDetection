/** 
* **************************************************************************** 
*  
*  @brief          Main interface of Example Algorithm Lib.
*
* ---------------------------------------------------------------------------- 
* 
*  @author         Jonas Hofstetter
*           
*  @copyright      CC Intelligent Sensors and Networks
*                  at Lucerne University of Applied Sciences 
*                  and Arts T&A, Switzerland. 
* 
**************************************************************************** 
*/ 

#ifndef PROCESSING_TEACH_MAIN_H
#define PROCESSING_TEACH_MAIN_H

/***************************** Include Files ********************************/

#include <stdint.h>
#include "ProcessingTeachParams.h"
#include "VcaProcMain.h"
#include "VcaProcBaseProcess.h"
#include "ProcessingDbgImages.h"

/************************** Constant Definitions ****************************/

/****************************************************************************/

namespace HSLU
{
    class ProcessingTeachMain : public VcaProcMain
    {
    public:

       /** 
        * @brief	Constructor
        */
        ProcessingTeachMain();

        /** 
        * @brief	Destructor
        */
        ~ProcessingTeachMain();

		/**
		* @brief	Creates all necessary objects.
		*			Returns 0 if successful. Call getErrorMessage() in case of errors.
		*/
		vcaProcErrorCode classFactory();

		/**
		* @brief	Initializes complete algorithm chain.
		*			Returns 0 if successful. Call getErrorMessage() in case of errors.
		*/
		vcaProcErrorCode initialize();

		/**
		* @brief	Returns pointer to current param handler.
		*/
		VcaParamHandler* getParamHandler();

		/**
		* @brief	Returns pointer to debug image list
		*/
		ProcessingDbgImages* getProcessingDbgImages() { return &mProcessingDbgImages; }

    private:

		/**
		* @brief	True if class factory has been called.
		*/
		bool mIsFactoryCalled;

		/**
		* @brief	hold instance of all debug images
		*/
		ProcessingDbgImages mProcessingDbgImages;

		/**
		* @brief  Pointer to parameters.
		*/
		ProcessingTeachParams* mParams;

    };
}
#endif /* PROCESSING_TEACH_MAIN_H */



