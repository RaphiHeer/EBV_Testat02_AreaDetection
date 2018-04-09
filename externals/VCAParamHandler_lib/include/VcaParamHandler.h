/**
 * ****************************************************************************
 * 
 *  @brief 		Main class for handling VCA parameters.
 *				In order to use it a derived class from VcaParamHandler needs
 *				to be created.
 *
 *				Design principles:
 *
 *						- If a parameter is not available, a compilation
 *						  error shall be generated.
 *						- Default values of parameters shall exist without
 *						  an external parameter file.
 *						- Parameter values representation as string to be
 *						  consistent with XML.
 *
 * ---------------------------------------------------------------------------
 *
 *  @author		Jonas Hofstetter
 *					
 *  @copyright	CC Innovation in Intelligent Multimedia Sensor
 *              Networks at Lucerne University of Applied Sciences
 * 				and Arts T&A, Switzerland.				
 *
 ****************************************************************************
 */

#ifndef VCA_PARAM_HANDLER_H
#define VCA_PARAM_HANDLER_H

/***************************** Include Files ********************************/

#include "VcaDefs.h"
#include "VcaParam.h"
#include "VcaParamsXml.h"
#include "VcaParamHandlerVersion.h"
#include "VcaUtils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <map>

/************************** Constant Definitions ****************************/

#define PRINT_NAME(name) #name

typedef std::map<std::string, VcaParam*>  ParamListMap;
typedef ParamListMap::iterator ParamListMapIter;

/****************************************************************************/

class DLL_EXPORT VcaParamHandler 
{
public:

	VcaParamHandler();

	virtual ~VcaParamHandler();

	/** 
    * @brief	Return values
    */ 
    enum RESULT{SUCCESS, ERROR_GENERAL};

	/** 
    * @brief	This function is used to define the default parameter.
	*			E.g. defineParam(myParam, VcaParam::INT, "0", "20",	"7", PRINT_NAME(myParam));
    */ 
	RESULT setDefaultParam(VcaParam& inParam, VcaParam::TYPE inType, std::string inMin, std::string inMax, std::string inValue, std::string inName, std::string desc = "");
	RESULT setDefaultParam(std::string desc, VcaParam& inParam, VcaParam::TYPE inType, std::string inMin, std::string inMax, std::string inValue, std::string inName);

	/** 
    * @brief	After parameters are defined, loadXML does compare the defined parameters
	*			with parameters in XML file at the position of inRootTag. If a parameter is found,
	*			it will be updated with the value from XML file
	*			(VcaParam::isDefaultModified() set true).
	*			inRootTag e.g. "<tag1><tag2>" or empty.
    */
	RESULT loadXML(std::string inFilePath, std::string inRootTag = "");

	/** 
    * @brief	Saves all parameters from mParamsList as XML to the
	*			given inFilePath using the inRootTag.
	*			inRootTag e.g. "<tag1><tag2>" or empty.
	*			If no parameter is passed, file path of loadXML() is used.
    */
	RESULT saveToXML(std::string inFilePath = "", std::string inRootTag = "");

	/** 
    * @brief  encode parameters as xml to given buf
    */
    RESULT encodeToXml(std::string& buf, bool diffOnly = false);

    /**
    * @brief  decode parameters as xml from given buf
    */
    RESULT decodeFromXml(std::string buf);
	
    /** 
    * @brief	List of all available parameters.
    */ 
	std::map<std::string, VcaParam*>* getParamsList();

	/** 
    * @brief	Returns current VCAParamHandler_lib version as string.
    */ 
	std::string getVersionString();

	/** 
    * @brief	Returns last error message. Error message and hasErrorOccurred() are
	*			cleared after this call.
    */ 
	std::string getLastErrorMessage();

	/** 
    * @brief	Clears current error message.
    */ 
	void clearErrorMessage();

private:

	/** 
    * @brief	Sets current error message.
    */ 
	void setErrorMessage(std::string inMessage);

	/** 
    * @brief	List of all available parameters.
    */ 
	std::map<std::string, VcaParam*> mParamsList;

	/** 
    * @brief	Class for XML handling.
    */ 
	VcaParamsXml mXmlParams;

	/** 
    * @brief	Main file of VcaUtils_lib.
    */ 
	VcaUtils mVcaUtils;

	/** 
    * @brief	Holds current error message.
    */ 
	std::string mErrorMessage;
    
};

#endif //VCA_PARAM_HANDLER_H