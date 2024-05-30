
#ifndef UPM_UNIVERSITY_COURSE_H_
#define UPM_UNIVERSITY_COURSE_H_



#include"model/course/course_code.h"
#include"model/grade/grade_obj.h"


class UniversityCourse {

public:
	UniversityCourse(CourseCode ccode, const std::string& title, float credits,
		Grade final_grade, bool qualityC = true, bool requiredC = true);
	UniversityCourse(const UniversityCourse& course) noexcept;
	UniversityCourse(UniversityCourse&& r_course) noexcept;
	~UniversityCourse() = default;

	UniversityCourse& operator=(const UniversityCourse& rhs_course) noexcept;
	UniversityCourse& operator=(UniversityCourse&& rhs_course) noexcept;
	bool operator==(const UniversityCourse& rhs_course) const;

	std::string getCourseCodeString() const;
	const CourseCode& getCourseCode() const;
	const std::string& getCourseTitle() const;
	float getCourseCredits() const;
	const Grade& getCourseFinalGrade() const;
	bool isQualityCourse() const;
	bool isRequiredProgramCourse() const;


private:
	CourseCode m_courseCode;
	std::string m_title;
	float m_creditHours;
	Grade m_finalGrade;
	bool m_isQualityCourse;
	bool m_isProgramRequired;

};



#endif // UPM_UNIVERSITY_COURSE_H_
