/* Copyright (C) 1996-2001 by Salvador E. Tropea (SET),
   see copyrigh file for details */
#define Uses_string
#define Uses_TApplication
#define Uses_TEvent
#define Uses_TRect
#define Uses_TDeskTop
#define Uses_TCEditWindow
#define Uses_TCEditor_Commands
// InfView requests
#include <infr.h>
#include <ceditor.h>

#define Uses_SETAppConst
#define Uses_TSetEditorApp
#include <setapp.h>

#include <inf.h>
#include <dskwin.h>
#include <dskhelp.h>
// Various help context
#include <editcoma.h>
// File Open dialog help context
#include <fileopen.h>

typedef struct
{
 int context;
 char *file;
 char *node;
} helpNode;

static char *EditorFile="setedit";

#define He(a) { cme##a, EditorFile, #a }
#define HHe(a,b) { cme##a, EditorFile, b }
#define Hc(a) { cmc##a, EditorFile, #a }
#define HHc(a,b) { cmc##a, EditorFile, b }
#define HC(a) { hc##a, EditorFile, #a }
#define HHC(a,b) { hc##a, EditorFile, b }

static helpNode helpList[]=
{
 He(Open),
 HHC(FileOpen,"Open"),
 He(New),
 //HHe(ChangeDrct,"Change directory"),
 HHe(OpenROCopy,"Open Read-only copy"),
 HHe(DosShell,"Shell"),
 He(Calculator),
 HC(Calculator),
 HHe(ShowClip,"Show clipboard"),
 He(InfView),
 HHe(ListWin,"List"),
 HHC(ListWin,"List"),
 He(LastHelp),
 HHe(UserScreen,"User Screen"),
 HHe(AnotherInfView,"Another InfView"),
 HHe(TipOfTheDay,"Tip of the day"),
 HHe(SyntaxHelpOps,"Options (Syntax help)"),
 HHe(SyntaxHelpFiles,"Files to search (Syntax help)"),
 HHe(SyntaxHelp,"Search (Syntax help)"),
 HHe(OpenPrj,"Open (Project)"),
 HHe(ClosePrj,"Close (Project)"),
 He(SDG),
 HHe(SDGDialog,"SDG Options"),
 HHe(SetColors,"Colors"),
 HHe(DeleteBkps,"Delete memorized backups"),
 HHe(QuitDelete,"Quit"),
 HHe(Quit,"Exit"),
 HHe(Resize,"Size/move"),
 He(Zoom),
 He(Tile),
 He(Cascade),
 HHe(Next,"Next (Window)"),
 HHe(Prev,"Previous (Window)"),
 He(Close),
 HHe(EditKeyBind,"Key assignment"),
 He(LoadKeyScans),
 HHe(SetUpAltKeys,"Setup Alt keys"),
 HHe(KeyPadBehavior,"Key pad behavior"),
 HHe(KbBackDefault,"Back to defaults"),
 HHe(SeeScanCodes,"Consult scan codes"),
 HHe(PrintEditor,"Print"),
 HHe(SetUpPrinter,"Print Setup"),
 HHe(GrepDialog,"Grep"),
 HHe(HTMLAccents,"Convert accents to tags"),
 HHe(HTMLTag2Accent,"Convert tags to accents"),
 HHe(ExportAsHTML,"Export as HTML"),
 HHc(InsertKeyName,"Insert key name"),
 HHe(RemapCodePage,"Remap code page"),
 HHe(ReDraw,"Redraw screen"),
 HHc(QuotedPrintDecode,"Block quoted printable decode"),
 HHc(IndentBlkOne,"Indent one space"),
 HHc(UnIndentBlkOne,"Unindent one character"),
 HHc(IndentBlk,"Indent one tab or gap"),
 HHc(UnIndentBlk,"Unindent one tab or gap"),
 HHc(CommentIndent,"Comment indent"),
 HHc(CommentUnIndent,"Comment unindent"),
 HHc(ArbitraryIndent,"Arbitrary indent"),
 He(NextMessage),
 He(PrevMessage),
 HHe(SetScreenOps,"Screen Options"),
 HHe(EditUserWords,"User Words"),
 HHe(EditDeflOpts,"Default global edition"),
 HHe(EditPalette,"Color Palette"),
 HHe(EdGralOptions,"Editor General"),
 HHe(ScreenSaverOpts,"Screen Saver"),
 HHe(FileOpenOptions,"Sort of the files and directories in the dialog"),
 HHe(EditNoBkp,"Do not create backups for"),
 HHe(IncludeList,"Search files under cursor in"),
 HHe(RunCommand,"Run program"),
 HHe(ConfRunCommand,"Run program (which one)"),
 Hc(Save),
 HHC(FileSave,"Save as"),
 HHc(SaveAs,"Save as"),
 HHc(SaveAsUNIX,"Save as UNIX"),
 HHc(SaveSameTime,"Save with same time"),
 Hc(Undo),
 Hc(Redo),
 Hc(Cut),
 Hc(Copy),
 Hc(Paste),
 Hc(Clear),
 HHc(SetLocalOptions,"Set Local"),
 HHc(SetGlobalOptions,"Set Global"),
 HHc(ExpandAllTabs,"Expand all tabs"),
 HHc(CompactBuffer,"Compact text"),
 HHc(PushCursorPos,"Push cursor position"),
 HHc(PopCursorPos,"Pop cursor position"),
 HHc(ToUpper,"Block to upper"),
 HHc(ToLower,"Block to lower"),
 HHc(ToggleCharCase,"Character toggle"),
 HHc(InvertCase,"Block invert"),
 HHc(AltCase,"Block alternate"),
 HHc(JumpToFunction,"Jump to function"),
 HHc(JumpToPrototype,"Jump to prototype"),
 HHc(GotoEditorLine,"Go to line"),
 HHc(CopyClipWin,"Copy to Windows Clipoard"),
 HHc(PasteClipWin,"Paste from Windows Clipboard"),
 HHc(RecordMacro,"Record (Macro)"),
 HHc(StopMacro,"Stop (Macro)"),
 HHc(PlayMacro,"Play (Macro)"),
 HHc(ChooseMacro,"Choose (Macro)"),
 HHc(RepeatMacro,"Repeat (Macro)"),
 HHc(GenCodeForMacro,"Generate Code"),
 HHc(ChoosePMacrosList,"Pseudo Macro (menu)"),
 Hc(Find),
 Hc(Replace),
 HHc(SearchAgain,"Search again"),
 HHc(SelRectStart,"Start (Rectangle)"),
 HHc(SelRectEnd,"End (Rectangle)"),
 HHc(SelRectHide,"Hide (Rectangle)"),
 HHc(SelRectCopy,"Copy (Rectangle)"),
 HHc(SelRectPaste,"Paste (Rectangle)"),
 HHc(SelRectCut,"Cut (Rectangle)"),
 HHc(SelRectDel,"Clear (Rectangle)"),
 HHc(SelRectMove,"Move (Rectangle)"),
 HHc(ProfileEditor,"Profile Editor"),
 HHC(OpenInfo,"File Open"),
 HHC(SaveBlock,"File Open"),
 HHC(ConfigFiles,"File Open"),
 HHC(OpenMP3,"File Open"),
 HHC(SaveMP3,"File Open"),
 HHC(GenOpenFile,"File Open"),
 HHC(ProjectFiles,"Project"),
 HHC(GenChDir,"Change directory"),
 HHC(RegExOptions,"Regular Expressions Options"),
 HHC(EditKeys,"How to configure the keyboard"),
 HHC(EditKeysSeq,"How to configure the keyboard"),
 HHC(EditKeysMac,"Assigning a sLisp macro"),
 HHC(EditKeysCom,"Assigning a sequence of commands"),
 HHC(EditorProjectWindow,"Project"),
 { 0,EditorFile,""}
};

void TSetEditorApp::GetContextHelp(void)
{
 //fprintf(stderr,"%d\n",helpCtxRequested);
 helpRequest=0;

 int i=0;
 while (helpList[i].context && helpList[i].context!=helpCtxRequested)
   {
    i++;
   }

 ShowHelpTopic(helpList[i].file,helpList[i].node);
}

void TSetEditorApp::ShowHelpTopic(char *file, char *node)
{
 TView *v=TProgram::deskTop->current;
 if (v && (v->state & sfModal))
    // When the help is called from a modal window we can't simply
    // show the InfView because it won't get the events. Executing
    // a modal help is the solution.
    InfManager->CreateModal(file,node);
 else
   {
    InfManager->Goto(file,node);
    InfManager->MakeVisible();
   }
}

// That's just a wrapper to avoid including a lot of things in other modules
void ShowHelpTopic(char *file, char *node)
{
 editorApp->ShowHelpTopic(file,node);
}
