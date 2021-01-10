#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Bicicleteria.h"

class Application : public wxApp {
	Bicicleteria *m_bicicleteria;
public:
	virtual bool OnInit();
};
#endif
