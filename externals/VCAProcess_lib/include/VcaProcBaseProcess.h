/**
***************************************************************************
*
*  @brief       Base class for processes.
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

#ifndef VCA_PROC_BASE_PROCESS_H
#define VCA_PROC_BASE_PROCESS_H

/**************************** Include Files ******************************/

#include <string>
#include <map>
#include <vector>
#include <stdint.h>

/************************* Constant Definitions **************************/

/*************************************************************************/

class VcaParamHandler;//not part of HSLU namespace


namespace HSLU
{
	class VcaProcBaseData;

    class VcaProcBaseProcess
    {
    public:
        /**
        * @brief Constructor
        */
        VcaProcBaseProcess();

        /**
        * @brief Destructor
        */
        virtual ~VcaProcBaseProcess();

		/**
		* @brief Called once in order to initialize the process at the beginning.
		*/
        virtual void initialize(VcaParamHandler* inParams) = 0;

		/**
		* @brief	Function called prior to process step.
		*/
		virtual void preProcessStep() = 0;

        /**
        * @brief Called for every single step.
        */
        virtual VcaProcBaseData* processStep(VcaProcBaseData* inputData, std::vector<VcaProcBaseProcess*> *baseDetectorListPtr=0) = 0;

		/**
		* @brief	Function called after process step.
		*/
		virtual void postProcessStep() = 0;

        /**
        * @brief Returns an object of itself. Necessary for class factory.
        */
        virtual VcaProcBaseProcess* getInstance() = 0;

        /**
        * @brief Returns name of process.
        */
        std::string getProcessName() const;

        /**
        * @brief Returns list of all warnings.
        */
        std::vector<std::string> getWarningMessageList() const;

		/**
		* @brief	Returns list of debug messages.
		*/
		std::vector<std::string> getDebugMessageList() const;

		/**
		* @brief	Returns list of debug messages as formatted string.
		*/
		std::string getDebugMessageListFormatted(int* numMessages);

        /**
        * @brief Clears all warnings in list.
        */
        void clearWarningMessageList();

		/**
		* @brief	Clears current debug message including errors and warnings.
		*/
		void clearDebugMessage();

		/**
		* @brief	Returns pointer to data of process specified by its name
		*/
		static VcaProcBaseData* getProcessDataByName(std::vector<VcaProcBaseProcess*> *baseDetectorListPtr, std::string processName);

		/**
		* @brief Returns pointer to internal data structure (same as returned by processStep())
		*/
		virtual VcaProcBaseData* getProcessData() { return (VcaProcBaseData*)NULL; }

		/**
		* @brief	Returns class name of calling class.
		*/
		inline std::string getClassName(const std::string& functionName)
		{
			size_t classNameBeginIndex = functionName.find("::");
			classNameBeginIndex = functionName.find("::", classNameBeginIndex + 1);
			std::string className = functionName.substr(classNameBeginIndex + 2, functionName.size() - classNameBeginIndex);
			return className;
		}
		#define __CLASS_NAME__ getClassName(__FUNCTION__)

		/**
		* @brief	Returns key consisting of class name and given attribute.
		*			Prefix with underscore of attribute is removed (E.g. key_).
		*/
		inline std::string attributeKey(const std::string& functionName, const std::string& attributeName)
		{
			std::string className = getClassName(functionName);
			// Remove prefix with underscore of attribute. E.g. "key_...".
			size_t underscoreIndex = attributeName.find("_");
			std::string attributeNameNoPrefix = attributeName.substr(underscoreIndex + 1, attributeName.size() - underscoreIndex);

			return className + "_" + attributeNameNoPrefix;
		}
		#define __KEY__(name) attributeKey(__FUNCTION__, #name)

    protected:
        
        /**
        * @brief Name of process.
        */
        std::string mProcessName;

       /**
        * @brief Adds warning message to mWarningMessageList.
        */
        void addWarningMessage(std::string inMessage);

		/**
		* @brief	Sets current debug message.
		*/
		void addDebugMessage(std::string inDebugMessage);

		/**
		* @brief	Throws runtime_error exception with given error message.
		*/
        void setErrorMessage(std::string inErrorMessage);

    private:

		/**
		* @brief List of warning messages.
		*/
		std::vector<std::string> mWarningMessageList;

		/**
		* @brief	Various debug message text.
		*/
		std::vector<std::string> mDebugMessage;
    };
}

#endif // VCA_PROC_BASE_PROCESS_H
