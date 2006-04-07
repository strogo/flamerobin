/*
  The contents of this file are subject to the Initial Developer's Public
  License Version 1.0 (the "License"); you may not use this file except in
  compliance with the License. You may obtain a copy of the License here:
  http://www.flamerobin.org/license.html.

  Software distributed under the License is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
  License for the specific language governing rights and limitations under
  the License.

  The Original Code is FlameRobin (TM).

  The Initial Developer of the Original Code is Milan Babuskov.

  Portions created by the original developer
  are Copyright (C) 2004 Milan Babuskov.

  All Rights Reserved.

  $Id$

  Contributor(s): Michael Hieke, Nando Dessena
*/

#ifndef DATABASEREGISTRATIONDIALOG_H
#define DATABASEREGISTRATIONDIALOG_H
//-----------------------------------------------------------------------------
#include <wx/wx.h>

#include "gui/BaseDialog.h"

class Server;
class Database;
//-----------------------------------------------------------------------------
class DatabaseRegistrationDialog: public BaseDialog {
private:
    Server* serverM;
    Database* databaseM;
    bool createM;
    bool connectAsM;
    bool isDefaultNameM;

    wxStaticText* label_name;
    wxTextCtrl* text_ctrl_name;
    wxStaticText* label_dbpath;
    wxTextCtrl* text_ctrl_dbpath;
    wxButton* button_browse;
    wxStaticText* label_username;
    wxTextCtrl* text_ctrl_username;
    wxStaticText* label_password;
    wxTextCtrl* text_ctrl_password;
    wxStaticText* label_charset;
    wxComboBox* combobox_charset;
    wxStaticText* label_role;
    wxTextCtrl* text_ctrl_role;
    wxStaticText* label_pagesize;
    wxChoice* choice_pagesize;
    wxStaticText* label_dialect;
    wxChoice* choice_dialect;
    wxCheckBox* checkbox_encrypted;
    wxButton* button_ok;
    wxButton* button_cancel;

    const wxString buildName(const wxString& dbPath) const;
    void createControls();
    void layoutControls();
    void setControlsProperties();
    void updateButtons();
    void updateIsDefaultName();
protected:
    virtual const wxString getName() const;
    virtual bool getConfigStoresHeight() const;
public:
    DatabaseRegistrationDialog(wxWindow* parent, const wxString& title,
        bool createDB = false,
        // a temporary solution, as we'll change the entire login scheme soon
        bool connectAs = false);

    void setServer(Server* s); // needed to create new db
    void setDatabase(Database* db);
private:
    // event handling
    enum {
        ID_textcontrol_dbpath = 101,
        ID_textcontrol_name,
        ID_textcontrol_username,
        ID_textcontrol_password,
        ID_button_browse,
        ID_button_ok,
        ID_button_cancel = wxID_CANCEL
    };

    void OnBrowseButtonClick(wxCommandEvent& event);
    void OnNameChange(wxCommandEvent& event);
    void OnOkButtonClick(wxCommandEvent& event);
    void OnSettingsChange(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};
//-----------------------------------------------------------------------------
#endif // DATABASEREGISTRATIONDIALOG_H
