//******************************************************************************************//
//              (c) Lucerne University of Applied Sciences and Arts 2016                    //
//        Competence Centre Innovation in Intelligent Multimedia Sensor Networks (IIMSN)    //
//******************************************************************************************//
// 
// generic interface class to hold all major references to VcaProcAlgorithmLib information
//

#if !defined(VCACONSTANTS__H__INCLUDED_)
#define VCACONSTANTS__H__INCLUDED_

///----------------------------------------------RUN-MODE-------------------------------------------------------
///@brief runmode: computer / ADSP-BF561.
#define COMPUTER 0
#define ADSP_BF561 1

#ifndef RUN_MODE
#error Please define RUN_MODE before including this header file. Choose values COMPUTER(0), ADSP_BF561(1)
#endif
///-------------------------------------------------------------------------------------------------------------

const int InfoAgcState = 201;
const int InfoChangeDetectionRois = 202;
const int InfoVehicles = 203;
const int InfoVehiclesResults = 204;
const int InfoProcessTiming = 205;
const int InfoTrackingRois = 206;

#endif //VCACONSTANTS__H__INCLUDED_