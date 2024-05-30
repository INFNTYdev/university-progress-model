
#ifndef UPM_UNIVERSITY_SEMESTER_TERM_H_
#define UPM_UNIVERSITY_SEMESTER_TERM_H_



#include<cstdint>
#include<vector>
#include"model/course/college_course.h"
#include"model/grade/point_map.h"


namespace SeasonTitle {
	const std::string SPRING{ "Spring" };
	const std::string SUMMER_I{ "Summer I" };
	const std::string SUMMER_II{ "Summer II" };
	const std::string FALL{ "Fall" };
	const std::string WINTER{ "Winter" };
}

enum class SemesterSeason { SPRING, SUMMER_I, SUMMER_II, FALL, WINTER };


std::string_view getSeasonTitle(SemesterSeason season);
bool courseGradeIsAtLeast(const UniversityCourse& course, Grade min_grade);


class Semester {

public:
	Semester(SemesterSeason season, uint16_t year, Semester* previous = nullptr);
	Semester(const Semester& semester) noexcept;
	Semester(Semester&& r_semester) noexcept;
	~Semester() = default;

	Semester& operator=(const Semester& rhs_semester) noexcept;
	Semester& operator=(Semester&& rhs_semester) noexcept;

	constexpr SemesterSeason getSeason() const;
	constexpr uint16_t getYear() const;
	constexpr size_t getCourseEnrollmentCount() const;
	const std::vector<UniversityCourse>& getCourses() const;
	std::vector<const UniversityCourse*> getQualityCourses() const;
	std::vector<const UniversityCourse*> getRequiredProgramCourses() const;
	std::vector<const Grade*> getSemesterGrades() const;
	float getAttemptedCreditHours() const;
	float getRequiredCreditsFailed(Grade pass_grade) const;
	float getRequiredCreditsPassed(Grade pass_grade) const;
	float getEarnedCreditHours(Grade pass_grade) const;
	float getQualityCreditHours(Grade pass_grade) const;
	float getPossibleQualityPoints(const GRADE_POINT_MAP& point_map) const;
	float getQualityPoints(const GRADE_POINT_MAP& point_map, Grade pass_grade) const;
	float getSemesterGradePointAverage(const GRADE_POINT_MAP& point_map, Grade pass_grade) const;
	float getSemesterScore(const GRADE_POINT_MAP& point_map, Grade pass_grade) const;
	bool hasPreviousSemester() const;
	bool hasCourseCode(const std::string& ccode);
	bool addCourse(UniversityCourse course);
	bool removeCourse(const std::string& ccode);


private:
	SemesterSeason m_season;
	uint16_t m_year;
	std::vector<UniversityCourse> m_courses;
	Semester* m_prior;

};



#endif // UPM_UNIVERSITY_SEMESTER_TERM_H_
