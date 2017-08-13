
// 五子棋View.h : C五子棋View 类的接口
//

#pragma once
#include <vector>
class C五子棋View : public CView
{   int chessArr[20][20];
	std::vector<CPoint>chessVec;
	bool isLocation(CPoint cp);
	void Location(CPoint cp);
	bool isWin(CPoint cp);
protected: // 仅从序列化创建
	C五子棋View();
	DECLARE_DYNCREATE(C五子棋View)
int RightORLeft;
// 特性
public:
	C五子棋Doc* GetDocument() const;
	void checkerboard(CDC*pDC);
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C五子棋View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
			
	
};

#ifndef _DEBUG  // 五子棋View.cpp 中的调试版本
inline C五子棋Doc* C五子棋View::GetDocument() const
   { return reinterpret_cast<C五子棋Doc*>(m_pDocument); }
#endif

