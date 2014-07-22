/***************************************************************
 * Name:      RoboWarsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Eric ()
 * Created:   2014-03-28
 * Copyright: Eric ()
 * License:
 **************************************************************/

#include "RoboWarsMain.h"
#include <wx/msgdlg.h>

//eric added libraries///////////
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/image.h>
#include <wx/dcbuffer.h>
#include <wx/utils.h>
#include <wx/defs.h>
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//////////////////////////////



//(*InternalHeaders(RoboWarsFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)


#include "Parameters.h"
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(RoboWarsFrame)
const long RoboWarsFrame::ID_PANEL2 = wxNewId();
const long RoboWarsFrame::ID_TEXTCTRL2 = wxNewId();
const long RoboWarsFrame::ID_TEXTCTRL3 = wxNewId();
const long RoboWarsFrame::ID_PANEL4 = wxNewId();
const long RoboWarsFrame::ID_PANEL5 = wxNewId();
const long RoboWarsFrame::ID_TEXTCTRL1 = wxNewId();
const long RoboWarsFrame::ID_PANEL3 = wxNewId();
const long RoboWarsFrame::ID_PANEL1 = wxNewId();
const long RoboWarsFrame::idMenuQuit = wxNewId();
const long RoboWarsFrame::idMenuOpen = wxNewId();
const long RoboWarsFrame::idMenuAbout = wxNewId();
const long RoboWarsFrame::ID_STATUSBAR1 = wxNewId();
//*)

bool RoboWarsFrame::isAppRunning = wxFalse;
const long RoboWarsFrame::ID_TIMER1 = wxNewId(  );

 int Parameters::TIME_TO_BREED_PREDATOR=0;
 int Parameters::TIME_TO_BREED_PREY=0;
 int Parameters::TIME_TO_EAT=0;

 int Parameters::PERCENT_PREDATOR=0;
 int Parameters::PERCENT_PREY = 0;
 int Parameters::PERCENT_OBSTACLES=0;
 int Parameters::PERCENT_BLACKHOLES=0;
 int Parameters::PERCENT_TRANSPORTHOLES=0;
 int Parameters::PERCENT_EMPTYCELLS=0;

 int Parameters::PREDATOR_AGGRESSIVENESS=0;

 int Parameters::NUMBER_OF_COLS=0;
 int Parameters::NUMBER_OF_ROWS=0;
int toggle;



BEGIN_EVENT_TABLE(RoboWarsFrame,wxFrame)
    //(*EventTable(RoboWarsFrame)
    //*)
END_EVENT_TABLE()

RoboWarsFrame::RoboWarsFrame(wxWindow* parent,wxWindowID id)
{
    //attempt to add background
    //bg_img.LoadFile( wxT( "bg.png" ), wxBITMAP_TYPE_PNG );

    bg_img = wxBitmap(wxImage(_T( "IMAGES/bg.png" )));
    PLANT = wxBitmap(wxImage(_T( "IMAGES/PLANT.png" )));
    PIG = wxBitmap(wxImage(_T( "IMAGES/PIG.png" )));
    WORM = wxBitmap(wxImage(_T( "IMAGES/WORM.png" )));
    OB = wxBitmap(wxImage(_T( "IMAGES/OB.png" )));
    T_H = wxBitmap(wxImage(_T( "IMAGES/T_H.png" )));
    B_H = wxBitmap(wxImage(_T( "IMAGES/B_H.png" )));
    SCORE_bg = wxBitmap(wxImage(_T( "IMAGES/SCORE_bg.png" )));
    START = wxBitmap(wxImage(_T( "IMAGES/START.png" )));
    wormwin = wxBitmap(wxImage(_T( "IMAGES/wromwin.png" )));
    pigwin = wxBitmap(wxImage(_T( "IMAGES/porkwin.png" )));
    easter = wxBitmap(wxImage(_T( "IMAGES/easter.png" )));



    //(*Initialize(RoboWarsFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuItem* MenuItem3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("ROBO WARS"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(941,645));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("/home/ubuntu/Documents/RoboWars/IMAGES/PIG.png"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(88,120), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(0,0,24));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxSize(600,645), wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxColour(0,0,24));
    BoxSizer1->Add(Panel2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxDefaultPosition, wxSize(600,432), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel3->SetBackgroundColour(wxColour(0,0,24));
    TextCtrl2 = new wxTextCtrl(Panel3, ID_TEXTCTRL2, _("Score"), wxPoint(72,288), wxDefaultSize, wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetForegroundColour(wxColour(132,219,244));
    TextCtrl2->SetBackgroundColour(wxColour(0,0,24));
    wxFont TextCtrl2Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl2->SetFont(TextCtrl2Font);
    TextCtrl3 = new wxTextCtrl(Panel3, ID_TEXTCTRL3, _("Score"), wxPoint(72,184), wxDefaultSize, wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->SetForegroundColour(wxColour(132,219,244));
    TextCtrl3->SetBackgroundColour(wxColour(0,0,24));
    wxFont TextCtrl3Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl3->SetFont(TextCtrl3Font);
    Panel4 = new wxPanel(Panel3, ID_PANEL4, wxPoint(272,384), wxSize(80,112), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel4->SetBackgroundColour(wxColour(0,0,24));
    Panel5 = new wxPanel(Panel3, ID_PANEL5, wxPoint(64,456), wxSize(152,32), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel5->SetBackgroundColour(wxColour(0,0,24));
    TextCtrl1 = new wxTextCtrl(Panel3, ID_TEXTCTRL1, _("0"), wxPoint(72,392), wxDefaultSize, wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetForegroundColour(wxColour(132,219,214));
    TextCtrl1->SetBackgroundColour(wxColour(0,0,24));
    wxFont TextCtrl1Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    BoxSizer1->Add(Panel3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuItem1->SetBitmap(wxBitmap(wxImage(_T("/home/ubuntu/Documents/RoboWars/IMAGES/WORM.png"))));
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, idMenuOpen, _("Open\tCtrl+O"), _("Open Xml File"), wxITEM_NORMAL);
    MenuItem3->SetBitmap(wxBitmap(wxImage(_T("/home/ubuntu/Documents/RoboWars/IMAGES/PIG.png"))));
    Menu1->Append(MenuItem3);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuItem2->SetBitmap(wxBitmap(wxImage(_T("/home/ubuntu/Documents/RoboWars/IMAGES/PLANT.png"))));
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RoboWarsFrame::OnPanel2Paint1,0,this);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&RoboWarsFrame::OnTextCtrl2Text);
    Panel5->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RoboWarsFrame::OnPanel5Paint,0,this);
    Panel5->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&RoboWarsFrame::OnPanel5LeftDown,0,this);
    Panel5->Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&RoboWarsFrame::OnPanel5RightDown,0,this);
    Panel3->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RoboWarsFrame::OnPanel3Paint,0,this);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RoboWarsFrame::OnPanel1Paint,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RoboWarsFrame::OnQuit);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RoboWarsFrame::OnOpen);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RoboWarsFrame::OnAbout);
    //*)

    GameTimer.SetOwner(this,ID_TIMER1);

    Connect( ID_TIMER1,wxEVT_TIMER,( wxObjectEventFunction )&RoboWarsFrame::OnTimerTick);


}

RoboWarsFrame::~RoboWarsFrame()
{
    //(*Destroy(RoboWarsFrame)
    //*)
}

void RoboWarsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void RoboWarsFrame::OnAbout(wxCommandEvent& event)
{
    const char* chars = "ROBO WARS! \nPress start and watch as the Porky Bots attack the Wormi invasion!\t\t\t\t\t\t\t\t\t";

// if your string is UTF-8 encoded, this is the shortest path :
    wxString msg = wxString::FromUTF8(chars);





   // wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));

   // wxString msg = "It's a notepad. What else is there to know?" ; //+ "\n" + wxbuildinfo(long_f)
   // wxMessageBox(msg, _("All you need to know about wxNotes"));
}

void RoboWarsFrame::OnPanel1Paint(wxPaintEvent& event)
{
   wxPaintDC dc(Panel1);

}


void RoboWarsFrame::OnPanel2Paint1(wxPaintEvent& event)
{

            //wxBufferedPaintDC dc( this );

   // wxPaintDC dc( this );
    wxPaintDC dc(Panel2);
    dc.DrawBitmap( bg_img, 0, 0, true );
   // dc.DrawBitmap( PLANT, 0, 0, true );
   // dc.DrawBitmap( PIG, 25, 0, true );
   // dc.DrawBitmap( WORM, 50, 0, true );

//    dc.SetBackground(Panel2->bg_img);



}

void RoboWarsFrame::OnPanel3Paint(wxPaintEvent& event)
{
    wxPaintDC dc(Panel3);
    dc.DrawBitmap( SCORE_bg, 0, 0, true );


}

void RoboWarsFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void RoboWarsFrame::OnPanel5Paint(wxPaintEvent& event)
{
      wxPaintDC dc(Panel5);
    dc.DrawBitmap( START, 0, 0, true );


}



void RoboWarsFrame::OnPanel5LeftDown(wxMouseEvent& event)
{


    if(RoboWarsFrame::isAppRunning)
    {
        //code to run if app is running and we want to stop it
        //stop the wxtimer
        GameTimer.Stop();
    }
    else
    {
        //code to run if app is stopped and we want it to run
        //check if there is an arena.  if not create arena and start timer.
        GameTimer.Start(750, false);
    }

    RoboWarsFrame::isAppRunning = !RoboWarsFrame::isAppRunning;

}



void RoboWarsFrame::OnPanel5RightDown(wxMouseEvent& event)
{
    ////////////////////////////////////////////////////////
    struct projectile
    {
        double x, y, vx, vy;
    } leafo;

    leafo.x = 0; // Paddle’s y component
    leafo.y = 0; // Paddle’s y component
    wxPaintDC dc(Panel2);
    dc.DrawBitmap( PLANT, int( leafo.x ), int( leafo.y ), true );
    if( wxGetKeyState( WXK_UP ) )
    {
      leafo.y -= 8;
        Update();
    }

    else if( wxGetKeyState( WXK_DOWN ) )
    {
         leafo.y += 8;
        Update();
    }




///////////////////////////////////////////////////
/*
    int x,y;

//    wxPaintDC dc(Panel2);




    for (x=0;x< 30;x++)
    {
        for (y=0;y<30;y++)
        {


            Update();
            dc.DrawBitmap( PLANT, x*25, y*25, true );



            }
        }

        dc.DrawBitmap( easter, 0, 0, true );







//    wxString clear;
//    TextCtrl3->ChangeValue(clear);
//    TextCtrl2->ChangeValue(clear);
*/

}
void RoboWarsFrame::OnOpen(wxCommandEvent& event)
{

    wxFileDialog *openDialog = new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""),
    wxT("TinyXML Files (*.xml)|*.xml"),
    wxFD_OPEN );

    int response = openDialog->ShowModal(); //get response from the dialog

    if(response == wxID_OK)
    { //if response ok, then load contents into textControl
        wxString returnFile = openDialog->GetFilename();
        Parameters::LoadValuesFromFile(returnFile);
        //this->textControl->LoadFile(openDialog->GetPath());

    }
    RoboWarsFrame::arena = new Arena(Parameters::NUMBER_OF_ROWS,Parameters::NUMBER_OF_COLS);
}
void RoboWarsFrame::OnTimerTick(wxTimerEvent& event)
{
    //handle event tick.  Will call animate and Draw.
    arena->AnimateArena();
    DrawArena();
}

void RoboWarsFrame::DrawArena()
{
    wxPaintDC dc(Panel2);
    dc.Clear();
    dc.DrawBitmap( bg_img, 0, 0, true );

    wxString  score_worm, score_pig, score_tick;
    double  scr_worm, scr_pig;
    static double scr_tick=0;



    scr_worm=0;
    scr_pig=0;

    int x,y;
    char thisCell;



    for (x=0;x< Parameters::NUMBER_OF_COLS;x++)
    {
        for (y=0;y<Parameters::NUMBER_OF_ROWS;y++)
        {

            wxPaintDC dc(Panel2);
            thisCell=arena->ReturnCellType(x,y);
            Update();
            switch(thisCell)

            {
                case 'P':

                dc.DrawBitmap( PIG, x*25, y*25, true );
                scr_pig+=1;
                break;

                case'r':
                dc.DrawBitmap( WORM, x*25, y*25, true );
                scr_worm+=1;
                break;

                case '#':
                dc.DrawBitmap( OB, x*25, y*25, true );
                break;

                case '*':
                dc.DrawBitmap( T_H, x*25, y*25, true );
                break;

                case 'O':
                dc.DrawBitmap( B_H, x*25, y*25, true );
                break;

            }
        }

    }


    scr_tick+=1;

    score_tick.Printf(wxT("%.0f"), scr_tick);
    TextCtrl1->ChangeValue(score_tick);



    score_worm.Printf(wxT("%.0f"), scr_worm);
    TextCtrl2->ChangeValue(score_worm);

    score_pig.Printf(wxT("%.0f"), scr_pig);
    TextCtrl3->ChangeValue(score_pig);

    if(scr_worm==0)
    {
        GameTimer.Stop();
        wxPaintDC dc(Panel2);
        dc.DrawBitmap( pigwin, 0, 0, true );
    }

    else if (scr_pig==0)
    {
        GameTimer.Stop();
        wxPaintDC dc(Panel2);
        dc.DrawBitmap( wormwin, 0, 0, true );
    }




}
