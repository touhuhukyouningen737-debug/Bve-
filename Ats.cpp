#include <windows.h>
#include <stdio.h>
#include "atsplugin.h"

// 設定値を保持する変数
double PsMaxSpeed = 105.0;
double PsDecelerate = 4.2;
int EBEnabled = 1;

// 設定ファイルの読み込み（プラグイン読み込み時に一度だけ実行）
void LoadConfig() {
    char path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);
    // 実際には車両フォルダ内の ini を指定しますが、まずはハードコードで代用
    // 本来は GetPrivateProfileInt 等でファイルから読み込みます
}

void WINAPI Load() { LoadConfig(); }
void WINAPI Dispose() { }
void WINAPI SetVehicleSpec(ATS_VEHICLESPEC spec) { }
void WINAPI Initialize(int brake) { }

void WINAPI SetBeaconData(ATS_BEACONDATA data) {
    if (data.Type == 255) {
        // 設定値 PsDecelerate を使ったブレーキ制御など
    }
}

ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE state, int *panel, int *sound) {
    ATS_HANDLES handle = {0};
    
    // PsMaxSpeed を超えたらブレーキをかける等の制御をここに記述
    if (state.Speed > PsMaxSpeed) {
        handle.Brake = 8;
    }
    
    return handle;
}

// 他の必須関数は空でOK
void WINAPI SetPower(int notch) { }
void WINAPI SetBrake(int notch) { }
void WINAPI SetReverser(int pos) { }
void WINAPI KeyDown(int key) { }
void WINAPI KeyUp(int key) { }
void WINAPI HornBlow(int type) { }
void WINAPI DoorOpen() { }
void WINAPI DoorClose() { }
void WINAPI SetSignal(int signal) { }
void WINAPI SetUndefine(int data) { }
