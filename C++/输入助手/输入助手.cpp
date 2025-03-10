#include <windows.h>
#include <iostream>
#include <string>

void SendKeys(const std::string& text) {
    for (char c : text) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = 0;
        input.ki.wScan = static_cast<WORD>(c);
        input.ki.dwFlags = KEYEVENTF_UNICODE;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        // 模拟按键按下
        SendInput(1, &input, sizeof(INPUT));

        input.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

        // 模拟按键释放
        SendInput(1, &input, sizeof(INPUT));
        Sleep(10); // 稍微延迟一下，防止输入过快
    }
}

std::string GetClipboardText() {
    if (!OpenClipboard(NULL)) {
        return "";
    }

    HANDLE hData = GetClipboardData(CF_UNICODETEXT);
    if (hData == NULL) {
        CloseClipboard();
        return "";
    }

    WCHAR* pszText = static_cast<WCHAR*>(GlobalLock(hData));
    if (pszText == NULL) {
        CloseClipboard();
        return "";
    }

    std::wstring wtext(pszText);
    std::string text(wtext.begin(), wtext.end());

    GlobalUnlock(hData);
    CloseClipboard();

    return text;
}

int main() {
    std::string clipboardText = GetClipboardText();
    if (!clipboardText.empty()) {
        std::cout << "Clipboard content: " << clipboardText << std::endl;

        // 延迟10秒
        Sleep(10000);

        // 获取鼠标光标位置
        POINT cursorPos;
        if (GetCursorPos(&cursorPos)) {
            // 将鼠标光标位置设置为焦点
            SetCursorPos(cursorPos.x, cursorPos.y);
            // 模拟鼠标点击以确保焦点在正确的位置
            mouse_event(MOUSEEVENTF_LEFTDOWN, cursorPos.x, cursorPos.y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, cursorPos.x, cursorPos.y, 0, 0);

            // 发送键盘输入
            SendKeys(clipboardText);
        } else {
            std::cout << "Could not get cursor position." << std::endl;
        }
    } else {
        std::cout << "Clipboard is empty or could not be accessed." << std::endl;
    }

    return 0;
}