//
// cvPreProcessor, Visual Tool for OpenCv
// Copyright (C) 2008  BlueKid
// GUI tool for OpenCv 
// Programmed by BlueKid");
//  http://derindelimavi.blogspot.com/");
// Please Send me any suggestion, modification or bugs.");
// Don't hesitate to contact me for any question");
// I will be very grateful with your feedbacks.");
// bluekid70@gmail.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

// generated by Fast Light User Interface Designer (fluid) version 1.0109

#ifndef cvPreProcessor_h
#define cvPreProcessor_h
#include <FL/Fl.H>
#include "math.h"
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Chart.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#include "Fl_OpenCV.H"
#include "Fl_MatrixReader.h"
#include "datatypes.h"
#include "cvutility.h"
extern IplImage *img,*pimg,*timg; 
extern IplImage *mimg; 
extern Fl_OpenCV *orj,*proc; 
Fl_Color fl_hsv_color(double H, double S, double V);
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
extern Fl_Group *Before;
extern Fl_Group *After;
#include <FL/Fl_Button.H>
extern Fl_Button *MemorySet1;
extern Fl_Button *MemoryGet1;
extern Fl_Button *MemorySet2;
extern Fl_Button *MemoryGet2;
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Browser.H>
extern Fl_Browser *Output;
Fl_Double_Window* make_window();
extern Fl_Menu_Item menu_[];

class Processor {
public:
  Processor();
private:
  void FixFilename(char *src, char *dst);
public:
  void CopyTo1();
  void CopyFromMemory(int i);
  void CopyToMemory(int i);
  IplImage *uimg; 
  IplImage *upimg; 
  int usize; 
  bool undo; 
  void SaveState();
  void Undo(bool full=true);
  void Load1();
  void Save1();
  void Load2();
  void Save2();
  void Clear();
  void SaveCode();
  void Exit();
  resize r; 
  void ReSize();
  void Rotate(int angle);
  void RGBToGray();
  void SRed();
  void SGreen();
  void SBlue();
  void SHue();
  void SSaturation();
  void EHist();
  threshold th; 
  void NormalThreshold();
  void AdaptiveThreshold();
  morph m; 
  void Erode();
  void Dilate();
  void Open();
  void Close();
  void Grad();
  void TopHat();
  void BlackHat();
  void WriteCodeMorph(int i);
  edge ed; 
  void Sobel();
  void Laplace();
  void Canny();
  void Add();
  void Sub();
  void Mul();
  void Div();
  void Max();
  void Min();
  void AbsDiff();
  void Compare(int op);
  void And();
  void Or();
  void Xor();
  void Not();
  smoothoptions  sm; 
  void Smooth();
  void Filter2D(int row,int col,int X,int Y,float *data);
  void RGBFilter(int mode,int Rmin,int Rmax,int Gmin,int Gmax,int Bmin,int Bmax );
  filter2doptions flt; 
  void HSFilter(int mode,int Hmin,int Hmax,int Smin,int Smax);
};
void cb_Ok(Fl_Return_Button*o, void*w);
#include <FL/Fl_Return_Button.H>
extern void cb_Ok(Fl_Return_Button*, void*);

class AboutDlg {
public:
  AboutDlg();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
  Fl_Browser *Info;
  void show();
  void hide();
};
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Choice.H>

class MorphOptions {
public:
  MorphOptions();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok_i(Fl_Return_Button*, void*);
  static void cb_Ok(Fl_Return_Button*, void*);
public:
  Fl_Spinner *iterations;
  Fl_Choice *Shape;
  Fl_Spinner *cols;
  Fl_Spinner *rows;
  Fl_Spinner *ax;
  Fl_Spinner *ay;
  void show();
  void hide();
};
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Slider.H>

class EdgeOptions {
public:
  EdgeOptions();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok1_i(Fl_Return_Button*, void*);
  static void cb_Ok1(Fl_Return_Button*, void*);
public:
  Fl_Choice *Aperture;
  Fl_Round_Button *xOrder;
  Fl_Round_Button *yOrder;
  Fl_Value_Slider *tmin;
private:
  void cb_tmin_i(Fl_Value_Slider*, void*);
  static void cb_tmin(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *tmax;
private:
  void cb_tmax_i(Fl_Value_Slider*, void*);
  static void cb_tmax(Fl_Value_Slider*, void*);
public:
  void show();
  void hide();
};
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>

class ThresholdOptions {
public:
  ThresholdOptions();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok2_i(Fl_Return_Button*, void*);
  static void cb_Ok2(Fl_Return_Button*, void*);
public:
  Fl_Value_Slider *thresh;
  Fl_Check_Button *Otsu;
private:
  void cb_Otsu_i(Fl_Check_Button*, void*);
  static void cb_Otsu(Fl_Check_Button*, void*);
public:
  Fl_Value_Slider *max;
  Fl_Choice *Type;
  Fl_Choice *Method;
  Fl_Spinner *BlockSize;
  Fl_Value_Input *Param1;
private:
  void cb_Apply_i(Fl_Button*, void*);
  static void cb_Apply(Fl_Button*, void*);
  void cb_Apply1_i(Fl_Button*, void*);
  static void cb_Apply1(Fl_Button*, void*);
public:
  void show();
  void hide();
  void Update();
};
#include <FL/Fl_Value_Output.H>

class ReSizeForm {
public:
  ReSizeForm();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok3_i(Fl_Return_Button*, void*);
  static void cb_Ok3(Fl_Return_Button*, void*);
public:
  Fl_Choice *Interpolation;
  Fl_Check_Button *aspect;
private:
  void cb_aspect_i(Fl_Check_Button*, void*);
  static void cb_aspect(Fl_Check_Button*, void*);
public:
  Fl_Value_Output *oldw;
  Fl_Value_Output *oldh;
  Fl_Value_Slider *ratio;
private:
  void cb_ratio_i(Fl_Value_Slider*, void*);
  static void cb_ratio(Fl_Value_Slider*, void*);
public:
  Fl_Value_Input *rwidth;
  Fl_Value_Input *rheight;
  void show();
  void hide();
};

class HistForm {
public:
  HistForm();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok4_i(Fl_Return_Button*, void*);
  static void cb_Ok4(Fl_Return_Button*, void*);
public:
  Fl_Chart *Chart;
  Fl_Spinner *Type;
private:
  void cb_Type_i(Fl_Spinner*, void*);
  static void cb_Type(Fl_Spinner*, void*);
public:
  Fl_Choice *Ch;
private:
  void cb_Ch_i(Fl_Choice*, void*);
  static void cb_Ch(Fl_Choice*, void*);
public:
  Fl_Value_Output *Non_Zero;
  Fl_Value_Output *Sum;
  Fl_Value_Output *Avg;
  Fl_Value_Output *StdDev;
  Fl_Value_Output *Min;
  Fl_Value_Output *Max;
  Fl_Value_Output *Width;
  Fl_Value_Output *Height;
  void show();
  void hide();
private:
  CvHistogram *hist[5]; 
  IplImage* himg[5]; 
  int non_zeros[5]; 
  double sums[5]; 
  double avgs[5]; 
  double std_devs[5]; 
  double mins[5]; 
  double maxs[5]; 
public:
  void Draw();
  void Calculate();
};

class SmoothForm {
public:
  SmoothForm();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok5_i(Fl_Return_Button*, void*);
  static void cb_Ok5(Fl_Return_Button*, void*);
public:
  Fl_Choice *Type;
  Fl_Value_Input *size1;
  Fl_Value_Input *size2;
  Fl_Value_Input *sigma1;
  Fl_Value_Input *sigma2;
private:
  void cb_Apply2_i(Fl_Button*, void*);
  static void cb_Apply2(Fl_Button*, void*);
public:
  void show();
  void hide();
  void save();
};
#include <FL/Fl_Dial.H>

class RotateForm {
public:
  RotateForm();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok6_i(Fl_Return_Button*, void*);
  static void cb_Ok6(Fl_Return_Button*, void*);
  void cb_Apply3_i(Fl_Button*, void*);
  static void cb_Apply3(Fl_Button*, void*);
public:
  Fl_Dial *dl;
private:
  void cb_dl_i(Fl_Dial*, void*);
  static void cb_dl(Fl_Dial*, void*);
public:
  Fl_Value_Output *Angle;
  void show();
  void hide();
};
#include <FL/Fl_Box.H>

class RGBFilterForm {
  bool FirstTime; 
public:
  RGBFilterForm();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok7_i(Fl_Return_Button*, void*);
  static void cb_Ok7(Fl_Return_Button*, void*);
  void cb_Apply4_i(Fl_Button*, void*);
  static void cb_Apply4(Fl_Button*, void*);
public:
  Fl_Group *Chart;
  Fl_Box *C5;
  Fl_Box *Cm;
  Fl_Box *C7;
  Fl_Box *C8;
  Fl_Box *C3;
  Fl_Box *C1;
  Fl_Box *C2;
  Fl_Box *C6;
  Fl_Box *C4;
  Fl_Value_Slider *Rmin;
private:
  void cb_Rmin_i(Fl_Value_Slider*, void*);
  static void cb_Rmin(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Rmax;
private:
  void cb_Rmax_i(Fl_Value_Slider*, void*);
  static void cb_Rmax(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Gmin;
private:
  void cb_Gmin_i(Fl_Value_Slider*, void*);
  static void cb_Gmin(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Gmax;
private:
  void cb_Gmax_i(Fl_Value_Slider*, void*);
  static void cb_Gmax(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Bmin;
private:
  void cb_Bmin_i(Fl_Value_Slider*, void*);
  static void cb_Bmin(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Bmax;
private:
  void cb_Bmax_i(Fl_Value_Slider*, void*);
  static void cb_Bmax(Fl_Value_Slider*, void*);
public:
  Fl_Check_Button *Mode;
  void show();
  void hide();
  void changecolor();
};

class HSFilterForm {
  bool FirstTime; 
public:
  HSFilterForm();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok8_i(Fl_Return_Button*, void*);
  static void cb_Ok8(Fl_Return_Button*, void*);
  void cb_Apply5_i(Fl_Button*, void*);
  static void cb_Apply5(Fl_Button*, void*);
public:
  Fl_Group *Chart;
  Fl_Box *Cm;
  Fl_Box *C3;
  Fl_Box *C1;
  Fl_Box *C2;
  Fl_Box *C4;
  Fl_Group *Sld;
  Fl_Value_Slider *Hmin;
private:
  void cb_Hmin_i(Fl_Value_Slider*, void*);
  static void cb_Hmin(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Hmax;
private:
  void cb_Hmax_i(Fl_Value_Slider*, void*);
  static void cb_Hmax(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Smin;
private:
  void cb_Smin_i(Fl_Value_Slider*, void*);
  static void cb_Smin(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *Smax;
private:
  void cb_Smax_i(Fl_Value_Slider*, void*);
  static void cb_Smax(Fl_Value_Slider*, void*);
public:
  Fl_Check_Button *Mode;
  void show();
  void hide();
  void changecolor();
};
#include <FL/Fl_Counter.H>

class Filter2DForm {
  int FirstTime; 
public:
  Filter2DForm();
  Fl_Double_Window *window;
  Fl_Return_Button *Ok;
private:
  void cb_Ok9_i(Fl_Return_Button*, void*);
  static void cb_Ok9(Fl_Return_Button*, void*);
  void cb_Apply6_i(Fl_Button*, void*);
  static void cb_Apply6(Fl_Button*, void*);
public:
  Fl_MatrixReader *Data;
  Fl_Counter *Col;
private:
  void cb_Col_i(Fl_Counter*, void*);
  static void cb_Col(Fl_Counter*, void*);
public:
  Fl_Counter *Row;
private:
  void cb_Row_i(Fl_Counter*, void*);
  static void cb_Row(Fl_Counter*, void*);
public:
  Fl_Counter *X;
  Fl_Counter *Y;
  void show();
  void hide();
};
#endif