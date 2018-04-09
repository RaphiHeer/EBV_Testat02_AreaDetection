/**
***************************************************************************
*
*  @brief       Base class for all process data exchange.
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

#ifndef VCA_PROC_BASE_DATA_H
#define VCA_PROC_BASE_DATA_H

/**************************** Include Files ******************************/

#include <stdint.h>

/************************* Constant Definitions **************************/

/*************************************************************************/

namespace HSLU
{
    class VcaProcBaseData
    {
    public:

        /**
        * @brief Constructor
        */
        VcaProcBaseData();

        /**
        * @brief Destructor
        */
        virtual ~VcaProcBaseData();

        /**
        * @brief Set timestamp of data in milliseconds
        */
        void setTimestampMs(long long timestampMs);

        /**
        * @brief Get timestamp of data in milliseconds
        */
        long long getTimestampMs() const;

    private:

        /**
        * @brief Timestamp of data
        */
        long long mTimestampMs;
    };
}

#endif // VCA_ALGO_BASE_DATA_H
