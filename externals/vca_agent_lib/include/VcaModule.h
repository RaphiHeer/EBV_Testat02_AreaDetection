/**
* ****************************************************************************
* 
*  @brief 		Module defnitions 
*				
*
*				Project: Smart Person Counter
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
#ifndef VCAMODULE
#define VCAMODULE

#include <map>
#include <string>

//fool the linker by a reference
class VOBase;
class Grabber;


class VcaModuleGrabberBase{
public:
    VcaModuleGrabberBase(std::string name);
    virtual Grabber* Create(int argc, char* argv[]) const = 0;
    std::string GetName() {return name;};
private:
    std::string name;
};


template <class T>class VcaModuleGrabber : public VcaModuleGrabberBase
{
public:
   VcaModuleGrabber(std::string name):VcaModuleGrabberBase(name){};
   virtual Grabber* Create(int argc, char* argv[]) const
        { return new T(argc, argv); }
};



class VcaModuleOptionBase{
public:
    VcaModuleOptionBase(std::string name);
    virtual VOBase* Create(int argc, char* argv[]) const = 0;
    std::string GetName() {return name;};
private:
    std::string name;
};

template <class T>class VcaModuleOption : public VcaModuleOptionBase
{
public:
    VcaModuleOption(std::string name):VcaModuleOptionBase(name){};
    virtual VOBase* Create(int argc, char* argv[]) const
        { return new T(argc, argv); }
};



class VcaModules {
public:
    static Grabber *CreateGrabber(int argc, char* argv[]);
    static VOBase  *CreateOption(int argc, char* argv[]);

    static void RegisterGrabber(VcaModuleGrabberBase* module);
    static void RegisterOption(VcaModuleOptionBase* module);

private:
    VcaModules(){};
    static VcaModules* Instance();

    // options and grabber may occupy the same names, therefore we use separate maps
    std::map<std::string, VcaModuleGrabberBase*> grabbers;
    std::map<std::string, VcaModuleOptionBase*>  voptions;

    static VcaModules *store;
};


#define DECLARE_GRABBER_MODULE(CLASSNAME) \
    static VcaModuleGrabber<CLASSNAME> g##CLASSNAME(MODULENAME_##CLASSNAME);

#define DECLARE_OPTION_MODULE(CLASSNAME) \
    static VcaModuleOption<CLASSNAME> g##CLASSNAME (MODULENAME_##CLASSNAME);



/*
    this class has to be implemented in the final executable or buisness specific library
    use the macros DECLARE_GRABBER_MODULE & DECLARE_OPTION_MODULE for this purpose.
    An "unresolved external" is an intended indication not to forget this.
*/
class VCAModuleRefs
{
public:
    /*
        reference all necessary modules
    */
    static void refModules();
};



#endif