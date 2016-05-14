#pragma once
#include "control.h"
#include <string>
#include <vector>

namespace HUI {

class IUIContainer
{
public:
   virtual UIControl* GetChild(int iIndex) const = 0;
   virtual int GetCount() const = 0;
   virtual bool Add(UIControl* pControl) = 0;
   virtual bool Remove(UIControl* pControl) = 0;
   virtual void RemoveAll() = 0;

}; // interface IUIContainer

class UIContainer : public UIControl, IUIContainer
{
public:
	UIContainer();
	~UIContainer() {}

	UIControl* LookupMouseFocusedControl(const UIPoint &point);

	// ��д���㲼�ֵķ���
	void DoLayout(const UIRect &rect);

	// ��д���Ʒ���
	void Render(const UIRect *rect) final;

	UIControl* GetChild(int iIndex) const;
    int GetCount() const;
    bool Add(UIControl* pControl);
    bool Remove(UIControl* pControl);
    void RemoveAll();

protected:
	virtual void CaculateChildrenRect();
	virtual void DrawGridLine();

protected:
	std::vector<UIControl*> m_children;

}; // class UIContainer

} // namespace HUI