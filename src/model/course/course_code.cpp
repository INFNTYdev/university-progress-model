
#include"model/course/course_code.h"


//	CourseCode::CONSTRUCTORS
CourseCode::CourseCode(const std::string& course, uint16_t c_number, const std::string& c_section)
	: m_course{ course },
	m_number{ c_number },
	m_section{ c_section }
{
	//
}

//CourseCode::CourseCode(const std::string& ccode)
//	: m_course{ this->NO_VALUE },
//	m_number{ NULL },
//	m_section{ this->NO_VALUE }
//{
//	size_t last{ 0 };
//
//	last = ccode.find(this->SEPERATOR, last);
//}

CourseCode::CourseCode(const CourseCode& ccode) noexcept
	: m_course{ ccode.m_course },
	m_number{ ccode.m_number },
	m_section{ ccode.m_section }
{
	//
}

CourseCode::CourseCode(CourseCode&& r_ccode) noexcept
	: m_course{ std::move(r_ccode.m_course) },
	m_number{ std::move(r_ccode.m_number) },
	m_section{ std::move(r_ccode.m_section) }
{
	//
}

//	CourseCode::FREE



//	CourseCode::OPERATOR
std::ostream& operator<<(std::ostream& os, const CourseCode& ccode)
{
	os << ccode.getCourseCode();

	return os;
}

CourseCode& CourseCode::operator=(const CourseCode& rhs_ccode) noexcept
{
	if (&rhs_ccode == this)
		return *this;

	this->m_course = rhs_ccode.m_course;
	this->m_number = rhs_ccode.m_number;
	this->m_section = rhs_ccode.m_section;

	return *this;
}

CourseCode& CourseCode::operator=(CourseCode&& rhs_ccode) noexcept
{
	if (&rhs_ccode == this)
		return *this;

	this->m_course = std::move(rhs_ccode.m_course);
	this->m_number = std::move(rhs_ccode.m_number);
	this->m_section = std::move(rhs_ccode.m_section);

	return *this;
}

bool CourseCode::operator==(const CourseCode& rhs_ccode) const
{
	if (this->m_course != rhs_ccode.m_course)
		return false;

	if (this->m_number != rhs_ccode.m_number)
		return false;

	if (this->m_section != rhs_ccode.m_section)
		return false;

	return true;
}

bool CourseCode::operator==(const std::string& string) const
{
	return (this->getCourseCode() == string);
}
//	CourseCode::OPERATOR END!



//	CourseCode::PUBLIC
const std::string& CourseCode::getCourseSubject() const
{
	return this->m_course;
}

uint16_t CourseCode::getCourseNumber() const
{
	return this->m_number;
}

const std::string& CourseCode::getCourseSection() const
{
	return this->m_section;
}

std::string CourseCode::getCourseCode() const
{
	std::ostringstream courseCodeBuffer{};

	if (this->m_course != this->NO_VALUE) {
		courseCodeBuffer << this->m_course;

		if (this->m_number != NULL) {
			courseCodeBuffer << this->SEPERATOR << this->m_number;

			if (this->m_section != this->NO_VALUE)
				courseCodeBuffer << this->SEPERATOR << this->m_section;
		}
	}

	return courseCodeBuffer.str();
}
//	CourseCode::PUBLIC END!



//	CourseCode::PRIVATE
//	CourseCode::PRIVATE END!



//	CourseCode::PROTECTED
//	CourseCode::PROTECTED END!
