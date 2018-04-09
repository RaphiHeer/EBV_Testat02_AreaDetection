//******************************************************************************************//
//              (c) Lucerne University of Applied Sciences and Arts 2013                    //
//        Competence Centre Innovation in Intelligent Multimedia Sensor Networks (IIMSN)    //
//******************************************************************************************//
// 
// generic coordinate class doing various calculations
//
#include <cstdlib>

#if !defined(VCACOORDINATE__H__INCLUDED_)
#define VCACOORDINATE__H__INCLUDED_



//======================================================
// Class Name		: VCACoordinate
// description		: Helper Class defines a vector
//					: with x and y coordiantes wiht
//					: double precision and some
//					: basic operation on its member
//					: variables
//					:  
//======================================================
template<typename CoordType>
class VCACoordinate
{
public:

	//======================================================
	// function name	: default construtor
	// description		: 
	//======================================================
	VCACoordinate():x(0),y(0) {}

	//======================================================
	// function name	: constructor
	// description		: sets the x=a and y=b
	//======================================================	
	VCACoordinate(CoordType a, CoordType b): x(a), y(b) {}

	//================================================================
	// function name	: bool operator==(const VCACoordinate& rhs) const;
	// description		: equal operator
	//================================================================
	bool operator==(const VCACoordinate& rhs) const;

	//======================================================
	// function name	: overloaded = opertor
	// description		: sets x = y = i;
	void operator=(const CoordType i);


	//======================================================
	// function name	: overloaded > operator
	// description		: retunrs true if the x and y co-
	//					: ordinate of this are > than the
	//					: ones from the rhs argument
	bool operator>(const VCACoordinate& rhs) const;


	//======================================================
	// function name	: overloaded >= operator
	// description		: retunrs true if the x and y co-
	//					: ordinate of this are >= than the
	//					: ones from the rhs argument
	bool operator>=(const VCACoordinate& rhs) const;


	//======================================================
	// function name	: overloaded <= operator
	// description		: retunrs true if the x and y co-
	//					: ordinate of this are <= than the
	//					: ones from the rhs argument
	bool operator<=(const VCACoordinate& rhs) const;


	//======================================================
	// function name	: overloaded < operator
	// description		: retunrs true if the x and y co-
	//					: ordinate of this are < than the
	//					: ones from the rhs argument
	bool operator<(const VCACoordinate& rhs) const;


	//======================================================
	// function name	: overloaded != operator
	// description		: retunrs true if the x and y co-
	//					: ordinate of this are != than the
	//					: ones from the rhs argument
	bool operator!=(const VCACoordinate& rhs) const;


	//======================================================
	// function name	: overloaded += operator
	// description		: adds the rhs argument coordiantes
	//					: to this.
	void operator+=(const VCACoordinate& rhs);
	
	//================================================================
	// function name	: VCACoordinate operator-(const VCACoordinate& rhs) const;
	// description		: minus operator, returns difference between lhs
	//					: and rhs VCACoordinate
	//================================================================
	VCACoordinate operator-(const VCACoordinate& rhs) const;
	
	//================================================================
	// function name	: VCACoordinate operator+(const VCACoordinate& rhs) const; 
	// description		: sum-operator, returns sum of lhs and rhs 
	//================================================================
	VCACoordinate operator+(const VCACoordinate& rhs) const; 

	//================================================================
	// function name	: VCACoordinate operator*(const double& d);
	// description		: multiplication with scalar operator
	//================================================================
	VCACoordinate operator*(const CoordType& d) const;

    //==================================================================================
    // fuction name     : operator*=(const double& d) const;
    // description      : multiplication with scalar
    //==================================================================================
    void operator*=(const CoordType& d);

	//================================================================
	// function name	: VCACoordinate operator*(const VCACoordinate& rhs) const;
	// description		: product of x and y coordinates taken individually
	//================================================================
	VCACoordinate operator*(const VCACoordinate& rhs) const;

	//================================================================
	// function name	: double VCACoordinate::AbsSqu(void);
	// description		: returns the absolute value squared of VCACoordinate
	//================================================================
	CoordType AbsSqu(void) const;

	//================================================================
	// function name	: VCACoordinate AbsVal(void) const;
	// description		: returns the absolute value of the coordinate
	//================================================================
	VCACoordinate AbsVal(void) const;
	//================================================================
	// function name	: VCACoordinate Floor(void) const;
	// description		: returns a coordinate with values being rounded
	//					: to the next higher integer value
	//================================================================
	VCACoordinate Floor(void) const;

	//======================================================
	// function name	: overloaded -= operator
	// description		: subtracts the rhs argument co-
	//					: ordinates from this
	void operator-=(const VCACoordinate& rhs);


	//======================================================
	// function name	: divide
	// description		: divides through d (no range check!!)
	void operator/=(const CoordType d);


	//================================================================
	// function name	: void VCACoordinate::Max(const VCACoordinate& rhs)
	// description		: compares the coordinate to rhs and chooses 
	//					: maximum value (for x and y separately)
	//================================================================
	void Max(const VCACoordinate& rhs);


	//================================================================
	// function name	: void VCACoordinate::Min(const VCACoordinate& rhs)
	// description		: compares the coordinate to rhs and chooses 
	//					: minimum value (for x and y separately)
	//================================================================
	void Min(const VCACoordinate& rhs);

    //==================================================================================
    // fuction name     :     void Sqare();
    // description      :   squares both x and y values of the coord.
    //==================================================================================
    void Sqare();

    //==================================================================================
    // fuction name     :   bool operator/=(const VCACoordinate& rhs) 
    // description      :   divides this by the respective values of rhs
    //==================================================================================
    bool operator/=(const VCACoordinate& rhs);
    //==================================================================================
    // fuction name     :     double SumAbs(void) const
    // description      :   returns |x|+|y|
    //==================================================================================
    CoordType SumAbs(void) const;

	//================================================================
	// function name	: VecProduct
	// description		: calculates the vector product a x b;
	//================================================================    
    static CoordType VecProduct(VCACoordinate a, VCACoordinate b);

	//================================================================
	// function name	: double Dot(VCACoordinate a);
	// description		: calculates the dot-product
	//================================================================
	CoordType Dot(const VCACoordinate& a) const;

    //================================================================
    // variable name    : MirrorY();
    // description      : sets y -> -y
    //================================================================
    void MirrorY();

    //================================================================
    // variable name    : NormalVec();
    // description      : sets x -> -y and y -> x thus is normal
    //================================================================
    void NormalVec();

	//================================================================
	// function name	: void SwitchXY(void);
	// description		: switches x and y values
	//================================================================
	void SwitchXY(void);

    //================================================================
	// function name	: Norm(void) const
	// description		: calculate Euclidean norm of vector
	//================================================================
    CoordType Norm(void) const;

    //================================================================
	// function name	: Normalize(void) const
	// description		: normalizes Euclidean norm of vector to 1 
	//================================================================
    void Normalize(void);

	//======================================================
	// description		: x co-ordinate
	CoordType x;


	//======================================================
	// description		: y co-ordinate
	CoordType y;

};



template<typename CoordType>
void VCACoordinate<CoordType>::operator=(const CoordType i)
{
	x=i;
	y=i;
}

template<typename CoordType>
bool VCACoordinate<CoordType>::operator==(const VCACoordinate& rhs) const
{
	return ((x == rhs.x) && (y == rhs.y));
}

template<typename CoordType>
bool VCACoordinate<CoordType>::operator>(const VCACoordinate& rhs) const
{
	return ((x > rhs.x) && (y > rhs.y));
}

template<typename CoordType>
bool VCACoordinate<CoordType>::operator>=(const VCACoordinate& rhs) const
{
	return ((x >= rhs.x) && (y >= rhs.y));
}

template<typename CoordType>
bool VCACoordinate<CoordType>::operator<=(const VCACoordinate& rhs) const
{
	return ((x <= rhs.x) && (y <= rhs.y));
}

template<typename CoordType>
bool VCACoordinate<CoordType>::operator<(const VCACoordinate& rhs) const
{
	return ((x < rhs.x) && (y < rhs.y));
}

template<typename CoordType>
bool VCACoordinate<CoordType>::operator!=(const VCACoordinate& rhs) const
{
	return ((x!=rhs.x) || (y!=rhs.y));
}


template<typename CoordType>
void VCACoordinate<CoordType>::operator+=(const VCACoordinate& rhs) 
{
	x += rhs.x;
	y += rhs.y;
}

template<typename CoordType>
void VCACoordinate<CoordType>::operator-=(const VCACoordinate& rhs) 
{
	x -= rhs.x;
	y -= rhs.y;
}

template<typename CoordType>
VCACoordinate<CoordType> VCACoordinate<CoordType>::operator*(const VCACoordinate& rhs) const
{
	return VCACoordinate(x * rhs.x, y * rhs.y);
}


template<typename CoordType>
void VCACoordinate<CoordType>::operator*=(const CoordType& d)
{
	x = x * d;
    y = y * d;
}

template<typename CoordType>
VCACoordinate<CoordType> VCACoordinate<CoordType>::operator-(const VCACoordinate& rhs) const
{
	return VCACoordinate(x-rhs.x,	y-rhs.y);
}


template<typename CoordType>
VCACoordinate<CoordType> VCACoordinate<CoordType>::operator+(const VCACoordinate& rhs) const
{
	return VCACoordinate(x+rhs.x,	y+rhs.y);
}


template<typename CoordType>
VCACoordinate<CoordType> VCACoordinate<CoordType>::operator*(const CoordType& d) const
{
	return VCACoordinate(x*d,	y*d);
}

template<typename CoordType>
void VCACoordinate<CoordType>::operator/=(const CoordType d) 
{
	if(d != 0)
	{
		x /= d;
		y /= d;
	}
}


template<typename CoordType>
void VCACoordinate<CoordType>::Max(const VCACoordinate& rhs)
{
	if(x < rhs.x) x = rhs.x;
	if(y < rhs.y) y = rhs.y;
}


template<typename CoordType>
void VCACoordinate<CoordType>::Min(const VCACoordinate& rhs)
{
	if(x > rhs.x) x = rhs.x;
	if(y > rhs.y) y = rhs.y;
}


template<typename CoordType>
CoordType VCACoordinate<CoordType>::AbsSqu(void) const
{
	return(x*x+y*y);
}


template<typename CoordType>
VCACoordinate<CoordType> VCACoordinate<CoordType>::AbsVal(void) const
{
	return(VCACoordinate(std::abs((CoordType) x), std::abs((CoordType) y)));
}


template<typename CoordType>
VCACoordinate<CoordType> VCACoordinate<CoordType>::Floor(void) const
{
	return(VCACoordinate((int) (x+1), (int) (y+1)));
}


template<typename CoordType>
CoordType VCACoordinate<CoordType>::VecProduct(VCACoordinate a, VCACoordinate b)
{
    return (a.x*b.y-a.y*b.x);
}


template<typename CoordType>
CoordType VCACoordinate<CoordType>::Dot(const VCACoordinate& a) const
{
    return (x*a.x+y*a.y);
}

template<typename CoordType>
void VCACoordinate<CoordType>::Sqare()
{
    x = x*x;
    y = y*y;
}

template<typename CoordType>
bool VCACoordinate<CoordType>::operator/=(const VCACoordinate& rhs) 
{
	if(rhs.x == 0 || rhs.y == 0) return false;
	
    x /= rhs.x;
	y /= rhs.y;
    return true;
}

template<typename CoordType>
CoordType VCACoordinate<CoordType>::SumAbs(void) const
{
	return(std::abs((CoordType) x)+std::abs((CoordType) y));
}

template<typename CoordType>
void VCACoordinate<CoordType>::MirrorY()
{
	y = -y;
}

template<typename CoordType>
void VCACoordinate<CoordType>::NormalVec()
{
    CoordType x_old = x;
	x = -y;
    y = x_old;
}

template<typename CoordType>
void VCACoordinate<CoordType>::SwitchXY(void)
{
	double a = x;
	x = y;
	y = a;
}

template<typename CoordType>
CoordType VCACoordinate<CoordType>::Norm(void) const
{
	return sqrt((CoordType) (x*x+y*y));
}

template<typename CoordType>
void VCACoordinate<CoordType>::Normalize(void)
{
    CoordType n = Norm();
    if(n > 0)
    {
	    *this /= n;
    }
}


#endif /* VCACOORDINATE__H__INCLUDED_ */

