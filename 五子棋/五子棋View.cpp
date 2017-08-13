
// ������View.cpp : C������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������.h"
#endif

#include "������Doc.h"
#include "������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������View

IMPLEMENT_DYNCREATE(C������View, CView)

BEGIN_MESSAGE_MAP(C������View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C������View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C������View ����/����

C������View::C������View()
{
	RightORLeft=0;
	for (int i=0;i<20;i++)
	{
		for (int j=0;j<20;j++)
		{
			chessArr[i][j]=0;
		}
	}


	// TODO: �ڴ˴���ӹ������

}

C������View::~C������View()
{
}
bool C������View::isWin(CPoint cp)
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


BOOL C������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}
void C������View::checkerboard(CDC*pDC)
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

// C������View ����

void C������View::OnDraw(CDC* pDC)
{
	C������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	checkerboard(pDC);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������View ��ӡ


void C������View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}
bool C������View::isLocation(CPoint cp)
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
void C������View::Location(CPoint cp)
{
	chessVec.push_back(cp);
}

BOOL C������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C������View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C������View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C������View ���

#ifdef _DEBUG
void C������View::AssertValid() const
{
	CView::AssertValid();
}

void C������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������Doc* C������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������Doc)));
	return (C������Doc*)m_pDocument;
}
#endif //_DEBUG


// C������View ��Ϣ�������


void C������View::OnLButtonDown(UINT nFlags, CPoint point)
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
									 MessageBox("�ڷ�ʤ");
								 }
								 RightORLeft++;
							 }
						 }
					 }
	}
	CView::OnLButtonDown(nFlags, point);
}


void C������View::OnRButtonDown(UINT nFlags, CPoint point)
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
						MessageBox("�׷�ʤ");
					}
						RightORLeft--;
				}
			}
		}
	
	}

	CView::OnRButtonDown(nFlags, point);
}
