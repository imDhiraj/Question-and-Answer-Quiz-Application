//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *QuestionLabel1;
	TLabel *Points;
	TRadioButton *Answer1RadioButton1;
	TRadioButton *Answer2RadioButton2;
	TRadioButton *Abswer3RadioButton3;
	TButton *SubmitAnswer;
	TLabel *pointsLabel;
	TLabel *EndLabel1;
	void __fastcall Answer1RadioButton1Change(TObject *Sender);
	void __fastcall Answer2RadioButton2Change(TObject *Sender);
	void __fastcall Abswer3RadioButton3Change(TObject *Sender);
	void __fastcall SubmitAnswerClick(TObject *Sender);
	void __fastcall PointsLabel3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
