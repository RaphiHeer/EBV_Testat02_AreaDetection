/**
 * ****************************************************************************
 * 
 *  @brief 		Main function of vca_agent managing the grabbers, servers and
 *				options.
 * 						
 * ---------------------------------------------------------------------------
 *
 *  @author		Roman Sidler, Jonas Hofstetter
 *					
 *  @copyright	CC Innovation in Intelligent Multimedia Sensor
 *              Networks at Lucerne University of Applied Sciences
 * 				and Arts T&A, Switzerland.				
 *
 ****************************************************************************
 */

#ifndef VCA_AGENT_H
#define VCA_AGENT_H


/****************************************************************************/

using namespace std;

class Grabber;
class VOBase;
class VcaAgentCfg;
class BarixClient;

class VcaAgent
{
public:

	/** 
	* @brief	Default constructor
	*/
    VcaAgent();

	/** 
	* @brief	Destructor
	*/
    ~VcaAgent();

	/** 
	* @brief	Result definitions
	*/
	// TODO: Many different result enums in different classes. Create overall concept of result indexes.
	enum RESULT{SUCCESS=0, INVALID_STARTARG, TOOLONG_STARTARGS, TOOMANY_HTTPSERVERARGS, HTTPSERVER_FAILED, IVPSERVER_FAILED, MODULE_NOT_COMPILED, FAILED};

	/** 
	* @brief	Runs agent using command line options.
	*			Error if return value not 0.
	*/
	int run(int argc, char **argv);

	/** 
	* @brief	Returns pointer to VcaAgentCfg used.
	*/
	VcaAgentCfg* getAgentCfg();

	/** 
	* @brief	Returns active vOption.
	*/
	VOBase** getVOptions();

	/** 
	* @brief	Returns active grabber.
	*/
	Grabber* getGrabber();

	/** 
	* @brief	true: Console will be kept open in debug mode.
	*/
	void setPauseAtDebug(bool inMode);

	
private:

	/** 
	* @brief	Defines hierarchy of option 
                OPT_PRIM: directly follows grabber
                OPT_SEC:  follows primary option, multiple in parallel
                OPT_FOLLOW: follows directly predecessor (to build queue of options following secondary option)
	*/
    enum OPTIONTYPE {OPT_PRIM=0, OPT_SEC, OPT_FOLLOW};

	/** 
	* @brief	VcaOptions.
	*/
	VOBase** mVOptions;

	/** 
	* @brief	VcaAgent configuration.
	*/
	Grabber* mGrabber;


	/** 
	* @brief	true: Console will be kept open in debug mode.
	*/
	bool mPauseAtDebug;

};
#endif /* VCA_AGENT_H */
