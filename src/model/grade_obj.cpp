
#include"model/grade_obj.h"


//	Grade::CONSTRUCTORS
Grade::Grade(const std::string& letter_grade)
	: m_representation{ interpretGradeLiteral(letter_grade) }
{
	//
}

Grade::Grade(GRADE_PERCENTAGE_MAP grade_map, const float percent_grade)
	: m_representation{ interpretGradePercent(grade_map, percent_grade) }
{
	//
}

Grade::Grade(const Grade& grade) noexcept
	: m_representation{ grade.m_representation }
{
	//
}

Grade::Grade(Grade&& r_grade) noexcept
	: m_representation{ r_grade.m_representation }
{
	//
}

//	Grade::FREE
std::string_view getLiteralGradeSymbol(GradeRepr representation)
{
	switch (representation) {
	case GradeRepr::P:
		return std::string_view{ GradeSymbol::P };
	case GradeRepr::AP:
		return std::string_view{ GradeSymbol::AP };
	case GradeRepr::A:
		return std::string_view{ GradeSymbol::A };
	case GradeRepr::AM:
		return std::string_view{ GradeSymbol::AM };
	case GradeRepr::BP:
		return std::string_view{ GradeSymbol::BP };
	case GradeRepr::B:
		return std::string_view{ GradeSymbol::B };
	case GradeRepr::BM:
		return std::string_view{ GradeSymbol::BM };
	case GradeRepr::CP:
		return std::string_view{ GradeSymbol::CP };
	case GradeRepr::C:
		return std::string_view{ GradeSymbol::C };
	case GradeRepr::CM:
		return std::string_view{ GradeSymbol::CM };
	case GradeRepr::DP:
		return std::string_view{ GradeSymbol::DP };
	case GradeRepr::D:
		return std::string_view{ GradeSymbol::D };
	case GradeRepr::F:
		return std::string_view{ GradeSymbol::F };
	default:
		return std::string_view{ GradeSymbol::NA };
	}
}

GradeRepr interpretGradeLiteral(const std::string& grade)
{
	for (GradeRepr legal : LEGAL_GRADE_SYMBOLS) {
		if (getLiteralGradeSymbol(legal) == grade)
			return legal;
	}

	return GradeRepr::NA;
}

GradeRepr interpretGradePercent(GRADE_PERCENTAGE_MAP gmap, float percentage)
{
	if (gmap.isDefault())
		return GradeRepr::NA;

	if (percentage >= gmap.AP_RANGE.second)
		return GradeRepr::AP;
	if (gmap.A_RANGE.first >= percentage && percentage >= gmap.A_RANGE.second)
		return GradeRepr::A;
	else if (gmap.AM_RANGE.first >= percentage && percentage >= gmap.AM_RANGE.second)
		return GradeRepr::AM;
	else if (gmap.BP_RANGE.first >= percentage && percentage >= gmap.BP_RANGE.second)
		return GradeRepr::BP;
	else if (gmap.B_RANGE.first >= percentage && percentage >= gmap.B_RANGE.second)
		return GradeRepr::B;
	else if (gmap.BM_RANGE.first >= percentage && percentage >= gmap.BM_RANGE.second)
		return GradeRepr::BM;
	else if (gmap.CP_RANGE.first >= percentage && percentage >= gmap.CP_RANGE.second)
		return GradeRepr::CP;
	else if (gmap.C_RANGE.first >= percentage && percentage >= gmap.C_RANGE.second)
		return GradeRepr::C;
	else if (gmap.CM_RANGE.first >= percentage && percentage >= gmap.CM_RANGE.second)
		return GradeRepr::CM;
	else if (gmap.DP_RANGE.first >= percentage && percentage >= gmap.DP_RANGE.second)
		return GradeRepr::DP;
	else if (gmap.D_RANGE.first >= percentage && percentage >= gmap.D_RANGE.second)
		return GradeRepr::D;
	else if (gmap.F_RANGE.first >= percentage && percentage >= gmap.F_RANGE.second)
		return GradeRepr::F;

	return GradeRepr::NA;
}



//	Grade::OPERATOR
std::ostream& operator<<(std::ostream& os, const Grade& grade)
{
	os << std::string{ getLiteralGradeSymbol(grade.m_representation) };

	return os;
}

Grade& Grade::operator=(const Grade& rhs_grade) noexcept
{
	if (&rhs_grade == this)
		return *this;

	this->m_representation = rhs_grade.m_representation;

	return *this;
}

Grade& Grade::operator=(Grade&& rhs_grade) noexcept
{
	if (&rhs_grade == this)
		return *this;

	this->m_representation = std::move(rhs_grade.m_representation);

	return *this;
}

bool Grade::operator==(const Grade& rhs_grade) const
{
	return (this->m_representation == rhs_grade.m_representation);
}

bool Grade::operator>(const Grade& rhs_grade) const
{
	return (this->m_representation > rhs_grade.m_representation);
}

bool Grade::operator<(const Grade& rhs_grade) const
{
	return (this->m_representation < rhs_grade.m_representation);
}
//	Grade::OPERATOR END!



//	Grade::PUBLIC
bool Grade::isValidGradeInstance() const
{
	return (this->m_representation != GradeRepr::NA);
}

GradeRepr Grade::getGradeRepresentation() const
{
	return this->m_representation;
}

std::string_view Grade::getLetterGrade() const
{
	return getLiteralGradeSymbol(this->m_representation);
}
//	Grade::PUBLIC END!



//	Grade::PRIVATE
//	Grade::PRIVATE END!



//	Grade::PROTECTED
//	Grade::PROTECTED END!
