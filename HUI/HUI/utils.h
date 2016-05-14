/**
 * @file    utils.h
 * @brief   UI������ʩ, ��װһЩ�������ݽṹ�࣬�Լ�һЩ�����࣬���������������
 * @author  ksdjfdf <330773102@qq.com>
 * @date	2016-04-22
 */

#pragma once
#include<Windows.h>
#include<string>

namespace HUI {

class UIControl;
namespace Utils {

// ��ϵͳ�Դ���tagRect��װΪ�Լ���Rect
class UIRect : public tagRECT
{
public:
	UIRect();
	UIRect(const RECT& src);
	UIRect(int x,int y,int width,int height);

	RECT ToRect() const;
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	void Empty();
	void Join(const RECT& rc);
	void ResetOffset();
	void Normalize();
	void Offset(int cx, int cy);
	void Inflate(int cx, int cy);
	void Deflate(int cx, int cy);
	void Union(UIRect& rc);

	// ��������Դ�����ཻ�ľ��Σ���first��second��ָ�����������ཻ�ľ���
	static UIRect IntersectRect(const UIRect *first,const UIRect *second);
};


// ��ϵͳ�Դ���tagSIZE��װΪ�Լ���SIZE��
class UISize : public tagSIZE
{
public:
   UISize();
   UISize(const SIZE &src);
   UISize(const RECT &rc);
   UISize(int cx, int cy);
};


// ͬ��UIPoint
class  UIPoint : public tagPOINT
{
public:
   UIPoint();
   UIPoint(const POINT &src);
   UIPoint(int x, int y);
   UIPoint(LPARAM lParam);
};


typedef COLORREF UIColor;
typedef LOGFONT	 UIFont;

class Font : public LOGFONT 
{
public:
	void SetFontSize(int size) {
		lfHeight = size;
	}

	void SetFontFamily(LPCTSTR family) {
		wcscpy_s(lfFaceName, family);
	}
};

// ��߾�
struct UIMargin
{
	UIMargin();
	UIMargin(int left,int top = 0,int right = 0,int bottom = 0);

	int left;
	int top;
	int right;
	int bottom;
};

// �ڱ߾�
struct UIPadding
{
	UIPadding();
	UIPadding(int leftPara, int topPara, int rightPara, int bottomPara);

	int left;
	int top;
	int right;
	int bottom;
};

// �ı���λ��ʽ
enum TextAlignment
{
	TextAlignmentLeft = DT_LEFT,
	TextAlignmentCenter	= DT_CENTER,
	TextAlignmentRight = DT_RIGHT,

	TextAlignmentTop = DT_TOP,
	TextAlignmentVCenter = DT_VCENTER,
	TextAlignmentBottom	= DT_BOTTOM,
};

//��λ��ʽ
enum Alignment
{
//���Զ�λ
	AlignmentLeftTop,
	AlignmentLeftCenter,
	AlignmentLeftBottom,
	AlignmentCenterTop,
	AlignmentCenter,
	AlignmentCenterBottom,
	AlignmentRightTop,
	AlignmentRightCenter,
	AlignmentRightBottom,
//��Զ�λ
	AlignmentLeft,
	AlignmentRight,
	AlignmentTop,
	AlignmentBottom,
	AlignmentFill,
};

// ����
enum Orientation {
	OrientationHorizontal, // ˮƽ
	OrientationVertical,   // ��ֱ
};

// class UIControl;
enum UINotifyEvent
{
	EventClick,		//����¼�
	EventTextChanged,	//�ı��仯�¼�
};

// �¼�֪ͨ�ӿ�
class IUINotify
{
public:
	virtual	void Notify(UINotifyEvent event,UIControl *control) = 0;
};


// ���ߺ���
std::wstring GetAppPath();
std::wstring UTF8toUTF16(const char *src);
void GetDefaultUIFont(UIFont &font);
UIFont* GetGlobalEditFont();
void OpenURL(const wchar_t *url, int flag = SW_SHOWMAXIMIZED, BOOL use_default_browser = TRUE);

} // namespace Utils
} // namespace HUI