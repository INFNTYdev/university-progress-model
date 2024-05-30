
#ifndef UPM_UNIVERSITY_COURSE_CODE_OBJ_H_
#define UPM_UNIVERSITY_COURSE_CODE_OBJ_H_



#include<string>
#include<cstdint>
#include<ostream>
#include<sstream>


class CourseCode {

public:
	CourseCode(const std::string& course, uint16_t c_number, const std::string& c_section = "");
	//CourseCode(const std::string& ccode);
	CourseCode(const CourseCode& ccode) noexcept;
	CourseCode(CourseCode&& r_ccode) noexcept;
	~CourseCode() = default;

	friend std::ostream& operator<<(std::ostream& os, const CourseCode& ccode);

	CourseCode& operator=(const CourseCode& rhs_ccode) noexcept;
	CourseCode& operator=(CourseCode&& rhs_ccode) noexcept;
	bool operator==(const CourseCode& rhs_ccode) const;
	bool operator==(const std::string& string) const;

	const std::string& getCourseSubject() const;
	uint16_t getCourseNumber() const;
	const std::string& getCourseSection() const;
	std::string getCourseCode() const;


private:
	std::string m_course;
	uint16_t m_number;
	std::string m_section;

	const std::string NO_VALUE{ "" };
	const char SEPERATOR{ '-' };

};



#endif // UPM_UNIVERSITY_COURSE_CODE_OBJ_H_
