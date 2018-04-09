/**
 * ****************************************************************************
 * 
 *  @brief 		Unsorted collection of utilites
 *				
 *
 *				Project: Smart Person Counter
 * 						
 * ---------------------------------------------------------------------------
 *
 *  @author		Roman Sidler
 *					
 *  @copyright	CC Innovation in Intelligent Multimedia Sensor
 *              Networks at Lucerne University of Applied Sciences
 * 				and Arts T&A, Switzerland.				
 *
 ****************************************************************************
 */

#ifndef VCAUTILS_H
#define VCAUTILS_H

#include <string>
#include <vector>
#include <sstream>

#include "VcaUtilsVersion.h"

struct sockaddr_in;


// general purpose string buffer
#define CHARBUF_SIZE 255
typedef char charbuf[CHARBUF_SIZE + 1];
#define CREATE_CHARBUF(buf) charbuf buf; \
                          *buf = buf[CHARBUF_SIZE] = '\0';

#define CHARBUF_EXT_SIZE 1023
typedef char charbufExt[CHARBUF_EXT_SIZE + 1];
#define CREATE_EXT_CHARBUF(buf) charbufExt buf; \
	*buf = buf[CHARBUF_EXT_SIZE] = '\0';

#define CHARBUF_HUGE_SIZE 4096 // Size of large buffer (should be alloced on heap not stack)

struct timespec;

// helper function for various purposes
class VcaUtils
{
public:

    /** 
    * @brief	Returns current VCAParamHandler_lib version as string.
    */ 
	std::string getVersionString();
	
	/** 
    * @brief	Return typed IP-address by String e.g. "192.168.60.123" or "cc.ii-msn.ch"
    */ 
    static long GetAddrFromString (const char* hostnameOrIp, sockaddr_in* addr);
	
	/** 
    * @brief	calculate difference between 2 timevals
    */ 
    static long timevaldiff(struct timeval *starttime, struct timeval *finishtime);
    

    /** 
    * @brief	calculate sum of 2 timespecs
    */ 
    static struct timespec tsAdd(struct  timespec  time1, struct  timespec  time2);
    
    /** 
    * @brief	calculate difference between 2 timespecs
    */ 
    static struct timespec tsDiff(struct  timespec  time1, struct  timespec  time2);
	
	/** 
    * @brief	yet another time interface ..
	*			this one is used to avoid excessive re-calculations of time units
    */ 
    static long long time_ms();

 	/** 
    * @brief	yet another time interface ..
	*			this one is used to avoid excessive re-calculations of time units
    */ 
    static long long time_usec();

 	/** 
    * @brief	yet another time interface ..
	*			this one is used to avoid excessive re-calculations of time units
    */ 
    static double time_sec();

#define MAX_CMDLINE_OPTS 64
	
	/** 
    * @brief	convert string into well known argv[] + argc (return value), expressions enclosed in "", (), [] are returned as one string
    */ 
    static int TokenizeOptions(char *argv[], char *argString);

  /** 
		* @brief	convert string into numerical scalar or vector of type char
		* the string can be a single number, e.g. "23" or a vector, where the '[]' is optional,
		* e.g. "23 45 67" or "[23 45 67]".
		*/ 
		static int String2Numeric(const char *string, char *values, int maxEntries, int index=0);

  /** 
		* @brief	convert string into numerical scalar or vector of type int
		* the string can be a single number, e.g. "23" or a vector, where the '[]' is optional,
		* e.g. "23 45 967" or "[23 45 967]".
		*/ 
		static int String2Numeric(const char *string, int *values, int maxEntries, int index=0);

  /** 
		* @brief	convert string into numerical scalar or vector of type int
		* the string can be a single number, e.g. "23" or a vector, where the '[]' is optional,
		* e.g. "23 45 967" or "[23 45 967]".
		*/ 
		static int String2Numeric(const char *string, short *values, int maxEntries, int index=0);

  /** 
		* @brief	convert string into numerical scalar or vector of type double
		* the string can be a single number, e.g. "23" or a vector, where the '[]' is optional,
		* e.g. "2.3 4.5 6.57" or "[2.3 4.5 6.57]".
		*/ 
		static int String2Numeric(const char *string, double *values, int maxEntries, int index=0);

  /** 
		* @brief	convert string into numerical scalar or vector of type double
		* the string can be a single number, e.g. "23" or a vector, where the '[]' is optional,
		* e.g. "2.3 4.5 6.57" or "[2.3 4.5 6.57]".
		*/ 
		static int String2Numeric(const char *string, float *values, int maxEntries, int index=0);


  /** 
		* @brief	convert string into numerical array of type short
		* the string can be a single row, e.g. "23, 56" or an array, where the rows are separated by ';',
		* e.g. "2.3 4.5; 6.57 3.14".
		*/ 
		static int String2NumericArray(const char *string, short *values, int maxEntries, int *numColsRead, int *numRowsRead, double factor=1.0);

  /** 
		* @brief	convert string into numerical array of type float
		* the string can be a single row, e.g. "23, 56" or an array, where the rows are separated by ';',
		* e.g. "2.3 4.5; 6.57 3.14".
		*/ 
		static int String2NumericArray(const char *string, float *values, int maxEntries, int *numColsRead, int *numRowsRead, double factor=1.0);

  /** 
		* @brief	convert string into numerical array of type double
		* the string can be a single row, e.g. "23, 56" or an array, where the rows are separated by ';',
		* e.g. "2.3 4.5; 6.57 3.14".
		*/ 
		static int String2NumericArray(const char *string, double *values, int maxEntries, int *numColsRead, int *numRowsRead, double factor=1.0);

  /** 
		* @brief	print vector (with length of numValues) to string into buffer of size count with defined format-string.
		*/ 
		static int sprintfVector(char *buffer, size_t count, const char *format, const char* charVector, int numValues);

  /** 
		* @brief	print vector (with length of numValues) to string into buffer of size count with defined format-string.
		*/ 
		static int sprintfVector(char *buffer, size_t count, const char *format, const int* intVector, int numValues);

  /** 
		* @brief	print vector (with length of numValues) to string into buffer of size count with defined format-string.
		*/ 
		static int sprintfVector(char *buffer, size_t count, const char *format, const double* dblVector, int numValues);


  /** 
		* @brief	print timestamp to string into buffer of size count.
		*/ 
		static char* sprintfTimestamp(char *buffer, size_t count, long long timeNowMs=0, bool filenameCompliant=false);

  /** 
	    * @brief	Convert integer into binary string representation
	    */ 
		static char* int2binstring(char* strBuffer, int buflen, int value, int minLength, bool lsbFirst=false);

  /** 
	    * @brief	Trim leading and trailing spaces (' ' and '\t') in string, done in-place.
	    */ 
        static void trimString(char* str);

		/**
		* @brief Checks if files exists.
		*/
		static bool existFile(const std::string& fileName);

		/**
		* @brief Reads binary file to buffer, with optionally allocating buffer.
		*/
		static int readFile2Buffer(const std::string& fileName, size_t* outSize, unsigned char** outBuffer);

		/**
		* @brief Converts a comma separated string to a string vector.
		*/
		static std::vector<std::string> csv2vector(const std::string& csvString, std::string delimiter = ",");

		typedef enum {
			JPGXFORM_NONE,		    /* no transformation */
			JPGXFORM_FLIP_H,		/* horizontal flip */
			JPGXFORM_FLIP_V,		/* vertical flip */
			JPGXFORM_TRANSPOSE,	    /* transpose across UL-to-LR axis */
			JPGXFORM_TRANSVERSE,	/* transpose across UR-to-LL axis */
			JPGXFORM_ROT_90,		/* 90-degree clockwise rotation */
			JPGXFORM_ROT_180,		/* 180-degree rotation */
			JPGXFORM_ROT_270,		/* 270-degree clockwise (or 90 ccw) */
			JPGXFORM_WIPE		    /* wipe */
		} JPG_TRANSFORM;

		/**
		* @brief   Lossless transformation of Jpeg images using jpeglib (transupp.cpp)
		* @details Jpeg compressed input image in buffer imageIn is lossless transformed to jpeg compressed output image
		*          in buffer imageOut, sizeOut is size of image. Buffer for imageOut can either be allocated by calling 
		*          function or is allocated by this function. In either case calling function must deallocate the buffer.
		* @remark  This function uses jpeglib (jpeg-9b_lib) including transupp.cpp (TRANSFORMS_SUPPORTED set to 1):
		*         - transupp.cpp must be added to makefile and projects compiling jpeglib
		*         - in transupp.h declarations must be enclosed in extern "C" such that exported functions are not mangled with C++ compiler
		*         - jpeg-9b_lib.lib must be linked to the application if this function is used
		*/
		static int losslessJpegTransforms(unsigned long sizeIn, unsigned char* imageIn, unsigned long *sizeOut, unsigned char** imageOut, JPG_TRANSFORM jpgTrf, int ofsX=0, int ofsY=0, int width=0, int height=0);

  /**
        * @brief Class handling time periods
        */
        class TimePeriod {
        public:
            TimePeriod():mInvertPeriods(false) {}

            /** 
            * @brief	Inserts period of format hh:mm-hh:mm into vector of periods.
            */ 
            int insertPeriod(char* str);

            /** 
            * @brief	Parse period of format hh:mm-hh:mm.
            */ 
            int parsePeriod(char* str, int& begSec, int& endSec);

            /** 
            * @brief	Checks if period is active (timeMs in millisec).
            */ 
            bool isActive(long long timeMs);

            /** 
            * @brief	Sets periods activitiy to normal (0) or inverted (1).
            */ 
            void setActivityMode(int mode);

            /** 
            * @brief	Sets periods activitiy to normal (0) or inverted (1).
            */ 
            bool getActivityMode() {return mInvertPeriods; }

            /** 
            * @brief	Sets periods activitiy to normal (0) or inverted (1).
            */ 
            void clear();

            /** 
            * @brief	Prints begin and end of period as string.
            */ 
            char* prtPeriod(unsigned int index, char* buf, int bufLen);

            /** 
            * @brief	Returns number of defined periods.
            */ 
            size_t size() { return mPeriods.size(); };

        private:
            /** 
            * @brief	Start and end of active period [start - end[ in seconds
            */ 
            std::vector<std::pair<int, int> > mPeriods;

            /** 
            * @brief	If true, activity of periods are inverted
            */ 
            bool mInvertPeriods;
        };

		/**
		* @brief	converts value to string using string-streams
		*/ 
		template<typename T>
		static std::string toString(T val) {
			std::ostringstream oss;
			oss << val;
			return oss.str();
		}

		/**
		* @brief	find multiple values in a vector, returns vector of iterators
		*/ 
		template<typename T>
		static std::vector<typename std::vector<T>::iterator> multifind(typename std::vector<T>::iterator _beg, typename std::vector<T>::iterator _end, T _val) {
			std::vector<typename std::vector<T>::iterator> foundItems;
			for(typename std::vector<T>::iterator iT = _beg; iT < _end; iT++) {
				if(*iT == _val) {
					foundItems.push_back(iT);
				}
			}
			return foundItems;
		}

private:
	/** 
    * @brief	replacement of strtok function, but with support of enclosed string-segments, e.g. "..", (..), ...
    */ 
	static char* strtok2(char *s1, const char *delimit, const char *segmdelimit);

  /** 
		* @brief	convert string into numerical scalar or numerical vector of various types
		* the string can be a single number, e.g. "23" or a vector, where the '[]' is optional,
		* e.g. "23 45 67" or "[23 45 67]".
		*/ 
		static int String2NumericGeneric(const char *string, void *values, int maxEntries, char valType, int index, int *charConsumed=0, double factor=1.0);

  /** 
		* @brief	convert string into numerical array of various types
		* the string can be a single line, e.g. "23, 456" or an array, where the rows are separated by ';',
		* e.g. "23 45; 67 89".
		*/ 
        static int String2NumericArrayGeneric(const char *string, void *values, int maxEntries, char valType, int *numColsRead, int *numRowsRead, double factor=1.0);

     /** 
	* @brief	print vector (with length of numValues) to string into buffer of size count with defined format-string.
	*/ 
		static int sprintfVectorGeneric(char *buffer, size_t count, const char *format, const void* intVector, int numValues, int valSize, char valtype);

};

#endif /* VCAUTILS_H */
