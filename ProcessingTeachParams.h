/**
* ****************************************************************************
*
*  @brief 		Class for all Example parameters based on
*				VcaParamHandler->VcaProcParamHandler.
*
* ----------------------------------------------------------------------------
*
*  @author		Jonas Hofstetter
*
*  @copyright	CC Intelligent Sensors and Networks
*				at Lucerne University of Applied Sciences
*				and Arts T&A, Switzerland.
*
****************************************************************************
*/

#ifndef PROCESSING_TEACH_PARAMS_H
#define PROCESSING_TEACH_PARAMS_H

/***************************** Include Files ********************************/

#include "VcaParamHandler.h"
#include "VcaParam.h"

/************************** Constant Definitions ****************************/

/****************************************************************************/

namespace HSLU
{
	class ProcessingTeachParams : public VcaParamHandler
	{
	public:

		/**
		* @brief Use predefined enum for registration in order to make sure 
		*		 that process indices do not change during development.
		*/
		enum PROCESS_LIST
		{			
			PROCESS_2_TEACH = 0,
		};

		/**
		* @brief Constructor
		*/
		ProcessingTeachParams();

		/**
		* @brief Destructor
		*/
		~ProcessingTeachParams();

		/**
		* @brief Process specific param example.
		*/
		VcaParam general_processCascade;
		VcaParam general_MeasureTime;		
		VcaParam Process2Teach_binaryThreshold;		
	};
}

#endif // PROCESSING_TEACH_PARAMS_H
