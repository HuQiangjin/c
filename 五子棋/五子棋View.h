
// ������View.h : C������View ��Ľӿ�
//

#pragma once
#include <vector>
class C������View : public CView
{   int chessArr[20][20];
	std::vector<CPoint>chessVec;
	bool isLocation(CPoint cp);
	void Location(CPoint cp);
	bool isWin(CPoint cp);
protected: // �������л�����
	C������View();
	DECLARE_DYNCREATE(C������View)
int RightORLeft;
// ����
public:
	C������Doc* GetDocument() const;
	void checkerboard(CDC*pDC);
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
			
	
};

#ifndef _DEBUG  // ������View.cpp �еĵ��԰汾
inline C������Doc* C������View::GetDocument() const
   { return reinterpret_cast<C������Doc*>(m_pDocument); }
#endif

