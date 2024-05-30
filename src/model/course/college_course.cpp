
#include"model/course/college_course.h"


//	UniversityCourse::CONSTRUCTORS
UniversityCourse::UniversityCourse(CourseCode ccode, const std::string& title,
	float credits, Grade final_grade, bool qualityC, bool requiredC)
	: m_courseCode{ ccode },
	m_title{ title },
	m_creditHours{ credits },
	m_finalGrade{ final_grade },
	m_isQualityCourse{ qualityC },
	m_isProgramRequired{ requiredC }
{
	//
}

UniversityCourse::UniversityCourse(const UniversityCourse& course) noexcept
	: m_courseCode{ course.m_courseCode },
	m_title{ course.m_title },
	m_creditHours{ course.m_creditHours },
	m_finalGrade{ course.m_finalGrade },
	m_isQualityCourse{ course.m_isQualityCourse },
	m_isProgramRequired{ course.m_isProgramRequired }
{
	//
}

UniversityCourse::UniversityCourse(UniversityCourse&& r_course) noexcept
	: m_courseCode{ std::move(r_course.m_courseCode) },
	m_title{ std::move(r_course.m_title) },
	m_creditHours{ std::move(r_course.m_creditHours) },
	m_finalGrade{ std::move(r_course.m_finalGrade) },
	m_isQualityCourse{ std::move(r_course.m_isQualityCourse) },
	m_isProgramRequired{ std::move(r_course.m_isProgramRequired) }
{
	//
}

//	UniversityCourse::FREE



//	UniversityCourse::OPERATOR
UniversityCourse& UniversityCourse::operator=(const UniversityCourse& rhs_course) noexcept
{
	if (&rhs_course == this)
		return *this;

	this->m_courseCode = rhs_course.m_courseCode;
	this->m_title = rhs_course.m_title;
	this->m_creditHours = rhs_course.m_creditHours;
	this->m_finalGrade = rhs_course.m_finalGrade;
	this->m_isQualityCourse = rhs_course.m_isQualityCourse;
	this->m_isProgramRequired = rhs_course.m_isProgramRequired;

	return *this;
}

UniversityCourse& UniversityCourse::operator=(UniversityCourse&& rhs_course) noexcept
{
	if (&rhs_course == this)
		return *this;

	this->m_courseCode = std::move(rhs_course.m_courseCode);
	this->m_title = std::move(rhs_course.m_title);
	this->m_creditHours = std::move(rhs_course.m_creditHours);
	this->m_finalGrade = std::move(rhs_course.m_finalGrade);
	this->m_isQualityCourse = std::move(rhs_course.m_isQualityCourse);
	this->m_isProgramRequired = std::move(rhs_course.m_isProgramRequired);

	return *this;
}

bool UniversityCourse::operator==(const UniversityCourse& rhs_course) const
{
	if (this->m_courseCode.getCourseSubject() != rhs_course.m_courseCode.getCourseSubject())
		return false;

	if (this->m_courseCode.getCourseNumber() != rhs_course.m_courseCode.getCourseNumber())
		return false;

	if (this->m_creditHours != rhs_course.m_creditHours)
		return false;

	return true;
}
//	UniversityCourse::OPERATOR END!



//	UniversityCourse::PUBLIC
std::string UniversityCourse::getCourseCodeString() const
{
	return this->m_courseCode.getCourseCode();
}

const CourseCode& UniversityCourse::getCourseCode() const
{
	return this->m_courseCode;
}

const std::string& UniversityCourse::getCourseTitle() const
{
	return this->m_title;
}

float UniversityCourse::getCourseCredits() const
{
	return this->m_creditHours;
}

const Grade& UniversityCourse::getCourseFinalGrade() const
{
	return this->m_finalGrade;
}

bool UniversityCourse::isQualityCourse() const
{
	return this->m_isQualityCourse;
}

bool UniversityCourse::isRequiredProgramCourse() const
{
	return this->m_isProgramRequired;
}
//	UniversityCourse::PUBLIC END!



//	UniversityCourse::PRIVATE
//	UniversityCourse::PRIVATE END!



//	UniversityCourse::PROTECTED
//	UniversityCourse::PROTECTED END!
