#pragma once

/**
 * @file    resource.h
 * @brief   UI��Դ���棬��ͼƬ������ڴ��У���map<���ƣ�����>�ķ�ʽ�������ڴ��У���
			�������ʱ����Ҫ�ͷ�
 * @author  ksdjfdf <330773102@qq.com>
 * @date	2016-04-25
 */

#include <xstring>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;
class CxImage;

namespace HUI {

class UIResourceManager
{
public:
	~UIResourceManager();
	static UIResourceManager* GetInstance();
	static void FreeInstance();
	static UIResourceManager *cache_;

	BOOL GetImageByFilePath(const wstring &path, CxImage **image);
private:
	UIResourceManager() {}
private:
	std::map<wstring, CxImage*> image_caches_;
}; // class UIResourceManager

} // namespace HUI