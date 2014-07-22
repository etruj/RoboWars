#include "Parameters.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include "tinyxml.h"
#include "tinystr.h"

using namespace std;

Parameters::Parameters()
{
    //ctor
}

Parameters::~Parameters()
{
    //dtor
}
void Parameters::LoadValues()
{
       TIME_TO_BREED_PREDATOR=7;
       TIME_TO_BREED_PREY=12;
       TIME_TO_EAT=14;
       PREDATOR_AGGRESSIVENESS=5;

       PERCENT_PREDATOR=15;
       PERCENT_PREY = 25;
       PERCENT_OBSTACLES=10;
       PERCENT_BLACKHOLES=5;
       PERCENT_TRANSPORTHOLES=5;
       PERCENT_EMPTYCELLS=40;


}
void Parameters::LoadValuesFromFile()
{

    /*cout<<"Before Reading: "<< endl;
    cout<<"TIME_TO_BREED_PREDATOR :"<<TIME_TO_BREED_PREDATOR<< endl;
    cout<<"TIME_TO_BREED_PREY :"<<TIME_TO_BREED_PREY<< endl;
    cout<<"TIME_TO_EAT :"<<TIME_TO_EAT<< endl;
    cout<<"PREDATOR_AGGRESSIVENESS :"<<PREDATOR_AGGRESSIVENESS<< endl;
    cout<<"PERCENT_PREDATOR :"<<PERCENT_PREDATOR<< endl;
    cout<<"PERCENT_PREY :"<<PERCENT_PREY<< endl;
    cout<<"PERCENT_OBSTACLES :"<<PERCENT_OBSTACLES<< endl;
    cout<<"PERCENT_BLACKHOLES :"<<PERCENT_BLACKHOLES<< endl;
    cout<<"PERCENT_TRANSPORTHOLES :"<<PERCENT_TRANSPORTHOLES<< endl;
    cout<<"PERCENT_EMPTYCELLS :"<<PERCENT_EMPTYCELLS<< endl;*/


    string m_name;
    char pFileName[]="RobotSettings.xml";
    TiXmlDocument doc(pFileName);
    if (!doc.LoadFile()) return;


	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem;
	TiXmlHandle hRoot(0);

		// block: name
	{
		pElem=hDoc.FirstChildElement().Element();
		// should always have a valid root but handle gracefully if it does
		if (!pElem) return;
		m_name=pElem->Value();

		// save this for later
		hRoot=TiXmlHandle(pElem);
	}
    pElem=hRoot.FirstChild("TIME_TO_BREED_PREDATOR").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&TIME_TO_BREED_PREDATOR);
    }

    pElem=hRoot.FirstChild("TIME_TO_BREED_PREY").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&TIME_TO_BREED_PREY);
    }

    pElem=hRoot.FirstChild("TIME_TO_EAT").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&TIME_TO_EAT);
    }

    pElem=hRoot.FirstChild("PREDATOR_AGGRESSIVENESS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PREDATOR_AGGRESSIVENESS);
    }

    pElem=hRoot.FirstChild("PERCENT_PREDATOR").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_PREDATOR);
    }

    pElem=hRoot.FirstChild("PERCENT_PREY").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_PREY);
    }

    pElem=hRoot.FirstChild("PERCENT_OBSTACLES").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_OBSTACLES);
    }

    pElem=hRoot.FirstChild("PERCENT_BLACKHOLES").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_BLACKHOLES);
    }

    pElem=hRoot.FirstChild("PERCENT_TRANSPORTHOLES").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_TRANSPORTHOLES);
    }

    pElem=hRoot.FirstChild("PERCENT_EMPTYCELLS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_EMPTYCELLS);
    }

    pElem=hRoot.FirstChild("NUMBER_OF_ROWS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&NUMBER_OF_ROWS);
    }

    pElem=hRoot.FirstChild("NUMBER_OF_COLS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&NUMBER_OF_COLS);
    }


    /*cout<<"After Reading: "<< endl;
    cout<<"TIME_TO_BREED_PREDATOR :"<<TIME_TO_BREED_PREDATOR<< endl;
    cout<<"TIME_TO_BREED_PREY :"<<TIME_TO_BREED_PREY<< endl;
    cout<<"TIME_TO_EAT :"<<TIME_TO_EAT<< endl;
    cout<<"PREDATOR_AGGRESSIVENESS :"<<PREDATOR_AGGRESSIVENESS<< endl;
    cout<<"PERCENT_PREDATOR :"<<PERCENT_PREDATOR<< endl;
    cout<<"PERCENT_PREY :"<<PERCENT_PREY<< endl;
    cout<<"PERCENT_OBSTACLES :"<<PERCENT_OBSTACLES<< endl;
    cout<<"PERCENT_BLACKHOLES :"<<PERCENT_BLACKHOLES<< endl;
    cout<<"PERCENT_TRANSPORTHOLES :"<<PERCENT_TRANSPORTHOLES<< endl;
    cout<<"PERCENT_EMPTYCELLS :"<<PERCENT_EMPTYCELLS<< endl;
    sleep(3);*/

}

void Parameters::LoadValuesFromFile(wxString& xmlFileName)
{
    char pFileName[19];
    strncpy(pFileName, (const char*)xmlFileName.mb_str(wxConvUTF8), 19);
    string m_name;
    TiXmlDocument doc(pFileName);
    if (!doc.LoadFile()) return;


	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem;
	TiXmlHandle hRoot(0);

		// block: name
	{
		pElem=hDoc.FirstChildElement().Element();
		// should always have a valid root but handle gracefully if it does
		if (!pElem) return;
		m_name=pElem->Value();

		// save this for later
		hRoot=TiXmlHandle(pElem);
	}
    pElem=hRoot.FirstChild("TIME_TO_BREED_PREDATOR").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&TIME_TO_BREED_PREDATOR);
    }

    pElem=hRoot.FirstChild("TIME_TO_BREED_PREY").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&TIME_TO_BREED_PREY);
    }

    pElem=hRoot.FirstChild("TIME_TO_EAT").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&TIME_TO_EAT);
    }

    pElem=hRoot.FirstChild("PREDATOR_AGGRESSIVENESS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PREDATOR_AGGRESSIVENESS);
    }

    pElem=hRoot.FirstChild("PERCENT_PREDATOR").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_PREDATOR);
    }

    pElem=hRoot.FirstChild("PERCENT_PREY").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_PREY);
    }

    pElem=hRoot.FirstChild("PERCENT_OBSTACLES").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_OBSTACLES);
    }

    pElem=hRoot.FirstChild("PERCENT_BLACKHOLES").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_BLACKHOLES);
    }

    pElem=hRoot.FirstChild("PERCENT_TRANSPORTHOLES").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_TRANSPORTHOLES);
    }

    pElem=hRoot.FirstChild("PERCENT_EMPTYCELLS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&PERCENT_EMPTYCELLS);
    }

    pElem=hRoot.FirstChild("NUMBER_OF_ROWS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&NUMBER_OF_ROWS);
    }

    pElem=hRoot.FirstChild("NUMBER_OF_COLS").Element();
    if (pElem)
    {
        pElem->QueryIntAttribute("value",&NUMBER_OF_COLS);
    }



}
