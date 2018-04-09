/**
 * ****************************************************************************
 * 
 *  @brief 		This class is handling XML parameters for VCA applications.
 *				It's using Mini-XML (http://www.minixml.org/).
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

#ifndef VCA_PARAMS_XML_H
#define VCA_PARAMS_XML_H

/***************************** Include Files ********************************/

#include "VcaDefs.h"
#include "VcaParam.h"
#include "mxml/mxml.h"
#include <list>

/************************** Constant Definitions ****************************/

#define XML_FILE_SIZE_MAX_BYTES		1024
#define XML_VCA_PARAMS_ROOT_NAME	"vcaparams"

/****************************************************************************/

class DLL_EXPORT VcaParamsXml
{
public:
	
	/** 
    * @brief	Create object with parameter data
    */ 
	VcaParamsXml();
	
	/** 
    * @brief	Destructor
    */
    ~VcaParamsXml();

	/** 
    * @brief	Return values
    */ 
    enum RESULT{SUCCESS, ERROR_GENERAL};
	
	/** 
    * @brief	Dump to file with given name.
	*			If no file name is set, path from loadFile() 
	*			is used.
    */ 
    RESULT writeFile(std::string inFileName = "");
	
	/** 
    * @brief	Loads an XML file to mXmlRoot.
    */ 
    RESULT loadFile(std::string inFileName, std::string inRootTag = "");
    
	/** 
    * @brief  write xml to given buffer
    */ 
    RESULT writeXmlToBuf(std::string& buf);
	
    /** 
    * @brief	read xml from given buffer
    */ 
    RESULT readXmlFromBuf(std::string buf, std::string inRootTag = "");

	/** 
    * @brief	Returns parameter from XML according to given
	*			"_" or "/" separated inParamPath. LoadFile has to be
	*			executed first. If an error occurs, 
	*			VcaParam.isEmpty() is true.
	*			E.g. inParamPath: "paramGroup1_param1"
	*			Note: Path without root element "vcaparams"
    */ 
    VcaParam getParameter(std::string inXmlParamPath);

    /**
    * @brief  same as above but get value only (rest taken from Param)
    */

    VcaParam getParameterValue(std::string inXmlParamPath, VcaParam* Param);

    /**
    * @brief delete root and complete xml tree
    */
    void deleteXmlRoot();

	/** 
    * @brief	Adds new parameter according to given inParam.
	*			If you want to save those changes in XML file,
	*			use writeFile();
    */ 
    RESULT addParameter(VcaParam& inParam);

	/** 
    * @brief	Sets value of attribute according to given
	*			inXmlParamPath, inAttributeName and inValue.
	*			If you want to save those changes in XML file,
	*			use writeFile();
    */ 
    RESULT setParameterAttribute(std::string inXmlParamPath, std::string inAttributeName, std::string inValue);

	/** 
    * @brief	Returns last error message.
    */ 
	std::string getLastErrorMessage();

	/** 
    * @brief	Clears current error message.
    */ 
	void clearErrorMessage();

private:

	/** 
    * @brief	Returns last error message.
    */ 
	void setErrorMessage(std::string inErrorMessage);
	
	/** 
    * @brief	Make the parser happy, mxml is small but not tolerant.
	*			Returns cleaned string.
    */ 
    std::string removeNotAllowedChars(std::string inStringToClean);

	/** 
    * @brief	Mini-XML does not apply any format for XML.
	*			So we add it here in order to make it more readable.
	*			Returns empty string if any error occurs.
    */ 
	std::string formatXmlString(std::string inXmlString);

	/** 
    * @brief	Replpaces all '_' in inString with '/'
	*			and returns as new string.
    */ 
	std::string replaceUnderscoreBySlash(std::string inString);

	/** 
    * @brief	XML-Document root
    */ 
    struct mxml_node_s* mXmlRoot;

	/** 
    * @brief	Node to the vcaparams section in XML.
    */ 
	mxml_node_t* mVcaParamsNode;

	/** 
    * @brief	Path to the file which was used in loadFile.
    */ 
	std::string mXmlFilePathOpened;

	/** 
    * @brief	Holds current error message.
    */ 
	std::string mErrorMessage;
};
#endif /* VCA_PARAMS_XML_H */
