#include <string>
#include "lane_constant_class.h"

LaneConstant::LaneConstant( std::string variablename,
							double initialvalue,
							double minvalue,
							double maxvalue,
							double increment ):
							variablename_{ variablename },
							value_{ initialvalue },
							previousvalue_ { initialvalue },
							minvalue_{ minvalue },
							maxvalue_{ maxvalue },
							increment_{ increment },
							direction_{1.0},
							reversedcount_{0}
{
	range_ = maxvalue - minvalue;
	//Comment out if you don't want to start in middle of range_
	value_ = (maxvalue - minvalue)/2;
}

void LaneConstant::Modify()
{
	previousvalue_ = value_;
	value_ += direction_*range_*increment_;
	if (value_ < minvalue_) {
		hitlimit_ = true;
		value_ = minvalue_;
	}
	if (value_ > maxvalue_) {
		hitlimit_ = true;
		value_ = maxvalue_;
	}
	return;
}

void LaneConstant::Reverse()
{
	reversedcount_++;
	direction_ *= -1.0;
	return;
}

void LaneConstant::SetPrevious()
{
	value_ = previousvalue_;
	return;
}
