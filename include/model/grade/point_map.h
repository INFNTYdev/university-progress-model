
#ifndef _UPM_GRADE_POINT_MAP_
#define _UPM_GRADE_POINT_MAP_

#include"model/grade/grade_obj.h"

typedef struct _UPM_GRADE_POINT_MAP {
	float AP_POINTS{ .0 };
	float A_POINTS{ .0 };
	float AM_POINTS{ .0 };

	float BP_POINTS{ .0 };
	float B_POINTS{ .0 };
	float BM_POINTS{ .0 };

	float CP_POINTS{ .0 };
	float C_POINTS{ .0 };
	float CM_POINTS{ .0 };

	float DP_POINTS{ .0 };
	float D_POINTS{ .0 };

	float F_POINTS{ .0 };


	bool isDefault() const
	{
		return (
			((this->AP_POINTS == .0) && (this->A_POINTS == .0) && (this->AM_POINTS == .0)) &&
			((this->BP_POINTS == .0) && (this->B_POINTS == .0) && (this->BM_POINTS == .0)) &&
			((this->CP_POINTS == .0) && (this->C_POINTS == .0) && (this->CM_POINTS == .0)) &&
			((this->DP_POINTS == .0) && (this->D_POINTS == .0)) && (this->F_POINTS == .0)
		);
	}

	float getGradePoints(const Grade& grade) const
	{
		if (this->isDefault())
			return .0;

		switch (grade.getGradeRepresentation()) {
		case GradeRepr::AP:
			return this->AP_POINTS;
		case GradeRepr::A:
			return this->A_POINTS;
		case GradeRepr::AM:
			return this->AM_POINTS;
		case GradeRepr::BP:
			return this->BP_POINTS;
		case GradeRepr::B:
			return this->B_POINTS;
		case GradeRepr::BM:
			return this->BM_POINTS;
		case GradeRepr::CP:
			return this->CP_POINTS;
		case GradeRepr::C:
			return this->C_POINTS;
		case GradeRepr::CM:
			return this->CM_POINTS;
		case GradeRepr::DP:
			return this->DP_POINTS;
		case GradeRepr::D:
			return this->D_POINTS;
		case GradeRepr::F:
			return this->F_POINTS;
		default:
			return .0;
		}
	}
} GRADE_POINT_MAP;
#endif // _UPM_GRADE_POINT_MAP_
