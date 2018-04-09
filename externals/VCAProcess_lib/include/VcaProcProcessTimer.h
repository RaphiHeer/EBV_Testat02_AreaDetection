/** 
* **************************************************************************** 
*  
*  @brief       Class for timing measurements.
*
* ---------------------------------------------------------------------------- 
* 
*  @author      Martin Rechsteiner
*           
*  @copyright   CC Intelligent Sensors and Networks
*				Lucerne University of Applied Sciences
*               and Arts T&A, Switzerland.
* 
**************************************************************************** 
*/ 

#ifndef VCA_PROC_PROCESS_TIMER_H
#define VCA_PROC_PROCESS_TIMER_H

/***************************** Include Files ********************************/

#include <stdint.h>
#include <string>
#include <time.h> 
#include <limits.h>
#include <map>

/************************** Constant Definitions ****************************/

/****************************************************************************/


namespace HSLU
{
    class VcaProcProcessTimer {

    public:

        /**
        * @brief Constructor
        */
        VcaProcProcessTimer():mLastGlobalStopUsec(0),mGuardTimeUsec(0) {};

        /**
        * @brief Destructor
        */
        ~VcaProcProcessTimer() {};

        /**
        * @brief Set guard time, elapsed time above this value are counted.
        */
        void setGuardTime(int guardTimeMs) { mGuardTimeUsec = 1000*guardTimeMs; }; // convert from millisec to microsec

        /**
        * @brief Set guard time, elapsed time above this value are counted.
        */
        int getGuardTime() const { return mGuardTimeUsec/1000; }; // convert from microsec to millisec

        /** 
        * @brief	Starts measuring the time until stopTimer with
        *			the same name is called.
        */
        void startTimer(const std::string& inName);

        /** 
        * @brief	Stops measuring the time with the same name from
        *			startTimer.
        */
        void stopTimer(const std::string& inName);

		/**
		* @brief Class with enhanced information for timer
		*/
		class TimerInfo
		{
		public:

			TimerInfo();
			~TimerInfo();

			void start(time_t timeNowUsec);
			void update(time_t timeNowUsec, time_t lastGlobalStartUsec, int guardTimeUsec);

			int getMeanUs() const;
			double getVarianceUs() const;
			int getLastTimeUs() const;
			int getMinUs() const;
			int getMaxUs() const;

			int getMeanMs() const;
			double getVarianceMs() const;
			int getLastTimeMs() const;
			int getMinMs() const;
			int getMaxMs() const;

			int getGuardEvents() const;
			int getNumCalls() const;

			time_t startTimeUsec;
			int numEvents;
			int numGuardEvents;
			double sumTimeUsec;
			double sumSqrTimeUsec;
			int minTimeUsec;
			int maxTimeUsec;
			int lastTimeUsec;
		};

		/**
		* @brief List of timer measurements.
		*/
		std::map<std::string, TimerInfo>* getTimerList();

        /** 
        * @brief	Complete list of timers is erased.
        */
        void clearTimers();

    private:

        /** 
        * @brief	Timer measurement list.
        */
        std::map<std::string, TimerInfo> mTimerList;

        /** 
        * @brief	Timestamp of most recent stop.
        */
        time_t mLastGlobalStopUsec;

        /** 
        * @brief	Limit of delay which should not be exceeded, events are counted.
        */
        int mGuardTimeUsec;
    };
}

#endif //VCA_PROC_PROCESS_TIMER_H