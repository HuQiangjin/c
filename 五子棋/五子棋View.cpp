
// 五子棋View.cpp : C五子棋View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "五子棋.h"
#endif

#include "五子棋Doc.h"
#include "五子棋View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C五子棋View

IMPLEMENT_DYNCREATE(C五子棋View, CView)

BEGIN_MESSAGE_MAP(C五子棋View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C五子棋View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C五子棋View 构造/析构

C五子棋View::C五子棋View()
{
	RightORLeft=0;
	for (int i=0;i<20;i++)
	{
		for (int j=0;j<20;j++)
		{
			chessArr[i][j]=0;
		}
	}


	// TODO: 在此处添加构造代码

}

C五子棋View::~C五子棋View()
{
}
bool C五子棋View::isWin(CPoint cp)
{
	int cp_x=cp.x/50;
	int cp_y=cp.y/50;
	int i=cp_x;
	int j=cp_y;
	int count=1;
	int nowChessColor=chessArr[cp_x][cp_y];
	while(1)
	{
		if (i>0&&i<20)
		{
			i--;
			if (nowChessColor==chessArr[i][j])
			{
				count++;
				if (count==5)
				{
					return true;
				}
			}
			else
			{
				break;
	
			}
		}
	else
	{
		break;
		}
	}
i=cp_x;
while(1)
{
	if (i>0&&i<20)
	{
		i++;
		if (nowChessColor==chessArr[i][j])
		{
			count++;
			if (count=5)
			{
				return true;
			}

		}
		else
		{
			break;
		}
	}
	else
	{
		break;
	}
}
   i=cp_x;
   count=1;

 while(1)
{
	if (j>0&&j<20)
	{
		j--;
		if (nowChessColor==chessArr[i][j])
		{
			count++;
			if (count==5)
			{
				return true;
			}
		}
		else
		{
			break;

		}
	}
	else
	{
		break;
	}
}
	j=cp_y;
	while(1)
	{
		if (j>0&&j<20)
		{
			j++;
			if (nowChessColor==chessArr[i][j])
			{
				count++;
				if (count==5)
				{
					return true;
				}
			}
			else
			{
				break;

			}
		}
		else
		{
			break;
	
		}
	}
	j=cp_y;
	count=1;
	while(1)
	{
		if (j>0 && j < 20 && i >0&& i<20)
		{
			j++;
			i++;
			if (nowChessColor==chessArr[i][j])
			{
				count++;
				if (count==5)
				{
					return true;
				}
			}
			else
			{
				break;

			}
		}
		else
		{
			break;
		}
  }
         j=cp_y;
		 i=cp_x;
		 
		 while (1)
		 {
			 if (j>0&&j<20&&i>0&&i<20)
			 {
				 j--;
				 i--;
				 if (nowChessColor==chessArr[i][j])
				 {
					 count++;
					 if (count==5)
					 {
						 return true;
					 }
				 }
				 else
				 {
					 break;

				 }
			 }
			 else
			 {
				 break;
			 }
			 }
		 j=cp_y;
		 i=cp_x;
		 count=1;
		 while(1)
		 {
			 if (j>0&&j<20&&i>0&&i<20)
			 {
				 j++;
				 i--;
				 if (nowChessColor==chessArr[i][j])
				 {
					 count++;
					 if (count==5)
					 {
						 return true;
					 }
				 }
				 else
				 {
					 break;

				 }
			 }
			 else
			 {
				 break;
			 }
			 }
		 j=cp_y;
		 i=cp_x;
		 while(1)
		 {
			 if (j>0&&j<20&&i>0&&i<20)
			 {
				 j--;
				 i++;
				 if (nowChessColor==chessArr[i][j])
				 {
					 count++;
					 if (count==5)
					 {
						 return true;
					 }
				 }
				 else
				 {
					 break;

				 }
			 }
			 else
			 {
				 break;
			 }
			 }
		 return false;
		 }


BOOL C五子棋View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}
void C五子棋View::checkerboard(CDC*pDC)
{
	for(int i=0;i<20;i++)
	{
		pDC->MoveTo(i*50,0);
		pDC->LineTo(i*50,1000);
	}
	for (int i=0;i<20;i++)
	{
		pDC->MoveTo(0,i*50);
		pDC->LineTo(1000,i*50);
	}
}

// C五子棋View 绘制

void C五子棋View::OnDraw(CDC* pDC)
{
	C五子棋Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	checkerboard(pDC);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C五子棋View 打印


void C五子棋View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}
bool C五子棋View::isLocation(CPoint cp)
{
	bool isLoc =true;
	for (int i=0;i<chessVec.size();i++)
	{
		if (cp.x==chessVec[i].x&&cp.y==chessVec[i].y)
		{
			isLoc=false;
		}
	}
	return isLoc;
}
void C五子棋View::Location(CPoint cp)
{
	chessVec.push_back(cp);
}

BOOL C五子棋View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C五子棋View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C五子棋View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C五子棋View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C五子棋View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C五子棋View 诊断

#ifdef _DEBUG
void C五子棋View::AssertValid() const
{
	CView::AssertValid();
}

void C五子棋View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C五子棋Doc* C五子棋View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C五子棋Doc)));
	return (C五子棋Doc*)m_pDocument;
}
#endif //_DEBUG


// C五子棋View 消息处理程序


void C五子棋View::OnLButtonDown(UINT nFlags, CPoint point)
{
	             if (RightORLeft==0)
	             {
					 CBrush*Brush=new CBrush(RGB(0,0,0));
					 CDC*pDC=this->GetDC();
					 pDC->SelectObject(Brush);
					 for(int i=0;i<1000;i+=50)
					 {
						 for (int j=0;j<1000;j+=50)
						 {
							 CRect rect(i,j,i+50,j+50);
							 CPoint tempPoint;
							 tempPoint=rect.CenterPoint();
							 if (rect.PtInRect(point)&&isLocation(tempPoint))
							 {
								 pDC->Ellipse(tempPoint.x-20,tempPoint.y-20,tempPoint.x+20,tempPoint.y+20);
							     Location(tempPoint);
								 chessArr[tempPoint.x/50][tempPoint.y/50]=1;
								 if (isWin(point))
								 {
									 MessageBox("黑方胜");
								 }
								 RightORLeft++;
							 }
						 }
					 }
	}
	CView::OnLButtonDown(nFlags, point);
}


void C五子棋View::OnRButtonDown(UINT nFlags, CPoint point)
{
	
	if (RightORLeft==1)
	{
		CBrush*Brush=new CBrush(RGB(255,255,255));
		CDC*pDC=this->GetDC();
		pDC->SelectObject(Brush);
		for (int i=0;i<1000;i+=50)
		{
			for (int j=0;j<1000;j+=50)
			{
				CRect rect(i,j,i+50,j+50);
				CPoint tempPoint;
				tempPoint=rect.CenterPoint();
				if (rect.PtInRect(point))
				{
					
					pDC->Ellipse(tempPoint.x-20,tempPoint.y-20,tempPoint.x+20,tempPoint.y+20);
					Location(tempPoint);
					chessArr[tempPoint.x/50][tempPoint.y/50]=1;
					if (isWin(point))
					{
						MessageBox("白方胜");
					}
						RightORLeft--;
				}
			}
		}
	
	}

	CView::OnRButtonDown(nFlags, point);
}
