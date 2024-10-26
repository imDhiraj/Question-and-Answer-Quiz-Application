//---------------------------------------------------------------------------

#include <fmx.h>
#include <queue>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class Question{
public:
	char* Text;
	char* Answer1;
	char* Answer2;
	char* Answer3;
	int CorrectAnswer;

	Question() {}
	Question(char* text,char* ans1,char* ans2,char* ans3,int correctAns) {
		Text=text;
		Answer1=ans1;
		Answer2=ans2;
		Answer3=ans3;
		CorrectAnswer =correctAns;
	}

};

std::queue<Question>LoadQuestion() {
		Question q1 = Question ("which coler does not apper on olympic rings?","Black","Orange", "Green", 2);
		Question q2 = Question ("which is the chemical formula for table slat?","NaCl","NaCl2", "Na2Cl", 1);
		Question q3 = Question ("which is longest river on earth?", "nile", "Mississippi","Amazon", 1);

		std::queue <Question>questions ;
		questions.push(q1);
		questions.push(q2);
		questions.push(q3);

		return questions;
}

std::queue <Question> questions;
	Question currentQuestion;
int selectedAnswer;
int points=0;


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	questions=LoadQuestion();
	currentQuestion=questions.front();

	QuestionLabel1->Text =currentQuestion.Text;
	Answer1RadioButton1->Text = currentQuestion.Answer1 ;
	Answer2RadioButton2->Text = currentQuestion.Answer2 ;
	Abswer3RadioButton3->Text = currentQuestion.Answer3 ;

	questions.pop();
	pointsLabel->Text =points;	
	EndLabel1->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Answer1RadioButton1Change(TObject *Sender)
{
    selectedAnswer=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Answer2RadioButton2Change(TObject *Sender)
{
    selectedAnswer=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Abswer3RadioButton3Change(TObject *Sender)
{
    selectedAnswer=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SubmitAnswerClick(TObject *Sender)
{
	if(selectedAnswer==currentQuestion.CorrectAnswer){
		points++;
		pointsLabel->Text =points;

	}
	if(!questions.empty()){
		currentQuestion=questions.front();

		QuestionLabel1->Text =currentQuestion.Text;
		Answer1RadioButton1->Text = currentQuestion.Answer1 ;
		Answer2RadioButton2->Text = currentQuestion.Answer2 ;
		Abswer3RadioButton3->Text = currentQuestion.Answer3 ;

		questions.pop();	
		Answer1RadioButton1->IsChecked =false;	
		Answer2RadioButton2->IsChecked =false;
		Abswer3RadioButton3->IsChecked =false;
	}
	else{
		  SubmitAnswer->Enabled	=false;
		  SubmitAnswer->Text ="End Of Test";

		  QuestionLabel1->Visible =false;
		  Answer1RadioButton1->Visible =false;	
		  Answer2RadioButton2->Visible =false;
		  Abswer3RadioButton3->Visible =false;
		  SubmitAnswer->Visible	=false;
		  Points->Visible	=false;
		  pointsLabel->Visible	=false;

		  EndLabel1->Visible =true;
		  EndLabel1->Text = "Your total points are " + IntToStr(points);
	}	
	}

//---------------------------------------------------------------------------

 void __fastcall TForm1::PointsLabel3Click(System::TObject *Sender) {
    // Your code here
}


