#pragma once

#include "container.h"
#include <cstdarg>

namespace HUI {

namespace Layout {
	
class UIGrid : public UIContainer
{
public:
	UIGrid();

	void SetRowsAndCols(int rows, int cols);
	int GetRows() const;
	int GetCols() const;

	void SetHeight(int rows, ...);
	void SetHeightScale(int rows, ...);

	void SetWidth(int cols, ...);
	void SetWidthScale(int cols, ...);

	void SetPos(UIControl *pControl, int row, int col);

	void ShowGridLine(bool showGridLine);

	// ��д���㲼�ַ���
	void DoLayout(const UIRect &rect);

	// ��д�Ի�
	void RenderSelf(const UIRect *rect);

protected:
	// �����Ӿ���
	void CaculateChildrenRect();
	// ����������
	void DrawGridLine();
private:
	int m_iRows; // ����
	int m_iCols; // ����
	bool m_bShowGridLine;

	// Grid��������
	vector<float> m_vHeight;
	vector<float> m_vWidth;
	vector<float> m_vHeightScale;
	vector<float> m_vWidthScale;

	vector<vector<UIControl*>> m_pvChildren;
	vector<vector<UIRect*>> m_pvChildrenRect;
}; // class Grid

}// namespace Layout

} // namespace HUI