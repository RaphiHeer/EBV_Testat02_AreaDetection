/** 
* **************************************************************************** 
*  
*  @brief		Main process interface.
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

#ifndef VCA_PROC_MAIN_H
#define VCA_PROC_MAIN_H

/***************************** Include Files ********************************/
#include <stdint.h>
#include <vector>
#include <string>

/************************** Constant Definitions ****************************/

/****************************************************************************/

class VcaParamHandler;//not part of HSLU namespace

namespace HSLU
{
	class VcaProcBaseProcess;
	class VcaProcProcessTimer;
	class VcaProcBaseData;

    class VcaProcMain
    {
    public:

        /** 
        * @brief	Constructor
        */
        VcaProcMain();

        /** 
        * @brief	Destructor
        */
        ~VcaProcMain();

		/**
		* @brief	Generic error codes. In case of VCA_PROC_ERROR, call getErrorMessage() for details.
		*/
		enum vcaProcErrorCode 
		{
			VCA_PROC_SUCCESS = 0,
			VCA_PROC_ERROR
		};

		/**
		* @brief	Creates all necessary objects.
		*			Returns 0 if successful. Call getErrorMessage() in case of errors.
		*/
		virtual vcaProcErrorCode classFactory() = 0;

		/**
		* @brief	Initializes complete algorithm chain.
		*			Returns 0 if successful. Call getErrorMessage() in case of errors.
		*/
		virtual vcaProcErrorCode initialize() = 0;

		/**
		* @brief	Returns pointer to current param handler.
		*/
		virtual VcaParamHandler* getParamHandler() = 0;

        /** 
        * @brief	Register process for work flow.
		*			processIndex must increment in the order of registration in order 
		*			to make sure that process of cascade remains always the same.
        */
        void registerProcess(uint32_t processIndex, VcaProcBaseProcess* baseProcess);

        /** 
        * @brief	Initialize all processes according to cascade.
        */
        void initializeMain(VcaParamHandler *params, std::vector<int32_t> processIndexList);

        /**
        * @brief Executes all registered processes of cascade.
		*		 Returns 0 if successful. Call getErrorMessage() in case of errors.
        */
		vcaProcErrorCode processStep(VcaProcBaseData* inputData);

		/**
		* @brief	Returns a pointer to the data returned from last process in the cascade.
		*/
		VcaProcBaseData* getLastDataFromCascade();

        /** 
        * @brief	Returns list of all process debug messages.
		*			verbosity 0: All messages
		*			verbosity 1: Only process messages.
        */
        std::vector<std::string> getDebugMessageList(uint32_t verbosity = 0) const;

        /** 
        * @brief	Returns all debug messages from getDebugMessageList().
        */
        std::string getAllDebugMessages() const;

        /** 
        * @brief	Returns list of all process warning messages.
        */
        std::vector<std::string> getWarningMessageList() const;

        /** 
        * @brief	Returns all warning messages from getDebugMessageList().
        */
        std::string getAllWarningMessages() const;

        /**
		* @brief	Returns error message if return value of ProcessingStep was not 0.
		*/
        std::string getErrorMessage() const;

		/**
		* @brief	Returns pointer to current timer of processes.
		*/
		VcaProcProcessTimer* getTimerProcesses();

		/**
		* @brief	Returns pointer to current timer of process.
		*/
		VcaProcProcessTimer* getTimerTotal();

		/**
		* @brief	Clears current debug message including errors and warnings.
		*/
		void clearMessages();

        /** 
        * @brief	List to initialized processes.
        */
        std::vector<VcaProcBaseProcess*>* getBaseDetectionList();

        /** 
        * @brief	Returns string of all registered processes.
        */
        std::string showRegisteredProcesses();

		/** 
        * @brief	get and set mMeasureTime;
        */
		void SetMeasureTime(bool measureTime) { mMeasureTime = measureTime; }
		bool GetMeasureTime() { return mMeasureTime; }

    protected:

        /**
		* @brief	Sets error message and throws exception by default..
		*/
        void setErrorMessage(std::string inErrorMessage, bool throwException = true);

		/**
		* @brief Adds warning message to message list.
		*/
		void addWarningMessage(std::string inMessage);

		/**
		* @brief	Adds debug message to message list.
		*/
		void addDebugMessage(std::string inDebugMessage);

		/**
		* @brief	Called after processStep() of complete process cascade.
		*/
		virtual void postProcessStep();

        /**
        * @brief  List of available processes.
        */
        std::vector<VcaProcBaseProcess*> mBaseProcessFactory;

        /**
        * @brief  List of processes.
        */
        std::vector<VcaProcBaseProcess*> mBaseProcessList;

        /**
        * @brief  Clears mVCAInfoMap.
        */
        std::string mErrorMessage;

        /**
        * @brief  Timestamp of recent processed image.
        */
        unsigned long long mRecentTimestampMs;

		/**
		* @brief List of warning messages.
		*/
		std::vector<std::string> mWarningMessageList;

		/**
		* @brief	Various debug message text.
		*/
		std::vector<std::string> mDebugMessage;

		/**
		* @brief	Increments by number of processes.
		*/
		uint32_t mNumberProcessesIndex;

		/**
		* @brief  Pointer to parameters.
		*/
		VcaParamHandler* mParams;

		/**
		* @brief  Pointer to the data returned from last process in the chain.
		*/
		VcaProcBaseData* mLastDataOfCascade;

		/**
        * @brief  whether or not to measure time.
        */
        bool mMeasureTime;

        /**
        * @brief  Class to measure timing elapsed in processes.
        */
        VcaProcProcessTimer* mTimerProcesses;

		/**
		* @brief  Class to measure timing elapsed overall.
		*/
		VcaProcProcessTimer* mTimerTotal;
    };
}
#endif /* VEHICLE_DETECTION_H */



