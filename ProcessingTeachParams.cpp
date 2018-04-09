#include "ProcessingTeachParams.h"

namespace HSLU
{
	ProcessingTeachParams::ProcessingTeachParams()
	{
		// Overall general parameters
		// ********************************

		setDefaultParam("Comma separated list of process cascade.",
			general_processCascade, VcaParam::INTVEC,			"0",	"99",	"0",	PRINT_NAME(general_processCascade));

		setDefaultParam("whether or not to mesure time",
			general_MeasureTime, VcaParam::BOOL,			"0",	"1",	"0",	PRINT_NAME(general_MeasureTime));

		//  Process specific param example.
		// ********************************

		setDefaultParam("Threshold for binary image.",
			Process2Teach_binaryThreshold, VcaParam::INT,		"0",	"255",	"30",		PRINT_NAME(Process2Teach_binaryThreshold));

	}


	ProcessingTeachParams::~ProcessingTeachParams()
	{
	}
}
