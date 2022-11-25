#include <Novice.h>

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int PosX[4];
	int PosY[4];
	int Speed[4];

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		PosX[0] = 50;
		Speed[0] = 2;
		PosX[0] += Speed[0];
		if (PosX[0] == 1230) {
			Speed[0] = 0;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::DrawBox(PosX[0], PosY[0], 16, 16, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(PosX[1], PosY[1], 16, 16, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(PosX[2], PosY[2], 16, 16, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(PosX[3], PosY[3], 16, 16, 0.0f, WHITE, kFillModeSolid);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
