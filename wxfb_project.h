///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BasePrincipal
///////////////////////////////////////////////////////////////////////////////
class BasePrincipal : public wxFrame
{
	private:

	protected:
		wxStaticText* m_NombreBicicleteria;
		wxStaticText* m_staticText34;
		wxBitmapButton* m_AccesoArticulos;
		wxStaticText* m_staticText35;
		wxBitmapButton* m_AgregarVenta;
		wxStaticText* m_staticText36;
		wxBitmapButton* m_AccesoVentas;
		wxStaticText* m_staticText37;
		wxBitmapButton* m_AccesoClientes;
		wxStaticBitmap* m_bitmap45;
		wxTextCtrl* m_fecha;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonArticulos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAgregarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonVentas( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonClientes( wxCommandEvent& event ) { event.Skip(); }


	public:

		BasePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PANTALLA PRINCIPAL"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE );

		~BasePrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseAgregarVenta
///////////////////////////////////////////////////////////////////////////////
class BaseAgregarVenta : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* m_bitmap47;
		wxTextCtrl* BarraBusqueda;
		wxStaticText* m_staticText53;
		wxTextCtrl* BarraCantidad;
		wxStaticText* m_cliente;
		wxTextCtrl* BarraCliente;
		wxGrid* m_grillabuscador;
		wxGrid* m_grillaVenta;
		wxStaticBitmap* m_bitmap12;
		wxButton* GuardarVenta;
		wxStaticBitmap* m_bitmap11;
		wxButton* BotonEliminarArticuloIngresado;
		wxStaticBitmap* m_bitmap2;
		wxTextCtrl* m_PrecioTotal;

		// Virtual event handlers, overide them in your derived class
		virtual void OnCambiarSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void AlEscribir( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterCantidad( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonGuardarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEliminarAI( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseAgregarVenta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Venta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );

		~BaseAgregarVenta();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseVentas
///////////////////////////////////////////////////////////////////////////////
class BaseVentas : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText29;
		wxStaticText* m_staticText30;
		wxTextCtrl* Desde_dia;
		wxTextCtrl* Desde_mes;
		wxTextCtrl* Desde_anio;
		wxStaticText* m_staticText36;
		wxTextCtrl* Hasta_dia;
		wxTextCtrl* Hasta_mes;
		wxTextCtrl* Hasta_anio;
		wxStaticBitmap* m_bitmap6;
		wxButton* BotonAceptar;

		// Virtual event handlers, overide them in your derived class
		virtual void AlApretarEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAceptar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseVentas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~BaseVentas();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseListaVentas
///////////////////////////////////////////////////////////////////////////////
class BaseListaVentas : public wxFrame
{
	private:

	protected:
		wxGrid* m_grilla;
		wxStaticText* m_staticText35;
		wxTextCtrl* BarraTotalVendido;
		wxStaticBitmap* m_bitmap36;
		wxStaticText* m_staticText34;
		wxTextCtrl* BarraCantidadVendida;
		wxStaticBitmap* m_bitmap37;
		wxStaticText* m_staticText32;
		wxTextCtrl* BarraGanaciaTotal;
		wxStaticBitmap* m_bitmap38;

		// Virtual event handlers, overide them in your derived class
		virtual void OnCambiaSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGrilla( wxGridEvent& event ) { event.Skip(); }


	public:

		BaseListaVentas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Lista de Ventas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxFRAME_FLOAT_ON_PARENT|wxMAXIMIZE|wxTAB_TRAVERSAL );

		~BaseListaVentas();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseClientes
///////////////////////////////////////////////////////////////////////////////
class BaseClientes : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* m_bitmap49;
		wxTextCtrl* BarraBusqueda;
		wxGrid* m_grilla;
		wxStaticBitmap* m_bitmap5;
		wxButton* BotonAgregar;
		wxStaticBitmap* m_bitmap3;
		wxButton* BotonModificar;
		wxStaticBitmap* m_bitmap4;
		wxButton* BotonEliminar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnCambiaSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void AlIngresarTexto( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlPresionarEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickBotonAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEliminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseClientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("CLIENTES"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );

		~BaseClientes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseAgregarCliente
///////////////////////////////////////////////////////////////////////////////
class BaseAgregarCliente : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nombre;
		wxStaticBitmap* m_bitmap32;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_telefono;
		wxStaticBitmap* m_bitmap33;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_direccion;
		wxStaticBitmap* m_bitmap34;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_bicicleta;
		wxStaticBitmap* m_bitmap35;
		wxButton* BotonGuardar;
		wxButton* BotonTerminar;

		// Virtual event handlers, overide them in your derived class
		virtual void AlApretarEnterNom( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterTel( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterDireccion( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterBicicleta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonGuardar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonTerminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseAgregarCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Cliente"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~BaseAgregarCliente();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseModificarCliente
///////////////////////////////////////////////////////////////////////////////
class BaseModificarCliente : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nombre;
		wxStaticBitmap* m_bitmap28;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_telefono;
		wxStaticBitmap* m_bitmap29;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_direccion;
		wxStaticBitmap* m_bitmap30;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_bicicleta;
		wxStaticBitmap* m_bitmap31;
		wxButton* BotonGuardar;
		wxButton* BotonTerminar;

		// Virtual event handlers, overide them in your derived class
		virtual void AlApretarEnterNom( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterCost( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterPrecio( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterStock( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonGuardar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonTerminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseModificarCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Modificar Cliente"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~BaseModificarCliente();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseArticulos
///////////////////////////////////////////////////////////////////////////////
class BaseArticulos : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* m_bitmap48;
		wxTextCtrl* BarraBusqueda;
		wxGrid* m_grilla;
		wxStaticBitmap* m_bitmap10;
		wxButton* m_button25;
		wxStaticBitmap* m_bitmap9;
		wxButton* BotonAgregar;
		wxStaticBitmap* m_bitmap8;
		wxButton* BotonModificar;
		wxStaticBitmap* m_bitmap7;
		wxButton* BotonEliminar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnCambiaSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void AlIngresarTexto( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickBotonCambiarPrecio( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEliminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseArticulos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("STOCK"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );

		~BaseArticulos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseCambioMasivo
///////////////////////////////////////////////////////////////////////////////
class BaseCambioMasivo : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText27;
		wxStaticBitmap* m_bitmap15;
		wxTextCtrl* BarraPorcentaje;
		wxStaticText* m_staticText28;
		wxStaticBitmap* m_bitmap151;
		wxTextCtrl* BarraProveedor;
		wxButton* m_button26;
		wxButton* m_button27;

		// Virtual event handlers, overide them in your derived class
		virtual void AlApretarEnterPorcentaje( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseCambioMasivo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~BaseCambioMasivo();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseModificarArticulo
///////////////////////////////////////////////////////////////////////////////
class BaseModificarArticulo : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nombre;
		wxStaticBitmap* m_bitmap23;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_costo;
		wxStaticBitmap* m_bitmap24;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_precio;
		wxStaticBitmap* m_bitmap25;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_stock;
		wxStaticBitmap* m_bitmap26;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_proveedor;
		wxStaticBitmap* m_bitmap27;
		wxButton* BotonGuardar;
		wxButton* BotonTerminar;

		// Virtual event handlers, overide them in your derived class
		virtual void AlApretarEnterNom( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterCost( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterPrecio( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterStock( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonGuardar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonTerminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseModificarArticulo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Modificar Artículo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~BaseModificarArticulo();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseAgregarArticulo
///////////////////////////////////////////////////////////////////////////////
class BaseAgregarArticulo : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nombre;
		wxStaticBitmap* m_bitmap18;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_costo;
		wxStaticBitmap* m_bitmap19;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_precio;
		wxStaticBitmap* m_bitmap20;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_stock;
		wxStaticBitmap* m_bitmap21;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_proveedor;
		wxStaticBitmap* m_bitmap22;
		wxButton* BotonGuardar;
		wxButton* BotonTerminar;

		// Virtual event handlers, overide them in your derived class
		virtual void AlApretarEnterNombre( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlAlpretarEnterCosto( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterPrecio( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterStock( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlApretarEnterProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonGuardar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonTerminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseAgregarArticulo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Artículo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~BaseAgregarArticulo();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseDetalleVenta
///////////////////////////////////////////////////////////////////////////////
class BaseDetalleVenta : public wxFrame
{
	private:

	protected:
		wxGrid* m_grillaDetalle;

		// Virtual event handlers, overide them in your derived class
		virtual void OnCambiaSize( wxSizeEvent& event ) { event.Skip(); }


	public:

		BaseDetalleVenta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("DETALLE VENTA"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE );

		~BaseDetalleVenta();

};

