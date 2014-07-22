/***************************************************************
 * Name:      RoboWarsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Eric ()
 * Created:   2014-03-28
 * Copyright: Eric ()
 * License:
 **************************************************************/

#include "RoboWarsApp.h"

//(*AppHeaders
#include "RoboWarsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(RoboWarsApp);

bool RoboWarsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	RoboWarsFrame* Frame = new RoboWarsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
