#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <time.h>

#define error(message) { printf(message "\n"); fflush(stdout); system("pause"); exit(-1); }

#define MID_FILE_PATH "music.wav"
#define LYRIC_FILE_PATH "lyric.lrc"

#define FRAME_WIDTH 120
#define FRAME_HEIGHT 30
#define CHARACTER "#"   // 在控制台用来显示图片的字符

#pragma pack(1)

typedef struct {
    unsigned char B, G, R;
} Pixel, ColorBGR;

typedef struct {
    int time;
    char lyric[100];
    char translation[100];
} LyricLine;

char strBuffer[(FRAME_WIDTH + 1) * (FRAME_HEIGHT + 1) * 24];
HANDLE hConsole;
LyricLine* lyrics;
int lyricLineNums;

BOOLEAN enableVTMode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return FALSE;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
        return FALSE;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
        return FALSE;
    return TRUE;
}

BOOLEAN playMusic(const char* filePath) {
    HANDLE module = LoadLibraryA("winmm.dll");

    typedef MCIERROR(WINAPI* MciSendStringT)(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);

    MciSendStringT func_mciSendStringA = (MciSendStringT)GetProcAddress((HMODULE)module, "mciSendStringA");
    if (func_mciSendStringA == NULL)
        return FALSE;

    char buff[255], command[100];
    sprintf_s(command, 100, "open %s alias playsound_134", filePath);
    func_mciSendStringA(command, buff, 254, NULL);
    sprintf_s(command, 100, "set playsound_134 time format milliseconds");
    func_mciSendStringA(command, buff, 254, NULL);
    sprintf_s(command, 100, "status playsound_134 length");
    func_mciSendStringA(command, buff, 254, NULL);
    sprintf_s(command, 100, "play playsound_134 from 0 to %s", buff);
    func_mciSendStringA(command, buff, 254, NULL);
    return TRUE;
}

// 读取歌词文件数据
BOOLEAN readLyricFile(const char* filePath, LyricLine** lyrics, int* lineNums) {
    FILE* fp;
    fopen_s(&fp, filePath, "r");

    if (!fp)
        error("打开歌词文件失败！");

    char line[200], lyric[100], translation[100];
    int minutes, seconds, milliseconds;
    int size = 10, i = 0;

    LyricLine* _lyrics = (LyricLine*)malloc(sizeof(LyricLine) * size);

    while (fgets(line, 200, fp)) {
        if (sscanf_s(line, "[%02d:%02d.%03d]%[^(] (%[^)])", &minutes, &seconds, &milliseconds, lyric, 100, translation, 100) == 5) {
            if (i == size) {
                size += 10;
                _lyrics = (LyricLine*)realloc(_lyrics, sizeof(LyricLine) * size);
            }

            _lyrics[i].time = minutes * 60000 + seconds * 1000 + milliseconds;
            strcpy_s(_lyrics[i].lyric, 100, lyric);
            strcpy_s(_lyrics[i].translation, 100, translation);
            i += 1;
        }
    }

    *lyrics = _lyrics;
    *lineNums = i;

    fclose(fp);
    return TRUE;
}

// 播放歌词
void playLyrics(LyricLine* lyrics, int lineNums) {

    clock_t startTime = clock();
    for (int i = 0; i < lineNums; ++i) {

        while (clock() < lyrics[i].time + startTime) {
            Sleep(100);
        }

        int bufferIndex = 0;
        COORD coord;
        coord.X = 0;
        coord.Y = 0;
        SetConsoleCursorPosition(hConsole, coord);

        int j = i - 4, end = i + 4;
        ColorBGR color;
        color.B = 243;
        color.G = 156;
        color.R = 131;

        if (i < 8) {
            j = 0;
            end = i + 1;
        }
        else if (i < 11) {
            j = i + i - 14;
            end = i + i - 6;
        }
        else if (i < 48) {
            j = i - 4;
            end = end < lineNums ? end : lineNums;
        }
        for (; j < end; j++) {
            if (j == i)
                bufferIndex += sprintf_s(strBuffer + bufferIndex, sizeof(strBuffer) - bufferIndex, "\033[1m\033[38;2;%d;%d;%dm%-50s\n%-50s\n\n\033[0m", color.R, color.G, color.B, lyrics[j].lyric, lyrics[j].translation);
            else
                bufferIndex += sprintf_s(strBuffer + bufferIndex, sizeof(strBuffer) - bufferIndex, "%-50s\n%-50s\n\n", lyrics[j].lyric, lyrics[j].translation);
        }

        strBuffer[bufferIndex] = '\0';
        puts(strBuffer);
        fflush(stdout);
    }
}

int main() {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.dwFontSize.Y = 16;
    wcscpy_s(cfi.FaceName, 32, L"SimHei");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    enableVTMode();

    setvbuf(stdout, NULL, _IOFBF, (FRAME_WIDTH + 1) * (FRAME_HEIGHT + 1) * 24);

    printf("\033[?25l");

    system("cls");

    readLyricFile(LYRIC_FILE_PATH, &lyrics, &lyricLineNums);
    playMusic(MID_FILE_PATH);
    playLyrics(lyrics, lyricLineNums);
    free(lyrics);
    system("pause");
    return 0;
}