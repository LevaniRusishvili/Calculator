

//WIN API   aris tu cvladebi romlebic funqcias gadaeqca rogor chaitena stackshi, da vinaa pasuxismgebeli stackis gasuftavebaze

//#define UNICODE
#define Addition			1
#define Subtraction			2
#define Multiplication		3
#define Division			4
#define BinaryToDecimal		5

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include "Resource.h"
#include "math.h"

int k=0;
int sz=100;
unsigned int Counter = 0;        //Buffer index

int Var=0;
int Var2=0;
int Op1=0;
int Op2=0;
int MyInt=0;
int EqualVar=0;
int tempCount=0;
int digitCount=0;
int EqualClicked=0;

int Buf1Length = 0;
int Op1Length =0;               // Calculate the number of digits in Op2
int validNumber1=0;
int digitOp1=0;
int digitBuf1=0;
int Buf2Length = 0;
int Op2Length =0;               // Calculate the number of digits in Op2
int validNumber2=0;
int digitOp2=0;
int digitBuf2=0;


int Add_Res=0;
int Sub_Res=0;
int Mul_Res=0;
int Div_Res=0;

char *Buf=NULL;
char *Buf1=NULL;
char *Buf2=NULL;

void Operand1(char *Buf,int Counter);
void Operand2(char *Buf,int tempCount,int Counter);
int Add(int Op1, int Op2);
int Sub(int Op1, int Op2);
int Mul(int Op1, int Op2);
void Div(int Op1, int Op2);
//---------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);                                                                                                                                                   //LRESULT aris long pointer tipis, hWND aris handle tu romel fanjarazea laparaki  wparam word param lparam lparam, mara orive 32 bitia 32 bitianshi
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

//---------------------------------------------------------------------------------------------------------------
//===============================================================================================================
//!!!!!!!!!!!!!!!!!!!!!AMIS GARDA  YVELAFERI GADATANILIA FILEBSHI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevINstance, LPSTR lpszArguments, int nCmdShow)
{

//--------------Main_Window-------------------------------------------------------------
    WNDCLASS wndClass;
    wndClass.hInstance = hInstance;                                                                                                                                                                                                           //this class belongs to this application
    wndClass.lpszClassName = TEXT("MY_CLASS_WINDOW");                                                                                                                                                                   //LONG POINTER TO STRING ZERO TERMINATED. THIS IS NAME OF THE CLASS
    wndClass.lpszMenuName = MAKEINTRESOURCE(IDM_MAIN_MENU);                                                                                                                                        //We have no menu for now
    wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);                                                                                                                                          //HBRUSH aris imistvis, rom rasac fuqncia abrunebs aris void* tipis, HBRUSH gardaqmnis mas HBRUSH tipad
    wndClass.cbClsExtra = 0;                                                                                                                                                                                        //count byte class extra     extra memory, ramdeni adgilia darchenili WNDCLASS klasis struqturis boloshi ro gava, ramdeni byte sheudzlia kide ro gamoyos. am shemtxvevashi veubnebit ro 0, ro ar gamogviyos araferi damatebit.
    wndClass.cbWndExtra = 0;                                                                                                                                                                                                //extra memory aris esec, mara windowsis struqtura ro gava boloshi, mas shemdeg
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);                                                                                                                                                                                  //0 imitoa, ro chven gvinda sistemis iconi, da ara aplikaciis. meore parametria tu ra tipis iconi gvinda. aplikaciis
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                                                                                                                                                                    //rogori kursori gvinda
    wndClass.style = CS_HREDRAW | CS_VREDRAW;                                                                                                                                                                                       //es nishnavs, rom tu fanjara gavwelet, wayves ferebi horizontaluradac da vertikaluradac, an tu vamodzravebt fanjaras, unda wayves ferebic
    wndClass.lpfnWndProc = MainWndProc;
    //long pointer to a function
//--------------------------------------------------------------------------------------
char Mychar;
//-----------------------Child_Window---------------------------------------------------
    WNDCLASS wndClass2;
    wndClass2.hInstance = hInstance;                                                                                                   //this class belongs to this application
    wndClass2.lpszClassName = TEXT("MY_CLASS_WINDOW_2");                                                                               //LONG POINTER TO STRING ZERO TERMINATED. THIS IS NAME OF THE CLASS
    wndClass2.lpszMenuName = NULL;                                                                                                     //We have no menu for now
    wndClass2.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);                                                                     //HBRUSH aris imistvis, rom rasac fuqncia abrunebs aris void* tipis, HBRUSH gardaqmnis mas HBRUSH tipad
    wndClass2.cbClsExtra = 0;                                                                                                          //count byte class extra     extra memory, ramdeni adgilia darchenili WNDCLASS klasis struqturis boloshi ro gava, ramdeni byte sheudzlia kide ro gamoyos. am shemtxvevashi veubnebit ro 0, ro ar gamogviyos araferi damatebit.
    wndClass2.cbWndExtra = 0;                                                                                                          //extra memory aris esec, mara windowsis struqtura ro gava boloshi, mas shemdeg
    wndClass2.hIcon = NULL;                                                                                                            //LoadIcon(NULL, IDI_APPLICATION);                                                                                   //0 imitoa, ro chven gvinda sistemis iconi, da ara aplikaciis. meore parametria tu ra tipis iconi gvinda. aplikaciis
    wndClass2.hCursor = LoadCursor(NULL, IDC_ARROW);                                                                                   //rogori kursori gvinda
    wndClass2.style = CS_HREDRAW | CS_VREDRAW;                                                                                         //es nishnavs, rom tu fanjara gavwelet, wayves ferebi horizontaluradac da vertikaluradac, an tu vamodzravebt fanjaras, unda wayves ferebic
    wndClass2.lpfnWndProc = ChildWndProc;
//-------------------------------------------------------------------------------------


//-----------------Register_Classes----------------------------------------------------
    if (RegisterClass(&wndClass) == 0)                                                                                                 //aq rasac vaketebt, aris is, rom ramshi vqmnit struqturas
    {
        MessageBox(NULL, TEXT("Error Registering Window Class"), TEXT("Error"), MB_OK | MB_ICONERROR);                                 //in case anything bad happens, gives us an error
    }

    if (RegisterClass(&wndClass2) == 0)                                                                                                //aq rasac vaketebt, aris is, rom ramshi vqmnit struqturas
    {
        MessageBox(NULL, TEXT("Error Registering Window Class 2"), TEXT("Error"), MB_OK | MB_ICONERROR);                               //in case anything bad happens, gives us an error
    }
//-------------------------------------------------------------------------------------


//------------------Create_Main_Window-------------------------------------------------
    HWND hMainWindow = NULL;                                                                                                          //integer value, ar aris pointeri, handle, igive key, misamarti, addressi
    hMainWindow = CreateWindow(TEXT("MY_CLASS_WINDOW"),                                                                               //iqmneba window da aseve queue, sadac mesijebi iyreba
                               TEXT("My Program - Main Window"),                                                                                        //title of our program
                               WS_OVERLAPPEDWINDOW,
                               200,                                                                                                   //location x
                               200,                                                                                                   //location y
                               400,                                                                                                   //width
                               400,                                                                                                   //height
                               NULL,
                               NULL,                                                                                                  //menu
                               hInstance,                                                                                             //handle of an instance
                               NULL);
//-------------------------------------------------------------------------------------


    ShowWindow(hMainWindow, nCmdShow);
    UpdateWindow(hMainWindow);

    MSG msg;
    BOOL returnValue;


 //---------------Get_Messages------------------------------------------------------------------------------                         //int
    while ((returnValue = GetMessage(&msg, NULL, 0, 0)) != 0)                                                                        //tu 0--ia damtavrdes,, tu -1, daaeroros, tu metia 0 ze kargia mashin                                                                                        //NULL aris handle fanjris, amshemtxvevashi 0 aris imitom, rom yvela fanjris mesijebi gvinda romelic chven aplikacias ekutvnis                                                                            //0 aris quit message. anu tu quit message ar miviget, programa gaagrdzelebs mushaobs, tuarada, daabrunebs 0 s da shewydeba
    {
        if (returnValue == -1)
        {
            MessageBox(NULL, TEXT("Error creating application"), TEXT("Error..."), MB_OK | MB_ICONERROR);
            return 0;
        }
        else
        {
      //      printf("Message Loop == Message: %u\n", msg.message);
            DispatchMessage(&msg);                                                                                                  //dabrunebuli messages handle, anu addressi, tviton texti,  wparam da lparametri gadaecema wndprocs
        }
    }
//----------------------------------------------------------------------------------------------------------
    return 0;
}

//===========================END_WINAPI_WINMAIN============================================================






LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)                                                //argumentebis gadacema xdeba marjvnidan marcxniv, anu stackshi jer chaiwereba lparam, mere wparam, mere mesiji, mere hWnd
{

//--------------------------------------------------------------------------------------------------------
  //  printf("Message Parent Procedure: %u\n", Message);
    static HMENU hMainMenu;
    static HMENU hSubMenu;
    static HWND hChildWindow1;                                                                                                     //Handle of childwindow1
    static HWND hChildWindow2;                                                                                                     //Handle of childwindow2

    int intHorizontalPosition;
    int intVerticalPosition;
    int intMessageReturnValue;

    static int d = 5;
    static int e = 4;

//---------------------------------------------------------------------------------------------------------

    switch (Message)
    {
//---------------------------------------------------------------------------------------------------------
    case WM_CREATE:
        hMainMenu = GetMenu(hWnd);
        hSubMenu = GetSubMenu(hMainMenu, 0);

        hChildWindow1 = CreateWindow(TEXT("MY_CLASS_WINDOW_2"),                                                                     //window for buttons
                                     TEXT("My Program - Mainc Window"),
                                     WS_CHILDWINDOW | WS_VISIBLE,
                                     10,
                                     10,
                                     365,
                                     50,
                                     hWnd,
                                     NULL,
                                     GetModuleHandle(NULL),
                                     NULL);
//------------------------------------------------------------------------

//------------------------------------------------------------------------
        hChildWindow2 = CreateWindow(TEXT("MY_CLASS_WINDOW_2"),                                                                     //window for result
                                     TEXT("My Program - Main Window"),
                                     WS_CHILDWINDOW | WS_VISIBLE,
                                     10,
                                     70,
                                     365,
                                     265,
                                     hWnd,
                                     NULL,
                                     GetModuleHandle(NULL),
                                     &e);
//-----------------------------------------------------------------------
        return 0;
        break;

//-----------------------------------------------------------------------------------------------------------
 case WM_COMMAND:
   //  printf("WM_COMMAND message received\n");
        switch (LOWORD(wParam))
        {
        case 101:
            printf("exit button is clicked ");
            break;

        }
//-----------------------------------------------------------------------------------------------------------
        return 0;
        break;

//-----------------------------------------------------------------------------------------------------------
    case WM_CONTEXTMENU:
        intHorizontalPosition = LOWORD(lParam);
        intVerticalPosition = HIWORD(lParam);
        TrackPopupMenu(hSubMenu, TPM_LEFTALIGN, intHorizontalPosition, intVerticalPosition, 0, hWnd, NULL);
        return 0;
        break;
//-----------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------
    case WM_CLOSE:
        intMessageReturnValue=MessageBox(hWnd,TEXT("Are you sure you want to exit the \napplication?"),TEXT("Information..."), MB_YESNO | MB_ICONQUESTION);
        if (intMessageReturnValue == IDYES)
        {
            DestroyWindow(hWnd);
        }
        return 0;
        break;
//-----------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        break;
//-----------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------
    case WM_SETCURSOR:
        if (((HWND)wParam) == hChildWindow1)                                                                                             //tu childwindowzea kursori
        {
      //      printf("====Child Window===\n");
       //     SetCursor(LoadCursor(NULL, IDC_HELP));                                                                                     //help daexatos kursors
        }
        else                                                                                                                             //tu arari childwindowze kursori
        {
            switch (LOWORD(lParam))
            {
            case HTRIGHT:                                                                                                               //right border tugvinda chavamatebt rastan mitanaze rogori gaxdes kursori
                SetCursor(LoadCursor(NULL, IDC_HAND));                                                                                  //size west east
                break;
            case HTSYSMENU:                                                                                                             //help icon
                SetCursor(LoadCursor(NULL, IDC_HELP));
                break;
            case HTCLOSE:                                                                                                               //close icon
                SetCursor(LoadCursor(NULL, IDC_HAND));
                break;
            case HTMAXBUTTON:
                SetCursor(LoadCursor(NULL, IDC_HAND));                                                                                  //cursor is hand shaped
                break;
            case HTMINBUTTON:
                SetCursor(LoadCursor(NULL, IDC_HAND));
                break;
            default:
                SetCursor(LoadCursor(NULL, IDC_ARROW));
            }
        }
        return TRUE;
//-----------------------------------------------------------------------------------------------------------
    default:

        return DefWindowProc(hWnd, Message, wParam, lParam);
    }
}

//==================End_Callback_Main_Window_Procedure=============================================================================





//=================================================================================================================================

//=============================================Callback_ChildWindow_Procedure======================================================
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{


//-----------------------------------------------------------------------------------------
  //  printf("Message Child Procedure: %u\n", Message);
    static int* a=0;
    static int c=0;
    static int i =0;
    int b=0;

    PAINTSTRUCT ps;
    HDC hDC;
    static HWND hStaticControl  = NULL;
    static HWND hStaticControl2 = NULL;
    static HWND hStaticControl3 = NULL;
    static HWND hStaticControl4 = NULL;
    static HWND hStaticControl5 = NULL;
    static HWND hStaticControl6 = NULL;
    static HWND hStaticControl7 = NULL;
    static HWND hStaticControl8 = NULL;
    static HWND hStaticControl9 = NULL;
    static HWND hStaticControl10= NULL;
    static HWND hStaticControl11= NULL;
    static HWND hStaticControl12= NULL;
    static HWND hStaticControl13= NULL;
    static HWND hStaticControl14= NULL;
    static HWND hStaticControl15= NULL;
    static HWND hStaticControl16= NULL;
    static HWND hStaticControl17= NULL;
    static HWND hStaticControl18= NULL;
    static HWND hStaticControl19= NULL;
    static HWND hStaticControl20= NULL;


//----------------------------------------------------------------------------------------

    switch (Message)
    {
//----------------------------------------------------------------------------
case WM_CREATE:

    a=(int*)(((LPCREATESTRUCTA)lParam)->lpCreateParams);
    if(a!=NULL)
    {
      c=*a;
    }
    if(c==4)
    {

        hStaticControl = CreateWindow(TEXT("BUTTON"),
    TEXT("1"),
    WS_CHILDWINDOW| WS_VISIBLE | BS_DEFPUSHBUTTON,
    10,
    11,
    85,
    35,
    hWnd,
    (HMENU)120,
    GetModuleHandle(NULL),
    NULL);



    hStaticControl2 = CreateWindow(TEXT("BUTTON"),
    TEXT("2"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    97,
    11,
    85,
    35,
    hWnd,
    (HMENU)121,
    GetModuleHandle(NULL),
    NULL);



    hStaticControl3 = CreateWindow(TEXT("BUTTON"),
    TEXT("3"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    184,
    11,
    85,
    35,
    hWnd,
    (HMENU)122,
    GetModuleHandle(NULL),
    NULL);


    hStaticControl4 = CreateWindow(TEXT("BUTTON"),
    TEXT("4"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    271,
    11,
    85,
    35,
    hWnd,
    (HMENU)123,
    GetModuleHandle(NULL),
    NULL);


    hStaticControl5 = CreateWindow(TEXT("BUTTON"),
    TEXT("5"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    10,
    50,
    85,
    35,
    hWnd,
    (HMENU)124,
    GetModuleHandle(NULL),
    NULL);

       hStaticControl6 = CreateWindow(TEXT("BUTTON"),
    TEXT("6"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    97,
    50,
    85,
    35,
    hWnd,
    (HMENU)125,
    GetModuleHandle(NULL),
    NULL);

    hStaticControl7 = CreateWindow(TEXT("BUTTON"),
    TEXT("7"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    184,
    50,
    85,
    35,
    hWnd,
    (HMENU)126,
    GetModuleHandle(NULL),
    NULL);

    hStaticControl8 = CreateWindow(TEXT("BUTTON"),
    TEXT("8"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    271,
    50,
    85,
    35,
    hWnd,
    (HMENU)127,
    GetModuleHandle(NULL),
    NULL);

     hStaticControl9 = CreateWindow(TEXT("BUTTON"),
    TEXT("9"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    10,
    88,
    85,
    35,
    hWnd,
    (HMENU)128,
    GetModuleHandle(NULL),
    NULL);

     hStaticControl10 = CreateWindow(TEXT("BUTTON"),
    TEXT("0"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    97,
    88,
    85,
    35,
    hWnd,
    (HMENU)129,
    GetModuleHandle(NULL),
    NULL);

     hStaticControl11 = CreateWindow(TEXT("BUTTON"),
    TEXT("."),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    184,
    88,
    85,
    35,
    hWnd,
    (HMENU)130,
    GetModuleHandle(NULL),
    NULL);

    hStaticControl12 = CreateWindow(TEXT("BUTTON"),
    TEXT("C"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    271,
    88,
    85,
    35,
    hWnd,
    (HMENU)131,
    GetModuleHandle(NULL),
    NULL);

         hStaticControl13 = CreateWindow(TEXT("BUTTON"),
    TEXT("+"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    10,
    127,
    85,
    35,
    hWnd,
    (HMENU)132,
    GetModuleHandle(NULL),
    NULL);

     hStaticControl14 = CreateWindow(TEXT("BUTTON"),
    TEXT("-"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    97,
    127,
    85,
    35,
    hWnd,
    (HMENU)133,
    GetModuleHandle(NULL),
    NULL);

     hStaticControl15 = CreateWindow(TEXT("BUTTON"),
    TEXT("x"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    184,
    127,
    85,
    35,
    hWnd,
    (HMENU)134,
    GetModuleHandle(NULL),
    NULL);

    hStaticControl16 = CreateWindow(TEXT("BUTTON"),
    TEXT("/"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    271,
    127,
    85,
    35,
    hWnd,
    (HMENU)135,
    GetModuleHandle(NULL),
    NULL);


          hStaticControl17 = CreateWindow(TEXT("BUTTON"),
    TEXT("="),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    10,
    165,
    85,
    35,
    hWnd,
    (HMENU)136,
    GetModuleHandle(NULL),
    NULL);

     hStaticControl18 = CreateWindow(TEXT("BUTTON"),
    TEXT("%"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    97,
    165,
    85,
    35,
    hWnd,
    (HMENU)137,
    GetModuleHandle(NULL),
    NULL);

     hStaticControl19 = CreateWindow(TEXT("BUTTON"),
    TEXT("hex"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    184,
    165,
    85,
    35,
    hWnd,
    (HMENU)138,
    GetModuleHandle(NULL),
    NULL);

    hStaticControl20 = CreateWindow(TEXT("BUTTON"),
    TEXT("bin"),
    WS_CHILDWINDOW | WS_VISIBLE | BS_DEFPUSHBUTTON,
    271,
    165,
    85,
    35,
    hWnd,
    (HMENU)139,
    GetModuleHandle(NULL),
    NULL);
//---------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------
 case WM_COMMAND:
     if(Var==0)     //shemodis marto ertxel
     {
        Buf=(char*)malloc(sz);
        memset(Buf, '\0', sz);
        Buf[sz+1]='\0';
        Buf1=(char*)malloc(Counter);
        memset(Buf1, '\0', Counter);
        Buf1[Counter+1]='\0';
        Buf2=(char*)malloc(Counter-tempCount);
        memset(Buf2, '\0', Counter-tempCount);
        Buf2[(Counter-tempCount)+1]='\0';
     }
  Var=1;
  Var2++;   //es cvladi damchirda null terminaciis sworad gamosayeneblad
   printf("WM_COMMAND message received\n");

        switch (LOWORD(wParam))
        {

             case 120:
            printf("1 button is clicked ");
            Buf[Counter]='1';

            break;


             case 121:
            printf("2 button is clicked ");
            Buf[Counter]='2';
            break;


              case 122:
            printf("3 button is clicked ");
            Buf[Counter]='3';
            break;


             case 123:
            printf("4 button is clicked ");
            Buf[Counter]='4';
            break;


              case 124:
            printf("5 button is clicked ");
            Buf[Counter]='5';
            break;


               case 125:
            printf("6 button is clicked ");
            Buf[Counter]='6';
            break;

             case 126:
            printf("7 button is clicked ");
           Buf[Counter]='7';
            break;

              case 127:
            printf("8 button is clicked ");
           Buf[Counter]='8';
            break;

             case 128:
            printf("9 button is clicked ");
           Buf[Counter]='9';
            break;

              case 129:
            printf("0 button is clicked ");
           Buf[Counter]='0';
            break;

              case 130:
            printf(". button is clicked ");
            Buf[Counter]='.';
            break;

              case 131:
            printf("C button is clicked ");
            Buf[Counter]='C';
            break;

               case 132:
            k = 1;
            printf("+ button is clicked\n");
            Buf[Counter]='+';
            Operand1(Buf,Counter);

      break;

             case 133:
                 k=2;
            printf("- button is clicked ");
            Buf[Counter]='-';
               Operand1(Buf,Counter);
            break;

              case 134:
                  k=3;
            printf("x button is clicked ");
            Buf[Counter]='x';
               Operand1(Buf,Counter);
            break;

             case 135:
                 k=4;
            printf("/ button is clicked ");

            Buf[Counter]='/';
               Operand1(Buf,Counter);
            break;

              case 136:
            printf("= button is clicked ");
            Buf[Counter]='=';
           Operand2(Buf,tempCount,Counter);
            break;

              case 137:
            printf("% button is clicked ");
            Buf[Counter]='%';
            break;

              case 138:
            printf("hex button is clicked ");
            break;

            case 139:
            printf("bin button is clicked ");
            break;
//-------------------------------------------------------------------------------------------------------------

        }


        printf("\nCounter = %d\n",Counter);

        printf("Buffer char 1:%c\n",Buf[0]);
        printf("Buffer char 2:%c\n",Buf[1]);
        printf("Buffer char 3:%c\n",Buf[2]);
        printf("Buffer char 4:%c\n",Buf[3]);
        printf("Buffer char 5:%c\n",Buf[4]);

        printf("Buffer String : %s\n",Buf);


//---------------------------------------------------------------------------

                if(EqualClicked==1)

                 {
                    if (k==1 || k==2 || k==3 || k==4)
                    {
                    Counter++;
                    Buf[Counter]='\0';
                        switch(k)
                        {
                        case Addition:
                            Add_Res = Add(Op1, Op2);
                            printf("Addition Result: %d\n", Add_Res);
                            break;
                        case Subtraction:
                            Sub_Res = Sub(Op1, Op2);
                            printf("Subtraction Result: %d\n", Sub_Res);
                            break;
                        case Multiplication:
                             Mul_Res = Mul(Op1, Op2);
                            printf("Multiplication Result: %d\n", Mul_Res);
                            break;
                        case Division:
                            Div(Op1,Op2);
                            break;
                        }
                        memset(Buf,0,sz);
                    }

                }
                else
                    {
                        if(Var2>1)
                        {
                             Counter++;
                             Buf[Counter]='\0';
                        }
                    }
//---------------------------------------------------------------------------
        return 0;
        break;
    }
    return 0;

//-------------------------------------------------------------------------------------------------------------
    default:
        return DefWindowProc(hWnd, Message, wParam, lParam);
    }
}




//------Function_Is_Called_When_'+'_'-'_x'_'-'_Is_Clicked-----------------------------------------------------
void Operand1(char *Buf, int Counter)
{
   for(int i =0; i<Counter;i++)
      {
          Buf1[i]=Buf[i];
      }
    Buf1[Counter]='\0';
    printf("Buffer 1 : %s\n",Buf1);
    Op1=atoi(Buf1);
  tempCount=strlen(Buf1)+1;      //for the index where + was clicked

  printf("Operand 1: %d",Op1);


   Buf1Length = strlen(Buf1);
 Op1Length = floor(log10(abs(Op1))) + 1; // Calculate the number of digits in Op2

// Check if the lengths match
if (Buf1Length != Op1Length)
    {
    printf("Error: Number exceeds maximum value of 2147483647\n");
    }
else
    {
    // Compare each digit of Buf2 with Op2
     validNumber1 = 1; // Assume the number is valid initially

    for (int i = 0; i < Buf1Length; i++)
        {
        // Convert Buf2[i] to its decimal value
         digitBuf1 = Buf1[i] - '0'; // Subtract '0'==48 to convert from ASCII to decimal

        // Get the corresponding digit of Op2
         digitOp1 = (Op1 / (int)pow(10, Buf1Length - i - 1)) % 10;

        // Compare the digits
        if (digitBuf1 != digitOp1) {
            validNumber1 = 0;

        }
    }

    if (validNumber1 && Op1 >= 0)
        {
        printf("Operand 1: %d\n", Op1);
        }

     else
    {
        printf("Error: Number exceeds maximum value of 2147483647\n");
    }
}
free(Buf1);
}
//---------------------------------------------------------------------------------------------



//-----------Function_Is_Called_When_'='_is_Clicked--------------------------------------------
void Operand2(char *Buf, int tempCount, int Count)
{
    EqualClicked=1;
 printf("tempCount : %d\n",tempCount);
            printf("Counter-tempCount : %d\n",Counter-tempCount);
            for(int i =0; i<(Counter-tempCount); i++)
            {
               Buf2[i]=Buf[tempCount+i];
            }
            Buf2[Counter-tempCount]='\0';
            printf("Buffer 2 : %s\n",Buf2);

            Op2=atoi(Buf2);

// Calculate the length of Buf2 and Op2
 Buf2Length = strlen(Buf2);
 Op2Length = floor(log10(abs(Op2))) + 1; // Calculate the number of digits in Op2

// Check if the lengths match
if (Buf2Length != Op2Length)
    {
    printf("Error: Number exceeds maximum value of 2147483647\n");
}
else
    {
    // Compare each digit of Buf2 with Op2
     validNumber2 = 1; // Assume the number is valid initially

    for (int i = 0; i < Buf2Length; i++)
    {
        // Convert Buf2[i] to its decimal value
         digitBuf2 = Buf2[i] - '0'; // Subtract '0' to convert from ASCII to decimal

        // Get the corresponding digit of Op2
         digitOp2 = (Op2 / (int)pow(10, Buf2Length - i - 1)) % 10;

        // Compare the digits
        if (digitBuf2 != digitOp2) {
            validNumber2 = 0;

        }
    }

    if (validNumber2 && Op2 >= 0) {
        printf("Operand 2: %d\n", Op2);
    } else {
        printf("Error: Number exceeds maximum value of 2147483647\n");
    }
  }
  free(Buf2);
}
//--------------------------------------------------------------------------------------------------




int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

void Div(int x, int y)
{

    if (y == 0)
    {
        printf("Error, Cannot Divide By Zero \n");
    }
    else
    {
        int result = x / y;
        int Reminder = x % y;
        printf("Result is : %d\n ", result);
        printf("\n Reminder is : %d\n", Reminder);
    }

}

void BinToDec(char x[40])
{
    unsigned int res = 0;
    int A = 0;
    int size = strlen(x);
    for (int i = 0; i < size; i++)
    {
        if (x[i] != 48 && x[i] != 49)			//48 is the decimal value of character 0, 49 is decimal value of character 1
        {
            A = 0;
        }

        else
        {
            A = 1;
        }
    }
    if (A == 0)
    {
        printf("Error, Binary Number Must Contain 0 or 1");
    }
    else if (A == 1)
    {
        int n = 0;
        while (size > 0)
        {
            res += (x[size - 1] - 48) * (pow(2, n));
            size--;
            n++;
        }
        printf("decimal value is : %d", res);

    }

}































//mousemove 512
//non clineent hit test 132 NIC
//Set cursor 32
//WM_NICHITTEST what part of the window corresponds to a particular screen coodrinate. rome windowshia mausi

//when mouse is on client area, messages are 512 - mouse move, 32 - set cursor, 132 - non client hit test determines in which area is mouse on
//mousemove gvadzlevs koordinatebs zemota marcxena kutxe aqvs 0;0 ad agebuli, client areasi
//roca mousi gamodzravda Client areashi chveni fanjris.
//1. sistema chaagdebs WM_MOUSEMOVE mesijs Post Message Queueshi (512)
//2.while(GetMessage(&msg, NULL,0,0)!=0 {dispatch(&msg} es shesruldeba da msg struqturashi chaiwereba 512
//3.DispatchMessage(&msg) daudzaxebs WndProc(hwnd w, uint u, wparam w, lparam l)-s, tu RESULT CALLBACKSHI mousemovi gviweria xokai, tuarada defwindowProc chvenmagivrad daamushavebs mesijs
//4.mere sistema gagzavnis WM_NCHITTEST s window procedureshi, tu vamushavebt mand monacems hokai, tuarada sistema defwindowproc daamushavebs da ecodineba mousis koordinatebi
//5.sistema gamogzavnis WM_SETCURSOR brdzanebas, rodesac mousi gamodzravdeba fanjris shignit

























































































