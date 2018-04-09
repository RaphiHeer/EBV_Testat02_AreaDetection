/**
 * ****************************************************************************
 * 
 *  @brief 		Generic preprocessor definitions
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

#ifndef DEFS_H
#define DEFS_H

	#ifdef BUILD_DLL  // define for projects using dll interface
		#ifdef _WIN32
			#define DLL_EXPORT __declspec(dllexport)
		#elif LINUX
			#define DLL_EXPORT
		#else
			#define DLL_EXPORT
		#endif // WIN32
	#else
		#define DLL_EXPORT
	#endif

#endif // WIN32
