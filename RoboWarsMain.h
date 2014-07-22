/***************************************************************
 * Name:      RoboWarsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Eric ()
 * Created:   2014-03-28
 * Copyright: Eric ()
 * License:
 **************************************************************/

#ifndef ROBOWARSMAIN_H
#define ROBOWARSMAIN_H

#include <wx/wx.h>


//(*Headers(RoboWarsFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include "Arena.h"

class RoboWarsFrame: public wxFrame
{

    /////////////////////headers for images/////////////
     wxBitmap bg_img;
     wxBitmap PLANT;
     wxBitmap PIG;
     wxBitmap WORM;
     wxBitmap OB;
     wxBitmap T_H;
     wxBitmap B_H;
     wxBitmap SCORE_bg;
     wxBitmap START;
     wxBitmap pigwin;
     wxBitmap wormwin;
     wxBitmap easter;




    ////////////////////////////////////////////////////




    public:

        RoboWarsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~RoboWarsFrame();
        Arena * arena;

    private:

        //(*Handlers(RoboWarsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnPanel2Paint1(wxPaintEvent& event);
        void OnPanel3Paint(wxPaintEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnPanel5Paint(wxPaintEvent& event);
        void OnPanel5LeftDClick(wxMouseEvent& event);
        void OnPanel5LeftDown(wxMouseEvent& event);
        void OnPanel5RightDown(wxMouseEvent& event);
        void OnOpen(wxCommandEvent& event);
        //*)
        void OnTimerTick(wxTimerEvent& event);
        void DrawArena();
        wxTimer GameTimer;

        static const long ID_TIMER1;

        //(*Identifiers(RoboWarsFrame)
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_PANEL4;
        static const long ID_PANEL5;
        static const long ID_TEXTCTRL1;
        static const long ID_PANEL3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuOpen;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        static bool isAppRunning;

        //(*Declarations(RoboWarsFrame)
        wxPanel* Panel5;
        wxPanel* Panel4;
        wxPanel* Panel1;
        wxPanel* Panel3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        wxPanel* Panel2;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ROBOWARSMAIN_H
