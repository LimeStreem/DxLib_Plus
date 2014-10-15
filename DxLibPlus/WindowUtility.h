#pragma once
class WindowUtility
{
private:
	WindowUtility();
	~WindowUtility();
public:
	static void SetWindowTitle(std::string title);
	static void SetWindowMode(bool isWindowed);
	static std::string GetWindowTitle();
	static bool GetWindowMode();
};

