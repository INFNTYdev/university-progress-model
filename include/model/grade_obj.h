
#ifndef UPM_GRADE_MDL_
#define UPM_GRADE_MDL_



#include<string>
#include<string_view>
#include<vector>
#include<ostream>
#include"percent_map.h"


namespace GradeSymbol {
	const std::string AP{ "A+" };
	const std::string A{ "A" };
	const std::string AM{ "A-" };

	const std::string BP{ "B+" };
	const std::string B{ "B" };
	const std::string BM{ "B-" };

	const std::string CP{ "C+" };
	const std::string C{ "C" };
	const std::string CM{ "C-" };

	const std::string DP{ "D+" };
	const std::string D{ "D" };

	const std::string F{ "F" };
	const std::string P{ "P" };
	const std::string NA{ "n/a" };
}

enum GradeRepr {
	NA,
	F, D, DP, CM, C, CP,
	BM, B, BP, AM, A, AP, P
};

const std::vector<GradeRepr> LEGAL_GRADE_SYMBOLS{
	GradeRepr::P,
	GradeRepr::AP,
	GradeRepr::A,
	GradeRepr::AM,
	GradeRepr::BP,
	GradeRepr::B,
	GradeRepr::BM,
	GradeRepr::CP,
	GradeRepr::C,
	GradeRepr::CM,
	GradeRepr::DP,
	GradeRepr::D,
	GradeRepr::F
};


std::string_view getLiteralGradeSymbol(GradeRepr representation);
GradeRepr interpretGradeLiteral(const std::string& grade);
GradeRepr interpretGradePercent(GRADE_PERCENTAGE_MAP grade_map, float percentage);


class Grade {

public:
	Grade(const std::string& letter_grade);
	Grade(GRADE_PERCENTAGE_MAP grade_map, const float percent_grade);
	Grade(const Grade& grade) noexcept;
	Grade(Grade&& r_grade) noexcept;
	~Grade() = default;

	friend std::ostream& operator<<(std::ostream& os, const Grade& grade);

	Grade& operator=(const Grade& rhs_grade) noexcept;
	Grade& operator=(Grade&& rhs_grade) noexcept;
	bool operator==(const Grade& rhs_grade) const;
	bool operator>(const Grade& rhs_grade) const;
	bool operator<(const Grade& rhs_grade) const;

	bool isValidGradeInstance() const;
	GradeRepr getGradeRepresentation() const;
	std::string_view getLetterGrade() const;


private:
	GradeRepr m_representation;

};



#endif // UPM_GRADE_MDL_
