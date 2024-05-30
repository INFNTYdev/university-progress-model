
#include"model/semester/semester_term.h"


//	Semester::CONSTRUCTORS
Semester::Semester(SemesterSeason season, uint16_t year, Semester* previous)
	: m_season{ season },
	m_year{ year },
	m_courses{},
	m_priorSemester{ previous }
{
	//
}

Semester::Semester(const Semester& semester) noexcept
	: m_season{ semester.m_season },
	m_year{ semester.m_year },
	m_courses{ semester.m_courses },
	m_priorSemester{ nullptr }
{
	//
}

Semester::Semester(Semester&& r_semester) noexcept
	: m_season{ std::move(r_semester.m_season) },
	m_year{ std::move(r_semester.m_year) },
	m_courses{ std::move(r_semester.m_courses) },
	m_priorSemester{ nullptr }
{
	//
}

//	Semester::FREE
std::string_view getSemesterSeasonTitle(SemesterSeason season)
{
	switch (season) {
	case SemesterSeason::WINTER:
		return std::string_view{ SeasonTitle::WINTER };
	case SemesterSeason::SUMMER_I:
		return std::string_view{ SeasonTitle::SUMMER_I };
	case SemesterSeason::SUMMER_II:
		return std::string_view{ SeasonTitle::SUMMER_II };
	case SemesterSeason::FALL:
		return std::string_view{ SeasonTitle::FALL };
	default:
		return std::string_view{ SeasonTitle::SPRING };
	}
}

bool courseGradeIsAtLeast(const UniversityCourse& course, Grade min_grade)
{
	return (course.getCourseFinalGrade() >= min_grade);
}



//	Semester::OPERATOR
Semester& Semester::operator=(const Semester& rhs_semester) noexcept
{
	if (&rhs_semester == this)
		return *this;

	this->m_season = rhs_semester.m_season;
	this->m_year = rhs_semester.m_year;
	this->m_courses = rhs_semester.m_courses;
	this->m_priorSemester = nullptr;

	return *this;
}

Semester& Semester::operator=(Semester&& rhs_semester) noexcept
{
	if (&rhs_semester == this)
		return *this;

	this->m_season = std::move(rhs_semester.m_season);
	this->m_year = std::move(rhs_semester.m_year);
	this->m_courses = std::move(rhs_semester.m_courses);
	this->m_priorSemester = nullptr;

	return *this;
}
//	Semester::OPERATOR END!



//	Semester::PUBLIC
constexpr SemesterSeason Semester::getSeason() const
{
	return this->m_season;
}

constexpr uint16_t Semester::getYear() const
{
	return this->m_year;
}

constexpr size_t Semester::getCourseEnrollmentCount() const
{
	return this->m_courses.size();
}

const std::vector<UniversityCourse>& Semester::getCourses() const
{
	return this->m_courses;
}

std::vector<const UniversityCourse*> Semester::getQualityCourses() const
{
	std::vector<const UniversityCourse*> qualityCourses{};

	for (const UniversityCourse& course : this->m_courses) {
		if (course.isQualityCourse())
			qualityCourses.emplace_back(&course);
	}

	return qualityCourses;
}

std::vector<const Grade*> Semester::getSemesterGrades() const
{
	std::vector<const Grade*> grades{};

	for (const UniversityCourse& course : this->m_courses)
		grades.emplace_back(&course.getCourseFinalGrade());

	return grades;
}

float Semester::getAttemptedCreditHours() const
{
	float attempted{ .0 };

	for (const UniversityCourse& course : this->m_courses)
		attempted += course.getCourseCredits();

	return attempted;
}

float Semester::getEarnedCreditHours(Grade pass_grade) const
{
	float earned{ .0 };

	for (const UniversityCourse& course : this->m_courses) {
		if (courseGradeIsAtLeast(course, pass_grade))
			earned += course.getCourseCredits();
	}

	return earned;
}

float Semester::getQualityCreditHours() const
{
	float qualityCredits{ .0 };

	for (const UniversityCourse* course : this->getQualityCourses())
		qualityCredits += course->getCourseCredits();

	// Corrections from previous semester
	//

	return qualityCredits;
}

float Semester::getPossibleQualityPoints(const GRADE_POINT_MAP& point_map) const
{
	float totalPossible{ .0 };

	for (const UniversityCourse* course : this->getQualityCourses()) {
		totalPossible += (
			course->getCourseCredits() *
			point_map.getGradePoints(Grade("A+"))
		);
	}

	return totalPossible;
}

float Semester::getQualityPoints(const GRADE_POINT_MAP& point_map, Grade pass_grade) const
{
	float qualityPoints{ .0 };

	for (const UniversityCourse* course : this->getQualityCourses()) {
		if (courseGradeIsAtLeast(*course, pass_grade)) {
			qualityPoints += (
				course->getCourseCredits() *
				point_map.getGradePoints(course->getCourseFinalGrade())
			);
		}
	}

	return qualityPoints;
}

float Semester::getSemesterGradePointAverage(const GRADE_POINT_MAP& point_map, Grade pass_grade) const
{
	if (this->getQualityCreditHours() == .0)
		return .0;

	float gradePointAverage{
		(this->getQualityPoints(point_map, pass_grade) / this->getQualityCreditHours())
	};

	return gradePointAverage;
}

float Semester::getSemesterScore(const GRADE_POINT_MAP& point_map, Grade pass_grade) const
{
	float percentageScore{ .0 };

	if (this->getPossibleQualityPoints(point_map) == .0)
		return percentageScore;

	percentageScore = (
		this->getQualityPoints(point_map, pass_grade) /
		this->getPossibleQualityPoints(point_map)
	);

	return percentageScore;
}

bool Semester::hasPreviousSemester() const
{
	return (this->m_priorSemester != nullptr);
}

bool Semester::hasCourseCode(const std::string& ccode)
{
	for (const UniversityCourse& course : this->m_courses) {
		if (course.getCourseCode() == ccode)
			return true;
	}

	return false;
}

bool Semester::addCourse(UniversityCourse course)
{
	if (this->hasCourseCode(course.getCourseCodeString()))
		return false;

	this->m_courses.push_back(course);

	return true;
}

bool Semester::removeCourse(const std::string& ccode)
{
	if (!this->hasCourseCode(ccode))
		return false;

	for (size_t i{ 0 }; i < this->m_courses.size(); ++i) {
		if (this->m_courses[i].getCourseCode() == ccode) {
			this->m_courses.erase(this->m_courses.begin() + i);

			return true;
		}
	}

	return false;
}
//	Semester::PUBLIC END!



//	Semester::PRIVATE
//	Semester::PRIVATE END!



//	Semester::PROTECTED
//	Semester::PROTECTED END!
