/**
 * ****************************************************************************
 * 
 *  @brief 		This class is representing a VCA parameter.
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

#ifndef VCA_PARAM_H
#define VCA_PARAM_H

/***************************** Include Files ********************************/

#include "VcaDefs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "vca/VCACoordinate.h"

typedef std::vector<std::vector<VCACoordinate<unsigned int> > > Coord2DVector;
typedef std::vector<std::vector<double > > Double2DVector;

/************************** Constant Definitions ****************************/

/****************************************************************************/

class DLL_EXPORT VcaParam
{
public:
	
	VcaParam();
    ~VcaParam();

	/** 
    * @brief	Return values
    */ 
    enum RESULT{SUCCESS, ERROR_GENERAL};

	/** 
    * @brief	Supported data types
    */ 
	enum TYPE {INT, DOUBLE, BOOL, STRING, INTVEC, DOUBLEVEC, INTVEC2D, DOUBLEVEC2D, LAST};

	/** 
    * @brief	Sets default data values using enum TYPE (recommended).
    */ 
	RESULT setDefaultData(std::string xmlParamPath, TYPE type, std::string min, std::string max, std::string value, std::string desc = "");

	/** 
    * @brief	Sets default data values using string type (not recommended).
    */ 
	RESULT setDefaultData(std::string xmlParamPath, std::string type, std::string min, std::string max, std::string value);

	/** 
    * @brief	Sets default data values of class.
    */ 
	RESULT setDefaultData(VcaParam& inParam);

	/** 
    * @brief	Sets data values using enum TYPE (recommended).
    */ 
	RESULT setData(std::string xmlParamPath, TYPE type, std::string min, std::string max, std::string value, std::string desc = "");

	/** 
    * @brief	Sets data values using string type (not recommended).
    */ 
	RESULT setData(std::string xmlParamPath, std::string type, std::string min, std::string max, std::string value, std::string desc = "");

	/** 
    * @brief	Sets data values of class.
    */ 
	RESULT setData(VcaParam& inParam);

	/** 
    * @brief	Sets the value.
    */ 
	void setValue(std::string inValue);

	/** 
    * @brief	Sets the value.
    */ 
	void setParamDesc(std::string inDesc);
	
    /** 
    * @brief	Sets the type as enum (recommended).
    */ 
	void setType(TYPE inType);

	/** 
    * @brief	Sets the type as string (not save).
    */ 
	void setTypeString(std::string inType);

	/** 
    * @brief	Sets the min.
    */ 
	void setMin(std::string inMin);

	/** 
    * @brief	Sets the max.
    */ 
	void setMax(std::string inMax);

	/**
	* @brief	Checks the range of class.
	*/
	RESULT checkRange();

	/**
    * @brief	Name of parameter parsed from mXmlParamPath
	*			E.g. mXmlParamPath:  "paramGroup1_param2"
	*			     mParameterName: "param2"
    */ 
	std::string getParameterName();

	/** 
    * @brief	Returns parameter as integer.
    */ 
	int getValueAsInt();

	/** 
    * @brief	Returns parameter as bool.
    */ 
	bool getValueAsBool();

	/** 
    * @brief	Returns parameter as double.
    */ 
	double getValueAsDouble();

	/** 
    * @brief	Returns parameter as string.
    */ 
	std::string getValueAsString();

    /**
    * @brief  special return type for lists (useful for areas and gates)
    *         String must be of the form "2,4,6,7;3,5,7,8;" for 2x2 points
    *         (last ';' is important!)
    */
    Coord2DVector getValueAsCoord2DVector();

    /**
    * @brief  special return type for lists for arrays of double
    *         String must be of the form "1.1,1.2,1.3;2.1,2.2,2.3;" for 2x3 values
    *         (last ';' is important!)
    */
    Double2DVector getValueAsDouble2DVector();

    /**
    * @brief special return type for lists (useful for areaid and gateid)
    */    
    std::vector<int> getValueAsIntVector();

	/**
	* @brief Returns value as vector of double float
	*/
	std::vector<double> getValueAsDoubleVector();

	/**
	* @brief Returns value as vector of single float
	*/
	std::vector<float> getValueAsFloatVector();

	/**
    * @brief	Returns parameter description as string.
    */ 
	std::string getParamDesc();

	/** 
    * @brief	Returns mXmlParamPath as string.
    */ 
	std::string getXmlParamPath();

	/** 
    * @brief	Returns mType as enum TYPE.
    */ 
	TYPE getParamType();

	/** 
    * @brief	Returns mType as string.
    */ 
	std::string getParamTypeString();

	/** 
    * @brief	Returns mMin as string.
    */ 
	std::string getParamMin();

	/** 
    * @brief	Returns mMax as string.
    */ 
	std::string getParamMax();

	/** 
	* @brief	True if first value set has been modified.
    */ 
	bool isDefaultModified();

	/** 
    * @brief	True if no data is set.
    */ 
	bool isEmpty();

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
    * @brief  helper for extracting numbers from list
    */
    int dec_size(unsigned int *sizeY, unsigned int *sizeX, const char* in);

	/**
	* @brief  helper for converting string to vector of numeric values (double)
	*/
	std::vector<double> str2doubleVector(std::string& valStr);

	/**
	* @brief  helper for converting string to vector of numeric values (float)
	*/
	std::vector<float> str2floatVector(std::string& valStr);

	/**
    * @brief  helper for converting string to vector of numeric values (int)
    */
    std::vector<int> str2intVector(std::string& valStr);

	/** 
    * @brief	Checks the range of class using a type string.
    */ 
	RESULT checkRange(TYPE inType);
	
	/** 
    * @brief	Returns last error message.
    */ 
	void setErrorMessage(std::string inErrorMessage);

	/** 
    * @brief	Checks if values are equal to defaults and
	*			sets respective status.
    */ 
	void checkDefaultAndSetStatus();

	/** 
    * @brief	Returns parameter name of given XML path.
    */ 
	std::string extractParamName(std::string &inXmlParamPath);
	
	/** 
    * @brief	Name of parameter parsed from mXmlParamPath
	*			E.g. mXmlParamPath:  "paramGroup1_param2"
	*			     mParameterName: "param2"
    */ 
	std::string mParameterName;

	/** 
    * @brief	XML path according to respective
	*			XML file.
    */ 
	std::string mXmlParamPath;
	
	/** 
    * @brief	Type of value,
    */ 
	TYPE mType;

	/** 
    * @brief	String representation of data types.
    */ 
	std::string mTypeStringList[LAST];

	/** 
    * @brief	Minimum value allowed.
    */ 
	std::string mMin;

	/** 
    * @brief	Maximum value allowed.
    */ 
	std::string mMax;

	/** 
    * @brief	Parameter value.
    */ 
	std::string mValue;

	/** 
    * @brief	True if no data is set.
    */
	bool mIsEmpty;

	/** 
    * @brief	Default type of value,
    */ 
	TYPE mDefaultType;

	/** 
    * @brief	Default minimum value allowed.
    */ 
	std::string mDefaultMin;

	/** 
    * @brief	Default maximum value allowed.
    */ 
	std::string mDefaultMax;

	/** 
    * @brief	Default parameter value.
    */ 
	std::string mDefaultValue;

    /** 
    * @brief	parameter description.
    */ 
	std::string mParamDesc;

	/** 
    * @brief	True if first value set has been modified.
    */
	bool mDefaultHasModified;

	/** 
    * @brief	Holds current error message.
    */ 
	std::string mErrorMessage;
};
#endif /* VCA_PARAM_H */
