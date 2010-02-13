#ifndef FTextRXTX_H_
#define FTextRXTX_H_

#include "FTextView.h"

///
/// A TextBase subclass to display received & transmitted text
///
class FTextRX : public FTextView
{
public:
	FTextRX(int x, int y, int w, int h, const char *l = 0);
        ~FTextRX();

	virtual int	handle(int event);

	void		set_quick_entry(bool b);
	bool		get_quick_entry(void) { return quick_entry; }

	void		setFont(Fl_Font f, int attr = NATTR);

protected:
	enum {
		RX_MENU_QRZ_THIS, RX_MENU_CALL, RX_MENU_NAME, RX_MENU_QTH,
		RX_MENU_STATE, RX_MENU_PROVINCE,RX_MENU_COUNTRY, RX_MENU_LOC,
		RX_MENU_RST_IN, RX_MENU_SERIAL, RX_MENU_XCHG,
		RX_MENU_DIV, RX_MENU_COPY, RX_MENU_CLEAR, RX_MENU_SELECT_ALL,
		RX_MENU_SAVE, RX_MENU_WRAP, RX_MENU_QUICK_ENTRY
	};

	void		handle_clickable(int x, int y);
	void		handle_qsy(int start, int end);
	void		handle_qso_data(int start, int end);
	void		handle_context_menu(void);
	void		menu_cb(size_t item);

	const char*	dxcc_lookup_call(int x, int y);
	static void	dxcc_tooltip(void* obj);

private:
	FTextRX();
	FTextRX(const FTextRX &t);
	bool	quick_entry;

protected:
	static Fl_Menu_Item menu[];
	struct {
		bool enabled;
		float delay;
	} tooltips;
};


///
/// A FTextBase subclass to display and edit text to be transmitted
///
class FTextTX : public FTextEdit
{
public:
	FTextTX(int x, int y, int w, int h, const char *l = 0);

	virtual int	handle(int event);

	void		clear(void);
	void		clear_sent(void);
	int			nextChar(void);
	bool		eot(void);

	void		setFont(Fl_Font f, int attr = NATTR);

protected:
	enum { TX_MENU_TX, TX_MENU_RX, TX_MENU_ABORT, TX_MENU_MFSK16_IMG,
	       TX_MENU_CUT, TX_MENU_COPY, TX_MENU_PASTE, TX_MENU_CLEAR, TX_MENU_READ,
	       TX_MENU_WRAP
	};
	int		handle_key(int key);
	int		handle_key_macro(int key);
	int		handle_dnd_drag(int pos);
	void		handle_context_menu(void);
	void		menu_cb(size_t item);
	void		change_keybindings(void);
	static int	kf_default(int c, Fl_Text_Editor_mod* e);
	static int	kf_enter(int c, Fl_Text_Editor_mod* e);
	static int	kf_delete(int c, Fl_Text_Editor_mod* e);
	static int	kf_cut(int c, Fl_Text_Editor_mod* e);
	static int	kf_paste(int c, Fl_Text_Editor_mod* e);

private:
	FTextTX();
	FTextTX(const FTextTX &t);

protected:
	static Fl_Menu_Item	menu[];
	bool			PauseBreak;
	int			txpos;
	static int		*ptxpos;
	int			bkspaces;
};

#endif // FTextRXTX_H_

// Local Variables:
// mode: c++
// c-file-style: "linux"
// End:
