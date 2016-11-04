MEMO
===========================


クラス設計
---------------------------
### gameParameterクラス
- ヘッダファイルのみ
- キャラクターの基本ステータス項目の構造体
- 構造体を埋めるためのデータ配列

### statusクラス
- gameParameterクラスの実体
- ステータスを増減するための関数

### characterクラス
- statusクラスを内包
- 攻撃関数
- 攻撃受ける関数
- 行動を選択する関数

### playerクラス
- gameクラスを継承
- 取れる行動一覧を表示するクラス

### enemyクラス
- gameクラスを継承
- 取れる行動一覧を表示するクラス

### gameクラス
- プレイヤークラスのスマートポインタを収容するvector
- 