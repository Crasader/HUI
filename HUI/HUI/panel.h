#pragma once
#include "container.h"

namespace HUI {
namespace Layout {

class UIStackPanel : public UIContainer
{
public:
	UIStackPanel();

	void SetOrientation(Orientation orientation);

	// �����ڱ߾�
	void SetPadding(int left, int top, int right, int bottom);
	void SetPadding(const UIPadding &padding);

	// ��д���㲼��
	void DoLayout(const UIRect &rect);

	// ��д�Ի淽��
	void RenderSelf(const UIRect *rect);

protected:
	void CaculateChildrenRect();
	void DrawGridLine();
private:
	Orientation m_orientation;
	UIPadding m_padding;
	vector<UIRect> m_vChildrenRect;
}; // class StackPanel

} // namespace Layout
} // namespace HUI