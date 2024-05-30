
#include<iostream>

#include"model/grade/grade_obj.h"
#include"model/grade/point_map.h"


int main(size_t argc, char* argv[])
{
	GRADE_PERCENTAGE_MAP gradeMap{};

	gradeMap.AP_RANGE.first = 100.;
	gradeMap.AP_RANGE.second = 96.5;
	gradeMap.A_RANGE.first = 96.4;
	gradeMap.A_RANGE.second = 92.5;
	gradeMap.AM_RANGE.first = 92.4;
	gradeMap.AM_RANGE.second = 89.5;

	gradeMap.BP_RANGE.first = 89.4;
	gradeMap.BP_RANGE.second = 86.5;
	gradeMap.B_RANGE.first = 86.4;
	gradeMap.B_RANGE.second = 82.5;
	gradeMap.BM_RANGE.first = 82.4;
	gradeMap.BM_RANGE.second = 79.5;

	gradeMap.CP_RANGE.first = 79.4;
	gradeMap.CP_RANGE.second = 76.5;
	gradeMap.C_RANGE.first = 76.4;
	gradeMap.C_RANGE.second = 72.5;
	gradeMap.CM_RANGE.first = 72.4;
	gradeMap.CM_RANGE.second = 69.5;

	gradeMap.DP_RANGE.first = 69.4;
	gradeMap.DP_RANGE.second = 66.5;
	gradeMap.D_RANGE.first = 66.4;
	gradeMap.D_RANGE.second = 63.5;

	gradeMap.F_RANGE.first = 63.4;
	gradeMap.F_RANGE.second = .0;


	
	GRADE_POINT_MAP pointMap{};

	pointMap.AP_POINTS = 4.3;
	pointMap.A_POINTS = 4.;
	pointMap.AM_POINTS = 3.7;

	pointMap.BP_POINTS = 3.3;
	pointMap.B_POINTS = 3.;
	pointMap.BM_POINTS = 2.7;

	pointMap.CP_POINTS = 2.3;
	pointMap.C_POINTS = 2.;
	pointMap.CM_POINTS = 1.7;

	pointMap.DP_POINTS = 1.3;
	pointMap.D_POINTS = 1.;



	Grade test{ gradeMap, 91.3 };

	std::cout << std::boolalpha <<
		"\nGrade: " << test <<
		"\nValid: " << test.isValidGradeInstance() <<
		"\nPoint: " << pointMap.getGradePoints(test) <<
		std::endl;

	//

	return 0;
}
