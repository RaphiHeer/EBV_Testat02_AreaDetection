/**
 * ****************************************************************************
 * 
 *  @brief 		Simple main running vca_agent.
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

#include <stdio.h> 
#include "VcaAgent.h"
#include "VcaModule.h"
 
int main (int argc, char* argv[]) 
{
	VCAModuleRefs::refModules();

	VcaAgent vcaAgent;
#ifdef NDEBUG
	fprintf(stdout,"Starting VCA agent release version (compiled %s %s, %i-bit)  (C) 2016  CC-IIMSN HSLU\n", __DATE__, __TIME__, (int)sizeof(int)*8);
#else
	fprintf(stdout,"Starting VCA agent debug version (compiled %s %s, %i-bit)  (C) 2016  CC-IIMSN HSLU\n", __DATE__, __TIME__, (int)sizeof(int)*8);
#endif
	int res = vcaAgent.run(argc, argv);
	return res;
}
