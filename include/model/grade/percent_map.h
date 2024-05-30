
#ifndef _UPM_GRADE_PERCENT_MAP_
#define _UPM_GRADE_PERCENT_MAP_
typedef struct _UPM_GRADE_PERCENT_MAP {
	
	// First of pair is upper bounds while second is lower bounds

	std::pair<float, float> AP_RANGE{ float(.0), float(.0) };
	std::pair<float, float> A_RANGE{ float(.0), float(.0) };
	std::pair<float, float> AM_RANGE{ float(.0), float(.0) };

	std::pair<float, float> BP_RANGE{ float(.0), float(.0) };
	std::pair<float, float> B_RANGE{ float(.0), float(.0) };
	std::pair<float, float> BM_RANGE{ float(.0), float(.0) };

	std::pair<float, float> CP_RANGE{ float(.0), float(.0) };
	std::pair<float, float> C_RANGE{ float(.0), float(.0) };
	std::pair<float, float> CM_RANGE{ float(.0), float(.0) };

	std::pair<float, float> DP_RANGE{ float(.0), float(.0) };
	std::pair<float, float> D_RANGE{ float(.0), float(.0) };

	std::pair<float, float> F_RANGE{ float(.0), float(.0) };


	bool isDefaultARange() const
	{
		bool defaultA_Range{
			(this->AP_RANGE.first == .0 && this->AP_RANGE.second == .0) &&
			(this->A_RANGE.first == .0 && this->A_RANGE.second == .0) &&
			(this->AM_RANGE.first == .0 && this->AM_RANGE.second == .0)
		};

		return defaultA_Range;
	}

	bool isDefaultBRange() const
	{
		bool defaultB_Range{
			(this->BP_RANGE.first == .0 && this->BP_RANGE.second == .0) &&
			(this->B_RANGE.first == .0 && this->B_RANGE.second == .0) &&
			(this->BM_RANGE.first == .0 && this->BM_RANGE.second == .0)
		};

		return defaultB_Range;
	}

	bool isDefaultCRange() const
	{
		bool defaultC_Range{
			(this->CP_RANGE.first == .0 && this->CP_RANGE.second == .0) &&
			(this->C_RANGE.first == .0 && this->C_RANGE.second == .0) &&
			(this->CM_RANGE.first == .0 && this->CM_RANGE.second == .0)
		};

		return defaultC_Range;
	}

	bool isDefaultDRange() const
	{
		bool defaultD_Range{
			(this->DP_RANGE.first == .0 && this->DP_RANGE.second == .0) &&
			(this->D_RANGE.first == .0 && this->D_RANGE.second == .0)
		};

		return defaultD_Range;
	}

	bool isDefaultFRange() const
	{
		return (this->F_RANGE.first == .0);
	}

	bool isDefault() const {
		return (
			this->isDefaultARange() &&
			this->isDefaultBRange() &&
			this->isDefaultCRange() &&
			this->isDefaultDRange() &&
			this->isDefaultFRange()
		);
	}
} GRADE_PERCENTAGE_MAP;
#endif // _UPM_GRADE_PERCENT_MAP_
