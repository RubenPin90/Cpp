
#include "AForm.hpp"

#ifndef SC_FORM_HPP
#define SC_FORM_HPP


class SCForm : public AForm {
	public:
		SCForm();
		SCForm(const SCForm& ref);
		~SCForm();
		SCForm operator=(const SCForm& rhs);

};


#endif