#include <wx/image.h>
#include "Application.h"
#include "HijaPrincipal.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	m_bicicleteria = new Bicicleteria("Articulos.txt","Clientes.dat","Ventas.txt", "DetallesVenta.txt");
	HijaPrincipal *win = new HijaPrincipal(m_bicicleteria);
	win->Show();
	return true;
}

